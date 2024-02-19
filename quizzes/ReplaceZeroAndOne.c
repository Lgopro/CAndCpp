#include <stddef.h> /* size_t */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


static void Swap(int *var1, int *var2);
void ReplaceOneAndZero(int *arr, size_t size , int *array_to_help);

int main()
{
    size_t i = 0;
	int arr[] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    int arr1[sizeof(arr)/sizeof(int)] = {0};
    ReplaceOneAndZero(arr, sizeof(arr)/sizeof(int), arr1);
    for(i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        printf("%d ", arr[i]);
    }

	return 0;
}

void ReplaceOneAndZero(int *arr, size_t size , int *array_to_help)
{
    size_t i = 0;
    size_t index_to_swap = 0;

    assert(arr);
    assert(0 < size);
    assert(array_to_help);

    index_to_swap = size - 1;

    for(i = 0; i < size; ++i)
    {
        if(1 == arr[i])
        {
             Swap((array_to_help + index_to_swap), &arr[i]);
             --index_to_swap;
        }
    }

    for(i = 0; i < size; ++i)
    {
        arr[i] = *(array_to_help + i);
    }
}

static void Swap(int *var1, int *var2)
{
    int temp = 0;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}