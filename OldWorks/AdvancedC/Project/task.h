#ifndef __TASK_H__
#define __TASK_H__

#include  <stdlib.h> /*size_t*/
#include <time.h> /* clock_gettime */

/** 
 * @brief Create a task .
 * @author Author Leon Golovko (lgopro06@gmail.com)
 * @see  
 */ 

typedef struct Task Task;

typedef int (*_func)(void* _context);

typedef enum
{
    TASK_SUCCESS = 0,
	TASK_NOT_INITIALIZED,
	TASK_REALLOCATION_FAILED
}ErrResult;


/**  
 * @brief Create a new task with given user parameters.  
 * @param[in] _func - user function to insert as a task. can't be null
 * @param[in] _context - user _context to provide the user function.
 * @param[in] _interval - user interval time for user function to run. can't be null
 * @return Task * - on success
 * @retval NULL on fail 
 *
 */  
Task* Task_Create(int (*_func)(void* _context) , void* _contect, double _interval);

/**  
 * @brief Deallocate a previously allocated task
 * Frees the task.
 * @param[in] _task - task to be deallocated.
 * @return None
 */
void Task_Destroy(Task* _task);

/**
 * @brief run the task  
 * @param[in] _task.
 * @return int - 1 if needs to be executed again otherwise return 0 and will stoped.
 */
int Task_Run(Task* _task);

/**
 * @brief determines what task time is lower.  
 * @param[in] _task1 and _task2.
 * @return 1 if _task1 is lower and 0 if _task2 is lower. 
 */
int Task_Less(Task* _task1, Task* _task2);


#endif /* __TASK_H__ */