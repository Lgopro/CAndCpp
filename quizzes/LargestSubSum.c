#include "stdio.h"
#include "assert.h"

int SubArraySum(int *arr, size_t size, size_t *m_begin, size_t *m_end)
{
    int sum = 0;
    int max_sum = 0;
    size_t begin = 0;
    size_t end = 0;
    int *arr_begin = NULL;

    assert(arr);

    arr_begin = arr;

    while(end != size)
    {
        sum += *arr_begin;
        if(sum < 0)
        {
            begin = end;
            sum = 0;
        }
        else if(sum > max_sum)
        {
            max_sum = sum;
            *m_begin = begin;
            *m_end = end;
        }
        ++arr_begin;
        ++end;
    }
    return max_sum;
}


int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    size_t begin = 0;
    size_t end = 0;
    int result = SubArraySum(arr, sizeof(arr)/sizeof(int), &begin, &end);
    printf("The result is %d with the begin at %ld and end at %ld\n",  result , begin, end);
    return 0;
}