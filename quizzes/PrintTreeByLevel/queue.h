/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 02/05/2023
*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h> /* size_t, NULL */
#include "Slist.h" /*slist_t*/

typedef slist_t queue_t;



/***********************************************************************/
/*
Description: Create a queue.
Arguments: Void.
Return: Pointer to queue if success or NULL at fail.
Time complexity: O(1).
Space complexity: O(1).
*/
queue_t *QCreate(void);

/***********************************************************************/
/*
Description: Destroy a queue.
Arguments: Valid pointer to a queue.
Return: Void.
Time complexity: O(n)
Space complexity: O(1)
*/
void QDestroy(queue_t *queue);


/***********************************************************************/
/*
Description: Push the value to the back of the queue.
Arguments: Valid pointers to queue and value.
Return: 0 on success and 1 on fail.
Time complexity: O(1)
Space complexity: O(1)
*/
int QEnqueue(queue_t *queue, const void *value);

/***********************************************************************/
/*
Description: Pop the front of the queue.
Arguments: Valid pointet to a queue.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void QDequeue(queue_t *queue);

/***********************************************************************/
/*
Description: 
Arguments: 	
Return: 1 on success and 0 on fail.
Time complexity: O(1)
Space complexity: O(1)
*/
int QIsEmpty(const queue_t *queue);


/***********************************************************************/
/*
Description: Get the value of the first member of the queue.
Arguments: Valid const pointer to queue.
Return: Void pointer.
Time complexity: O(1)
Space complexity: O(1)
*/
void *QPeek(const queue_t *queue);

/***********************************************************************/
/*
Description: Return the size of the queue.
Arguments: Valid const pointer to queue.
Return: Size of queue.
Time complexity: O(n)
Space complexity: O(1)
*/
size_t QSize(const queue_t *queue);

/***********************************************************************/
/*
Description: Move the begining of src to the end of dest.
Arguments: Valid pointer to src and dest queues.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void QAppend(queue_t *dest, queue_t *src);

#endif /*__QUEUE_H__*/
