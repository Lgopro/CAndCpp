/*
Rev: Yaron Margalit
Dev: Leonid Golovko
status: finished
date:19/04/23
*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/

#include "Stack.h"

struct Stack
{
    size_t size;
    size_t capacity;
    size_t element_size;
    char *sp;
};




stack_t *StackCreate(size_t capacity, size_t element_size)
{
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
	if(NULL == stack)
	{
		return NULL;
	}
	stack->sp = (char *)malloc(sizeof(char) * capacity * element_size + 1);
	if(NULL == stack->sp)
	{
		free(stack);
		return NULL;
	}
	stack->size = 0;
	stack->capacity = capacity;
	stack->element_size = element_size;
	return stack;
}

void StackDestroy(stack_t *my_stack)
{
	assert(NULL != my_stack);
	
	free(my_stack->sp);
	free(my_stack);
	my_stack = NULL;
}

void StackPush(stack_t *my_stack, const void *element)
{
	size_t location = my_stack->element_size * my_stack->size;
	char *start = my_stack->sp;
	size_t counter = 0;
	
	assert(NULL != my_stack);
	assert(NULL != element);
	assert(my_stack->size != my_stack->capacity);
	
	start = start + location;
	while(counter < my_stack->element_size && my_stack->capacity != my_stack->size)
	{
		*start = *(char *)element;
		++start;
		element = (char *)element + 1;
		++counter;
	}
	++my_stack->size;

}

void StackPop(stack_t *my_stack)
{
	assert(NULL != my_stack);
	
	if(0 < my_stack->size)
	{
		--my_stack->size;
	}
		
}
void *StackPeek(const stack_t *my_stack)
{
	size_t location = my_stack->element_size * my_stack->size;
	char *start = my_stack->sp;
	
	assert(NULL != my_stack);
	
	if(0 == my_stack->size)
	{
		return NULL;
	
	}
	start = start + location - my_stack->element_size;
	return (void *)start;
	
	

}
int StackIsEmpty(const stack_t *my_stack)
{
	assert(NULL != my_stack);
	return (0 == my_stack->size) ? 1 : 0;

}
size_t StackSize(const stack_t *my_stack)
{
	assert(NULL != my_stack);
	return my_stack->size;

}
size_t StackCapacity(const stack_t *my_stack)
{
	assert(NULL != my_stack);
	return my_stack->capacity;
}
