
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/
#include <sys/select.h>

#define TEXT_SIZE (20)
#define BUFFER_SIZE (100)
#define PING_AMOUNT (5)
#define PONG_AMOUNT (5)
#define UNTIL_END (1)

typedef struct Server
{
    char ack[TEXT_SIZE];
    int udpsock;
    int tcpsock;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;
    char buffer_from_user[BUFFER_SIZE];
    socklen_t client_len;
    fd_set rset;
    int maxfd;
    int ready_descriptor;
}server;

void TCPSendAndRecieveServer(server *server);

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

int main()
{

    server combined_server;
 
    /* create listening TCP socket */
    combined_server.tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&combined_server.server_addr, sizeof(combined_server.server_addr));
    combined_server.server_addr.sin_family = AF_INET;
    combined_server.server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    combined_server.server_addr.sin_port = htons(7070);
 
    // binding server addr structure to listenfd
    bind(combined_server.tcpsock, (struct sockaddr*)&combined_server.server_addr, sizeof(combined_server.server_addr));
    listen(combined_server.tcpsock, 10);
 
    /* create UDP socket */
    combined_server.udpsock = socket(AF_INET, SOCK_DGRAM, 0);
    // binding server addr structure to udp sockfd
    bind(combined_server.udpsock, (struct sockaddr*)&combined_server.udpsock, sizeof(combined_server.udpsock));
 
    // clear the descriptor set
    FD_ZERO(&combined_server.rset);
 
    // get maxfd
    combined_server.maxfd = max(combined_server.tcpsock, combined_server.udpsock) + 1;
    while(UNTIL_END)
    {
 
        // set listenfd and udpfd in readset
        FD_SET(combined_server.tcpsock, &combined_server.rset);
        FD_SET(combined_server.udpsock, &combined_server.rset);
 
        // select the ready descriptor
        combined_server.ready_descriptor = select(combined_server.maxfd, &combined_server.rset, NULL, NULL, NULL);
 
        // if tcp socket is readable then handle
        // it by accepting the connection
        if (FD_ISSET(combined_server.tcpsock, &combined_server.rset)) 
        {
            TCPSendAndRecieveServer(&combined_server);
        }
        // if udp socket is readable receive the message.
        if (FD_ISSET(combined_server.udpsock, &combined_server.rset)) 
        {
            UDPSendAndRecieveServer(&combined_server);
        }
    }
}


void TCPSendAndRecieveServer(server *server)
{
    ssize_t bytes_reveived = 0;
    const char *ack = "Pong";
    /* Listen for incoming connections */
    int newsockfd;
    
    /* Accept incoming connection */
    newsockfd = accept(server->tcpsock, (struct sockaddr *)&server->client_addr, &server->client_len);
    if (newsockfd == -1) {
        perror("accept");
        close(server->tcpsock);
        exit(EXIT_FAILURE);
    }
    
    /* Receive message from client */
    memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user));
    bytes_reveived = recv(newsockfd, server->buffer_from_user, sizeof(server->buffer_from_user), 0);
    if(bytes_reveived <= 0 )
    {
        return;
    }
    printf("Received from client: %s\n", server->buffer_from_user);
    printf("Send Pong\n");
    /* Send acknowledgment to client */ 
    send(newsockfd, ack, strlen(ack), 0);
    close(newsockfd);
}



void UDPSendAndRecieveServer(server *server)
{ 
    server->client_len = sizeof(server->client_addr);
    printf("Server waiting for messages...\n");
    
    /* Receive message from client */
    memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user)); /* Clear the buffer using memset() */
    recvfrom(server->udpsock, server->buffer_from_user, sizeof(server->buffer_from_user), 0, (struct sockaddr *)&server->client_addr, &server->client_len);
    printf("Received from client: %s\n", server->buffer_from_user);
    printf("Send Pong! back to user.\n");
    /* Send acknowledgment to client */
    sendto(server->udpsock, "Leon Pong", 10, 0, (struct sockaddr *)&server->client_addr, server->client_len);
}