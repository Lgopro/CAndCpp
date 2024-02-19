
#include "PingPong.h"


void UDPCreateSocketServer(udp_server *server)
{
    /* Create UDP socket */
    server->sockfd = socket(AF_INET, SOCK_DGRAM, 0); /* AF_INET specifies the address family (IPv4).
                                            SOCK_DGRAM indicates that it's a UDP socket. */
    if (server->sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
} 

void UDPPrepareAddrServer(udp_server *server,size_t port)
{  
    /* Bind socket to server address */
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY; /* INADDR_ANY specifies that the server can listen on any available network interface */
    server->server_addr.sin_port = htons(port);  /*  Server port number */
    if (bind(server->sockfd, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr)) == -1) 
    {
        perror("bind");
        close(server->sockfd);
        exit(EXIT_FAILURE);
    }
}  

void UDPSendAndRecieveServer(udp_server *server)
{ 
    server->client_len = sizeof(server->client_addr);
    printf("Server waiting for messages...\n");
    
    while(UNTIL_END)
    {
         /* Receive message from client */
        memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user)); /* Clear the buffer using memset() */
        recvfrom(server->sockfd, server->buffer_from_user, sizeof(server->buffer_from_user), 0, (struct sockaddr *)&server->client_addr, &server->client_len);
        printf("Received from client: %s\n", server->buffer_from_user);
        printf("Send Pong! back to user.\n");
        /* Send acknowledgment to client */
        sendto(server->sockfd, "Leon Pong", 10, 0, (struct sockaddr *)&server->client_addr, server->client_len);
    }
    
    close(server->sockfd);
}



