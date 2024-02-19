#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include <string.h>
#include "dlist.h"
#define SUCCESS 0
#define FAIL 1

#include <stdio.h>
#include <string.h>

unsigned int Recursion(unsigned int num)
{
    unsigned int result = 0;
    if(0 == num)
    {
        return (num);
    }
    result = Recursion(num - 1);
    return (result + num);
}

int Multiplication(int num1, int num2)
{
    int result = 0;
    if(0 == num2)
    {
        return (num2);
    }
    result = Multiplication(num1, num2 - 1);
    result += num1;
    return (result);
}

int Multiplication(int num1, int num2)
{
    int result = 0;
    if(0 == num2)
    {
        return (num2);
    }
    result = Multiplication(num1, num2 - 1);
    result += num1;
    return (result);
}

unsigned int AddOne(unsigned int number, size_t bit)
{
    unsigned int result = 0;
    if(32 == bit)
    {
        return (number);
    }
    if(number & (1UL << bit))
    {
        return number;
    }
    else
    {
        number ^= 1UL << bit;
        result = AddOne(number, bit + 1);
    }
    return (result);
}

int main() 
{
    unsigned int result = 0 ;
    result = Recursion(5);
    printf("%d\n", result);
    result = Multiplication(5, 5);
    printf("5 * 5 = %d\n", result);
    result = AddOne(6, 0);
    printf("result is:%d\n", result);
    return 0;
}