#include <stdio.h>



int FlipDigitsInNum(int num)
{
    int return_num = 0;
    int sign = 1;

    int digit = 0;

    if(num < 0)
    {
        sign = -1;
    }

    while(num != 0)
    {
        return_num *= 10;
        digit = num % 10;
        num /= 10;
        return_num += digit;
        
    }

    return return_num * sign;

}

unsigned char MirrorMe(unsigned char number)
{
    unsigned char result = 0;
    
    for(size_t i = 0; i < 8; ++i)
    {
        if(number & (1 << i))
        {
            result |= 1 << (8 - i);
        }
    }
    return result;
}

void PrintMe(unsigned char number)
{   
    for(int i = 8; i >= 0; --i)
    {
        if(number & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

void PrintMeInt(unsigned int number)
{   
    for(int i = 31; i >= 0; --i)
    {
        if(number & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int FlipBit(int val, unsigned int n)
{
    n %= 32;
    return ((val & (1 << n)) ? (val & ~(1 << n)) : (val | (1 << n))); 
}

int main()
{
    int result = FlipDigitsInNum(123456);
    unsigned int int_num = 35;
    unsigned char number = 6;
    unsigned char number_mirror = 0;

    printf("flip number 123456 to %d\n", result);


    number_mirror = MirrorMe(number);
    printf("number\n");
    PrintMe(number);

    printf("number mirror\n");
    PrintMe(number_mirror);

    printf("int number\n");
    PrintMeInt(int_num);
    int_num = FlipBit(int_num, 7);
    printf("int number after flip 7 bit\n");
    PrintMeInt(int_num);

    int_num = FlipBit(int_num, 1);
    printf("int number after flip 1 bit\n");
    return 0;
}