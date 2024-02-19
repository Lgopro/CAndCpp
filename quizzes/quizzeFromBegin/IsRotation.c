
#include "stdio.h"
#include <assert.h>

#define PASS 0
#define FAIL 1


int IsRotation(int *arr_to_test, int *arr_full, size_t size_arr_to_test, size_t size_arr_full)
{
    size_t i = 0;
    size_t j = 0;
    size_t counter = 0;

    assert(arr_to_test);
    assert(arr_full);
    
    for(i = 0;i < size_arr_full; ++i)
    {
        counter = 0;
        if(arr_full[i] == arr_to_test[0])
        {
            for(j = 0; j < size_arr_to_test; ++j)
            {
                if(arr_full[(i + j) % size_arr_full] == arr_to_test[j])
                {
                    ++counter;
                }
            }
            if(counter == size_arr_to_test)
            {
                return PASS;
            }
        } 
    }

    return FAIL;
}

int main()
{
    int array_full[] = {4, 3, 5, 1, 4, 5, 2, 6, 2, 1};
    int array_test[] = {1, 4, 3, 5, 1, 4};
    int array_test1[] = {1, 4, 3, 4, 4, 5};

    int result1 = 0;
    int result2 = 0;

    result1 = IsRotation(array_test, array_full, sizeof(array_test)/sizeof(int), sizeof(array_full)/sizeof(int));
    if(result1 == PASS)
    {
        printf("Its pass\n");
    }
    else
    {
        printf("Its fail\n");
    }
    result2 = IsRotation(array_test1, array_full, sizeof(array_test1)/sizeof(int), sizeof(array_full)/sizeof(int));
    if(result2 == PASS)
    {
        printf("Its pass\n");
    }
    else
    {
        printf("Its fail\n");
    }
    return 0;
}