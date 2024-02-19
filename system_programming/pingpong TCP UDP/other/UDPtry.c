#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_1 12345

int main() 
{
    int sockfd;
    ssize_t bytes_received = 0;
    struct sockaddr_in server_addr;
    char buffer[1024];
    
    /* Create UDP socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_1);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    /* Bind socket to server address */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Server 1 listening on port %d\n", PORT_1);
    
    while (1) {
        /* Receive message from client */
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received <= 0) {
            break;
        }
        printf("Server 1 received: %s\n", buffer);
    }
    
    close(sockfd);
    
    return 0;
}
