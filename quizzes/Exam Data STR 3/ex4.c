#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include <string.h>
#include "dlist.h"
#define SUCCESS 0
#define FAIL 1

#include <stdio.h>
#include <string.h>

int ShiftRight(char *array, size_t shift) 
{
    int len = strlen(array);
    char *left_side = NULL;
    char *right_side = NULL;
    size_t i = 0;

    assert(array);

    left_side = (char *)malloc(sizeof(strlen(array) + 1));
    if(NULL == left_side)
    {
        return (FAIL);
    }
    right_side = (char *)malloc(sizeof(strlen(array) + 1));
    if(NULL == right_side)
    {
        return (FAIL);
    }
    
    for (i = len - 1; i >= shift; --i) 
    {
        right_side[i] = array[i - shift];
    }

    for (i = 0; i < shift; ++i) 
    {
        left_side[i] = array[len - shift + i];
    }

    for(i = 0; i < shift; ++i)
    {
        array[i] = left_side[i];
    }

    for(i = shift; i <= strlen(array) - 1; ++i)
    {
        array[i] = right_side[i];
    }
    free(left_side);
    free(right_side);
    return (SUCCESS);
}

int main() {
    char arr[] = "Hello, World!";
    size_t shiftPositions = 3;

    printf("Original array: %s\n", arr);
    ShiftRight(arr, shiftPositions);
    printf("Shifted array: %s\n", arr);

    return 0;
}


