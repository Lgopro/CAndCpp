#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "queue.h"

void test1QueueCreate(void);
void test2QueueCreate(void);
void test3QueueDestroy(void);
void test4QueueInsert(void);
void test5QueueInsert(void);
void test6QueueInsert(void);
void test7QueueInsert(void);
void test8QueueRemove(void); 
void test9QueueRemove(void);
void test10QueueRemove(void);
void test11QueueIsEmpty(void);
void test12QueueIsEmpty(void);
void test13QueueIsEmpty(void);
void test14GetItem(void);


int main()
{
 	test1QueueCreate();
 	test2QueueCreate();
 	test3QueueDestroy();
 	test4QueueInsert();
 	test4QueueInsert();
 	test5QueueInsert();
 	test6QueueInsert();
 	test7QueueInsert();
 	test8QueueRemove(); 
 	test9QueueRemove(); 
 	test10QueueRemove(); 
 	test11QueueIsEmpty();
 	test12QueueIsEmpty();
 	test12QueueIsEmpty();
 	test13QueueIsEmpty();
	test14GetItem();
	
	return 0;
}

void test1QueueCreate()
{
	struct Queue* Queue=NULL;
	Queue=QueueCreate(0);
	if(NULL == Queue)
	{
		printf("test 1 pass\n");
	}
	else
	{
		printf("test 1 fail\n");
	}

}

void test2QueueCreate()
{
	struct Queue* Queue=NULL;
	Queue=QueueCreate(5);
	if(NULL == Queue)
	{
		printf("test 2 fail\n");
	}
	else
	{
		printf("test 2 pass\n");
	}

}



void test3QueueDestroy()
{
	struct Queue* Queue=NULL;
	Queue=QueueCreate(5);
	QueueDestroy(Queue);
	if(NULL == Queue)
	{
		printf("test 3 pass\n");
	}
	else
	{
		printf("test 3 fail\n");
	}

}

void test4QueueInsert(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	Queue=QueueCreate(5);
	err=QueueInsert (Queue,5);
	if(err == ERR_OK)
	{
		printf("test 4 pass\n");
	}
	else
	{
		printf("test 4 fail\n");
	}
}
void test5QueueInsert(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	err=QueueInsert (Queue,5);
	if(err == ERR_ALLOCATION_FAILED)
	{
		printf("test 5 pass\n");
	}
	else
	{
		printf("test 5 fail\n");
	}	
}

void test6QueueInsert(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	Queue=QueueCreate(1);
	QueueInsert(Queue,5);
	err=QueueInsert (Queue,5);
	if(err == ERR_OVERFLOW)
	{
		printf("test 6 pass\n");
	}
	else
	{
		printf("test 6 fail\n");
	}
}

void test7QueueInsert(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	int num;
	Queue=QueueCreate(1);
	QueueInsert (Queue,5);
	QueueRemove (Queue, &num);
	err=QueueInsert (Queue,5);
	
	if(err == ERR_OK)
	{
		printf("test 7 pass\n");
	}
	else
	{
		printf("test 7 fail\n");
	}
}

void test8QueueRemove(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	int num;
	Queue=QueueCreate(3);
	QueueInsert (Queue,5);
	err=QueueRemove (Queue, &num);
	if(err == ERR_OK)
	{
		printf("test 8 pass\n");
	}
	else
	{
		printf("test 8 fail\n");
	}
}
void test9QueueRemove(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	int num;
	Queue=QueueCreate(3);
	err=QueueRemove (Queue, &num);
	if(err == ERR_UNDERFLOW)
	{
		printf("test 9 pass\n");
	}
	else
	{
		printf("test 9 fail\n");
	}
}

void test10QueueRemove(void)
{
	struct Queue* Queue=NULL;
	ADTErr err;
	int num;
	err=QueueRemove (Queue, &num);
	if(err == ERR_ALLOCATION_FAILED)
	{
		printf("test 10 pass\n");
	}
	else
	{
		printf("test 10 fail\n");
	}
}


void test11QueueIsEmpty(void)
{
	struct Queue* Queue=NULL;
	int num;
	num=QueueIsEmpty(Queue);
	if(num == 2)
	{
		printf("test 11 pass\n");
	}
	else
	{
		printf("test 11 fail\n");
	}
}

void test12QueueIsEmpty(void)
{
	struct Queue* Queue=NULL;
	int num;
	QueueCreate(3);
	num=QueueIsEmpty(Queue);
	if(num == 0)
	{
		printf("test 12 pass\n");
	}
	else
	{
		printf("test 12 fail\n");
	}
}
void test13QueueIsEmpty(void)
{
	struct Queue* Queue=NULL;
	int num;
	QueueCreate(3);
	QueueInsert (Queue,5);
	num=QueueIsEmpty(Queue);
	if(num == 1)
	{
		printf("test 13 pass\n");
	}
	else
	{
		printf("test 13 fail\n");
	}
}
void test14GetItem(void)
{
	struct Queue* Queue=NULL;
	int num;
	num=GetItem(Queue);
	if(num==0)
	{
		printf("test 14 pass\n");
	}
	else
	{
		printf("test 14 fail\n");
	}
}





