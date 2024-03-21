

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


using namespace ilrd;

void check_host_name(int hostname) 
{ //This function returns host name for local computer
    if (hostname == -1) 
    {
        perror("gethostname");
        exit(1);
    }
}

void check_host_entry(struct hostent * hostentry) 
{ //find host info from host name
    if (hostentry == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }
}

void IP_formatter(char *IPbuffer) 
{ //convert IP string to dotted decimal format
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

TcpUser::TcpUser()
{
    is_user_active = true;
    /*Send that im alive*/
}

TcpUser::~TcpUser()
{
    is_user_active = false;
    /*Send that im dead*/
   
    auto now = std::chrono::system_clock::now();
    m_last_active_time = std::chrono::system_clock::to_time_t(now);
}

        
void TcpUser::GetScreenshot()
{
    
}
        
std::time_t TcpUser::GetLastActiveTime()
{
    if(is_user_active = true)
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }
    
    return m_last_active_time;
}
        
char *TcpUser::GetIp()
{
    char host[256];
    
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, sizeof(host)); //find the host name
    check_host_name(hostname);
    host_entry = gethostbyname(host); //find host information
    check_host_entry(host_entry);
    m_ip = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0])); //Convert into IP string
    printf("Current Host Name: %s\n", host);
    printf("Host IP: %s\n", m_ip);
    return m_ip;
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
    /* Create TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}  
void TcpUser::TCPPrepareAddrUser(size_t port, char *IP)
{
    /* Prepare server address */
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);  /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr(IP);  /* Server IP address */
    
    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void TcpUser::TCPSendAndRecieveUser()
{
    int i = 0;
    const char *message = "Ping!";
    char ack[100];
    for(i = 0;i < PING_AMOUNT; ++i)
    {
        /* Send message to server */
        send(sockfd, message, strlen(message), 0);
        printf("Sent to server: %s\n", message);
        
        /* Receive acknowledgment from server */
        sleep(1);
        recv(sockfd, ack, sizeof(ack), 0);
        printf("Received acknowledgment: %s\n", ack);
    }   
    close(sockfd);
}  





UdpUser::UdpUser()
{
     is_user_active = true;
    /*Send that im alive*/
}

UdpUser::~UdpUser()
{
    is_user_active = false;
    /*Send that im dead*/
   
    auto now = std::chrono::system_clock::now();
    m_last_active_time = std::chrono::system_clock::to_time_t(now);
}

void UdpUser::GetScreenshot()
{
    
}

std::time_t UdpUser::GetLastActiveTime()
{
    if(is_user_active = true)
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }
    
    return m_last_active_time;
}

char *UdpUser::GetIp()
{
    char host[256];
    
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(host, sizeof(host)); //find the host name
    check_host_name(hostname);
    host_entry = gethostbyname(host); //find host information
    check_host_entry(host_entry);
    m_ip = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0])); //Convert into IP string
    printf("Current Host Name: %s\n", host);
    printf("Host IP: %s\n", m_ip);
    return m_ip;
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

void UdpUser::UDPPrepareAddrUser(size_t port, char* IP) 
{
    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);   /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr(IP);  /* Server IP address */
    
}  

void UdpUser::UDPSendAndRecieveUser() 
{ 
    int i = 0;
    char ack[50];
    for(i = 0;i < PING_AMOUNT; ++i)
    {
        /* Send message to server */
        const char *message = "Ping!";
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        printf("Sent to server: %s\n", message);
        /* Receive acknowledgment from server */
        sleep(1);
        recvfrom(sockfd, ack, sizeof(ack), 0, NULL, NULL);
        printf("Received acknowledgment: %s\n", ack);
    }
    close(sockfd);
}

Server::Server(std::string github_link) : m_github_link(github_link)
{
    /* create listening TCP socket */
    tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(7070);
 
    // binding server addr structure to listenfd
    bind(tcpsock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(tcpsock, 10);
 
    /* create UDP socket */
    udpsock = socket(AF_INET, SOCK_DGRAM, 0);
    // binding server addr structure to udp sockfd
    bind(udpsock, (struct sockaddr*)&udpsock, sizeof(udpsock));
 
    // clear the descriptor set
    FD_ZERO(&rset);
 
    // get maxfd
    maxfd = max(tcpsock, udpsock) + 1;
    while(m_working_server != false)
    {
        // set listenfd and udpfd in readset
        FD_SET(tcpsock, &rset);
        FD_SET(udpsock, &rset);
 
        // select the ready descriptor
        ready_descriptor = select(maxfd, &rset, NULL, NULL, NULL);
 
        // if tcp socket is readable then handle
        // it by accepting the connection
        if (FD_ISSET(tcpsock, &rset)) 
        {
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
    const char *ack = "Pong";
    /* Listen for incoming connections */
    int newsockfd;
    
    /* Accept incoming connection */
    newsockfd = accept(tcpsock, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd == -1) 
    {
        perror("accept");
        close(tcpsock);
        exit(EXIT_FAILURE);
    }
    
    /* Receive message from client */
    memset(buffer_from_user, 0, sizeof(buffer_from_user));
    bytes_reveived = recv(newsockfd, buffer_from_user, sizeof(buffer_from_user), 0);
    if(bytes_reveived <= 0 )
    {
        return;
    }
    printf("Received from client: %s\n", buffer_from_user);
    printf("Send Pong\n");
    /* Send acknowledgment to client */ 
    send(newsockfd, ack, strlen(ack), 0);
    close(newsockfd);
}
        
void Server::UDPSendAndRecieveServer()
{
    client_len = sizeof(client_addr);
    printf("Server waiting for messages...\n");
    
    /* Receive message from client */
    memset(buffer_from_user, 0, sizeof(buffer_from_user)); /* Clear the buffer using memset() */
    recvfrom(udpsock, buffer_from_user, sizeof(buffer_from_user), 0, (struct sockaddr *)&client_addr, &client_len);
    printf("Received from client: %s\n", buffer_from_user);
    printf("Send Pong! back to user.\n");
    /* Send acknowledgment to client */
    sendto(udpsock, "Leon Pong", 10, 0, (struct sockaddr *)&client_addr, client_len);
}


void Server::CloseServer()
{
    m_working_server = false;
}