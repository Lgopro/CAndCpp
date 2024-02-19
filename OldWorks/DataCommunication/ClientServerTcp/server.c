
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>

#define BACK_LOG 1000

int main()
{
    struct sockaddr_in sin;
    struct sockaddr_in client_sin;
    char data_addr[]= "hello,im server";
    unsigned int data_len = strlen(data_addr);
    int optval = 1;
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int client_sock;
    ssize_t sent_bytes;
    unsigned int read_bytes;
    /* int sent_bytes; */
   unsigned int addr_len = sizeof(data_addr);


    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }


    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) 
    {
        perror("reuse failed");
        abort();
    }

   
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(2670);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) 
    {
        perror("bind failed");
        abort();
    }

    if (listen(sock, BACK_LOG) < 0) 
    {
        perror("listen failed");
        abort();

    }


    addr_len = sizeof(client_sin);

    client_sock = accept(sock,(struct sockaddr *) &client_sin,&addr_len);
    if (client_sock < 0) 
    {
        perror("accept failed");
        abort();
    }

    sent_bytes = send(client_sock, data_addr, data_len, 0);
    if (sent_bytes < 0) 
    {
        perror("send failed");
    }

    expected_data_len = sizeof(buffer);
    read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) 
    {
        close(sock);
    }
    else if (read_bytes < 0) 
    {
        perror("recv failed");
    }
    else 
    {
        printf("%s\n", buffer);
    }   

    close(sock);
    close(client_sock);
    return 0;
}