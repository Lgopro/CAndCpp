#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t UniqueElements(int *arr, size_t size, int *unique)
{
    size_t counter = 0;
    size_t return_counter = 0;

    assert(arr);
    assert(unique);

    for(size_t i = 0;i < size; ++i)
    {
        counter = 0;
        for(size_t j = 0; j < size; ++j)
        {
            if(i == j && i == size - 1 && counter == 0)
            {
                unique[return_counter] = arr[i];
                ++return_counter;
            }
            else if(i == j)
            {
                continue;
            }
            else if(arr[i] == arr[j])
            {
                ++counter;
            }

            if(j == size - 1 && counter == 0)
            {
                unique[return_counter] = arr[i];
                ++return_counter;
            }
        }
    }
    return return_counter;
}

int main()
{
    int *arr = (int *)malloc(sizeof(int) * 10);
    int *unique = (int *)malloc(sizeof(int) * 10);

    arr[0] = 3;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 6;
    arr[4] = 3;
    arr[5] = 2;
    arr[6] = 1;
    arr[7] = 8;
    arr[8] = 3;
    arr[9] = 5;
    

    size_t result = UniqueElements(arr, 10, unique);
    printf("There are %ld numbers\nThe numbers are: ", result);
    for(size_t i = 0; i < result; ++i)
    {
        printf("%d ", unique[i]);
    }
    printf("\n");
    return 0;
}