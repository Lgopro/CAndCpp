
#include <stddef.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

unsigned int PlusOneWhile(unsigned int number)
{
    unsigned int bits_counter = 1;
    if(number == 0)
    {
        return 0;
    }
    while((number & (number - 1)) != 0)
    {

        number = number & (number - 1);
        ++bits_counter;
    }
    return bits_counter;
}

unsigned int PlusOneFor(unsigned int number)
{
    unsigned int bits_counter = 0;
    for(size_t i = 0; i < 32; ++i)
    {
        if(number & 1 << i)
        {
            ++bits_counter;
        }
    }
    return bits_counter;
}

int SecondAndSix(unsigned char number)
{
    return ((number >> 1 & 1) && (number >> 5 & 1));
}

int SecondOrSix(unsigned char number)
{
    return ((number >> 1 & 1) || (number >> 5 & 1));
}

unsigned char SwapThreeAndFive(unsigned char number)
{
    int three = (number >> 2) & 1;
    int five = (number >> 4) & 1;
    if(three == five)
    {
        return number;
    }
    else
    {
        number = number ^ (1 << 2);
        number = number ^ (1 << 4);
    }
    return number;
}





int main()
{

    printf("Amount of bits are PlusOneWhile(16) %d\n", PlusOneWhile(16));
    printf("Amount of bits are PlusOneWhile(15) %d\n", PlusOneWhile(15));
    printf("Amount of bits are PlusOneFor(16) %d\n", PlusOneFor(16));
    printf("Amount of bits are PlusOneFor(15) %d\n", PlusOneFor(15));

    int result = SecondAndSix(34);
    
    if(result == TRUE)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }


    int result1 = SecondOrSix(18);
    if(result1 == TRUE)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    int result2 = SecondOrSix(17);
    if(result2 == TRUE)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    printf("result of SwapThreeAndFive(2) is %d\n", SwapThreeAndFive(100));


    return 0;
}