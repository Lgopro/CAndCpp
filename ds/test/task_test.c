/*
Rev: Bar Shadkhin
Dev: Leonid Golovko
status: finished
date: 22/05/2023
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

void TaskCreateTest();
void TaskRestOFFunctionsTest();


int main()
{	
	TaskCreateTest();
	TaskRestOFFunctionsTest();
	return 0;
}




void TaskCreateTest()
{

	int param = 5;
	size_t delay = 5;
	size_t interval_in_sec = 5;
	int status = 0;
	time_t time;
	task_t *task = TaskCreate(Operation, (void *)&param, 
				   delay, interval_in_sec, 
				   &CleanUp, NULL);
	
	
	
	task->task_id = TaskGetUID((const task_t *)task);
	
	status = TaskIsMatch((const task_t *)task, task->task_id);
	
	time = TaskGetTimeToRun((const task_t *)task);
	
	if(time == task->time_to_run && 1 == status && time == task->time_to_run)
	{
		printf("TaskCreateTest pass\n");
	}
	else
	{
		printf("TaskCreateTest fail\n");
	}
	
	TaskDestroy(task);
	
}


void TaskRestOFFunctionsTest()
{

	int param = 5;
	int param1 = 5;
	size_t delay = 5;
	size_t interval_in_sec = 5;
	int status = 0;
	int status1 = 0;
	int status2 = 0;
	int status3 = 0;
	time_t time;
	task_t *task = TaskCreate(Operation, (void *)&param, 
				   delay, interval_in_sec, 
				   &CleanUp, NULL);
	
	task_t *task1 = TaskCreate(Operation, (void *)&param1, 
				   10, 10, 
				   &CleanUp, NULL);
	
	task->task_id = TaskGetUID((const task_t *)task);
	
	status = TaskIsMatch((const task_t *)task, task->task_id);
	
	status2 = TaskIsMatch((const task_t *)task, task1->task_id);
	
	status3 = TaskIsMatch((const task_t *)task, UIDBadUID);
	
	time = TaskGetTimeToRun((const task_t *)task);
	
	status1 = TaskIsBefore((const task_t *)task, (const task_t *)task1);
	
	if(time == task->time_to_run && 1 == status && 
	   time == task->time_to_run && 1 == status1 && 0 == status2 && 0 == status3)
	{
		printf("TaskRestOFFunctionsTest pass\n");
	}
	else
	{
		printf("TaskRestOFFunctionsTest fail\n");
	}
	
	TaskDestroy(task);
	TaskDestroy(task1);
}



