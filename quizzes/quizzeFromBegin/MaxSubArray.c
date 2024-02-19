

#include "stdio.h"
#include <assert.h>


int MaxSubArray(int *array, int *begin, int *end, size_t size)
{
    int start = 0;
    int finish = 0;

    int sum = 0;
    int max_sum = 0;

    assert(array);
    assert(begin);
    assert(end);

    while(finish != size)
    {
        sum += array[finish];

        if(sum < 0)
        {
            ++finish;
            start = finish;
            sum = 0;
        }
        else if(sum > max_sum)
        {
            max_sum = sum;
            *begin = start;
            *end = finish;
            ++finish;
        }
        else
        {
            ++finish;
        }
    }
    return max_sum;
}

int main()
{
    int array_full[] = {-2, 1, -3, 4, -1, 2, 3, -5, 4};

    int begin = 0;
    int end = 0;

    int result1 = 0;
    int result2 = 0;

    result1 = MaxSubArray(array_full, &begin, &end, sizeof(array_full)/sizeof(int));
    printf("The max sum is: %d\n The numbers are %d and %d\n", result1, begin, end);

    for(size_t i = 0; i < sizeof(array_full)/sizeof(int) ; ++i)
    {
        printf("%d ", array_full[i]);
    }
    printf("\n");
    return 0;
}