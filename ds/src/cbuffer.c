/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 03/05/2023
*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/

#define FULL 1

#define EMPTY 0

#define NO_SPACE 0

#define NO_ACTION_MADE -1

#include "cbuffer.h"

struct CBuff
{
	size_t capacity;
	size_t start;
	size_t end;
	char buffer[1];
};

ssize_t CBuffWrite(cbuff_t *c_buffer, const void *src, size_t count)
{
	void *what_to_add = (void *)src;
	ssize_t counter = 0;
	
	assert(NULL != c_buffer);
	assert(NULL != src);
	assert(0 != count);
	
	if((c_buffer->end  == c_buffer->start ) && (FULL == *(c_buffer->buffer + c_buffer->capacity)))
	{
		return (NO_ACTION_MADE);
	}
	
	while(0 != count)
	{
		*(c_buffer->buffer + c_buffer->end) = *(char *)what_to_add;
		c_buffer->end = (c_buffer->end + 1) % c_buffer->capacity;
		what_to_add = (char *)(what_to_add) + 1;
		--count;
		++counter;
		
		if(c_buffer->end  == c_buffer->start)
		{
			*(c_buffer->buffer + c_buffer->capacity) = FULL;
			break;
			
		}
	}
	
	if(0 == counter)
	{
		return (NO_ACTION_MADE);
	}
	
	return (counter);
	

}

ssize_t CBuffRead(cbuff_t *c_buffer, void *dest, size_t count)
{

	char *what_t_read = (char *)dest;
	ssize_t counter = 0;
	
	assert(NULL != c_buffer);
	assert(NULL != dest);
	assert(0 != count);
	
	if((c_buffer->end  == c_buffer->start) && (EMPTY == *(c_buffer->buffer + c_buffer->capacity)))
	{
			return (NO_ACTION_MADE);
	}
	
	*(c_buffer->buffer + c_buffer->capacity) = EMPTY;
	
	while(0 != count)
	{
		
		*what_t_read = *(c_buffer->buffer + c_buffer->start);
		c_buffer->start = (c_buffer->start + 1) % c_buffer->capacity;
		
		++what_t_read;
		--count;
		++counter;
		
		if(c_buffer->end  == c_buffer->start)
		{
			*(c_buffer->buffer + c_buffer->capacity) = EMPTY;
			break;
		}
	}
	
	if(0 == counter)
	{
		return (NO_ACTION_MADE);
	}
	
	return (counter);
	
}



size_t CBuffFreeSpace(const cbuff_t *c_buffer)
{
	int size = 0;
	
	assert(NULL != c_buffer);
	
	if(FULL == *(c_buffer->buffer + c_buffer->capacity))
	{
		return NO_SPACE;
	}
	
	if(c_buffer->start > c_buffer->end)
	{
		return c_buffer->start - c_buffer->end; 
	}
	
	size = c_buffer->end - c_buffer->start;
	
	if(0 > size)
	{
		size *= -1;
	}
	
	return (c_buffer->capacity - (size_t)size);

}

size_t CBuffCapacity(const cbuff_t *c_buffer)
{
	assert(NULL != c_buffer);
	
	return (c_buffer->capacity);
}

int CBuffIsEmpty(const cbuff_t *c_buffer)
{

	assert(NULL != c_buffer);

	return ((c_buffer->start == c_buffer->end) && (EMPTY == *(c_buffer->buffer + c_buffer->capacity)));
}

cbuff_t *CBuffCreate(size_t capacity)
{
	cbuff_t *cbuffer = NULL;
	
	assert(0 != capacity);
	
	cbuffer = (cbuff_t *)malloc(sizeof(cbuff_t) + capacity + 1);
	
	if(NULL == cbuffer)
	{
		return NULL;
	}
	
	cbuffer->capacity = capacity;
	cbuffer->start = 0;
	cbuffer->end = 0;
	
	*(cbuffer->buffer + cbuffer->capacity) = EMPTY;
	
	cbuffer->start %= cbuffer->capacity;
	cbuffer->end %= cbuffer->capacity;
	
	return (cbuffer);
}




void CBuffDestroy(cbuff_t *c_buffer)
{
	assert(NULL != c_buffer);
	
	free(c_buffer);
	
	c_buffer = NULL;
}
