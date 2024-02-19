/*
Rev: Bar Shadkhin
Dev: Leonid Golovko
status: finished
date: 22/05/2023
*/

#include <stdio.h> /*printf*/
#include <time.h> /*sleep*/
#include <unistd.h> /*sleep*/
#include <stdlib.h> /*malloc*/


#include "uid.h"
#include "task.h"
#include "pqueue.h"
#include "scheduler.h"

typedef struct RemoveMyself
{
	scheduler_t *scheduler;
	ilrd_uid_t *data;

}remove_myself;

void Print(ilrd_uid_t var)
{
    struct tm* curr_time;
  
    curr_time = localtime(&var.time);
	printf("pid is: %d\n", var.pid);
	printf("counter is: %ld\n", var.counter);
	printf("%02d:%02d:%02d\n", curr_time->tm_hour, curr_time->tm_min,
   			curr_time->tm_sec);
	printf("pip is: %s\n", var.ip);
	printf("*****************\n");
}

static int RemoveMyself(void * data)
{
	return SchedulerRemoveTask(((remove_myself *)data)->scheduler, *((remove_myself *)data)->data);
}



static int Operation(void * data)
{
	
	printf("The data is %d\n", *(int *)data);
	return 0;
}

static int Operation1(void * data)
{
	static int counter = 5;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}

static int Operation2(void * data)
{
	static int counter = 3;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}

static int Operation3(void * data)
{
	static int counter = 2;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}

static int Operation4(void * data)
{
	static int counter = 1;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}

static int StopOperation(void * data)
{
	if(NULL == data)
	{
		return 1;
	}
	(void)data;
	SchedulerStop((scheduler_t *)data);
	printf("STOP!\n");
	return 2;
}
static int Operation5(void * data)
{
	static int counter = 3;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}
static int Operation6(void * data)
{
	static int counter = 3;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}
static int Operation7(void * data)
{
	static int counter = 3;
	printf("The data is %d\n", *(int *)data);
	--counter;
	if(0 == counter)
	{
	
		return DO_NOT_REPEAT;
	}
	return REPEAT;
}
void SchedulerAddTaskTest();
void SchedulerCreateTest();
void SchedulerRemoveTaskTest();
void SchedulerRunTaskTest1();
void SchedulerRunTaskTest2();
void SchedulerRunTaskTest3();

int main()
{	
	SchedulerCreateTest();
	SchedulerAddTaskTest();
	SchedulerRemoveTaskTest();
	SchedulerRunTaskTest1();
	SchedulerRunTaskTest2();
	SchedulerRunTaskTest3();
	return 0;
}

void SchedulerCreateTest()
{
	scheduler_t *scheduler = SchedulerCreate();
	
	if(1 == SchedulerIsEmpty((const scheduler_t *)scheduler) && 0 == SchedulerSize((const scheduler_t *)scheduler) && NULL != scheduler)
	{
		printf("SchedulerCreateTest pass\n");
	}
	else
	{
		printf("SchedulerCreateTest fail\n");
	}
	
	
	
	SchedulerDestroy(scheduler);
}


void SchedulerAddTaskTest()
{
	ilrd_uid_t data = {0};
	ilrd_uid_t data1 = {0};
	int value = 5;
	int value1 = 6;
	scheduler_t *scheduler = SchedulerCreate();
	
	
	data = SchedulerAddTask(scheduler, Operation, (void *)&value,  6, 5,  
							NULL, NULL);
				   
	data1 = SchedulerAddTask(scheduler, Operation, (void *)&value1,  10, 6,  
							NULL, NULL);
							
	
				   
	if(0 == SchedulerIsEmpty((const scheduler_t *)scheduler) && 2 == SchedulerSize((const scheduler_t *)scheduler) 
	   && NULL != scheduler && 0 == UIDIsSame(data, UIDBadUID) && 0 == UIDIsSame(data1, UIDBadUID))
	{
		printf("SchedulerAddTaskTest pass\n");
	}
	else
	{
		printf("SchedulerAddTaskTest fail\n");
		printf("SchedulerIsEmpty %d\n", SchedulerIsEmpty((const scheduler_t *)scheduler));
		printf("SchedulerSize %ld\n", SchedulerSize((const scheduler_t *)scheduler));
		
	
		printf("UIDIsSame(data, UIDBadUID) %d\n", UIDIsSame(data, UIDBadUID));
		printf("UIDIsSame(data1, UIDBadUID %d\n", UIDIsSame(data1, UIDBadUID));
		
	}
	
	
	
	SchedulerDestroy(scheduler);
}

void SchedulerRemoveTaskTest()
{
	ilrd_uid_t data = {0};
	ilrd_uid_t data1 = {0};
	ilrd_uid_t data2 = {0};
	ilrd_uid_t data3 = {0};
	int value = 5;
	int value1 = 6;
	
	int status = 0;
	scheduler_t *scheduler = SchedulerCreate();
	
	
	data = SchedulerAddTask(scheduler, Operation, (void *)&value,  6, 5,  
							NULL, NULL);
				   
	data1 = SchedulerAddTask(scheduler, Operation, (void *)&value1,  10, 6,  
							NULL, NULL);
	data2 = SchedulerAddTask(scheduler, Operation, (void *)&value,  6, 5,  
							NULL, NULL);
				   
	data3 = SchedulerAddTask(scheduler, Operation, (void *)&value1,  10, 6,  
							NULL, NULL);	
									   
	status = SchedulerRemoveTask(scheduler, data2);
	(void)data;
	(void)data1;
	(void)data3; 
	if(0 == status && 3 == SchedulerSize((const scheduler_t *)scheduler))
	{
		printf("SchedulerRemoveTaskTest pass\n");
	}
	else
	{
		printf("SchedulerRemoveTaskTest fail\n");
		printf("SchedulerSize %ld\n", SchedulerSize((const scheduler_t *)scheduler));
	}
	
	
	
	SchedulerDestroy(scheduler);
}


void SchedulerRunTaskTest1()
{
	ilrd_uid_t data = {0};
	ilrd_uid_t data1 = {0};
	ilrd_uid_t data2 = {0};
	ilrd_uid_t data3 = {0};
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int status = 0;
	scheduler_t *scheduler = SchedulerCreate();
	
	
	data = SchedulerAddTask(scheduler, Operation, (void *)&value,  6, 1,  
							NULL, NULL);
				   
	data1 = SchedulerAddTask(scheduler, Operation, (void *)&value1,  10, 2,  
							NULL, NULL);
	data2 = SchedulerAddTask(scheduler, Operation, (void *)&value2,  6, 3,  
							NULL, NULL);
				   
	data3 = SchedulerAddTask(scheduler, StopOperation, (void *)scheduler,  13, 6,  
							NULL, NULL);	
									   
	status = SchedulerRun(scheduler);
	(void)data;
	(void)data2;
	(void)data1;
	(void)data3; 
	if (STOPPED == status && 3 == SchedulerSize((const scheduler_t *)scheduler))
	{
		printf("SchedulerRunTaskTest1 pass\n");
	}
	else
	{
		printf("SchedulerRemoveTaskTest1 fail\n");
		printf("SchedulerSize %ld\n", SchedulerSize((const scheduler_t *)scheduler));
		printf("status %d\n",status);
	}
	
	SchedulerClear(scheduler);
	
	SchedulerDestroy(scheduler);
}

void SchedulerRunTaskTest2()
{
	ilrd_uid_t data = {0};
	ilrd_uid_t data1 = {0};
	ilrd_uid_t data2 = {0};
	ilrd_uid_t data3 = {0};
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	int status = 0;
	scheduler_t *scheduler = SchedulerCreate();
	
	
	data = SchedulerAddTask(scheduler, Operation1, (void *)&value,  6, 1,  
							NULL, NULL);
				   
	data1 = SchedulerAddTask(scheduler, Operation2, (void *)&value1,  10, 2,  
							NULL, NULL);
	data2 = SchedulerAddTask(scheduler, Operation3, (void *)&value2,  6, 3,  
							NULL, NULL);
				   
	data3 = SchedulerAddTask(scheduler, Operation4, (void *)&value3,  13, 6,  
							NULL, NULL);	
									   
	status = SchedulerRun(scheduler);
	(void)data;
	(void)data2;
	(void)data1;
	(void)data3; 
	if (SUCCESS == status && 0 == SchedulerSize((const scheduler_t *)scheduler))
	{
		printf("SchedulerRunTaskTest2 pass\n");
	}
	else
	{
		printf("SchedulerRemoveTaskTest2 fail\n");
		printf("SchedulerSize %ld\n", SchedulerSize((const scheduler_t *)scheduler));
		printf("status %d\n",status);
	}
	
	
	
	SchedulerDestroy(scheduler);
}


void SchedulerRunTaskTest3()
{
	ilrd_uid_t data = {0};
	ilrd_uid_t data1 = {0};
	ilrd_uid_t data2 = {0};
	ilrd_uid_t data3 = {0};
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int status = 0;
	remove_myself *data_for_test =(remove_myself *)malloc(sizeof(remove_myself));
	
	scheduler_t *scheduler = SchedulerCreate();
	
	data_for_test->scheduler = scheduler;
	data_for_test->data = &data3;
	
	data = SchedulerAddTask(scheduler, Operation5, (void *)&value,  6, 1,  
							NULL, NULL);
				   
	data1 = SchedulerAddTask(scheduler, Operation6, (void *)&value1,  10, 2,  
							NULL, NULL);
							
	data2 = SchedulerAddTask(scheduler, Operation7, (void *)&value2,  6, 3,  
							NULL, NULL);
				   
	
	data3 = SchedulerAddTask(scheduler, RemoveMyself, (void *)data_for_test,  13, 6,  
							NULL, NULL);
							
				   
		
									   
	status = SchedulerRun(scheduler);
	(void)data;
	(void)data2;
	(void)data1;
	(void)data3; 
	if (SUCCESS == status && 0 == SchedulerSize((const scheduler_t *)scheduler))
	{
		printf("SchedulerRunTaskTest3 pass\n");
	}
	else
	{
		printf("SchedulerRemoveTaskTest3 fail\n");
		printf("SchedulerSize %ld\n", SchedulerSize((const scheduler_t *)scheduler));
		printf("status %d\n",status);
	}
	
	free(data_for_test);
	
	SchedulerDestroy(scheduler);
}


