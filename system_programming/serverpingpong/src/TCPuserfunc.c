/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 03/09/23
*/
#include <time.h> /*srand*/
#include <stdlib.h> /*srand*/
#include "PingPong.h"


void TCPCreateSocketUser(tcp_user *user)
{
    /* Create TCP socket */
    user->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (user->sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}  
void TCPPrepareAddrUser(tcp_user *user, size_t port, char *IP)
{
    /* Prepare server address */
    
    user->server_addr.sin_family = AF_INET;
    user->server_addr.sin_port = htons(port);  /* Server port number */
    user->server_addr.sin_addr.s_addr = inet_addr(IP);  /* Server IP address */
    
    /* Connect to the server */
    if (connect(user->sockfd, (struct sockaddr *)&user->server_addr, sizeof(user->server_addr)) == -1) 
    {
        perror("connect");
        close(user->sockfd);
        exit(EXIT_FAILURE);
    }
}

void TCPSendAndRecieveUser(tcp_user *user)
{
    
    const char *message = "Ping!";
    char ack[4];
    
    /* Send message to server */
    send(user->sockfd, message, strlen(message), 0);
    printf("Sent to server: %s\n", message);
        
    /* Receive acknowledgment from server */
        
    recv(user->sockfd, ack, sizeof(ack), 0);
    printf("Received acknowledgment: %s\n", ack);
       
    
}  


