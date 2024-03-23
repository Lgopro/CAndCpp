

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

using namespace ilrd;

void check_host_name(int hostname)
{ // This function returns host name for local computer
    if (hostname == -1)
    {
        perror("gethostname");
        exit(1);
    }
}

void check_host_entry(struct hostent *hostentry)
{ // find host info from host name
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}

void IP_formatter(char *IPbuffer)
{ // convert IP string to dotted decimal format
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
/* 
TcpUser::TcpUser(int port) : server_port_number(port)
{
    char TotalMessage[SIZE_OF_TEXT];
    is_user_active = true;

    m_ip = GetIp();

    TCPCreateSocketUser();
    TCPPrepareAddrUser();

    while (true)
    {
        std::cout << "Please enter a username" << std::endl;
        std::cin >> m_user_name;
        std::cout << "Please enter a password" << std::endl;
        std::cin >> m_pass_word;

        std::cout << "Please wait while processing information" << std::endl;
        strcpy(TotalMessage, m_user_name);
        strcat(TotalMessage, m_pass_word);

        TCPSendAndRecieveUser(TotalMessage);
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

TcpUser::~TcpUser()
{
    char TotalMessage[SIZE_OF_TEXT];
    is_user_active = false;

    strcpy(TotalMessage, m_user_name);
    strcat(TotalMessage, m_pass_word);
    strcat(TotalMessage, "F");

    TCPSendAndRecieveUser(TotalMessage);
    auto now = std::chrono::system_clock::now();
    m_last_active_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Exit server. Good night!" << std::endl;
    close(sockfd);
}

void TcpUser::GetScreenshot()
{
}

std::time_t TcpUser::GetLastActiveTime()
{
    if (is_user_active = true)
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }

    return m_last_active_time;
}

const char *TcpUser::GetIp()
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

std::string TcpUser::GetUserName() const
{
    return m_user_name;
}

std::string TcpUser::GetPassword() const
{
    return m_pass_word;
}

bool TcpUser::IsActive() const
{
    return is_user_active;
}

void TcpUser::TCPCreateSocketUser()
{
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}
void TcpUser::TCPPrepareAddrUser()
{
    

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port_number); 
    server_addr.sin_addr.s_addr = inet_addr(GetIp()); 

    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void TcpUser::TCPSendAndRecieveUser(char *message)
{
    char ack[100];
    
    send(sockfd, message, SIZE_OF_TEXT, 0);
    printf("Sent to server: %s\n", message);

    
    sleep(1);
    recv(sockfd, ack, sizeof(ack), 0);
    std::cout << "Received acknowledgment: " << ack << std::endl;
    if (strcmp(ack, "success") == 0)
    {
        is_user_right = true;
    }
}
 */
UdpUser::UdpUser(int port) : server_port_number(port)
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

UdpUser::~UdpUser()
{
    char TotalMessage[SIZE_OF_TEXT];

    is_user_active = false;
    /*Send that im dead*/

    strcpy(TotalMessage, m_user_name);
    strcat(TotalMessage, m_pass_word);
    strcat(TotalMessage, "F");

    UDPSendAndRecieveUser(TotalMessage);
    auto now = std::chrono::system_clock::now();
    m_last_active_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "Exit server. Good night!" << std::endl;
    close(sockfd);
}

void UdpUser::GetScreenshot()
{
}

std::time_t UdpUser::GetLastActiveTime()
{
    if (is_user_active = true)
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }

    return m_last_active_time;
}

const char *UdpUser::GetIp()
{
    char host[256];

    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, sizeof(host)); // find the host name
    check_host_name(hostname);
    host_entry = gethostbyname(host); // find host information
    check_host_entry(host_entry);
    m_ip = inet_ntoa(*((struct in_addr *)host_entry->h_addr_list[0])); // Convert into IP string
    return m_ip.c_str();
}

std::string UdpUser::GetUserName() const
{
    return m_user_name;
}

std::string UdpUser::GetPassword() const
{
    return m_pass_word;
}

bool UdpUser::IsActive() const
{
    return is_user_active;
}

void UdpUser::UDPCreateSocketUser()
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void UdpUser::UDPPrepareAddrUser()
{
    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port_number);      /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr(m_ip.c_str()); /* Server IP address */
}

void UdpUser::UDPSendAndRecieveUser(char *message)
{
    /* Send message to server */
    /* const char *message = "Ping!"; */
    sendto(sockfd, message, SIZE_OF_TEXT, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    std::cout << "Sent to server: " << message << std::endl;

    /* Receive acknowledgment from server */
    sleep(1);
    recvfrom(sockfd, ack, sizeof(ack), 0, NULL, NULL);
    std::cout << "Received acknowledgment: " << ack << std::endl;
    if (strcmp(ack, "success") == 0)
    {
        is_user_right = true;
    }
}

Server::Server(int server_port, std::string github_link) : m_github_link(github_link), server_port_number(server_port)
{
}

void Server::Run()
{
    /* create listening TCP socket */
    tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port_number);

    // binding server addr structure to listenfd
    if (bind(tcpsock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        close(tcpsock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(tcpsock, 10) == -1)
    {
        perror("listen");
        close(tcpsock);
        exit(EXIT_FAILURE);
    }
    
    /* create UDP socket */
    udpsock = socket(AF_INET, SOCK_DGRAM, 0);
    // binding server addr structure to udp sockfd
    bind(udpsock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // clear the descriptor set
    FD_ZERO(&rset);

    // get maxfd
    maxfd = max(tcpsock, udpsock) + 1;
    while (m_working_server != false)
    {
        // set listenfd and udpfd in readset
        FD_SET(tcpsock, &rset);
        FD_SET(udpsock, &rset);
        // select the ready descriptor
        std::cout << "Got to select" << std::endl;
        ready_descriptor = select(maxfd, &rset, NULL, NULL, NULL);
        // if tcp socket is readable then handle
        // it by accepting the connection
        if (FD_ISSET(tcpsock, &rset))
        {
            std::cout << "Entered TCPSendAndRecieveServer" << std::endl;
            TCPSendAndRecieveServer();
        }
        // if udp socket is readable receive the message.
        if (FD_ISSET(udpsock, &rset))
        {
            UDPSendAndRecieveServer();
        }
    }
}

Server::~Server()
{
    m_working_server = false;
}

void Server::TCPSendAndRecieveServer()
{
    ssize_t bytes_reveived = 0;

    /* Listen for incoming connections */
    int newsockfd;

    /* Accept incoming connection */
    newsockfd = accept(tcpsock, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd == -1)
    {
        perror("accept");
    }

    /* Receive message from client */
    memset(buffer_from_user, 0, sizeof(buffer_from_user));
    std::cout << "Got until recieve" << std::endl;
    while(true)
    {
        bytes_reveived = recv(newsockfd, buffer_from_user, sizeof(buffer_from_user), 0);
        if (bytes_reveived <= 0)
        {
            /* std::cout << "Did not get anything" << std::endl; */
            continue;
        }
        std::cout << "Got something" << std::endl;
        std::string buff = buffer_from_user;
        std::cout << "Recieved" << buff << std::endl;
        if (buff.length() <= 4)
        {
            send(newsockfd, "fail", 5, 0);
        }

        auto result = m_user_list.find(buff.substr(0, buff.length() - 4));

        if (buff.substr(buff.length() - 1, buff.length()) == "F" &&
            m_user_list.find(buff.substr(0, buff.length() - 5)) != m_user_list.end())
        {
            std::cout << "Got here1" << std::endl;
            auto result = m_user_list.find(buff.substr(0, buff.length() - 5));
            result->second.is_active = false;
            send(newsockfd, "success", 8, 0);
            close(newsockfd);
            return;
        }

        if (m_user_list.find(buff.substr(0, buff.length() - 4)) == m_user_list.end())
        {
            std::cout << "Got here2" << std::endl;
            sendto(newsockfd, "fail", 5, 0, (struct sockaddr *)&client_addr, client_len);
        }
        else
        {

            if (result->second.password != buff.substr(buff.length() - 4, buff.length()))
            {
                std::cout << "Got here3" << std::endl;
                sendto(newsockfd, "fail", 5, 0, (struct sockaddr *)&client_addr, client_len);
            }
            std::cout << "Got here4" << std::endl;
            result->second.is_active = true;
            sendto(newsockfd, "success", 8, 0, (struct sockaddr *)&client_addr, client_len);
        }
    }
    /* close(newsockfd); */
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
            m_user_list.find(buff.substr(0, buff.length() - 5)) != m_user_list.end())
        {
            auto result = m_user_list.find(buff.substr(0, buff.length() - 5));
            result->second.is_active = false;
            sendto(udpsock, "success", 8, 0, (struct sockaddr *)&client_addr, client_len);
            return;
        }

        if (m_user_list.find(buff.substr(0, buff.length() - 4)) == m_user_list.end())
        {
            sendto(udpsock, "fail", 5, 0, (struct sockaddr *)&client_addr, client_len);
        }
        else
        {
            if (result->second.password != buff.substr(buff.length() - 4, buff.length()))
            {
                sendto(udpsock, "fail", 5, 0, (struct sockaddr *)&client_addr, client_len);
            }
            result->second.is_active = true;
            sendto(udpsock, "success", 8, 0, (struct sockaddr *)&client_addr, client_len);
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

void Server::PrintAllUserNames() const
{
    for (auto iter : m_user_list)
    {
        std::cout << iter.first << std::endl;
    }
}