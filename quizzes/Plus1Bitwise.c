#include <stdio.h>


unsigned int PlusOne(unsigned int number)
{
    for(int i = 0; i < 32; ++i)
    {
        if(number & (1UL << i))
        {
            number ^= 1UL << i;
        }
        else
        {
            number ^= 1UL << i;
            break;
        }
    }

    return number;
}

int main()
{
    unsigned int number = 1234;
    unsigned int result = PlusOne(number);

    printf("The number is %d and the result is %d\n", number, result);

    return 0;
}