#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) 
    {
        std::cerr << "Listen failed" << std::endl;
        return 1;
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) 
    {
        std::cerr << "Accept failed" << std::endl;
        return 1;
    }

    // Receive image data
    std::ofstream outfile("received_image.png", std::ios::binary);
    if (!outfile.is_open()) 
    {
        std::cerr << "Failed to create output file" << std::endl;
        close(new_socket);
        close(server_fd);
        return 1;
    }

    int bytes_received;
    while ((bytes_received = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) 
    {
        outfile.write(buffer, bytes_received);
    }

    if (bytes_received < 0) 
    {
        std::cerr << "Receive failed" << std::endl;
    }

    outfile.close();
    close(new_socket);
    close(server_fd);
    return 0;
}