/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 20/06/2023
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <time.h> /* time_t*/
#include <unistd.h> /*sleep*/

#define MATCH 1
#define NOT_MATCH 1

#include "scheduler.h"
#include "pqueue.h"
#include "heap.h"

struct Scheduler 
{
	pq_t * pq;
	int is_stop;
	int to_remove; 
	task_t *current_task;

};



static int Compare(const void *value1, const void *value2);
static int IsMatch(const void *value1, const void *value2);





scheduler_t *SchedulerCreate(void)
{
	
	scheduler_t *scheduler =(scheduler_t *)malloc(sizeof(scheduler_t));
	
	if(NULL == scheduler)
	{
		return NULL;
	}
	
	scheduler->pq = PQCreate(Compare);
	if(NULL == scheduler->pq)
	{
		free(scheduler);
		return NULL;
	}
	
	scheduler->current_task = NULL;
	scheduler->is_stop = SUCCESS;
	scheduler->to_remove = SUCCESS;
	
	return scheduler;
}

void SchedulerDestroy(scheduler_t *scheduler)
{
	assert(NULL != scheduler);
	
	SchedulerClear(scheduler);
	PQDestroy(scheduler->pq);
	free(scheduler);
	
	scheduler = NULL;
}    

int SchedulerRemoveTask(scheduler_t *scheduler, ilrd_uid_t uid)
{
	assert(NULL != scheduler);
	assert(!UIDIsSame(UIDBadUID, uid));
	scheduler->to_remove = 1;
	if(&uid == PQErase(scheduler->pq, IsMatch , (void *)&uid))
	{
		return SUCCESS;
	}
	if(TaskIsMatch(scheduler->current_task, uid))
	{
		TaskDestroy(scheduler->current_task);
		return SUCCESS;
	}
	return ERROR;	
}

ilrd_uid_t SchedulerAddTask(scheduler_t *scheduler, int (*op_func_t)(void *), void *op_param, 
				   size_t delay_in_sec, size_t interval_in_sec, 
				   void (*task_clean_up_t)(void *), void *clean_up_param)
{
	
	task_t *task = NULL;
	
	assert(NULL != op_func_t);
	assert(NULL != scheduler);
	assert(0 != interval_in_sec);
	
	
	
	task = TaskCreate(op_func_t, op_param, delay_in_sec, interval_in_sec, 
				      task_clean_up_t,clean_up_param);
				      
	task->task_id = TaskGetUID((const task_t *)task); 
	
	
	if(TaskIsMatch((const task_t *)task, UIDBadUID))
	{
		TaskDestroy(task);
		return (UIDBadUID);
	}
	if(ERROR == PQEnqueue(scheduler->pq, task))
	{
		TaskDestroy(task);
		return (UIDBadUID);
	
	}
	
	return (task->task_id);
		
	
}

int SchedulerRun(scheduler_t *scheduler)
{
	
	
	int status = SUCCESS;
	assert(NULL != scheduler);
	
	
	scheduler->is_stop = SUCCESS;
	
	while(STOPPED != scheduler->is_stop &&
		  (1 != SchedulerIsEmpty((const scheduler_t *)scheduler)))
	{
		scheduler->to_remove = 0;
		scheduler->current_task = NULL;
		
		scheduler->current_task = (task_t *)PQDequeue(scheduler->pq);
		
			
		while(sleep(scheduler->current_task->time_to_run > time(NULL)))
		{
			sleep(scheduler->current_task->time_to_run - time(NULL));
		}
		
		status = TaskRun(scheduler->current_task);
		
		if(1 == scheduler->to_remove)
		{
			continue;
		}
			if(SUCCESS == status)
			{
					
				if(PQEnqueue(scheduler->pq, (void *)scheduler->current_task))
				{
					
					TaskDestroy(scheduler->current_task);
					return (ERROR);
				}
				
			}
			else if(ERROR == status)
			{
				TaskDestroy(scheduler->current_task);
			}
			else if(STOPPED == scheduler->is_stop)
			{
				TaskDestroy(scheduler->current_task);
				return (STOPPED);
			} 
	}
	
	return (SUCCESS);
}

void SchedulerStop(scheduler_t *scheduler)
{
	assert(NULL != scheduler);
	
	scheduler->is_stop = STOPPED;
}

size_t SchedulerSize(const scheduler_t *scheduler)
{
	assert(NULL != scheduler);
	
	return PQSize((const pq_t *)scheduler->pq);
}

int SchedulerIsEmpty(const scheduler_t *scheduler)
{
	assert(NULL != scheduler);

	return PQIsEmpty((const pq_t *)scheduler->pq);
}


void SchedulerClear(scheduler_t *scheduler)
{
	task_t *data = NULL;
	assert(NULL != scheduler);
	
	while(!SchedulerIsEmpty((const scheduler_t *)scheduler))
	{
		data = (void *)PQDequeue(scheduler->pq); 
		TaskDestroy(data);
	}
}

static int Compare(const void *value1, const void *value2)
{
	return (((((task_t *)value1)->time_to_run - ((task_t *)value2)->time_to_run)));

}


static int IsMatch(const void *value1, const void *value2)
{
	if(UIDIsSame(((task_t *)value1)->task_id, *(ilrd_uid_t *)value2))
	{
		TaskDestroy((task_t *)value1);
		return MATCH;
	}
	return (UIDIsSame(((task_t *)value1)->task_id, *(ilrd_uid_t *)value2));

}


