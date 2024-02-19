#include <time.h> /*srand*/
#include <stdlib.h> /*srand*/
#include "PingPong.h"


void UDPCreateSocketUser(udp_user *user)
{
    user->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (user->sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}

void UDPPrepareAddrUser(udp_user *user,size_t port, char* IP) 
{
    /* Prepare server address */
    user->server_addr.sin_family = AF_INET;
    user->server_addr.sin_port = htons(port);   /* Server port number */
    user->server_addr.sin_addr.s_addr = inet_addr(IP);  /* Server IP address */   
}  

void UDPSendAndRecieveUser(udp_user *user)
{
    char ack[50];
    const char *message = "Ping!";
    struct sockaddr_in server_addr; /* Temporary storage for server address */
    socklen_t server_len;
    /* Send message to server using combined server's address */
    sendto(user->sockfd, message, strlen(message), 0, (struct sockaddr *)&user->server_addr, sizeof(user->server_addr));
    printf("Sent to server: %s\n", message);

    /* Receive acknowledgment from server */
    
    server_len = sizeof(server_addr);
    recvfrom(user->sockfd, ack, sizeof(ack), 0, (struct sockaddr *)&server_addr, &server_len);
    printf("Received acknowledgment: %s\n", ack);

    
}


