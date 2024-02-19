#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include "dlist.h"
#define SUCCESS 0
#define FAIL 1

void SumOfTwo(unsigned int *arr, unsigned int *result_array, unsigned int find, size_t size);

int main()
{
    unsigned int arr[] = {1,4,0, 3, 5, 1, 4};  
    unsigned int arr1[2] = {0};   
    SumOfTwo(arr, arr1, 4, 7);
    printf("num1 is %d and num2 is %d\n", arr1[0], arr1[1]);
    return 0;

}

void SumOfTwo(unsigned int *arr, unsigned int *result_array, unsigned int find, size_t size)
{
    unsigned int num_to_find = 0;
    size_t i = 0;
    size_t j = 0;
    assert(arr);
    assert(result_array);

    for(i = 0; i < size - 1; ++i)
    {
        if(arr[i] > find)
        {
            continue;
        }
        num_to_find = find - arr[i];
        for(j = i + 1; j < size; ++j)
        {
            if(num_to_find == arr[j])
            {
                result_array[0] = arr[i];
                result_array[1] = num_to_find;
                return;
            }
        }
    }
}