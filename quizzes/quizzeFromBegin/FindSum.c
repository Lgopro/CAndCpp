
#include "stdio.h"
#include <assert.h>

void FindSumInArray(int *arr, size_t size, int sum_to_fun, int *var1, int *var2)
{
    int i = 0;
    size_t begin = 0;
    size_t end = 0;

    assert(arr);
    assert(var1);
    assert(var2);

    end = size - 1;

    while(begin != end)
    {
        if(sum_to_fun == arr[begin] + arr[end])
        {
            *var1 = begin;
            *var2 = end;
            return;
        }
        else if(sum_to_fun > arr[begin] + arr[end])
        {
            ++begin;
        }
        else
        {
            --end;
        }
    }

    *var1 = -1;
    *var2 = -1;
    return;
}


int main()
{
    int arr[] = {1, 6,7,8,9,11,15};
    int begin = 0;
    int end = 0;
    int sum = 17;

    FindSumInArray(arr, 7, sum, &begin, &end);
    if(begin == 0 && end == 0)
    {
        printf("No sum found\n");
    }
    else
    {
        printf("The number to find is %d. The array locations are %d and %d\n", sum, begin, end);
        printf("The number to find is %d. The array numbers at the locations are %d and %d\n", sum, arr[begin],arr[end]);
    }

    sum = 25;
    FindSumInArray(arr, 7, sum, &begin, &end);
    if(begin == -1 && end == -1)
    {
        printf("No sum found\n");
    }
    else
    {
        printf("The number to find is %d. The array locations are %d and %d\n", sum, begin, end);
        printf("The number to find is %d. The array numbers at the locations are %d and %d\n", sum, arr[begin],arr[end]);
    }

    return 0;
}