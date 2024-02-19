
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

#define TRUE 1
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
    char data_addr[50]/*  = "hi friend, im client" */;
    char buffer[4096];
    ssize_t sent_bytes;
    ssize_t read_bytes; 
    size_t expected_data_len;
    int index,i,sendData[ITEMS_NUM] = {-1};
    
    memset(&sin, 0 ,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("192.168.1.104");
    sin.sin_port = htons(1875);
    
    for(i=0;i<ITEMS_NUM;i++)
    {
        sendData[i] = -1;
    }
    srand(time(NULL));
    while(TRUE)
    {  
        
        for(i=0;i<ITEMS_NUM;i++)
        {
            
            
            index = rand()%100;
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
                        /* abort(); */
                        close(sendData[i]);
                         sendData[i] = -1;
                        
                    }
                }
                
            } 
            else if(sendData[i] != -1)
            {
                if(index < 30 )
                {
                    sprintf(data_addr,"hi freind im client %d", sendData[i]);

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
                        sendData[i] = -1;
                        
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
                    close(sendData[i]);
                    sendData[i] = -1;
                }
            }  
        } 
    } 

    



    return 0;
}
