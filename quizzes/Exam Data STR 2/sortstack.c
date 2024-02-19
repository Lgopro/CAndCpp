
#define SUCCESS 0
#define FAIL 1

#include <stdio.h> /*assert*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*free*/

#include "Stack.h"

stack_t *StackSort(stack_t *to_sort);

int main()
{
	stack_t *result = NULL;
    int a = 5;
    int b = 2;
    int c = -1;
    int d = 10; 
    int e = -2;
	result = StackCreate(10, 4);
    StackPush(result , &a);
    StackPush(result , &b);
    StackPush(result , &c);
    StackPush(result , &d);
    StackPush(result , &e);
    result = StackSort(result);
    free(result);
	return 0;
}

stack_t *StackSort(stack_t *to_sort)
{
    stack_t *help_stack = NULL;
    int sort_temp = 0;
    int help_temp = 0;
    assert(to_sort);
    help_stack = StackCreate(10, 4);
    if(NULL == help_stack)
    {
        return NULL;
    }
    while(0 != StackSize(to_sort))
    {
        if(0 == StackSize(help_stack))
        {
            sort_temp = *(int *)StackPeek(to_sort);
            StackPop(to_sort);
            StackPush(help_stack ,&sort_temp);
        }
        else
        {
            sort_temp = *(int *)StackPeek(to_sort);
            help_temp = *(int *)StackPeek(help_stack);
            if(help_temp >= sort_temp)
            {
                StackPop(to_sort);
                StackPush(help_stack, &sort_temp);
            }
            else
            {
                while(0 != StackSize(help_stack) && *(int *)StackPeek(help_stack) < *(int *)StackPeek(to_sort))
                {
                    StackPush(to_sort, StackPeek(help_stack));
                    StackPop(help_stack);
                }
                StackPush(help_stack, &sort_temp);
            }
        }
    }
    return (help_stack);
}
