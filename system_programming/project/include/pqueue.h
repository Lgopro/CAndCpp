/*
Rev: Maria Ponomariov.
Dev: Leonid Golovko
status: finished
date: 17/05/2023
*/

#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include <stddef.h> /* size_t */

#include "sortlist.h" 

typedef struct PQueue pq_t;


/*****************************************************************************/
/*
Description: Create a priority queue.
Arguments: Compare fucntion.
Return: A pointer to the created queue.
Time complexity: O(1).
Space complexity: O(1).
*/

pq_t *PQCreate(int (*compare)(const void *,const void *));

/*****************************************************************************/
/*
Description: Destroy a priority queue.
Arguments: Valid pointer to queue.
Return: Void.
Time complexity: O(n).
Space complexity: O(1).
*/

void PQDestroy(pq_t *pq);

/*****************************************************************************/
/*
Description: Insert an element into the priority queue.
Arguments: Valid pointer to queue and data.
Return: SUCCESS on 0 / FAIL on 1.
Time complexity: O(n).
Space complexity: O(1).
*/

int PQEnqueue(pq_t *pq, void *data);

/*****************************************************************************/
/*
Description: Delete an element from the front of the priority queue.
Arguments: Valid pointer to queue and data.
Return: SUCCESS on 0 / FAIL on 1.
Time complexity: O(n).
Space complexity: O(1).
*/

void *PQDequeue(pq_t *pq);

/***********************************************************************/
/*
Description: Look at value of first priority queue element.
Arguments: Valid pointer to priority queue.
Time complexity: O(1)
Space complexity: O(1)
*/
void *PQPeek(const pq_t *pq);

/*****************************************************************************/
/*
Description: Erase an element from the priority queue.
Arguments: Valid pointer to priority queue,pointer to match function and void 
pointer to param.
SUCCESS on 0 / FAIL on 1.
Time complexity: O(n).
Space complexity: O(1).
*/

void *PQErase(pq_t *pq, int (*is_match)(const void *, const void *), void *param);

/*****************************************************************************/
/*
Description: Empty the queue.
Arguments: Valid pointer to priority queue.
Return: Void.
Time complexity: O(n).
Space complexity: O(1).
*/

void PQClear(pq_t *pq);
/*****************************************************************************/
/*
Description: Count elements in the priority queue.
Arguments: Valid pointer to priority queue.
Return: Size of the priority queue.
Time complexity: O(n).
Space complexity: O(1).
*/

size_t PQSize(const pq_t *pq);

/*****************************************************************************/
/*
Description: Count elements in the queue. 
Arguments: Valid pointer to priority queue.
SUCCESS on 1 / FAIL on 0.
Time complexity: O(1).
Space complexity: O(1).
*/
int PQIsEmpty(const pq_t *pq);

#endif /* __PQUEUE_H__ */
