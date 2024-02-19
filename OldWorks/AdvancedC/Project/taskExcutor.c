#include <stdio.h>
#include "heap.h"
#include "Time.h"
#include "task.h"
#include "taskExcutor.h"


#define DEFAULT_BLOCK_SIZE ((size_t)100)
#define DEFAULT_INIT_SIZE ((size_t)100)

static int LessConvert(const void* _compareleft,const void* _compareright )
{
    return Task_Less((Task*)_compareleft, (Task*)_compareright);
}

int task10(void* _context)
{
    if(*(int*)_context == 1)
    {
        printf("This is right\n");
        return 1;
    }
    return 0;
}
struct Executer
{
    Heap* m_tasks;
    Vector* m_vectorTask;
    int m_flagPause;
    
};


Executer* Executer_Create(void)
{
    Executer* newExec;
     if(NULL == (newExec=(struct Executer*)malloc(sizeof(struct Executer))))
 	{
   		return NULL;
    }
    newExec->m_vectorTask = Vector_Create(DEFAULT_INIT_SIZE, DEFAULT_BLOCK_SIZE);
    newExec->m_tasks = Heap_Build(newExec->m_vectorTask, LessConvert);
    newExec->m_flagPause = 0;
    return newExec;
}

static void TaskDest(void* task)
{
    Task_Destroy((Task*)task);
}

 void Executer_Destroy(Executer* _exec)
{
    if(NULL == _exec)
    {
        return;
    }
    _exec->m_vectorTask = Heap_Destroy(&_exec->m_tasks);
    Vector_Destroy(&_exec->m_vectorTask, TaskDest);
    free(_exec);
} 


ErrResult_Executer Executer_AddTask(Executer* _exec ,userFunc _func  , void* _contect, double _interval)
{
    Task* newTask;
    if(NULL == _exec)
    {
        return EXECUTER_NOT_INITIALIZED;

    }
    if(NULL == _func || NULL == _contect)
    {
        return EXECUTER_NULL_POINTER;
    }
    newTask = Task_Create(_func , _contect, _interval);
    Heap_Insert(_exec->m_tasks, (void*)newTask);
    return EXECUTER_SUCCESS;
}


size_t Executer_Run(Executer* _exec)
{
    Task* task;
    while(_exec->m_flagPause != 1 && Heap_Size(_exec->m_tasks))
    {
        task = Heap_Extract(_exec->m_tasks);
        if(Task_Run(task))
        {
            Heap_Insert(_exec->m_tasks, (void*)task);
        }
    }
    return Heap_Size(_exec->m_tasks);
} 


ErrResult_Executer Executer_Pause(Executer* _exec)
{
    if(NULL == _exec)
    {
        return EXECUTER_NOT_INITIALIZED;
    }
    _exec->m_flagPause = 1;
    return EXECUTER_SUCCESS;
} 