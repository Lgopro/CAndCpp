#include <stdio.h> /*printf*/
#include <assert.h> /*assert*/
#include "Stack.h"
#define SUCCESS 0
#define FAIL 1

int CheckStackParenthess(char *arr, stack_t *stack);

int main()
{
	char *arr = "[]{()}";
	char *arr1 = "[]{(()(}))";
	int status = 0;
	int status1 = 0;
	stack_t *stack = StackCreate(20, 1);
	status = CheckStackParenthess(arr, stack);
	status1 = CheckStackParenthess(arr1, stack);
	if(1 == status1 && 0 == status)
	{
		printf("stack pass\n");
	}
	else
	{
		printf("fail\n");
		printf("arr is %d\n", status);
		printf("arr1 is %d\n", status1);
	}
	return 0;
}




int CheckStackParenthess(char *arr, stack_t *stack)
{

	char *runner = NULL;
	
	assert(NULL != arr);
	
	runner = arr;
	
	while('\0' != *runner)
	{
		if('(' == *runner || '[' == *runner || '{' == *runner || '<' == *runner)
		{
			StackPush(stack, runner);
		}
			else if(')' == *runner)
			{
				if('(' == *(char *)StackPeek(stack))
				{
					StackPop(stack);
				}
				else
				{
					return (FAIL);
				}
			}
			else if(']' == *runner)
			{
				if('[' == *(char *)StackPeek(stack))
				{
					StackPop(stack);
				}
				else
				{
					return (FAIL);
				}
			}
			else if('}' == *runner)
			{
				if('{' == *(char *)StackPeek(stack))
				{
					StackPop(stack);
				}
				else
				{
					return (FAIL);
				}
			}
			else if('>' == *runner)
			{
				if('<' == *(char *)StackPeek(stack))
				{
					StackPop(stack);
				}
				else
				{
					return (FAIL);
				}
			}
		
		++runner;
	}
	if(0 != StackSize(stack))
	{
		return FAIL;
	}
	
	return SUCCESS;
}