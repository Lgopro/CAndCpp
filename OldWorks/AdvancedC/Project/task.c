#include <time.h>
#include <unistd.h>
#include <sys/time.h>   
#include <sys/resource.h> 
#include <unistd.h>
#include "Time.h"
#include "task.h"


struct Task
{
    _func m_func;
    void* m_content;
    struct timespec m_exeTime;
    struct timespec m_Interval;

};


Task* Task_Create(int (*_func)(void* _context) , void* _contect, double _interval)
{
    Task* newTask;
    if(NULL == _func || NULL == _contect)
    {
        return NULL;
    }
    if(NULL == (newTask=(struct Task*)malloc(sizeof(struct Task))))
 	{
   		return NULL;
    }

    newTask->m_content = _contect;
    newTask->m_func = _func;
    newTask->m_exeTime = Time_Convert(_interval);
    newTask->m_Interval = Time_Convert(_interval);
    return newTask;
}



void Task_Destroy(Task* _task)
{
    if(NULL == _task)
    {
        return;
    }
    free(_task);
    
}

int Task_Less(Task* _task1, Task* _task2)
{
    return Time_Is_Less(&_task1->m_exeTime , &_task2->m_exeTime);
}

int Task_Run(Task* _task)
{
    struct timespec rightTime;
    if(NULL == _task)
    {
        return -1;
    }
    rightTime = Time_Add(&_task->m_exeTime);
    Time_SleepUntil(rightTime);
    if(_task->m_func(_task->m_content))
    {

        return 1;
    }
    Time_Add(&_task->m_Interval);
    return 0;

}