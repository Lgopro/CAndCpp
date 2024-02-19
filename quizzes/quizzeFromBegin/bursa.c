
#include "stdio.h"
#include <assert.h>

void Bursa(int *arr, size_t size, int *begin, int *end)
{

    int sum = 0;
    int max_sum = 0;
    int min = 0;
    int max = 1;

    assert(arr);
    assert(begin);
    assert(end);

    while(max != size)
    {
        if(arr[min] < arr[max])
        {
            sum = arr[max] - arr[min];
            if(max_sum < sum)
            {
                max_sum  = sum;
                *begin = min;
                *end = max;
            }
        }
        else
        {
            min = max; 
        }
        ++max;
    }

}

int main()
{
    int arr[] = {6, 12,3, 5, 1, 4, 9, 2};
    int begin = 0;
    int end = 0;

    Bursa(arr, sizeof(arr)/sizeof(int), &begin, &end);

    printf("buy index is %d, sell index is %d. The profit is: %d\n", begin, end, arr[end] - arr[begin]);
    
    return 0;
}