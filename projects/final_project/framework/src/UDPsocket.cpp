
#include "UDPsocket.hpp"

#include <unistd.h>
#include <thread>
#include <arpa/inet.h>
#include "string.h"
#include "messageheader.hpp"
#include "minnion_disk.hpp"
#include "handleton_inst.hpp"
#include "uid_map.hpp"
#include <functional>
#include <chrono>

using namespace ilrd;
UDPsocket::UDPsocket(char *ip, unsigned int port):m_port(port), m_ip(ip)
{
    struct sockaddr_in m_serverAddr;
   
    if ((m_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        perror("Socket creation failed");
        return;
    }
   
    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_port = htons(m_port); 
    m_serverAddr.sin_addr.s_addr = inet_addr(m_ip); 

    // Bind the socket to the address
    if (bind(m_socket, (const struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) < 0) 
    {
        perror("Binding failed");
        return;
    }
    m_message = new char[1024];
}
UDPsocket::~UDPsocket()
{
    close(m_socket);
    delete [] m_message;
}
void UDPsocket::RecieveMinnion()
{
    int n;
    socklen_t len = sizeof(m_clientAddr);

    std::cout << "Minnion Server is listening..." << std::endl;
    /* n = recvfrom(m_socket, m_message, 1024, 0, (struct sockaddr*)&m_clientAddr, &len); */
    std::cout << "Minnion Server Got message..." << std::endl;
    std::cout << *m_message <<*(u_int32_t *)(m_message + 1) << *(u_int32_t *)(m_message + 5) << (m_message + 9) << std::endl;
    return;
}

void UDPsocket::RecieveMaster()
{
    int n;
    socklen_t len = sizeof(m_clientAddr);

    std::cout << "Master Server is listening..." << std::endl;
    n = recvfrom(m_socket, m_message, 1024, 0, (struct sockaddr*)&m_clientAddr, &len);
    std::cout << "Master Server Got message..." << std::endl;
    std::cout << m_message << std::endl;
    return;
}

void UDPsocket::Send(char *ip, unsigned int port, char *array, u_int32_t uid)
{
    m_clientAddr.sin_family = AF_INET;
    m_clientAddr.sin_port = htons(port); 
    m_clientAddr.sin_addr.s_addr = inet_addr(ip); 
    // Send the message to the server
    /* std::cout<< "Inside Send data is: " << *array << *(u_int32_t *)(array + 1) << *(u_int32_t *)(array + 5) <<  *(u_int32_t *)(array + 9) << std::endl; */
    ssize_t value = sendto(m_socket, (const char*)array, 1000, 0, (const struct sockaddr*)&m_clientAddr, sizeof(m_clientAddr));
    if(-1 == value)
    {
        std::cout<<"Failed to send message" << std::endl;
    }
    else
    {
        GetUIDMap()->SetUIDstatus(uid, UIDMap::SENT);
        GetUIDMap()->Print();
        std::cout << "Message sent." << std::endl;
    }
}

unsigned int UDPsocket::GetSocket() const
{
    return m_socket;
}

char *UDPsocket::GetMessage()
{
    return m_message;
}


void UDPsocket::SetMessageWrite(char * message)
{
    *m_message = *message;
    *(u_int32_t *)(m_message + 1) = *(u_int32_t *)(message + 1);
    *(u_int32_t *)(m_message + 5) = *(u_int32_t *)(message + 5);
    *(u_int32_t *)(m_message + 9) = *(u_int32_t *)(message + 9);
    strcpy((m_message + 13), (message + 13));
}

void UDPsocket::SetMessageRead(char * message)
{
    *m_message = *message;
    *(u_int32_t *)(m_message + 1) = *(u_int32_t *)(message + 1);
    *(u_int32_t *)(m_message + 5) = *(u_int32_t *)(message + 5);
    *(u_int32_t *)(m_message + 9) = *(u_int32_t *)(message + 9);
    m_uid = *(u_int32_t *)(message + 9);
    *(m_message + 13) = '\0';
}

void UDPsocket::SetMessageReturn(char *message)
{
    strcpy(m_message, message);
}

u_int32_t UDPsocket::GetUID() const
{
    return m_uid;
}