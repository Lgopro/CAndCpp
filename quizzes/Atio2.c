

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define POSITIVE 1
#define NEGATIVE -1
#define UNTIL_NOT_FALSE 1

long Atio(char *arr)
{
    assert(arr);

    int flag_sign = POSITIVE;

    size_t location = 0;
    size_t length = strlen(arr);
    long final_number = 0;
    int number = 0;


    int number_result;
    while(UNTIL_NOT_FALSE)
    {
        if(arr[location] == ' ')
        {
            ++location;
        }
        else
        {
            break;
        }
    }

    if(arr[location] == '-')
    {
        flag_sign = NEGATIVE;
        ++location;
    }

    while(location < length)
    {
        final_number *= 10;
        number = arr[location] - '0';
        final_number += number;
        ++location;
    }
    
    return flag_sign * final_number;
}

int main()
{
    char arr[] = "  -453";
    long result = Atio(arr);
    printf("The result is %ld\n", result);
    return 0;
}