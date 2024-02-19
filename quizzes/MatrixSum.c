#include <stdio.h>
#include <stdlib.h>


int **MatrixSum(int **array, int x, int y)
{
    assert(array);

    for(int i = 0; i < y; i++)
    {
        for(int j = 0;j < x; ++j)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            else if(i == 0 && j != 0)
            {
                array[i][j] += array[i][j - 1];
            }
            else if(i != 0 && j == 0)
            {
                array[i][j] += array[i - 1][j];
            }
            else
            {
                array[i][j] += array[i - 1][j] + array[i][j - 1] - array[i - 1][j - 1];
            }
        }
    }
    
    return array;
}

int main()
{
    int x = 3;
    int y = 3;
    int j = 0;
    int i = 0;
    int k = 0;
    int counter = 0;

    int **matrix = (int **)malloc(x * sizeof(int *));
    for(i = 0; i < y; ++i)
    {
        matrix[i] = (int *)malloc(sizeof(int) * x);
    }

    for(j = 0; j < y; ++j)
    {
        for(k = 0; k < x; ++k)
        {
            matrix[j][k] = counter;
            ++counter;
        }
    }
    MatrixSum(matrix, x, y);

    for(j = 0; j < y; ++j)
    {
        for(k = 0; k < x; ++k)
        {
            printf("%d ",  matrix[j][k]);
        }
        printf("\n");
    }
    return 0;
}