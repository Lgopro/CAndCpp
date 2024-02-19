
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/
#include <assert.h>

#include "Stack.h"


int IsNumInArray(int number, int *arr, size_t size);




int main()
{	
	int number = 6;
	int arr[]={1, 3, 6, 4, 6, 7};
	int result = 0;
	
	result = IsNumInArray(number, arr, 6);

	if(0 == result)
	{
		printf("Number %d is in the array\n", number);
	
	}
	else
	{
		printf("Number %d is not in the array\n", number);
	
	}
	return 0;
}



int IsNumInArray(int number, int *arr, size_t size)
{
	size_t counter = 0;
	int result = 1;
	
	assert(NULL != arr);
	assert(0 != size);
	
	
	while(counter != size)
	{
		result =result * (number ^ *arr);
		++arr;
		++counter;
		
	}
	return result;

}

