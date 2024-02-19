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
    char ack[5];
    int sockfd;
    struct sockaddr_in server_addr;
    int broadcast = 1;
    /* Create UDP socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1) 
    {
        perror("setsockopt");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    

    /* Prepare server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);   /* Server port number */
    server_addr.sin_addr.s_addr = inet_addr("10.10.3.255");  /* Server IP address */


    for(i = 0;i < PING_AMOUNT; ++i)
    {
        /* Send message to server */
        const char *message = "Ping!";
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        printf("Sent to server: %s\n", message);
        
        /* Receive acknowledgment from server */
        
        recvfrom(sockfd, ack, sizeof(ack), 0, NULL, NULL);
        printf("Received acknowledgment: %s\n", ack);
    }
    close(sockfd);
    return 0;
}