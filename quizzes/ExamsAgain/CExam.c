#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


#define PLUS 1
#define MINUS -1
#define TRUE 1
#define BITS_IN_INT 32

int FlipDigitsInNum(int num)
{
    int sign = PLUS;
    int new_number = 0;
    int ehida = 0;
    if(0 == num)
    {
        return 0;
    }

    if(num < 0)
    {
        sign = MINUS;
        num *= -1;
    }

    while(TRUE)
    {
        ehida = num % 10;
        new_number += ehida;
        num /= 10;
        if(num > 0)
        {
            new_number *= 10;
        }
        else
        {
            break;
        }
    }

    return new_number * sign;

}

unsigned char SwapBits(unsigned char var)
{
    unsigned char new_var = 0;
    for(int i = 7; i >= 0; --i)
    {
        if(!(var & 1 << i))
        {
            new_var ^= 1 << i;
        }
    }

    return new_var;
}


void PrintBits(unsigned char var)
{
    for(int i = 7; i >= 0; --i)
    {
        if(var & 1 << i)
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

void PrintIntBits(int var)
{
    for(int i = 31; i >= 0; --i)
    {
        if(var & 1 << i)
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
    n %= BITS_IN_INT;
    val ^= 1 << n;
    return val;

}

unsigned char RotateLeft(unsigned char var, unsigned int amount)
{
    unsigned char left_side = 0;
    unsigned char right_side = 0;

    amount %= 8;

    left_side = var << amount;
    right_side = var >> (8 - amount);

    return left_side | right_side;

}

size_t Strlen(const char *arr)
{
    char *arr_begin = (char *)arr;
    size_t counter = 0;

    assert(arr);

    while(*arr_begin != '\0')
    {
        ++counter;
        ++arr_begin;
    }

    return counter;
}

int Strcmp(const char *s1, const char *s2)
{
    char *begin_s1 = (char *)s1;
    char *begin_s2 = (char *)s2;

    assert(s1);
    assert(s2);

    while(TRUE)
    {
        if(*begin_s1 == '\0' && *begin_s2 == '\0')
        {
            return 0;
        }

        if(*begin_s1 == '\0' || *begin_s2 == '\0')
        {
            break;
        }

        if(*begin_s1 != *begin_s2)
        {
            break;
        }

        ++begin_s1;
        ++begin_s2;
    }

    if(*begin_s1 == '\0' || *begin_s2 == '\0')
    {
        if(*begin_s1 == '\0')
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    if(*begin_s1 != *begin_s2)
    {
        if((int)*begin_s1 > (int)*begin_s2)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

char *Strcpy(char *dest, const char *src)
{

    char *dest_arr = (char *)dest;
    char *src_arr = (char *)src;

    assert(dest);
    assert(src);

    while(*src_arr != '\0')
    {
        *dest_arr = *src_arr;
        ++src_arr;
        ++dest_arr;
    }
    *dest_arr = '\0';
    return dest;
}


char *Strncpy(char *dest, const char *src, size_t n)
{
    char *dest_arr = (char *)dest;
    char *src_arr = (char *)src;
    size_t counter = 0;

    assert(dest);
    assert(src);

    while(*src_arr != '\0' && counter != n)
    {
        *dest_arr = *src_arr;
        ++src_arr;
        ++dest_arr;
        ++counter;
    }

    *dest_arr = '\0';
    return dest;
}


char *Strcat(char *dest, const char *src)
{

    char *dest_text = dest;
    char *src_text = (char *)src;

    assert(dest);
    assert(src);
    
    dest_text = dest_text + strlen(dest_text);

    while(*src_text != '\0')
    {
        *dest_text = *src_text;
        ++dest_text;
        ++src_text;

    }

    *dest_text = '\0';


    return dest;
}

unsigned long Fibonachi(unsigned int num)
{
    if(num == 0)
    {
        return 0;
    }

    if(num == 1 || num == 2)
    {
        return 1;
    }

    int *fibonachi_arr = (int *)malloc(sizeof(num));
    if(NULL == fibonachi_arr)
    {
        return 0;
    }

    fibonachi_arr[0] = 0;
    fibonachi_arr[1] = 1;
    fibonachi_arr[2] = 1;

    for(int i = 3; i < num; ++i)
    {
       fibonachi_arr[i] = fibonachi_arr[i - 1] + fibonachi_arr[i - 2];
    }

    unsigned long result = fibonachi_arr[num - 1];

    return result;
}

void IntToString(int number, char *arr)
{
    assert(arr);
    sprintf(arr, "%d\n", number);

    return;
}

int main()
{
    char arr_str[] = "Sup";
    int result = FlipDigitsInNum(-345);
    printf("%d\n", result);
    PrintBits(32);
    PrintBits(11);

    PrintBits(SwapBits(11));

    PrintIntBits(FlipBit(32, 9));

    PrintBits(RotateLeft(32, 4));

    if(Strlen(arr_str) == strlen(arr_str))
    {
        printf("strlen correct\n");
    }
    else
    {
        printf("My Strlen is %zu\n", Strlen(arr_str));
        printf("System strlen is %zu\n", strlen(arr_str));
    }

    char arr[] = "I will fly";
    char arr1[] = "I will";
    char arr2[] = "Again";
    char arr_cpy[30];
    char arr_cpy_2[30];
    if(0 == Strcmp(arr, arr) && 1 == Strcmp(arr, arr1) && -1 == Strcmp(arr2, arr1))
    {
        printf("Strcmp correct\n");
    }

    Strcpy(arr_cpy, (const char *)arr);
    printf("%s\n", arr_cpy);

    Strncpy(arr_cpy_2, (const char *)arr, 5);
    printf("%s\n", arr_cpy_2);

    Strcat(arr_cpy, arr2);
    printf("%s\n", arr_cpy);

    printf("Fibonachi of 5 is %zu\n", Fibonachi(5));


    char arr_string[20];
    IntToString(-34, arr_string);
    printf("%s", arr_string);
    return 0;
}