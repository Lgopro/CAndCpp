
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/



long *SumIntPairsToLongs(int ints[], size_t numOfElement);




int main()
{	
	int arr[] = {1, 6, 456, -3, 8, 12};
	size_t size = 6;
	size_t i = 0;
	long *longarr = NULL;
	long *begin = NULL;
	
	longarr = SumIntPairsToLongs(arr, size);
	begin = longarr;
	for(i = 0; i < size / 2; ++i)
	{
		printf("Its %ld ", *longarr);
		++longarr;
	
	}
	free(begin);
	return 0;
}



long *SumIntPairsToLongs(int ints[], size_t numOfElement)
{
	size_t i = 0;
	long *arr = (long *)malloc(sizeof(long) * numOfElement / 2);
	long *begin = arr;
	
	assert(NULL != ints);
	assert(0 == numOfElement % 2);
	
	for(i = 0; i < numOfElement; i += 2)
	{
		*begin = (long)*(ints +i) + (long)*(ints + i + 1);
		++begin;
	}
	return arr;
}

