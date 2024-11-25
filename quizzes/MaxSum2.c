#include <stdio.h>
#include <assert.h>

int MaxSubArray(int* arr, size_t size, int *begin_loc, int *end_loc)
{   
    assert(arr);
    assert(begin_loc);
    assert(end_loc);

    int sum = 0;
    int max_sum = 0;
    int begin = 0;
    int end = 0;

    while((size_t)end < size)
    {
        sum += arr[end];

        if(sum > max_sum)
        {
            *begin_loc = begin;
            *end_loc = end;
            max_sum = sum;
        }

        if(sum < 0)
        {
            sum = 0;
            begin = end + 1;
            end = begin;
            continue;
        }

        ++end;
    }

    return max_sum;
}

int main()
{
    int begin = 0;
    int end = 0;
    int arr[] = {-2, -1, -3, 4, -1, 2, 3,-5, 4};
    int result = MaxSubArray(arr, sizeof(arr)/sizeof(int), &begin, &end);

    printf("The result is %d and the begin is in the location %d of the array and the end is in %d of the array\n", result, begin, end);
    return 0;
}