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
#define MAX_ITEMS 1000

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
    int flags,read_bytes,client_sock,expected_data_len = sizeof(buffer),optval = 1;
    Vector* vector;
    int* userInput;
    void* valueEnd;
    void* pClient;
    size_t i;

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

    vector = Vector_Create(1024, 50);
    addr_len = sizeof(client_sin);
    while(1)
    {
        client_sock = accept(sock,(struct sockaddr *) &client_sin,&addr_len);
        if (client_sock < 0) 
        {
            if(errno != EAGAIN && errno != EWOULDBLOCK)
            {
                perror("accept failed");
                close(client_sock);
            }
        }
        if(Vector_Size(vector) >= MAX_ITEMS)
        {
            close(client_sock);
        }
        if (client_sock > 0 && Vector_Size(vector) < MAX_ITEMS) 
        {
            if(FAIL == (flags = fcntl(client_sock, F_GETFL)))
            {
                perror("error at fcntl. F_GETFL.");
                close(client_sock);
            }
            if(FAIL == fcntl(client_sock, F_SETFL, flags | O_NONBLOCK))
            {
                perror("error at fcntl. SETFL.");
                close(client_sock);
            }
            userInput=(int*)malloc(sizeof(int));
            *userInput = client_sock;
            Vector_Append(vector, (void*)userInput);
        }
       /*  expected_data_len = sizeof(buffer); */
        for(i=0; i< Vector_Size(vector) ;++i)
        {
            Vector_Get(vector, i, &pClient);
            if(*(int*)pClient == 0)
            {
                printf("hello");
            }
            read_bytes = recv(*(int*)pClient, buffer, expected_data_len, 0);
            if (read_bytes == 0) 
            {
                Vector_Get(vector, Vector_Size(vector)-1, &valueEnd);
                Vector_Set(vector, i, valueEnd);
                Vector_Remove(vector, &valueEnd);
                close(*(int*)pClient);
                free(pClient);
                
            }
            else if (read_bytes < 0) 
            {
                if(errno != EAGAIN && errno != EWOULDBLOCK)
                {
                    perror("accept failed");
                    Vector_Get(vector, Vector_Size(vector)-1, &valueEnd);
                    Vector_Set(vector, i, (void*)valueEnd);
                    Vector_Remove(vector, &valueEnd);
                    close(*(int*)pClient);
                    free(pClient);
                    
                   
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
    Vector_Destroy(&vector, DestroyVecPart);
    
    close(sock);

    return 0;
}