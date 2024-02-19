
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define UNTIL_END (1)
#define NOT_ZERO (200000)
int gcd(int a, int b);
 
void RotateRight(char arr[], int move_by)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    char temp = 0;
    size_t g_c_d = 0;
    size_t size = 0;
    
    assert(arr);
    
    size = strlen(arr);
    move_by = move_by % size;
    g_c_d = gcd(move_by, size);
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
 

void PrintArray(char arr[])
{
    size_t i = 0;
    for (i = 0; i < strlen(arr); i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}
 
int gcd(int a, int b)
{
    if (0 == b)
    {
        return a;
    }  
    
    return gcd(b, a % b);

        
}
 
int main()
{
    char arr[] = "hello";
    PrintArray(arr);
    RotateRight(arr, 2);
    PrintArray(arr);
    return 0;
}

