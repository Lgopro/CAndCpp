#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

long Pow2(unsigned int x, unsigned int y)
{
    return (x * (y << 2));
}

size_t IsPowerTwo(unsigned int num)
{
    size_t counter = 0;
    while(num != 0)
    {
        num = num & (num - 1);
        ++counter;
    }

    if(counter == 1)
    {
        return TRUE;
    }
    return FALSE;
}

unsigned int AddOne(unsigned int number)
{
    for(int i = 0; i < 32; ++i)
    {
        if(number & 1 << i)
        {
            number = number ^ (1 << i);
        }
        else
        {
            number = number ^ (1 << i);
            return number;
        }
    }
    return number;
}
size_t CountBits(unsigned int number)
{
    size_t counter = 0;
    for(size_t i = 0; i < 32; ++i)
    {
        if(number & 1 << i)
        {
            ++counter;
        }
    }
    return counter;
}

void PrintOnly3Bits(unsigned int *arr, size_t size)
{
    size_t result = 0;

    assert(arr);

    for(size_t i = 0; i < size; ++i)
    {
        result = CountBits(arr[i]);
        if(result == 3)
        {
            printf("The number is %d\n", arr[i]);
        }
    }
}

void PrintInt(unsigned int number)
{
    for(int i = 31; i >= 0 ; --i)
    {
        if(number & 1 << i)
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

unsigned int Mirror(unsigned int number)
{
    unsigned int result = 0;
    int begin = 0;
    int end = 31;

    for(end = 31; end >= 0; --end)
    {
        if(number & 1 << end)
        {
            result = result ^ 1 << begin;
        }
        ++begin;
    }
    return result;
}

unsigned int FindNumber(unsigned int number)
{
    for(int i = 32; i >= 0; --i)
    {
        if(number & 1 << i)
        {
            if(i > 3)
            {
                return 1<< i;
            }
            else
            {
                return 1;
            }
        }
    }
}


int main()
{
    long result = Pow2(3, 2);
    printf("3 pow 2 is %ld\n", result);

    size_t amount = IsPowerTwo(32);
    if(amount != 1)
    {
        printf("Not power of two\n");
        printf("Amount of %ld\n", amount);
        
    }
    else
    {
        printf("Power of two\n");
        printf("Amount of %ld\n", amount);
    }
    size_t amount1 = IsPowerTwo(111);
    if(amount1 != 1)
    {
        printf("Not power of two\n");
        printf("Amount of %ld\n", amount1);
    }
    else
    {
        printf("Power of two\n");
        printf("Amount of %ld\n", amount1);
    }

    unsigned int added_one = AddOne(31);
    printf("31 plus one is %d\n", added_one);

    unsigned int arr[] = {5, 2, 6, 11, 20, 32, 7};

    PrintOnly3Bits(arr, 7);

    PrintInt(321);
    PrintInt(Mirror(321));
    
    return 0;
}
