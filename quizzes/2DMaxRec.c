#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void Biggest2D(int **array, size_t x, size_t y, int number, size_t *x_begin, size_t *y_begin, size_t *x_end, size_t *y_end)
{
    int sum = 0;
    int diff = number;
    assert(array);

    for(size_t i = 0; i < y; ++i)
    {
        for(size_t j = 0; j < x; ++j)
        {
            sum = 0;
            for(size_t k = i; k < y; ++k)
            {
                for(size_t z = j; z < x; ++z)
                {
                   sum += array[k][z];
                   if(number - sum < diff)
                   {
                        diff = number - sum;
                        *x_begin = j;
                        *y_begin = i;
                        *x_end = z;
                        *y_end = k;
                   }
                }
            }
        }
    }
}



int main()
{
    size_t y = 3;
    size_t counter = 1;

    size_t x_begin = 0;
    size_t y_begin = 0;
    size_t y_end = 0;
    size_t x_end = 0;

    int **sum_array = (int **)malloc(sizeof(int *) * 3);
    for(size_t i = 0; i < y; ++i)
    {
        sum_array[i] = (int *)malloc(sizeof(int) * 3);
    }
    for(size_t i = 0; i < y; ++i)
    {
        for(size_t j = 0; j < y; ++j)
        {
            sum_array[i][j] = counter;
            ++counter;
        }
    }
    Biggest2D(sum_array, 3, 3, 33, &x_begin, &y_begin, &x_end, &y_end);

    for(size_t y = y_begin; y < y_end; ++y)
    {
        printf("\n");
        for(size_t x = x_begin; x < x_end; ++x)
        {
            printf("%d ", sum_array[y][x]);
        }
    }
    for(size_t i = 0; i < y; ++i)
    {
        free(sum_array[i]);
    }
    free(sum_array);
    return 0;

}