

#include "stdio.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define BEEF -123415

int AtoiBaseTen(char *arr)
{
    int result = 0;
    int end = 0;
    int sign = 1;
    char *temp = NULL;

    assert(arr);
    
    end = strlen(arr) - 1;
    temp = (char *)malloc(sizeof(strlen(arr) + 1));
    if(NULL == temp)
    {
        return BEEF;
    }

    if(*arr == '-')
    {
        sign = -1;
    }
    
    if(sign == -1)
    {
        for(int begin = 0; begin < strlen(arr); ++begin)
        {
            temp[begin] = arr[end];
            --end;
        }
        temp[strlen(arr) - 1] = '\0';
    }
    else
    {
        --end;
        for(int begin = 1; begin < strlen(arr); ++begin)
        {
            temp[begin] = arr[end];
            --end;
        }
        temp[strlen(arr) - 2] = '\0';
    }
    
    for(int i = 0; i < strlen(temp); ++i)
    {
        int number = temp[i] - '0';
        result += number;
    }
    
    free(temp);
    return result * sign;
}

int main()
{
    char arr[] = "-64785345";
    int number = AtoiBaseTen(arr);
    printf("The number is %d\n", number);

    return 0;
}