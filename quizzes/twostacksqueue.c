







#include <stdio.h> /*printf*/
#include <stdlib.h>
#include <assert.h>


#include "Stack.h"

void Enqueue(stack_t *insert, const void *value);
void Dequeue(stack_t *insert, stack_t *pop);


int main()
{
	stack_t *stack_front;
	stack_t *stack_back;
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	
	
	
	stack_front = StackCreate(20, 4);
	stack_back = StackCreate(20, 4);
	
	
	Enqueue(stack_front, (const void *)&val1);
	Enqueue(stack_front, (const void *)&val2);
	Enqueue(stack_front, (const void *)&val3);
	Enqueue(stack_front, (const void *)&val4);
	Enqueue(stack_front, (const void *)&val5);
	
	Dequeue(stack_front, stack_back);
	
	if(4 == StackSize((const stack_t *)stack_back) && 2 == *(int *)StackPeek((const stack_t *)stack_back))
	{
		printf("Test pass\n");
	}
	else
	{
		printf("Test fail\n");
		printf("size is %ld\n", StackSize((const stack_t *)stack_back));
		printf("peek is %d\n", *(int *)StackPeek((const stack_t *)stack_back));
	}
	free(stack_front);
	free(stack_back);
	
	return 0;
}






/***********************************************************************/
/*
Description: Push the value to the back of the queue.
Arguments: Valid pointers to queue and value.
Return: 0 on success and 1 on fail.
Time complexity: O(1)
Space complexity: O(1)
*/
void Enqueue(stack_t *insert, const void *value)
{
	assert(NULL != insert);
	assert(NULL != value);
	
	StackPush(insert, value);
	
	
}

/***********************************************************************/
/*
Description: Pop the front of the queue.
Arguments: Valid pointet to a queue.
Return: Void.
Time complexity: O(1)
Space complexity: O(1)
*/
void Dequeue(stack_t *insert, stack_t *pop)
{
	void *value = NULL;
	
	assert(NULL != insert);
	assert(NULL != pop);
	if(0 != StackSize((const stack_t *)pop))
	{
		StackPop(pop);
		return;
	
	}
	while(0 != StackSize((const stack_t *)insert))
	{
		value = StackPeek((const stack_t *)insert);
		StackPop(insert);
		StackPush(pop, (const void *)value);
	}
	StackPop(pop);
}
