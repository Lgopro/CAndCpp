/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 03/09/23
*/

#include <time.h> /*srand*/
#include <stdlib.h> /*srand*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/
#include <sys/select.h>
#include <sys/time.h>

#define TEXT_SIZE (20)
#define BUFFER_SIZE (100)
#define PING_AMOUNT (5)
#define PONG_AMOUNT (5)
#define EXIT (1)
#define PORT (7070)
#define EQUAL (0)
#define ERROR (-1)
#define NO_DATA_ENTERED (0)

typedef struct Server
{
    char ack[TEXT_SIZE];
    int udpsock;
    int tcpsock;
    int another_tcp_sock;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;
    char buffer_from_user[BUFFER_SIZE];
    socklen_t client_len;
    fd_set rset;
    fd_set newrset;
    int maxfd;
    int status;
    int delay_up;
}server;

void TCPSendAndRecieveServer(server *server, int fd);
void UDPSendAndRecieveServer(server *server);

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

void RenewDelay(struct timeval *delay, server *combined_server)
{
    delay->tv_sec = 7; 
    delay->tv_usec = 0;  
    combined_server->delay_up = 0;
}

int Server()
{
    struct timeval delay;
    int exit_flag = 0;
    server combined_server;
    char input[BUFFER_SIZE];
    int i = 0;
    combined_server.client_len = sizeof(combined_server.client_addr);
    
    RenewDelay(&delay, &combined_server);
    /* create listening TCP socket */
    combined_server.tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    /* bzero(&combined_server.server_addr, sizeof(combined_server.server_addr)); */
    combined_server.server_addr.sin_family = AF_INET;
    combined_server.server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    combined_server.server_addr.sin_port = htons(PORT);
 
    /* create UDP socket */
    combined_server.udpsock = socket(AF_INET, SOCK_DGRAM, 0);
    /* binding server addr structure to udp sockfd */
    bind(combined_server.udpsock, (struct sockaddr*)&combined_server.server_addr, sizeof(combined_server.server_addr));

    /* binding server addr structure to listenfd */
    bind(combined_server.tcpsock, (struct sockaddr*)&combined_server.server_addr, sizeof(combined_server.server_addr));
    listen(combined_server.tcpsock, 10);
 
    /* clear the descriptor set */
    FD_ZERO(&combined_server.rset);
 
    /* get maxfd */
    combined_server.maxfd = max(combined_server.tcpsock, combined_server.udpsock) + 1;
    /* set listenfd and udpfd in readset */
        FD_SET(combined_server.tcpsock, &combined_server.rset);
        FD_SET(combined_server.udpsock, &combined_server.rset);
        FD_SET(STDIN_FILENO, &combined_server.rset);
        /* select the ready descriptor */
    while(EXIT != exit_flag)
    {
        
        combined_server.newrset = combined_server.rset;

        combined_server.status = select(combined_server.maxfd, &combined_server.newrset, NULL, NULL, &delay);
        if(combined_server.status < 0)
        {
            printf("Select fail\n");
            break;
        }
        if(combined_server.status == 0)
        {
            printf("Time delay of 7 second is up\n");
            RenewDelay(&delay, &combined_server);
            continue;
        }
        for(i = 0; i <= combined_server.maxfd; ++i)
        {
            if(FD_ISSET(i, &combined_server.newrset))
            {
                /* if tcp socket is readable then handle
                it by accepting the connection */
                if (i == combined_server.tcpsock) 
                {
                    RenewDelay(&delay, &combined_server);

                    combined_server.another_tcp_sock = accept(i, (struct sockaddr *)&combined_server.client_addr, &combined_server.client_len);
                    if (combined_server.another_tcp_sock < 0) 
                    {
                        printf("server accept failed\n");
                        return(-1);
                    }
                    if (-1 == combined_server.another_tcp_sock)
                    {
                        printf("accept failed\n");
                        exit_flag = 1;
                        break; 
                    }
                    FD_SET(combined_server.another_tcp_sock, &combined_server.rset); 
                    combined_server.maxfd = (combined_server.another_tcp_sock >= combined_server.maxfd) ? combined_server.another_tcp_sock + 1 : combined_server.maxfd;
                         
                }

                /* if udp socket is readable receive the message. */
                else if (i == combined_server.udpsock) 
                {
                    RenewDelay(&delay, &combined_server);
                    UDPSendAndRecieveServer(&combined_server);
                }
                else if (i == STDIN_FILENO)  /* Check for input from stdin */
                {
                    RenewDelay(&delay, &combined_server);
                    
                    if (fgets(input, BUFFER_SIZE, stdin) != NULL)
                    {
                        /* Process the input string (e.g., send to clients) */
                        printf("Received from stdin: %s", input);
                        if(EQUAL == strcmp(input, "ping\n"))
                        {
                            printf("Pong\n");
                        }
                        else if(EQUAL == strcmp(input, "quit\n"))
                        {
                            printf("quit entered\n");
                            exit_flag = EXIT;
                            break;
                        }
                    }
                }
                else
                {
                    RenewDelay(&delay, &combined_server);
                    TCPSendAndRecieveServer(&combined_server, i);
                }
            }
        }
    }
    close(combined_server.tcpsock);
    close(combined_server.udpsock);
    return 0;
}



void TCPSendAndRecieveServer(server *server, int fd)
{
    ssize_t bytes_received = 0;
    ssize_t send_return = 0;
    const char *ack = "Pong";
    server->client_len = sizeof(server->client_addr);

    /* Receive message from client */
    memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user));
    bytes_received = recv(fd, server->buffer_from_user, sizeof(server->buffer_from_user), 0);
    if (0 == bytes_received)
    {
        FD_CLR(fd, &server->rset);
        FD_CLR(fd, &server->newrset);
        close(fd);
        return;
    }
    if (0 > bytes_received)
    {
        perror("recv");
        FD_CLR(fd, &server->rset);
        FD_CLR(fd, &server->newrset);
        close(fd);
        return;
    }
    

    printf("Received from client: %s\n", server->buffer_from_user);
    printf("Send Pong\n");

    /* Send acknowledgment to client */
    send_return = send(fd, ack, strlen(ack), 0);
    if(-1 == send_return)
    {
        perror("recv");
        return;
    }

}



void UDPSendAndRecieveServer(server *server)
{ 
    ssize_t bytes_received = 0;
    ssize_t send_return = 0;
    server->client_len = sizeof(server->client_addr);
    
    printf("Server waiting for messages...\n");
    
    /* Receive message from client */
    memset(server->buffer_from_user, 0, sizeof(server->buffer_from_user)); /* Clear the buffer using memset() */
    bytes_received = recvfrom(server->udpsock, server->buffer_from_user, sizeof(server->buffer_from_user), 0, (struct sockaddr *)&server->client_addr, &server->client_len);
    if (0 > bytes_received)
    {
        perror("recv");
        return;
    }
    printf("Received from client: %s\n", server->buffer_from_user);
    printf("Send Pong! back to user.\n");
    /* Send acknowledgment to client */
    send_return = sendto(server->udpsock, "Pong", 5, 0, (struct sockaddr *)&server->client_addr, server->client_len);
    if(-1 == send_return)
    {
        perror("recv");
        return;
    }
}

