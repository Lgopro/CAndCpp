/*
Rev: Bar Shadkhin
Dev: Leonid Golovko
status: finished
date: 22/05/2023
*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#include "task.h" 








task_t *TaskCreate(int (*op_func)(void *), void *param, 
				   size_t delay_in_sec, size_t interval_in_sec, 
				   void (*task_cleanup)(void *), void *cleanup_param)
{
	
	task_t *task = NULL;
	assert(NULL != op_func);
	
	task = (task_t *)malloc(sizeof(task_t));
	
	if(NULL == task)
	{
		return NULL;
	}
	
	task->op_func = op_func; 
	task->op_param = param; 
	
	task->task_id = UIDCreate();
	if(UIDIsSame(UIDBadUID, task->task_id))
	{
		free(task);
		return NULL;
	}
	
	task->time_to_run = time(NULL) + delay_in_sec; 
	task->interval_in_sec = interval_in_sec;
	task->task_cleanup = task_cleanup;
	task->cleanup_param = cleanup_param;
	return task;
}



void TaskDestroy(task_t *task)
{
	assert(NULL != task);
	if(NULL != task->task_cleanup && NULL != task->cleanup_param)
	{
		task->task_cleanup(task->cleanup_param);
	}
	free(task);
}


int TaskRun(task_t *task)
{
	int status = 0;
	
	assert(NULL != task);
	
	TaskUpdateTimeToRun(task);
	
	status = task->op_func(task->op_param);
	
		
	
	return status;
}

ilrd_uid_t TaskGetUID(const task_t *task)
{

	assert(NULL != task);
	
	return task->task_id;

}


time_t TaskGetTimeToRun(const task_t *task)
{
	assert(NULL != task);
	
	return task->time_to_run;
}

int TaskUpdateTimeToRun(task_t *task)   
{
	
	assert(NULL != task);

	task->time_to_run = task->time_to_run + task->interval_in_sec;
	return 0;
}

int TaskIsBefore(const task_t *to_check, const task_t *check_against)
{

	assert(NULL != to_check);
	assert(NULL != check_against);

	return (to_check->time_to_run < check_against->time_to_run);
}

int TaskIsMatch(const task_t *task1, ilrd_uid_t uid)
{
	assert(NULL != task1);
	
	return(UIDIsSame(task1->task_id, uid));
}


