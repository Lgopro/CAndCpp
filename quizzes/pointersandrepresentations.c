#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/
int main()
{
    char arr[] ={0x40, 0x50, 0x60, 0x70, 0x80, 0x82, 0x83};
    unsigned long num = *(unsigned long *)arr;
    printf("%ld long\n", num);
    short *sqrt = (short *)&num;
    sqrt += (sizeof(num) >> 2);
    char result = *sqrt;
    printf("%d\n", result);
    return 0;
}