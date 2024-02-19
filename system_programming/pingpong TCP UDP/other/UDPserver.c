#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/


#define PONG_AMOUNT (5)
#define UNTIL_END (1)

int main() 
{
    int sockfd;
    int i = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    char buffer[1024];
    
    /* Create UDP socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); /* AF_INET specifies the address family (IPv4).
                                            SOCK_DGRAM indicates that it's a UDP socket. */
    if (sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    /* Bind socket to server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; /* INADDR_ANY specifies that the server can listen on any available network interface */
    server_addr.sin_port = htons(8080);  /*  Server port number */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server waiting for messages...\n");
    
    while(UNTIL_END)
    {
         /* Receive message from client */
        memset(buffer, 0, sizeof(buffer)); /* Clear the buffer using memset() */
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &client_len);
        printf("Received from client: %s\n", buffer);
        printf("Send Pong! back to user.\n");
        /* Send acknowledgment to client */
        sendto(sockfd, "Leon Pong", 10, 0, (struct sockaddr *)&client_addr, client_len);
    }
    
    close(sockfd);
    return 0;
}