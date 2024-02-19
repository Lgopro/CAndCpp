
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/
#include <assert.h>

#include "Stack.h"
#define FAIL (1)
#define SUCCESS (0)

typedef struct MyArr
{
	stack_t *stack;
	stack_t *min_stack;
	
}my_arr;

int MinVar(my_arr *arr);
void ArrDestroy(my_arr *arr);
void ArrPop(my_arr *arr);
void ArrPush(my_arr *arr, const void *element);
my_arr *ArrCreate(size_t capacity, size_t element_size);
void StackMinTest();


int main()
{	
	StackMinTest();
	return 0;
}

void StackMinTest()
{
	my_arr *arr_min = NULL;

	int min = 0;
	
	int a = 8;
	int b = 9;
	int c = 22;
	int d = 12;
	int e = -1;
	arr_min = ArrCreate(20, 4);
	ArrPush(arr_min, (const void *)&a);
	ArrPush(arr_min, (const void *)&b);
	ArrPush(arr_min, (const void *)&c);
	ArrPush(arr_min, (const void *)&d);
	ArrPush(arr_min, (const void *)&e);
	min = MinVar(arr_min);
	printf("min is: %d\n", min);
	ArrPop(arr_min);
	min = *(int *)StackPeek((const stack_t *)arr_min->min_stack);
	printf("min is: %d\n", min);
	ArrDestroy(arr_min);


}

my_arr *ArrCreate(size_t capacity, size_t element_size)
{
	my_arr *arr = (my_arr*)malloc(sizeof(my_arr));
	if(NULL == arr)
	{
		return NULL;
	}
	arr->stack = StackCreate(capacity, element_size);
	arr->min_stack = StackCreate(capacity, element_size);
	return arr;
}

void ArrDestroy(my_arr *arr)
{
	assert(NULL != arr);
	StackDestroy(arr->stack);
	StackDestroy(arr->min_stack);
	free(arr);
}


int ArrPush(my_arr *arr, const void *element)
{
	assert(NULL != arr);
	assert(NULL != element);
	if(StackSize(arr->stack) == StackCapacity(arr->stack))
	{
		return (FAIL);
	}
	StackPush(arr->stack, element);
	if( 0 == StackSize(arr->min_stack) || *(int *)element < *(int *)StackPeek(arr->min_stack))
	{
		StackPush(arr->min_stack, element);
	}
	return (SUCCESS);
}

void ArrPop(my_arr *arr)
{
	assert(NULL != arr);
	if(*(int *)StackPeek(arr->min_stack) == *(int *)StackPeek(arr->stack))
	{
		StackPop(arr->min_stack);
	}
	StackPop(arr->stack);
}


int MinVar(my_arr *arr)
{
	assert(NULL != arr);
	return *(int *)StackPeek(arr->min_stack);
	
}


