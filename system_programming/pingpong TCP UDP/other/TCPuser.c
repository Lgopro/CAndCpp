#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/

#define PING_AMOUNT (5)


int main() 
{
    int i = 0;
    int sockfd;
    struct sockaddr_in server_addr;
    char ack[4];
    const char *message = "Ping!";

    /* Create TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);  /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  /* Server IP address */
    
    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) 
    {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    for(i = 0;i < PING_AMOUNT; ++i)
    {
        /* Send message to server */
        
        send(sockfd, message, strlen(message), 0);
        printf("Sent to server: %s\n", message);
        
        /* Receive acknowledgment from server */
        
        recv(sockfd, ack, sizeof(ack), 0);
        printf("Received acknowledgment: %s\n", ack);
    }   
    close(sockfd);
    
    return 0;
}