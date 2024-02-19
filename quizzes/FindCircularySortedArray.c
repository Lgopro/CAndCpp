#include <stdio.h> /*printf*/
#include <assert.h> /*assert*/



void FindCircularIntArray(int *arr, int size, int num_to_find);

int main()
{
	int arr[] = {9, 11, 44, 66, 1, 3, 4, 6, 7};
	int size = 9;
	FindCircularIntArray(arr, size, 2);
	FindCircularIntArray(arr, size, 11);
	FindCircularIntArray(arr, size, 44);
	FindCircularIntArray(arr, size, 5);
	FindCircularIntArray(arr, size, 67);
	return 0;
}


void FindCircularIntArray(int *arr, int size, int num_to_find)
{
	int i = 0;
	assert(arr);
	assert(0 < size);
	i = size - 1;
	
	while(0 <= i)
	{
		if(*(arr + i) == num_to_find)
		{
			printf("Element found at index %d\n", i);
			return;
		}
		if(*(arr + i) < *(arr + i - 1) && num_to_find > *(arr + i - 1))
		{
			return;
		}
		--i;
	}
	printf("No Element is found\n");
}
