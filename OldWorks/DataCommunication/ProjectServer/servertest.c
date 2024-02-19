#include <stdio.h>

#include "mu_test.h"
#include "vector.h"
#include "server.h"

void DestroyPart(void* _item)
{
	if(NULL == _item)
	{
		return;
	}
	_item = NULL;
}

void GetClient(int _socketnum)
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

UNIT(Server_Create_Check)
    Server* server;
    server = ServerCreate(GetClient, GotMessage,ClientFailed); 
	ASSERT_THAT(server != NULL);
    ServerDestroy(&server);
    server = ServerCreate(NULL, GotMessage,ClientFailed); 
    ASSERT_THAT(server == NULL);
    server = ServerCreate(GetClient, NULL,ClientFailed); 
    ASSERT_THAT(server == NULL);
    server = ServerCreate(GetClient, GotMessage,NULL); 
    ASSERT_THAT(server == NULL);
END_UNIT

UNIT(Server_Destroy_Check)
    Server* server;
    server = ServerCreate(GetClient, GotMessage,ClientFailed); 
	ASSERT_THAT(server != NULL);
    ServerDestroy(&server);
END_UNIT


UNIT(Server_Run_Check)
    Server* server;
    server = ServerCreate(GetClient, GotMessage,ClientFailed);
    Run(server);
END_UNIT




TEST_SUITE(SERVER_LIST)

	IGNORE_TEST(Server_Create_Check)
	IGNORE_TEST(Server_Destroy_Check)
	TEST(Server_Run_Check)
	
END_SUITE