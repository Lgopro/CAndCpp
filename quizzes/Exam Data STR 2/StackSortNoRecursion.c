#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

void StackToSort(stack_t * to_sort, stack_t *sorted)
{
    int temp_val = 0;

    while(0 != StackSize(to_sort))
    {
        temp_val = *(int *)StackPeek(to_sort);
        StackPop(to_sort);

        while(0 != StackSize(sorted) && *(int *)StackPeek(sorted) < temp_val)
        {
            StackPush(to_sort, StackPeek(sorted));
            StackPop(sorted);

        }
        StackPush(sorted, &temp_val);
    }
    

}


int main()
{
	stack_t *before_sort = NULL;
    stack_t *after_sort = NULL;
    size_t i = 0;
    size_t size = 0;
    int a = 5;
    int b = 2;
    int c = -1;
    int d = 10; 
    int e = -2;
	before_sort = StackCreate(10, 4);
    after_sort = StackCreate(10, 4);
    StackPush(before_sort , &a);
    StackPush(before_sort , &b);
    StackPush(before_sort , &c);
    StackPush(before_sort , &d);
    StackPush(before_sort , &e);
    size = StackSize(before_sort);
    StackToSort(before_sort, after_sort);
    for(i = 0; i < size; ++i)
    {
        printf("Value is: %d\n", *(int *)StackPeek(after_sort));
        StackPop(after_sort);
    }

    free(before_sort);
    free(after_sort);
	return 0;
}