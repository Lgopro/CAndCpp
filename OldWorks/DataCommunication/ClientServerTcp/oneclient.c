
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

    struct sockaddr_in sin;
    char data_addr[]= "hi friend, im client";
    char buffer[4096];
    int sent_bytes;
    int read_bytes;
    int expected_data_len;
    
    
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }
    
    
    memset(&sin, 0 ,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("192.168.0.250");
    sin.sin_port = htons(1234);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) 
    {
        perror("connection failed");
        abort();
    }
    
    sent_bytes = send(sock, data_addr, strlen(data_addr), 0);
    if (sent_bytes < 0) 
    {
        perror("send failed");
    }
   
    expected_data_len = sizeof(buffer);
    read_bytes = recv(sock, buffer, expected_data_len, 0);
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



    return 0;
}
