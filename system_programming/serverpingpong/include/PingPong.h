

#ifndef __PING_PONG__
#define __PING_PONG__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /*close*/

#define TEXT_SIZE (20)
#define BUFFER_SIZE (100)
#define PING_AMOUNT (5)
#define PONG_AMOUNT (5)
#define UNTIL_END (1)
#define PORT (7070)

typedef struct UDPserver
{
    char ack[TEXT_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;
    char buffer_from_user[BUFFER_SIZE];
    socklen_t client_len;
}udp_server;

typedef struct UDPuser
{
    char ack[TEXT_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;
}udp_user;

typedef struct TCPserver
{
    char ack[TEXT_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;
    char buffer_from_user[BUFFER_SIZE];
    socklen_t client_len;

}tcp_server;

typedef struct TCPuser
{
    char ack[TEXT_SIZE];
    int sockfd;
    struct sockaddr_in server_addr;
    char server_ip_addr[TEXT_SIZE];
    int server_port_number;

}tcp_user;



void UDPCreateSocketUserBroadcast(udp_user *user);
void UDPPrepareAddrUserBroadcast(udp_user *user, size_t port, char *IP);
void UDPSendAndRecieveUserBroadcast(udp_user *user);

void UDPCreateSocketServer(udp_server *server);
void UDPPrepareAddrServer(udp_server *server,size_t port);
void UDPSendAndRecieveServer(udp_server *server);

void UDPCreateSocketUser(udp_user *user);
void UDPPrepareAddrUser(udp_user *user,size_t port, char* IP);
void UDPSendAndRecieveUser(udp_user *user);

void TCPCreateSocketServer(tcp_server *server);
void TCPPrepareAddrServer(tcp_server *server, size_t port);
void TCPSendAndRecieveServer(tcp_server *server, int fd);

void TCPCreateSocketUser(tcp_user *user);
void TCPPrepareAddrUser(tcp_user *user, size_t port, char *IP);
void TCPSendAndRecieveUser(tcp_user *user);


int Server();
#endif /*__PING_PONG__*/
