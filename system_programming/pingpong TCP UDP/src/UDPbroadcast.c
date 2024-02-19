
#include "PingPong.h"
void UDPCreateSocketUserBroadcast(udp_user *user)
{

    int broadcast = 1;
    /* Create UDP socket */
    user->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (user->sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(user->sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) == -1) 
    {
        perror("setsockopt");
        close(user->sockfd);
        exit(EXIT_FAILURE);
    }
}  
void UDPPrepareAddrUserBroadcast(udp_user *user, size_t port, char *IP)
{
    /* Prepare server address */
    user->server_addr.sin_family = AF_INET;
    user->server_addr.sin_port = htons(port);   /* Server port number */
    user->server_addr.sin_addr.s_addr = inet_addr(IP);  /* Server IP address */
}
void UDPSendAndRecieveUserBroadcast(udp_user *user)
{
    int i = 0;
    char ack[5];
    for(i = 0;i < PING_AMOUNT; ++i)
    {
        /* Send message to server */
        const char *message = "Ping!";
        sendto(user->sockfd, message, strlen(message), 0, (struct sockaddr *)&user->server_addr, sizeof(user->server_addr));
        printf("Sent to server: %s\n", message);
        
        /* Receive acknowledgment from server */
        sleep(1);
        recvfrom(user->sockfd, ack, sizeof(ack), 0, NULL, NULL);
        printf("Received acknowledgment: %s\n", ack);
    }
    close(user->sockfd);

}

