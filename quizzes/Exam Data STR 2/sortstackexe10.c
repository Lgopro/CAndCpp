#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"


void stack_insert(stack_t *stack, void *value)
{
    int data = 0;

    assert(stack);
    assert(value);

    if(0 == StackSize(stack))
    {
        StackPush(stack, value);
        return;
    }
    data = *(int *)StackPeek(stack);
    if(data >= *(int *)value)
    {
        StackPush(stack, value);
        return;
    }
    else
    {
        StackPop(stack);
        stack_insert(stack, value);
        StackPush(stack, &data);
    }
}


int main()
{
	stack_t *result = NULL;
    size_t i = 0;
    size_t size = 0;
    int a = 5;
    int b = 2;
    int c = -1;
    int d = 10; 
    int e = -2;
	result = StackCreate(10, 4);
    stack_insert(result , &a);
    stack_insert(result , &b);
    stack_insert(result , &c);
    stack_insert(result , &d);
    stack_insert(result , &e);
    size = StackSize(result);
    for(i = 0; i < size; ++i)
    {
        printf("Value is: %d\n", *(int *)StackPeek(result));
        StackPop(result);
    }

    free(result);
	return 0;
}