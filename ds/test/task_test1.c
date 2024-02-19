/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date:16/05/2023
*/

#include <stdio.h> /*printf*/
#include <time.h> /*sleep*/
#include <unistd.h> /*sleep*/


#include "task.h" 

static int Operation(void * data)
{
	if(NULL == data)
	{
		return 1;
	}
	printf("The data is %d\n", *(int *)data);
	return 0;
}

void CleanUp(void *data)
{
	data = NULL;
	(void)data;
	printf("The data now is NULL\n");
	
}

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

void TaskCreateTest();

int main()
{	
	TaskCreateTest();
	return 0;
}




void TaskCreateTest()
{

	int param = 5;
	size_t delay = 5;
	size_t interval_in_sec = 5;
	int status = 0;
	int status1 = 0;
	int StatusIsBefore = 0;
	time_t time;
	task_t *task = TaskCreate(Operation, (void *)&param, 
				   delay, interval_in_sec, 
				   &CleanUp, NULL);
	
	task_t *task1 = TaskCreate(Operation, (void *)&param, 
				   10, 10, 
				   &CleanUp, NULL);
	
	task->task_id = TaskGetUID((const task_t *)task);
	
	status = TaskIsMatch((const task_t *)task, task->task_id);
	
	status1 = TaskIsMatch((const task_t *)task, task1->task_id);
	
	time = TaskGetTimeToRun((const task_t *)task);
	
	TaskRun(task);
	
	StatusIsBefore = TaskIsBefore((const task_t *)task1, (const task_t *)task);
	
	Print(task->task_id);
	Print(task1->task_id);
	
	if(time == task->time_to_run && 1 == status  && 0 == status1 
	   && 0 == StatusIsBefore)
	{
		printf("TaskCreateTest pass\n");
		printf("TaskGetUIDTest pass\n");
		printf("TaskIsMatchTest pass\n");
		printf("TaskGetTimeToRunTest pass\n");
		printf("TaskDestroyTest pass\n");
	}
	else
	{
		printf("TaskCreateTest fail\n");
		printf("TaskGetUIDTest fail\n");
		printf("TaskIsMatchTest fail\n");
		printf("TaskGetTimeToRunTest fail\n");
		printf("TaskDestroyTest fail\n");
		printf("status %d\n", status);
		printf("status1 %d\n", status1);
		printf("StatusIsBefore %d\n", StatusIsBefore);
	}
	
	TaskDestroy(task);
	TaskDestroy(task1);
}



