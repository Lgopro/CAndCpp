
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
int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in sin;
    ssize_t sent_bytes;
    unsigned int sin_len = sizeof(sin),read_bytes;
    char buffer[4096];
    char data[]= "hello,im server";
    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(2660);
    if(bind(sock, (struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        perror("bind failed");
        abort();
    }


    while(1)
    {
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
        

        sent_bytes = sendto(sock, data, strlen(data), 0,(struct sockaddr *) &sin, sizeof(sin));
        if (sent_bytes < 0)
        {
            perror("sendto failed");
            abort();
        }

    
    }
    
    close(sock);
    return 0;
}