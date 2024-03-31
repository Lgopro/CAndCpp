#include "UserAndServer.hpp"

#include <iomanip>
#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>
#include <netdb.h>
#include <thread>
#include <ctime>
#include <sstream>
#include <fstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace ilrd;

void check_host_name(int hostname)
{ 
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}

void check_host_entry(struct hostent *hostentry)
{ 
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}

void IP_formatter(char *IPbuffer)
{ 
    if (NULL == IPbuffer)
    {
        perror("inet_ntoa");
        exit(1);
    }
}

static int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}


User::User(int udp_port, int tcp_port) : server_port_number(udp_port), tcp_server_port_number(tcp_port)
{
    char TotalMessage[SIZE_OF_TEXT];

    m_ip = GetIp();

    UDPCreateSocketUser();
    UDPPrepareAddrUser();
    while (true)
    {
        std::cout << "Please enter a username" << std::endl;
        std::cin >> m_user_name;
        std::cout << "Please enter a password" << std::endl;
        std::cin >> m_pass_word;

        std::cout << "Please wait while processing information" << std::endl;
        strcpy(TotalMessage, m_user_name);
        strcat(TotalMessage, m_pass_word);

        UDPSendAndRecieveUser(TotalMessage);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (is_user_right == true)
        {
            break;
        }
        std::cout << "Wrong username or infomation" << std::endl;
    }

    std::cout << "Entered server. Good day!" << std::endl;
    is_user_active = true;
}

User::~User()
{
    char TotalMessage[SIZE_OF_TEXT];
    char date[20];
    is_user_active = false;
    m_last_active_time = std::time(nullptr);

    std::strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", std::localtime(&m_last_active_time));

    strcpy(TotalMessage, m_user_name);
    strcat(TotalMessage, m_pass_word);
    strcat(TotalMessage, date);
    strcat(TotalMessage, "F");

    UDPSendAndRecieveUser(TotalMessage);
    auto now = std::chrono::system_clock::now();
    m_last_active_time = std::chrono::system_clock::to_time_t(now);

    std::cout << "Sending screenshot before exiting." << std::endl;
    SendScreenshot();

    std::cout << "Exit server. Good night!" << std::endl;
    
}

void User::SendScreenshot()
{
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(tcp_server_port_number);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        std::cerr << "Connection failed" << std::endl;
        close(sockfd);
        return;
    }

    std::string saveDirectory = "/home/lgopro/Desktop/";
    std::string name = m_user_name;
    std::string pass = m_pass_word;
    
    // Open image file
    std::ifstream file(saveDirectory + name + pass + ".png", std::ios::binary);
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open file" << std::endl;
        close(sockfd);
        return;
    }

    // Read image file and send over TCP
    char buffer[1024];
    while (!file.eof()) 
    {
        file.read(buffer, sizeof(buffer));
        send(sockfd, buffer, file.gcount(), 0);
    }

    file.close();
    close(sockfd);
}

std::time_t User::GetLastActiveTime()
{
    if (is_user_active = true)
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }

    return m_last_active_time;
}

const char *User::GetIp()
{
    char host[256];

    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, sizeof(host)); 
    check_host_name(hostname);
    host_entry = gethostbyname(host); 
    check_host_entry(host_entry);
    m_ip = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0])); 
    return m_ip.c_str();
}

std::string User::GetUserName() const
{
    return m_user_name;
}

std::string User::GetPassword() const
{
    return m_pass_word;
}

bool User::IsActive() const
{
    return is_user_active;
}

void User::UDPCreateSocketUser()
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void User::UDPPrepareAddrUser()
{
    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port_number);      /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr(m_ip.c_str()); /* Server IP address */
}

void User::UDPSendAndRecieveUser(char *message)
{
    /* Send message to server */
    /* const char *message = "Ping!"; */
    sendto(sockfd, message, SIZE_OF_TEXT, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    #ifndef NDEBUG
    std::cout << "Sent to server: " << message << std::endl;
    #endif /*NDEBUG*/

    /* Receive acknowledgment from server */
    sleep(1);
    recvfrom(sockfd, ack, sizeof(ack), 0, NULL, NULL);
    std::string str = ack;
    std::string succ_or_fail = str.substr(0, 7);
    if (strncmp(ack, "success", 7) == 0 && is_user_right == false)
    {
        #ifndef NDEBUG
        std::cout << "Received acknowledgment: " << succ_or_fail << std::endl;
        #endif /*NDEBUG*/
        m_github_link = str.substr(7, str.length());
        #ifndef NDEBUG
        std::cout << "Link recieved! Its " << m_github_link << std::endl;
        #endif /*NDEBUG*/
        is_user_right = true;
        return;
    }
    else
    {
        #ifndef NDEBUG
        std::cout << "Received acknowledgment: " << succ_or_fail << std::endl;
        #endif /*NDEBUG*/
    }
    
    close(sockfd);
}

std::string User::GetLink()
{
    return m_github_link;
}



Server::Server(int udp_port_number, int tcp_port_number, std::string github_link) : m_github_link(github_link), server_port_number(udp_port_number), tcp_server_port_number(tcp_port_number)
{
}

void Server::TCPCreateSocketServer()  
{  
    /* Create TCP socket */
    tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcpsock == -1) 
    {
        std::cerr << "tcp socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}  

void Server::TCPPrepareAddrServer()
{
    /* Bind socket to server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(tcp_server_port_number);   /* Server port number */

    if (bind(tcpsock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        std::cerr << "tcp bind" << std::endl;
        close(tcpsock);
        exit(EXIT_FAILURE);
    }
}

void Server::TCPPrepareListenServer()
{
    if (listen(tcpsock, 5) < 0) 
    {
        std::cerr << "tcp listen" << std::endl;
        close(tcpsock);
        exit(EXIT_FAILURE);
    }
    std::cout << "TCP Server listening for connections..." << std::endl;
}

void Server::UDPCreateSocketServer()
{
    udpsock = socket(AF_INET, SOCK_DGRAM, 0);
    if (udpsock == -1) 
    {
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::UDPPrepareAddrServer()
{
    // Server configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port_number);

    // Bind socket
    if (bind(udpsock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        std::cerr << "Error binding socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::Run()
{
    TCPCreateSocketServer();
    TCPPrepareAddrServer();
    TCPPrepareListenServer();
    
    UDPCreateSocketServer();
    UDPPrepareAddrServer();

    /* clear the descriptor set */
    FD_ZERO(&rset);

    /* get maxfd */
    maxfd = max(tcpsock, udpsock) + 1;
    while (m_working_server != false)
    {
        /* set listenfd and udpfd in readset */
        FD_SET(tcpsock, &rset);
        FD_SET(udpsock, &rset);
        /* select the ready descriptor */

        #ifndef NDEBUG
        std::cout << "Got to select" << std::endl;
        #endif /*NDEBUG*/

        ready_descriptor = select(maxfd, &rset, NULL, NULL, NULL);

        #ifndef NDEBUG
        std::cout << "Got after select" << std::endl;
        #endif /*NDEBUG*/

        /* if tcp socket is readable then handle */
        /* it by accepting the connection */
        if (FD_ISSET(tcpsock, &rset))
        {
            #ifndef NDEBUG
            std::cout << "Entered TCP" << std::endl;
            #endif /*NDEBUG*/
            TCPSendAndRecieveServer(file_name);
        }
        /* if udp socket is readable receive the message. */
        if (FD_ISSET(udpsock, &rset))
        {
            UDPSendAndRecieveServer();
        }
    }
}

Server::~Server()
{
    m_working_server = false;
    close(tcpsock);
    close(udpsock);
}

void handleClient(int new_socket, std::string name, int tcpport)
{
    char buffer[SIZE_OF_TEXT] = {0};
    int valread;
    
    /* Open file to write received data, overwriting if it exists */
    std::ofstream received_file(name, std::ios::binary | std::ios::trunc);
    if (!received_file.is_open()) 
    {
        std::cerr << "Failed to create " << name << std::endl;
        close(new_socket);
        return;
    }

    /* Receive image data and write to file */
    while ((valread = recv(new_socket, buffer, SIZE_OF_TEXT, 0)) > 0) 
    {
        received_file.write(buffer, valread);
    }

    received_file.close();
    close(new_socket);
}

void Server::TCPSendAndRecieveServer(std::string name)
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        client_len = sizeof(client_addr);
        if((new_socket = accept(tcpsock, (struct sockaddr *)&client_addr, (socklen_t *)&client_len)) < 0) 
        {
            perror("accept");
        }
        std::thread(handleClient, new_socket, name, tcp_server_port_number).join();

    } 
}

void Server::UDPSendAndRecieveServer()
{
    client_len = sizeof(client_addr);
    printf("Server waiting for messages...\n");

    /* Receive message from client */
    while (m_working_server != false)
    {
        memset(buffer_from_user, 0, sizeof(buffer_from_user)); /* Clear the buffer using memset() */
        recvfrom(udpsock, buffer_from_user, sizeof(buffer_from_user), 0, (struct sockaddr *)&client_addr, &client_len);
        printf("Received from client: %s\n", buffer_from_user);
        std::string buff = buffer_from_user;

        if (buff.length() <= 4)
        {
            sendto(udpsock, "fail", 5, 0, (struct sockaddr *)&client_addr, client_len);
        }

        auto result = m_user_list.find(buff.substr(0, buff.length() - 4));

        if (buff.substr(buff.length() - 1, buff.length()) == "F" &&
            m_user_list.find(buff.substr(0, buff.length() - 24)) != m_user_list.end())
        {
            auto result = m_user_list.find(buff.substr(0, buff.length() - 24));
            result->second.is_active = false;
            file_name = buff.substr(0, buff.length() - 24) + buff.substr(buff.length() - 24, buff.length() - 20) +".png";
            std::string time_string = buff.substr(buff.length() - 20, buff.length() - 1);
            /* Create a std::tm structure to hold the parsed time */
            std::tm timeInfo = {};

            /* Create a std::istringstream from the time string */
            std::istringstream ss(time_string);

            /* Use std::get_time to parse the time string into a std::tm structure */
            ss >> std::get_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

            /* Check if the parsing was successful */
            if (ss.fail()) 
            {
                std::cerr << "Error parsing time string" << std::endl;
                return;
            }

            /* Convert the std::tm structure to a time_t value */
            result->second.m_last_active_time = std::mktime(&timeInfo);
        
            char answer[50];
            strcpy(answer, "success");
            strcat(answer, m_github_link.c_str());
            sendto(udpsock, answer, 50, 0, (struct sockaddr *)&client_addr, client_len);

            return;
        }

        if (m_user_list.find(buff.substr(0, buff.length() - 4)) == m_user_list.end())
        {
            sendto(udpsock, "fail", 50, 0, (struct sockaddr *)&client_addr, client_len);
        }
        else
        {
            if (result->second.password != buff.substr(buff.length() - 4, buff.length()))
            {
                sendto(udpsock, "fail", 50, 0, (struct sockaddr *)&client_addr, client_len);
            }

            result->second.is_active = true;
            result->second.was_active_ever = true;
            char answer[50];
            strcpy(answer, "success");
            strcat(answer, m_github_link.c_str());
            sendto(udpsock, answer, 50, 0, (struct sockaddr *)&client_addr, client_len);
        }
    }
}

void Server::CloseServer()
{
    m_working_server = false;
}

void Server::PrintAllActiveUsers() const
{
    size_t counter = 0;

    for (auto iter : m_user_list)
    {
        if (iter.second.is_active == true)
        {
            ++counter;
            std::cout << iter.second.domain << std::endl;
            std::cout << iter.second.ip << std::endl;
            std::cout << iter.second.machine << std::endl;
            std::cout << iter.second.user << std::endl;
            std::cout << iter.second.password << std::endl;
        }
    }

    if (counter == 0)
    {
        std::cout << "There are no active users now" << std::endl;
    }
}

void Server::AddNewUser(std::string user_name, UserData user_data)
{
    for (auto iter : m_user_list)
    {
        if (user_name == iter.first)
        {
            std::cout << "Already has such user, please enter another name" << std::endl;
            return;
        }
    }
    m_user_list.insert({user_name, user_data});
}

void Server::RemoveUser(std::string user_name)
{
    for (auto iter : m_user_list)
    {
        if (user_name == iter.first)
        {
            m_user_list.erase(user_name);
            return;
        }
    }
    std::cout << "No such user. Please try again." << std::endl;
}

void Server::PrintAllUserNames() const
{
    for (auto iter : m_user_list)
    {
        std::cout << iter.first << std::endl;
    }
}


void Server::PrintLastActiveTime(std::string user_name)
{
    auto iter = m_user_list.find(user_name);
    if(iter == m_user_list.end())
    {
        std::cout << "No such user. Please try again." << std::endl;
        return;
    }
    else
    {
        if(iter->second.was_active_ever == false)
        {
            std::cout << "User " << iter->second.user << " has never been active" << std::endl;
            return;
        }
        else if(iter->second.is_active == true)
        {
            iter->second.m_last_active_time =  time(nullptr);
            std::cout << "ACTIVE USSR" << std::endl;
        }
        std::cout << "Last Active time of user: " << iter->second.user << " is: " << ctime(&iter->second.m_last_active_time) << std::endl;
    }
}