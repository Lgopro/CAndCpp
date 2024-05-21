

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) 
{
    size_t counter = 0;
    int location = 0;

    int *LUT = (int *)malloc(sizeof(int) * N);
    if(LUT == NULL)
    {
        return -1;
    }
    
    for(int i = 0; i < N; ++i)
    {
        LUT[i] = -1;
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            if(LUT[i] != -1)
            {
                break;
            }

            if(A[i] == A[j])
            {
                LUT[i] = j;
                LUT[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i < N; ++i)
    {
        LUT[i] == -1;
        location = i;
    }
    free(LUT);
    return A[location];
}



int main()
{
    int A[] = {9, 3, 9, 3, 9, 7, 9};


    int value = solution(A, 7);


    printf("The result is: %d\n", value);
    return 0;
}