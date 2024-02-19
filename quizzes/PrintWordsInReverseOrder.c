#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int Reverse(char str[]);

int main()
{
	char string[] = "I Like Programming";
    Reverse(string);
	return 0;
}


int Reverse(char str[])
{
    char *arr = NULL;
    int length = strlen(str);
    int i = 0;

    assert(str);

    arr = (char *)malloc(sizeof(char) * length);
    if(NULL == arr)
    {
        return 1;
    }
    strcpy(arr, str);
    for (i = length - 1; i >= 0; --i) 
    {
        if (arr[i] == ' ') 
        {
            arr[i] = '\0'; 
            printf("%s ", &(arr[i]) + 1);
        }
    }
    printf("%s\n", arr);
    free(arr);
    return 0;
}