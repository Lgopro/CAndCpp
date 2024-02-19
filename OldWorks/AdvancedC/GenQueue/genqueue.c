
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAGIC 8127438




struct Queue
{
	int m_magic;
    void*   *m_que;
    size_t  m_size;
    size_t  m_head;      /* Index of head in m_vec. */
    size_t  m_tail;      /* Index of tail in m_vec. */
    size_t  m_nItems;
};


Queue* Queue_Create(size_t _maxSize)
{
	struct Queue* Queue=NULL;
	if(_maxSize == 0)
	{
		return NULL;
	}
 	if(NULL == (Queue=(struct Queue*)malloc( sizeof(struct Queue) + _maxSize*sizeof(void**))))
    {
   		return NULL;
    }
    
    Queue->m_que = (void**)(Queue+1);
	Queue->m_size = _maxSize;
	Queue->m_nItems = 0;
	Queue->m_head = 0;
	Queue->m_tail = 0;
	Queue->m_magic = MAGIC;
	return Queue;
}



void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item))
{
	int i;
	if(_queue == NULL)
	{
        return ;
	}
	if((*_queue != NULL) && (*_queue)->m_magic == MAGIC)
	{
		
		if(NULL != _elementDestroy)
		{
			for(i=0; i< (*_queue)->m_nItems && NULL != _elementDestroy ;i++)
			{
				(*_elementDestroy)((*_queue)->m_que[i]);
			}
		}
		(*_queue)->m_magic=0;
		free(*_queue);
		*_queue= NULL;
		return ;
	}
	

}


Queue_Result Queue_Enqueue(Queue* _queue, void* _item)
{

	if(_queue == NULL)
	{
        return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_item == NULL)
	{
        return QUEUE_UNINITIALIZED_ITEM;
	}
	
	if(_queue->m_nItems == _queue->m_size)
	{
		return QUEUE_OVERFLOW;
	}
	else if(_queue->m_tail<_queue->m_size-1)
	{
		_queue->m_que[_queue->m_tail] = _item;
		_queue->m_tail++;
		_queue->m_nItems++;
		return QUEUE_SUCCESS;
	}
	else
	{
		_queue->m_que[_queue->m_tail]=_item;
		_queue->m_tail=0;
		_queue->m_nItems++;
		return QUEUE_SUCCESS;
	}
}

Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue)
{

	if(_queue==NULL)
	{
        return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_pValue == NULL)
	{
        return QUEUE_UNINITIALIZED_ITEM;
	}
	if(_queue->m_nItems==0)
	{
		return QUEUE_UNDERFLOW;
	}
	else if(_queue->m_head<_queue->m_size-1)
	{
		*_pValue=_queue->m_que[_queue->m_head];
		_queue->m_head++;
		_queue->m_nItems--;
		return QUEUE_SUCCESS;
		
	}
	else
	{
		*_pValue=_queue->m_que[_queue->m_head];
		_queue->m_head=0;
		_queue->m_nItems--;
		return QUEUE_SUCCESS;
	}

}


int Queue_IsEmpty(const Queue* _queue)
{
	if(_queue==NULL)
	{
        return -1;
	}
	if(_queue->m_nItems==0)
	{
		return 0;
	}
	return 1;
}

