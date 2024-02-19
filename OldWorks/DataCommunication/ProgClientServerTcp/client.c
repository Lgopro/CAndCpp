
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define ITEMS_NUM 1000
/* int GetSoccet(void)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }
    return sock;
} */

int main()
{

    struct sockaddr_in sin;
    char data_addr[]= "hi friend, im client";
    char buffer[4096];
    ssize_t sent_bytes;
    ssize_t read_bytes; 
    size_t expected_data_len;
    int index,i,sendData[ITEMS_NUM] = {-1},j;
    
    memset(&sin, 0 ,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("192.168.0.10");
    sin.sin_port = htons(2670);
    
    for(i=0;i<ITEMS_NUM;i++)
    {
        sendData[i] = -1;
    }
    srand(60);
    while(1)
    {  
        for(i=0;i<ITEMS_NUM;i++)
        {
            
            
            index = rand()%ITEMS_NUM;
            if(sendData[i] == -1)
            {
                if(index < 30)
                {
                    sendData[i] = socket(AF_INET, SOCK_STREAM, 0);
                    if(sendData[i] < 0)
                    {
                        perror("socket failed");
                        abort();
                    }
                    if (connect(sendData[i], (struct sockaddr *) &sin, sizeof(sin)) < 0) 
                    {
                        perror("connection failed");
                        abort();
                    }
                }
                
            } 
            else if(sendData[i] != -1)
            {
                if(index < 30 )
                {
                    sent_bytes = send(sendData[i], data_addr, strlen(data_addr), 0);
                    if (sent_bytes < 0) 
                    {
                        perror("send failed");
                    }
            
                    expected_data_len = sizeof(buffer);
                    read_bytes = recv(sendData[i], buffer, expected_data_len, 0);
                    if (read_bytes == 0) 
                    {
                        close(sendData[i]);
                    }
                    else if (read_bytes < 0) 
                    {
                        perror("recv failed");
                    }
                    else 
                    {
                        buffer[read_bytes] = '\0';
                        printf("%s\n", buffer);
                    } 
                }
                else if(index >= 30 && index < 36)
                {
                    sendData[i] = -1;
                    close(sendData[i]);
                }
            }  
        } 
        j++;
    } 

    



    return 0;
}
