

#include <stdio.h> /*printf*/
#include <stdlib.h> /*calloc*/
#include <assert.h>
#include <string.h>

void Swap(char *var1, char *var2);
void PrintPermutations(char *arr);

int main()
{
    char arr[] = "ABC";
    PrintPermutations(arr);
    return 0;
}

void Swap(char *var1, char *var2)
{
    char temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


void PrintPermutations(char *arr)
{
    
    int i = 0;
    int *help_arr = NULL;
    int length = 0;

    assert(arr);

    length = strlen(arr);
    help_arr = calloc(length, sizeof(int));
    if(NULL == help_arr)
    {
        return;
    }
    printf("%s\n", arr);

    while (i < length)
    {
        if (help_arr[i] < i)
        {
            if (i % 2 == 0)
            {
                Swap(&arr[0], &arr[i]);
            }
            else
            {
                Swap(&arr[help_arr[i]], &arr[i]);
            }
            printf("%s\n", arr);
            ++help_arr[i];
            i = 0;
        }
        else
        {
            help_arr[i] = 0;
            ++i;
        }
    }

    free(help_arr);
}
