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
    int sockfd, newsockfd;
    ssize_t bytes_reveived = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    const char *ack = "Pong";
    char buffer[1024];
    
    /* Create TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    /* Bind socket to server address */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);   /* Server port number */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    /* Listen for incoming connections */
    listen(sockfd, 5);
    printf("Server listening for connections...\n");
    
    /* Accept incoming connection */
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd == -1) {
        perror("accept");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    

    while(UNTIL_END)
    {
        /* Receive message from client */
        memset(buffer, 0, sizeof(buffer));
        bytes_reveived = recv(newsockfd, buffer, sizeof(buffer), 0);
        if(bytes_reveived <= 0 )
        {
            break;
        }
        printf("Received from client: %s\n", buffer);
        printf("Send Pong\n");
        /* Send acknowledgment to client */
        
        send(newsockfd, ack, strlen(ack), 0);
    }
    close(newsockfd);
    close(sockfd);
    
    return 0;
}
