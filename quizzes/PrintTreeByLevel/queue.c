/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 02/05/2023
*/
#include <stdlib.h> /*free*/
#include <assert.h> /*assert*/

#define FAIL 1
#define SUCCESS 0


#include "queue.h"



queue_t *QCreate(void)
{
	queue_t * queue = SListCreate();
	
	return queue;
}


void QDestroy(queue_t *queue)
{
	assert(NULL != queue);
	
	SListDestroy(queue);
	
}


int QEnqueue(queue_t *queue, const void *value)
{
	iter_t location = SListEnd((const slist_t *)queue);
	
	assert(NULL != queue);
	assert(NULL != value);
	
	if(NULL == location)
	{
		return FAIL;
	}
	
	location = SListInsert(location, (void *)value);
	
	return SUCCESS;
}



void QDequeue(queue_t *queue)
{

	iter_t location = SListBegin((const slist_t *)queue);
	
	assert(NULL != queue);

	SListRemove(location);
}

void *QPeek(const queue_t *queue)
{
	
	iter_t location = SListBegin((const slist_t *)queue);
	
	assert(NULL != queue);

	return SListGet(location);;
	
}

size_t QSize(const queue_t *queue)
{
	assert(NULL != queue);
	
	return SListCount(queue);
}

int QIsEmpty(const queue_t *queue)
{

	assert(NULL != queue);
	
	return (SListEnd((const slist_t *)queue) == SListBegin((const slist_t *)queue));

}




void QAppend(queue_t *dest, queue_t *src)
{
	
	assert(NULL != dest);
	assert(NULL != src);

	ListAppend(dest, src);

}

