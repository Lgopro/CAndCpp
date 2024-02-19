#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define NO_ROTATION_NEEDED (0)
size_t HowMuchTimesRotated(int *arr, size_t size);

int main()
{
    size_t result = 0;
	int arr[] = {7, 8, 11, 15, 55,  1, 4, 5};
    int arr1[] = {7, 8, 55,  1, 4, 5};
    result = HowMuchTimesRotated(arr, 8);
    printf("The result is %ld\n", result);
    result = HowMuchTimesRotated(arr1, 6);
    printf("The result is %ld\n", result);
	return 0;
}

size_t HowMuchTimesRotated(int *arr, size_t size)
{
    size_t i = 0;
    
    assert(arr);
    assert(0 < size);

    for(i = 1;i < size; ++i)
    {
        if(*(arr + i) < *(arr + i - 1))
        {
            return (i);
        }
    }
    return (NO_ROTATION_NEEDED);
}