#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define UNTIL_END (1)
#define NOT_ZERO (200000)
int Find(char *str,char find);

/*int main()
{
	int status1 = 0;
    int status2 = 0;
    char str[] ="hello world";
    char a = 'a';
    char b = 'o';
    status1 = Find(str, a);
    status2 = Find(str, b);
    printf("status 1 is: %d\n", status1);
    printf("status 2 is: %d\n", status2);
	return 0;
}*/

int Find(char *str,char find)
{
    size_t counter = 0;
    int result = NOT_ZERO;

    assert(str);

    while(counter < strlen(str))
    {
        result *= *(str + counter)^find;

        ++counter;
    }

    return result;
}


void PrintArray(int arr[], int size);
 

int gcd(int a, int b);
 
void RotateRight(int arr[], int move_by, int size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int g_c_d = 0;
    move_by = move_by % size;
    g_c_d = gcd(move_by, size);

    assert(arr);
    
    for(i = 0; i < g_c_d; ++i) 
    {
        temp = arr[i];
        j = i;
        while (UNTIL_END) 
        {
            k = (j - move_by + size) % size;
            if (k >= size)
            {
                k = k - size;
            }
            if (k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
 

void PrintArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
 
int gcd(int a, int b)
{
    if (0 == b)
    {
        return a;
    }  
    else
    {
        return gcd(b, a % b);
    }
        
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}