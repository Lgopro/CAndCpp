
#include "PingPong.h"

void TCPCreateSocketServer(tcp_server *server)  
{  
    /* Create TCP socket */
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) 
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
}  

void TCPPrepareAddrServer(tcp_server *server, size_t port)
{
    /* Bind socket to server address */
    server->server_addr.sin_family = AF_INET;
    server->server_addr.sin_addr.s_addr = INADDR_ANY;
    server->server_addr.sin_port = htons(port);   /* Server port number */
    if (bind(server->sockfd, (struct sockaddr *)&server->server_addr, sizeof(server->server_addr)) == -1) 
    {
        perror("bind");
        close(server->sockfd);
        exit(EXIT_FAILURE);
    }
}


void TCPSendAndRecieveServer(tcp_server *server)
{
    ssize_t bytes_reveived = 0;
    const char *ack = "Pong";
    /* Listen for incoming connections */
    int newsockfd;
    listen(server->sockfd, 5);
    printf("Server listening for connections...\n");
    
    /* Accept incoming connection */
    newsockfd = accept(server->sockfd, (struct sockaddr *)&server->client_addr, &server->client_len);
    if (newsockfd == -1) {
        perror("accept");
        close(server->sockfd);
        exit(EXIT_FAILURE);
    }
    

    while(UNTIL_END)
    {
        /* Receive message from client */
        memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user));
        bytes_reveived = recv(newsockfd, server->buffer_from_user, sizeof(server->buffer_from_user), 0);
        if(bytes_reveived <= 0 )
        {
            break;
        }
        printf("Received from client: %s\n", server->buffer_from_user);
        printf("Send Pong\n");
        /* Send acknowledgment to client */
        
        send(newsockfd, ack, strlen(ack), 0);
    }
    close(newsockfd);
    close(server->sockfd);
    
    
}


