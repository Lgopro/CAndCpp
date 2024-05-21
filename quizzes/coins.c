
#include <stdio.h>
#include <assert.h>

#define ERROR -1

int MinCoins(int N, int *denominations, int size)
{
    int counter = 0;

    assert(denominations);

    while(N != 0)
    {
        if(denominations[size - 1] > N)
        {
            --size;
        }
        else
        {
            N -= denominations[size - 1];
            ++counter;
        }
        if(size == 0)
        {
            break;
        }

        
    }

    if(N == 0)
    {
        return counter;
    }


    return ERROR;
}

int lengthOfLIS(int* nums, int numsSize)
{
    
}

int main()
{
    int arr[] = {4, 7};
    int result = MinCoins(27, arr, sizeof(arr)/sizeof(int));

    if(result == ERROR)
    {
        printf("Error\n");
    }
    else
    {
        printf("Result is %d\n", result);
    }
    return 0;
}