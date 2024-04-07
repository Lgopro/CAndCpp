
/*Tcp.cpp begin*/
#include "Tcp.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <string.h>

using namespace ilrd;

const int MAX_CLIENTS = 10;

TcpUser::TcpUser(int tcp_port, size_t sleep, std::string name) : m_tcp_port(tcp_port), m_sleep_for(sleep), m_name(name), m_to_send(true)
{
    TCPCreateSocketUser();
    TCPPrepareAddrUser();
}
        
TcpUser::~TcpUser()
{

    close(m_sock);
}

void TcpUser::TCPCreateSocketUser()
{
    if ((m_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        std::cerr << "Socket creation error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    m_serv_addr.sin_family = AF_INET;
    m_serv_addr.sin_port = htons(m_tcp_port);
}  
void TcpUser::TCPPrepareAddrUser()
{
    if(inet_pton(AF_INET, "127.0.0.1", &m_serv_addr.sin_addr) <= 0) 
    {
        std::cerr << "Invalid address/Address not supported: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    if (connect(m_sock, (struct sockaddr *)&m_serv_addr, sizeof(m_serv_addr)) < 0) 
    {
        std::cerr << "Connection Failed: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

void TcpUser::TCPSendAndRecieveUser()
{
    char date[SIZE_OF_TEXT];
    char message[SIZE_OF_TEXT];
    
    while(m_to_send != false)
    {
        message[SIZE_OF_TEXT] = {0};
        date[SIZE_OF_TEXT] = {0};
        m_last_active_time = std::time(nullptr);
        std::strftime(date, sizeof(date), "[%Y-%m-%d %H:%M:%S] ", std::localtime(&m_last_active_time));
        strcat(message, m_name.c_str());
        strcat(message, date);
        /* Send message to server */
        send(m_sock, message, strlen(message), 0);
        std::this_thread::sleep_for(std::chrono::seconds(m_sleep_for));
    }   
}  

void TcpUser::Stop()
{
    m_to_send = false;
}

TcpServer::TcpServer(int tcp_port_number) : m_serverPort(tcp_port_number), m_to_send(true)
{

}
        
TcpServer::~TcpServer()
{

}


void ClientHandler(int client_socket, bool *flag)
{
    
    char buffer[SIZE_OF_TEXT] = {0};
    while(*flag != false)
    {
        if(read(client_socket, buffer, SIZE_OF_TEXT) > 0)
        {
            std::cout << "Message from client: " << buffer <<std::endl;
            buffer[SIZE_OF_TEXT] = {0};
        }
    }

    close(client_socket);
}

void TcpServer::Run()
{
    TCPCreateSocketServer();
    TCPPrepareAddrServer();
    TCPPrepareListenServer();

    while (m_to_send != false) 
    {
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            if ((m_client_socket = accept(m_server_fd, (struct sockaddr *)&m_address, (socklen_t*)&m_addrlen)) < 0) 
            {
                std::cerr << "accept: " << strerror(errno) << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        std::thread t1(ClientHandler, m_client_socket, &m_to_send);
        t1.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void TcpServer::Stop()
{
    m_to_send = false;
}

void TcpServer::TCPCreateSocketServer()  
{  
    if ((m_server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        std::cerr << "socket failed: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}  

void TcpServer::TCPPrepareAddrServer()
{
    if (setsockopt(m_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &m_opt, sizeof(m_opt))) 
    {
        std::cerr << "setsockopt: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(m_serverPort);
}

void TcpServer::TCPPrepareListenServer()
{
    if (bind(m_server_fd, (struct sockaddr *)&m_address, sizeof(m_address))<0) 
    {
        std::cerr << "bind failed: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    
    if (listen(m_server_fd, MAX_CLIENTS) < 0) 
    {
        std::cerr << "listen: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port: " << m_serverPort << std::endl;
}

/*Tcp.cpp end*/