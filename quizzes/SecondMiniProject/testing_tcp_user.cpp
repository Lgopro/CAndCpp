#include <iostream>
#include <fstream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 9980

int main() 
{
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        std::cerr << "Connection failed" << std::endl;
        close(sockfd);
        return 1;
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
        return 1;
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
    return 0;
}