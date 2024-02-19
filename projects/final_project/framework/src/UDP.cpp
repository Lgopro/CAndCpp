
#include "UDP.hpp"

#include <unistd.h>
#include <arpa/inet.h>
#include "string.h"
#include "messageheader.hpp"
#include "minnion_disk.hpp"

using namespace ilrd;

UDPreciever::UDPreciever(size_t port, char * ip):m_port(port), m_ip(ip)
{
}

void UDPreciever::Recieve()
{
    int m_recieve_socket, n;
    char buffer[1025];
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t len = sizeof(clientAddr);

    // Create a UDP socket
    if ((m_recieve_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        perror("Socket creation failed");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(m_port); // Port to listen on
    serverAddr.sin_addr.s_addr = inet_addr(m_ip); // Specify the target server's IP address

    // Bind the socket to the address
    if (bind(m_recieve_socket, (const struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) 
    {
        perror("Binding failed");
        return;
    }

    std::cout << "Server is listening..." << std::endl;
    
    n = recvfrom(m_recieve_socket, buffer, 1024, 0, (struct sockaddr*)&clientAddr, &len);
    /* std::cout << "Received message: " << message.GetArray() << " The offset is: " << message.GetOffset() << " The how much is: " << message.GetHowMuch() << std::endl; */
    std::cout << "Received message: " << buffer << std::endl;
    
    std::cout << "Got here: ----------" << buffer << std::endl;
    close(m_recieve_socket);
    return;
}

UDPsender::UDPsender(size_t port, char * ip, size_t amount, char *array):m_port(port), m_ip(ip), m_amount(amount), m_array(array)
{
}

UDPsender::~UDPsender()
{
}

void UDPsender::Send()
{
    int m_send_socket, n;
    struct sockaddr_in serverAddr;

    // Create a UDP socket
    if ((m_send_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(m_port); // Server's port
    serverAddr.sin_addr.s_addr =  inet_addr(m_ip); // Specify the target server's IP address

    // Send the message to the server
    sendto(m_send_socket, (const char*)m_array, 1024, 0, (const struct sockaddr*)&serverAddr, sizeof(serverAddr));

    std::cout << "Message sent to server." << std::endl;

    close(m_send_socket);
}