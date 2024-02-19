
#include "tcp.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include <iomanip>
#include <ctime>
#include <thread>
#include <fcntl.h>
#include <algorithm>

const int SIZE = 1024;



using namespace ilrd;

std::mutex TCPsocket::m_mutex;

TCPsocket::TCPsocket(char *ip, unsigned int port): m_port(port), m_flag(true)
{
    m_ip = new char[30];
    strcpy(m_ip, ip);
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_addr.s_addr = inet_addr(ip); 
    m_serverAddr.sin_port = htons(port);    
}

void TCPsocket::Bind()
{
    if (bind(m_socket, (struct sockaddr *)&m_serverAddr, sizeof(m_serverAddr)) == -1) 
    {
        perror("bind");
        close(m_socket);
        exit(EXIT_FAILURE);
    }
}

void TCPsocket::ListenAndAccept()
{
    unsigned int socket = 0;
    listen(m_socket, 5);
    printf("Server listening for connections...\n");

    m_client_len = sizeof(m_clientAddr);

    
    while(m_flag)
    {
        socket = accept(m_socket, (struct sockaddr *)&m_clientAddr, &m_client_len);
        if (socket == -1) 
        {
            perror("accept");
            close(m_socket);
            exit(EXIT_FAILURE);
        }

        auto status = std::find(m_list_sockets.begin(), m_list_sockets.end(), socket);
        if(m_list_sockets.end() == status)
        {
            m_list_sockets.push_back(socket);
        }  

        fd_set read_fds;
        FD_ZERO(&read_fds);

        int max_fd = -1;
        for (auto iter_socket : m_list_sockets) 
        {
            FD_SET(iter_socket, &read_fds);
            max_fd = std::max(max_fd, iter_socket);
        }

        struct timeval timeout;
        timeout.tv_sec = 2;  
        timeout.tv_usec = 0;

        int ready_fds = select(max_fd + 1, &read_fds, nullptr, nullptr, &timeout);

        if(ready_fds == -1) 
        {
            perror("select");
            break;
        } 
        else if (ready_fds > 0)
        {
                
            for(auto iter_socket : m_list_sockets) 
            {
                if(FD_ISSET(iter_socket, &read_fds)) 
                {
                    std::thread(Recive, iter_socket, &m_flag).detach();
                }
            }
        } 
        else 
        {
            std::cout << "Timeout." << std::endl;
        }
        
    }
}


void TCPsocket::Recive(unsigned int socket, bool *flag)
{
    char message[SIZE];
    while(*flag)
    {
        memset(message, 0, SIZE);
        int bytes_reveived = recv(socket, message, SIZE, 0);
        if(bytes_reveived <= 0 )
        {
            std::cout<< "No signal recieved" << std::endl;
        }

        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        
        std::tm *timeinfo = std::localtime(&in_time_t);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", timeinfo);

        std::unique_lock<std::mutex> lock(m_mutex);

        std::cout<< buffer << " " << message << std::endl;
    }
}



TCPsocket::~TCPsocket()
{
    m_flag = false;
    close(m_socket);
    delete [] m_ip;
}


