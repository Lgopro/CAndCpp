#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/
#define MAX 

void PrintPermutations(char * str, size_t begin, size_t length);
void Swap(char *var1, char *var2);

int main()
{
	
	char string[] = "ABCD";
    PrintPermutations(string, 0, strlen(string) - 1);
	return 0;
}

void PrintPermutations(char * str, size_t begin, size_t length)
{
    size_t i = 0; 


    assert(str);
    assert(0 < length);

    if (begin == length) 
    {
        for(i = 0;i <= begin; ++i)
        {
            printf("%s\n", &str[i]); 
        } 
    }
    else
    { 
        for (i = begin; i <= length; i++) 
        { 
            Swap((str + begin), (str + i)); 
            PrintPermutations(str, begin + 1, length);
            Swap((str + begin), (str + i)); 
        } 
    }  
}

void Swap(char *var1, char *var2)
{
    char temp = 0;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}