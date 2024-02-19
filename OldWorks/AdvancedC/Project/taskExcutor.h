#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

#include  <stdlib.h> /*size_t*/
#include <time.h> /* clock_gettime */

/** 
 * @brief Create a periodic task executer.
 * @author Author Leon Golovko (lgopro06@gmail.com)
 * @see  
 */ 

typedef struct Executer Executer;
typedef int (*userFunc)(void* _context); 
typedef enum
{
    EXECUTER_SUCCESS = 0,
	EXECUTER_NOT_INITIALIZED,
	EXECUTER_NULL_POINTER,
	EXECUTER_REALLOCATION_FAILED
}ErrResult_Executer;

/**  
 * @brief Apply a executer for running tasks.  
 * @param[in] none
 * @return Executer * - on success
 * @retval NULL on fail 
 */
Executer* Executer_Create(void);

/**  
 * @brief Deallocate a previously allocated executer
 * Frees the executer.
 * @param[in] _exec - Executer to be deallocated.  On success will be nulled.
 * @return None
 */
void Executer_Destroy(Executer* _exec);

/**
 * @brief Add an tasks to the Executer preserving Executer property.  
 * @param[in] _exec - Executer to insert task to.
 * @param[in] _func - user function to insert as a task. can't be null
 * @param[in] _context - user _context to provide user function.
 * @param[in] _interval - user interval time for user function to run. can't be null
 * @return success or error code 
 * @retval EXECUTER_SUCCESS  on success
 * @retval EXECUTER_NOT_INITIALIZED  error, EXECUTER not initialized
 * @retval EXECUTER_REALLOCATION_FAILED error, EXECUTER could not reallocate underlying vector 
 */
ErrResult_Executer Executer_AddTask(Executer* _exec , userFunc _func , void* _contect, double _interval);

/**
 * @brief Run all tasks in the Given Executer.  
 * @param[in] _exec - Executer .
 * @return size_t - number of remaining tasks.  
 */
size_t Executer_Run(Executer* _exec);

/**
 * @brief Pause the Executer.  
 * @param[in] _exec - Executer .
 * @return success or error code 
 * @retval EXECUTER_SUCCESS  on success
 * @retval EXECUTER_NOT_INITIALIZED  error, Executer not initialized.
 */
ErrResult_Executer Executer_Pause(Executer* _exec);


#endif


