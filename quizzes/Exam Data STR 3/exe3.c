#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include <string.h>
#include "dlist.h"
#define SUCCESS 0
#define FAIL 1

int Find(char *arr, char find);

int main()
{
    char arr[] = "I will fly";
    char find = 'b';
    int result = 0;
    result = Find(arr, find);
    if(0 == result)
    {
        printf("Pass\n");
    }
    return 0;

}

int Find(char *arr, char find)
{
    size_t i = 0;
    int sum = 1000;
    while(i < strlen(arr - 1))
    {
        sum *= arr[i] ^ find;
        ++i;
    }
    return (sum);
}