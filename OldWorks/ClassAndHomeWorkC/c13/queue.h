#ifndef QUEUE_U
#define QUEUE_U
#include <stdlib.h> /*size_t*/
/*TODO ifdef*/

#define EXIT 0
#define CREATE_QUEUE 1
#define DESTROY_QUEUE 2
#define ADD_ITEM_TO_QUEUE 3
#define REMOVE_ITEM_FROM_QUEUE 4
#define CHECK_QUEUE_IS_EMPTY 5
#define PRINT_QUEUE 6
#define MAGIC 983274
typedef struct Queue Queue;


/*
Description: Function creates a queue.
Input: Pointer to the queue structure.
Output: Returnes the created structure if succesfully created or returns NULL if not.
*/
struct Queue* QueueCreate (size_t _size);
/*
Description: Function destroyes the queue.
Input: Pointer to the queue structure.
Output: void.
*/
void QueueDestroy(struct Queue *_queue);
/*
Description: Function adds the selected number to queue.
Input: Pointer to the queue structure and the item it addes.
Output: If adds the number succesfully return ERR_OK.
If the queue wasent created return ERR_ALLOCATION_FAILED.
If there is no space to add return ERR_OVERFLOW.
*/
ADTErr QueueInsert (struct Queue *_queue, int  _item);
/*
Description: Function removes the number and saves it in a number on the menu.
Input: Pointer to the queue structure and the pointer to the item it removed.
Output: If removes the number succesfully return ERR_OK.
If the queue wasent created return ERR_ALLOCATION_FAILED.
If there was nothing to delete return ERR_UNDERFLOW.
*/
ADTErr QueueRemove (struct Queue *_queue, int *_item);
/*
Description: Function check if the queue is empty.
Input: Pointer to the queue structure.
Output: 0 if the queue is empty or 1 if its not.
*/
int QueueIsEmpty(struct Queue *_queue);
/*
Description: Function print the queue.
Input: Pointer to the queue structure.
Output: void.
*/
void QueuePrint(Queue *_queue);
/*
Description: Function print the error types.
Input: The returened value of the error from each function.
Output: void.
*/
void PError(ADTErr _error);
/*
Description: Function gets the initual size from user.
Input: Pointer to the queue structure.
Output: The created queue structure.
*/
struct Queue* Enter(struct Queue* _queue);
/*
Description: Function gets the number to add to queue from user.
Input: Pointer to the queue structure.
Output: The number inputed by user.
*/
int GetItem(struct Queue* _queue);

#endif
