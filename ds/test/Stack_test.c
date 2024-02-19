/*
Rev: Yaron Margalit
Dev: Leonid Golovko
status: finished
date:19/04/23
*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/

#include "Stack.h"

/*struct Stack
{
    size_t size;
    size_t capacity;
    size_t element_size;
    char *SP;
};*/

void StackCreateAndDestroyTest();

void StackPushTest();

void StackPopTest();

void StackPeekTest();

void StackIsEmptyTest();

void StackSizeTest();

void StackCapacityTest();


int main()
{	
	StackCreateAndDestroyTest();
	StackCapacityTest();
	StackSizeTest();
	StackIsEmptyTest();
	StackPushTest();
	StackPopTest();
	StackPeekTest();
	return 0;
}

void StackPeekTest()
{
	stack_t *stack;

	void *result = NULL;
	void *result1 = NULL;
	
	int a = 8;
	int b = 9;
	stack = StackCreate(20, 4);
	StackPush(stack, (const void *)&a);
	StackPush(stack, (const void *)&b);
	result = StackPeek((const stack_t *)stack);
	StackPop(stack);
	result1 = StackPeek((const stack_t *)stack);
	if(9 == *(int *)result && 8 == *(int *)result1)
	{
		printf("Test StackPeekTest pass\n");
	}
	else
	{
		printf("Test StackPeekTest fail\n");
	}
	StackDestroy(stack);


}
void StackPopTest()
{
	stack_t *stack;
	size_t i = 0;
	void * result = NULL;
	char word[]= "Hello World";
	stack = StackCreate(20, 1);
	while(i < strlen(word))
	{
		StackPush(stack, (const void *)&word[i]);
		++i;
	}
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	result = StackPeek(stack);
	if('o' == *(char *)result && 8 == StackSize(stack))
	{
		printf("Test StackPopTest pass\n");
	}
	else
	{
		printf("Test StackPopTest fail\n");
	}
	StackDestroy(stack);
}
void StackPushTest()
{
	stack_t *stack;
	size_t i = 0;
	void * result = NULL;
	char word[]= "Hello World";
	stack = StackCreate(20, 1);
	while(i < strlen(word))
	{
		StackPush(stack, (const void *)&word[i]);
		++i;
	}
	result = StackPeek(stack);
	if('d' == *(char *)result && 11 == StackSize(stack))
	{
		printf("Test StackPopTest pass\n");
	}
	else
	{
		printf("Test StackPopTest fail\n");
	}
	StackDestroy(stack);
}


void StackCreateAndDestroyTest()
{
	stack_t *stack;
	stack = StackCreate(20, 1);
	if(0 == StackSize(stack) && 20 == StackCapacity(stack) && NULL != stack)
	{
		printf("Test StackCreateTest pass\n");
	}
	else
	{
		printf("Test StackCreateTest fail\n");
	}
	StackDestroy(stack);
}


void StackCapacityTest()
{
	stack_t *stack;
	stack = StackCreate(20, 1);
	
	if(20 == StackCapacity(stack))
	{
		printf("Test StackCapacityTest pass\n");
	}
	else
	{
		printf("Test StackCapacityTest fail\n");
	}
	StackDestroy(stack);


}

void StackSizeTest()
{
	stack_t *stack;
	char ch = 'a';
	stack = StackCreate(20, 1);
	if(0 == StackSize(stack))
	{
		
		StackPush(stack, (const void *)&ch);
		
		if(1 == StackSize(stack))
		{
			
			StackPop(stack);
		
			if(0 == StackSize(stack))
			{
				printf("Test StackSizeTest pass\n");
			
			}
		}
		
	}
	else
	{
		printf("%ld\n", StackSize(stack));
		printf("Test StackSizeTest fail\n");
	}
	StackDestroy(stack);


}

void StackIsEmptyTest()
{

	stack_t *stack;
	char ch = 'a';
	stack = StackCreate(20, 1);
	if(1 == StackIsEmpty(stack))
	{
		
		StackPush(stack, (const void *)&ch);
		
		if(0 == StackIsEmpty(stack))
		{
			
			StackPop(stack);
		
			if(1 == StackIsEmpty(stack))
			{
				printf("Test StackIsEmptyTest pass\n");
			
			}
		}
		
	}
	else
	{
		
		printf("Test StackIsEmptyTest fail\n");
	}
	StackDestroy(stack);
}

