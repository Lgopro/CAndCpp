
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include <string.h>

#define SUCCESS 0
#define FAIL 1
#define CHANGE 0
#include <stdio.h>
#include <string.h>

typedef struct int_array
{
    int *arr;
    int *counter;
} int_array_t;

static int flag_counter = 0;
static int global_val = 0;

void SetVal(int_array_t *array, int indx, int val)
{
    assert(array);
    array->arr[indx] = val;
    ++array->counter[indx];
}

int GetVal(int_array_t *array, int indx)
{
    assert(array);
    if (flag_counter > array->counter[indx])
    {
        return (global_val);
    }
    return (array->arr[indx]);
}

void SetAll(int_array_t *array, int val)
{
    assert(array);
    global_val = val;
    ++flag_counter;
}
