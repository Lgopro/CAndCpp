
#include "UserAndServer.hpp"
#include <thread>
#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <vector>

using namespace ilrd;
Server::Server(int udp_port_number, int tcp_port_number, std::string github_link) : m_github_link(github_link), server_port_number(udp_port_number), tcp_server_port_number(tcp_port_number)
{
}

void Server::TCPCreateSocketServer()  
{  
    /* Create TCP socket */
    tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    if (tcpsock == -1) 
    {
        perror("socket");
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
        perror("bind");
        close(tcpsock);
        exit(EXIT_FAILURE);
    }
}

void Server::TCPPrepareListenServer()
{
    if (listen(tcpsock, 3) < 0) 
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    std::cout << "TCP Server listening for connections..." << std::endl;
}


void handleClient(int new_socket, std::string name, int tcpport)
{
    char buffer[SIZE_OF_TEXT] = {0};
    int valread;
    
     // Open file to write received data, overwriting if it exists
    std::ofstream received_file(name, std::ios::binary | std::ios::trunc);
    if (!received_file.is_open()) 
    {
        std::cerr << "Failed to create " << name << std::endl;
        close(new_socket);
        return;
    }

    // Receive image data and write to file
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

Server::~Server()
{
    m_working_server = false;
    close(tcpsock);
}

void Server::CloseServer()
{
    m_working_server = false;
}

int main()
{
    Server server(9888, 9980, "hella");

    server.TCPCreateSocketServer();
    server.TCPPrepareAddrServer();
    server.TCPPrepareListenServer();
    std::string name = "tttt.png";

    std::thread t1([&]
    {
        server.TCPSendAndRecieveServer(name);
    });
    
    std::this_thread::sleep_for(std::chrono::seconds(10));

    server.CloseServer();
    t1.join();
    return 0;   
}