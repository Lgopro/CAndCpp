#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "queue.h"


struct Queue
{
    int*    m_que;
    size_t  m_size;
    size_t  m_head;      /* Index of head in m_vec. */
    size_t  m_tail;      /* Index of tail in m_vec. */
    size_t  m_nItems;
    int m_magic;
};

void PError(ADTErr _error)
{	
        if(_error==ERR_OK)
        {
                printf("Operation successful\n\n");
        }
        if(_error==ERR_GENERAL)
        {
                printf("General error.Please try again\n\n");
        }
        if(_error==ERR_NOT_INITIALIZED)
        {
                printf("Not initialized. Please try again\n\n");
        }
        if(_error==ERR_REALLOCATION_FAILED)
        {
                printf("Relocation failed. Please try again\n\n");
        }
        if(_error==ERR_UNDERFLOW)
        {
                printf("There is nothing to remove. Please try again\n\n");
        }
        if(_error==ERR_OVERFLOW)
        {
                printf("Cant add anymore. Please try again\n\n");
        }
        if(_error==ERR_WRONG_INDEX)
        {
                printf("Wrong index\n\n");
        }


}


struct Queue* Enter(struct Queue* _queue)
{	

	size_t initsize;
	printf("Please enter the initual size of the Queue:\n");
	scanf("%lu", &initsize);
	getchar();
	_queue=QueueCreate(initsize);
	return _queue;
}

struct Queue* QueueCreate(size_t _initialSize)
{
	struct Queue* Queue=NULL;
	int* items = NULL;
	if(_initialSize==0)
	{
		return NULL;
	}
	
 	if(NULL == (Queue=(struct Queue*)malloc(sizeof(struct Queue)*1)))
   {
   		
   		return NULL;
   }
   
   Queue->m_size = _initialSize;
   Queue->m_nItems = 0;
   Queue->m_head = 0;
   Queue->m_tail = 0;
   items=(int*)malloc(sizeof(int)*(Queue->m_size+1));
   if(NULL == items)
   {
   		free(Queue);
   		return NULL;	
   }
   Queue->m_que = items;
   return Queue;
}


void QueueDestroy(struct Queue* _queue)
{

if(_queue==NULL)
	{
        return ;
	}
	if(_queue && _queue->m_magic == MAGIC)
	{
	    if(_queue->m_que)
	    {
	        free(_queue->m_que);
	    }
		free(_queue);
		_queue->m_magic=0;
		
		return ;
	}
}

void QueuePrint(struct Queue* _queue)
{

	size_t i,k=0;
	if(_queue==NULL)
	{
        return;
	}
	else if(_queue->m_nItems==0)
	{
        return;
	}
	if(_queue->m_head<_queue->m_tail)
	{
		for(i=_queue->m_head;i<_queue->m_tail;i++)
		{
			printf("The %lu item is: %d\n", k+1,_queue->m_que[i]);
			k++;
		}
		return;
	}
	else
	{
		for(i=_queue->m_head;i<_queue->m_size;i++)
		{
			printf("The %lu item is: %d\n", k+1,_queue->m_que[i]);
			k++;
		}
		for(i=0;i<_queue->m_tail;i++)
		{
			printf("The %lu item is: %d\n", k+1,_queue->m_que[i]);
			k++;
		}
		return;
	}
	
}

int QueueIsEmpty(struct Queue* _queue)
{	
	if(_queue==NULL)
	{
        return 2;
	}
	if(_queue->m_nItems==0)
	{
		return 0;
	}
	return 1;

}

int GetItem(struct Queue* _queue)
{
	int item;
	if(_queue==NULL)
	{
        return 0;
	}
	
	printf("Please enter a number for the item you want to join:\n");
	scanf("%d", &item);
	getchar();
	return item;
}

ADTErr QueueInsert (struct Queue* _queue, int  _item)
{
	if(_queue==NULL)
	{
        return ERR_ALLOCATION_FAILED;
	}
	
	if(_queue->m_nItems==_queue->m_size)
	{
		return ERR_OVERFLOW;
	}
	else if(_queue->m_tail<_queue->m_size-1)
	{
		_queue->m_que[_queue->m_tail]=_item;
		_queue->m_tail++;
		_queue->m_nItems++;
		return ERR_OK;
	}
	else
	{
		_queue->m_que[_queue->m_tail]=_item;
		_queue->m_tail=0;
		_queue->m_nItems++;
		return ERR_OK;
	}
	
}

ADTErr QueueRemove (struct Queue* _queue, int* _item)
{
	if(_queue==NULL)
	{
        return ERR_ALLOCATION_FAILED;
	}
	if(_queue->m_nItems==0)
	{
		return ERR_UNDERFLOW;
	}
	else if(_queue->m_head<_queue->m_size-1)
	{
		*_item=_queue->m_que[_queue->m_head];
		_queue->m_head++;
		_queue->m_nItems--;
		return ERR_OK;
		
	}
	else
	{
		*_item=_queue->m_que[_queue->m_head];
		_queue->m_head=0;
		_queue->m_nItems--;
		return ERR_OK;
	}
}



