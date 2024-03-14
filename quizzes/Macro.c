


#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define ISBIGINDIAN() \
    ({int a = 32; \
    char *arr = (char *)&a; \
    (arr[0] == a) ? TRUE : FALSE;\
    })

#define MAX(a, b) ((a > b) ? a : b)


#define MAXTHREE(a,b,c) (MAX(MAX(a, b), c))

int main()
{
    int number1 = 23;
    int number2 = 55;
    int number3 = 43;

    int value = ISBIGINDIAN();
    if(value == TRUE)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

    
    printf("Result is %d between the numbers of 23 and 43\n", MAX(number1, number3));
    printf("Result is %d between the numbers of 23 and 55 and 43\n", MAXTHREE(number1, number2, number3));
    return 0;
}