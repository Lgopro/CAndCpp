#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
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
#include "vector.h"



#define BACK_LOG 1000
#define FAIL -1
#define MAX_ITEMS 1024


void DestroyVecPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;

}



int main()
{
    struct sockaddr_in sin;
    struct sockaddr_in client_sin;
    char data_addr[]= "hello,im server";
    unsigned int data_len = strlen(data_addr);
    char buffer[4096];
    ssize_t sent_bytes;
    unsigned int addr_len = sizeof(data_addr);
    int flags,read_bytes,client_sock,expected_data_len = sizeof(buffer),optval = 1,activity = 0;
    Vector* vector;
    int* userInput;
    void* valueEnd;
    void* pClient;
    size_t i;
    fd_set master, temp;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket failed");
        abort();
    }


    if(FAIL == (flags = fcntl(sock, F_GETFL)))
    {
        perror("error at fcntl. F_GETFL.");
        abort();
    }
    if(FAIL == fcntl(sock, F_SETFL, flags | O_NONBLOCK))
    {
        perror("error at fcntl. SETFL.");
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
    sin.sin_port = htons(1875);
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
    FD_ZERO(&master);
    FD_SET(sock, &master);

    vector = Vector_Create(1050, 50);
    addr_len = sizeof(client_sin);
    while(1)
    {
        temp = master;
        activity = select(MAX_ITEMS, &temp, NULL, NULL, NULL); 
        if (FD_ISSET(sock, &temp))
        {
            activity--;
            client_sock = accept(sock,(struct sockaddr *) &client_sin,&addr_len);
            if (client_sock < 0) 
            {
                
                    perror("accept failed");
                    close(client_sock);
                
            }
            else if(client_sock >= MAX_ITEMS || Vector_Size(vector) >= MAX_ITEMS) /*TODO was if and not else if and with continue*/
            {
                close(client_sock);
                /* continue; */
            }
            else /* (client_sock > 0)  */  /*TODO was if and not else */
            {
            
                userInput=(int*)malloc(sizeof(int));
                *userInput = client_sock;
                Vector_Append(vector, (void*)userInput);
                FD_SET(client_sock, &master);
                
            }

        }

        for(i=0; i< Vector_Size(vector) ;++i)
        {
            Vector_Get(vector, i, &pClient);
            if(FD_ISSET(*(int*)pClient,&temp))
            {
                read_bytes = recv(*(int*)pClient, buffer, expected_data_len, 0);
                if (read_bytes == 0) 
                {
                    FD_CLR(*(int*)pClient,&master);
                    Vector_Get(vector, Vector_Size(vector)-1, &valueEnd);
                    Vector_Set(vector, i, valueEnd);
                    Vector_Remove(vector, &valueEnd);
                    close(*(int*)pClient);
                    free(pClient);
                    activity--;
                }
                else if (read_bytes < 0) 
                {
                    if(errno != EAGAIN && errno != EWOULDBLOCK)
                    {
                        FD_CLR(*(int*)pClient,&master);
                        perror("accept failed");
                        Vector_Get(vector, Vector_Size(vector)-1, &valueEnd);
                        Vector_Set(vector, i, (void*)valueEnd);
                        Vector_Remove(vector, &valueEnd);
                        close(*(int*)pClient);
                        free(pClient);
                        activity--;
                    
                    }
                }
                else
                {
                    
                    printf("%s\n", buffer);
                    sent_bytes = send(*(int*)pClient, data_addr, data_len, 0);
                    if (sent_bytes < 0) 
                    {
                        perror("send failed");
                        
                    }
                }
             }  
        }
        

    }
    Vector_Destroy(&vector, DestroyVecPart);
    
    close(sock);

    return 0;
}
