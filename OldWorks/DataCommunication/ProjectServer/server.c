#include "vector.h"
#include "server.h"
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

static int ReadBytes(Server* _server,int _activity,fd_set* _master , void* _valueEnd,int _index,void* _client);
static void ClientSocket(Server* _server, fd_set* _master, unsigned int _addr_len);
static int VectorManipulations(void* _client, fd_set* _master,Vector* _vector,void* _valueEnd,int _activity,int _index);
static int SocketCreate(void);



#define MAGIC 34523456
#define BACK_LOG 1000
#define FAIL -1
#define MAX_ITEMS 1024
#define PORT 2670

struct Server
{
    int m_magic;
    Vector* m_vector;
    int m_socket;
    InvalidClient m_invalidClient;
    GotMessege m_messege;
    Fail m_fail;
};

/* void GetClient(int _socketnum)
{
    char data_addr[] = "welcome client";
    SendMessege((void*)&_socketnum,data_addr,sizeof(data_addr));
    return ;
}

void ClientFailed(int _socketnum)
{
   char data_addr[] = "client send failed";
    SendMessege((void*)&_socketnum,data_addr,sizeof(data_addr));
    return ;
}

void GotMessage(int _socketnum,char _buffer[],size_t _bufferlen)
{
    char data_addr[50];
    sprintf (data_addr,"hello  client %d i am server",_socketnum);
    SendMessege((void*)&_socketnum,data_addr,sizeof(data_addr));
    return ;
}
 */




static void DestroyVecPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;

}


Server* ServerCreate(InvalidClient _invalidclient,GotMessege _messege,Fail _fail)
{
    Server* server;
    if( NULL == _invalidclient || NULL == _messege || NULL == _fail )
    {
        return NULL;
    }
    if(NULL == (server=(struct Server*)malloc(sizeof(struct Server))))
 	{
   		return NULL;
    }
    server->m_socket = SocketCreate();
    server->m_magic = MAGIC;
    server->m_vector = Vector_Create(1050, 50);
    server->m_invalidClient = _invalidclient;
    server->m_messege = _messege;
    server->m_fail = _fail;
    return server;

}

static int SocketCreate(void)
{
    int flags, optval = 1;
    struct sockaddr_in sin;
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
    sin.sin_port = htons(PORT);
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
    return sock;
    
}

void Run(Server* _server)
{
    struct sockaddr_in client_sin;
    char data_addr[]= "hello,im server";
    unsigned int addr_len = sizeof(data_addr);
    int activity = 0;
    Vector* vector;
    void* valueEnd;
    void* pClient;
    size_t i;
    fd_set master, temp;


    FD_ZERO(&master);
    FD_SET(_server->m_socket, &master);
    vector = _server->m_vector;
    addr_len = sizeof(client_sin);
    while(1)
    {
        temp = master;
        activity = select(MAX_ITEMS, &temp, NULL, NULL, NULL);
        if (FD_ISSET(_server->m_socket, &temp))
        {
            activity--;
            ClientSocket(_server,&master, addr_len);   
        }
        for(i=0; i< Vector_Size(vector) ;++i)
        {
            Vector_Get(vector, i, &pClient);
            if(FD_ISSET(*(int*)pClient,&temp))
            { 
                activity = ReadBytes(_server, activity, &master , valueEnd, (int)i, pClient);
            } 
        }
        

    }
}




static int VectorManipulations(void* _client, fd_set* _master,Vector* _vector,void* _valueEnd,int _activity,int _index)
{
    FD_CLR(*(int*)_client,_master);
    Vector_Get(_vector, Vector_Size(_vector)-1, &_valueEnd);
    Vector_Set(_vector, (size_t)_index, (void*)_valueEnd);
    Vector_Remove(_vector, &_valueEnd);
    close(*(int*)_client);
    free(_client);
    _activity--;
    return _activity;

}
void SendMessege(void* _client, char _arr[], unsigned int _length)
{
    ssize_t sent_bytes;
    sent_bytes = send(*(int*)_client, _arr, _length, 0);
    if (sent_bytes < 0) 
    {
        perror("send failed");
                        
    }
}

void ServerDestroy(Server** _server)
{
    if((*_server) && (*_server)->m_magic == MAGIC)
	{
        Vector_Destroy(&(*_server)->m_vector, DestroyVecPart);
	    (*_server)->m_magic = 0;
		free(*_server);
		*_server = NULL;
        /*TODO add more things to destroy*/
		return ;
	}
}

static void ClientSocket(Server* _server, fd_set* _master, unsigned int _addr_len)
{
    int client_sock;
    struct sockaddr_in client_sin;
    int* userInput;
    client_sock = accept(_server->m_socket,(struct sockaddr *) &client_sin,&_addr_len);
    if (client_sock < 0) 
    {    
        perror("accept failed");
        close(client_sock);   
    }
    else if(client_sock >= MAX_ITEMS || Vector_Size(_server->m_vector) >= MAX_ITEMS) /*TODO it was if*/
    {
        close(client_sock);
        /* continue; */
    }
    else/* if (client_sock > 0)  */
    {
        userInput=(int*)malloc(sizeof(int));
        *userInput = client_sock;
        Vector_Append(_server->m_vector, (void*)userInput);
        FD_SET(client_sock, _master);
    }

}

static int ReadBytes(Server* _server,int _activity,fd_set* _master , void* _valueEnd,int _index,void* _client)
{
    char buffer[4096],data_addr[]= "hello,im server";
    int read_bytes,expected_data_len = sizeof(buffer);
    unsigned int data_len = (unsigned int)strlen(data_addr);
    read_bytes = (int)recv(*(int*)_client, buffer, (size_t)expected_data_len, 0);
    if (read_bytes == 0) 
    {
        _activity = VectorManipulations(_client, _master, _server->m_vector,_valueEnd,_activity, _index);
    }
    else if (read_bytes < 0) 
    {
        if(errno != EAGAIN && errno != EWOULDBLOCK)
        {
            perror("accept failed");
            _activity = VectorManipulations(_client, _master,_server->m_vector,_valueEnd,_activity, _index);
        }
    }
    else
    {
        printf("%s\n", buffer);
        SendMessege(_client, data_addr, data_len);
    }

    return _activity;

}
/* int main()
{
    Server* server;
    server = ServerCreate(GetClient, GotMessage,ClientFailed);
    Run(server);
    
    return 0;
} */
