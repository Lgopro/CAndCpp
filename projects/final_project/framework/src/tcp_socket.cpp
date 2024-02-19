
#include "tcp_socket.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 

using namespace ilrd;

TCPsocket::TCPsocket(char *ip, unsigned int port): m_port(port)
{
    m_message = new char[1024];
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
    listen(m_socket, 5);
    printf("Server listening for connections...\n");
    
    /* Accept incoming connection */
    m_new_socket = accept(m_socket, (struct sockaddr *)&m_clientAddr, &m_client_len);
    if (m_new_socket == -1) 
    {
        perror("accept");
        close(m_socket);
        exit(EXIT_FAILURE);
    }
}

void TCPsocket::Send(char *message)
{
    send(m_new_socket, message, 1024, 0);
}
        
void TCPsocket::Recive()
{
    memset(m_message, 0, strlen(m_message) - 1);
    int bytes_reveived = recv(m_new_socket, m_message, 1024, 0);
    if(bytes_reveived <= 0 )
    {
        std::cout<< "No signal recieved" << std::endl;
    }
    std::cout<< "Signal recieved from user is: "<< m_message << std::endl;
}

char *TCPsocket::GetMessage()
{
    return m_message;
}

TCPsocket::~TCPsocket()
{
    close(m_socket);
    close(m_new_socket);
    delete [] m_message;
    delete [] m_ip;
}


void TCPsocket::SetPort(unsigned int port)
{
    
}
        
void SetIp(char *ip)
{

}