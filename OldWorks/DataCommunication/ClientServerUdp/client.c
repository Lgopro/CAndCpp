
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    char data[]= "hello freind,im client";
    unsigned int sin_len;
    char buffer[4096];
    struct sockaddr_in sin;
    ssize_t sent_bytes;
    int read_bytes;

    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }
    
    
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("192.168.0.106");
    sin.sin_port = htons(2000);
    sent_bytes = sendto(sock, data, strlen(data), 0,(struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0)
    {
        perror("sendto failed");
        abort();
    }

   
    read_bytes = recvfrom(sock, buffer, sizeof(buffer), 0,(struct sockaddr *) &sin, &sin_len);
    if (read_bytes < 0) 
    {
        perror("resive from failed");
        abort();
    }
     else
    {
        printf("%s\n", buffer);
    }
    close(sock);
    return 0;
}