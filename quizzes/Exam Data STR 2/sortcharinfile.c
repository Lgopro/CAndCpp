#define SUCCESS 0
#define FAIL 1

#include <stdio.h> /*assert*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*free*/

#include "Stack.h"

int SortCharsInFile(const char *filename, char *result);

int main()
{
	char result[24] = {0};
   
    const char filename[] = "file.txt";
    SortCharsInFile(filename, result);
    
	return 0;
}

int SortCharsInFile(const char *filename, char *result)
{
    FILE *name = NULL;
    size_t length = 0;
    size_t i = 0;
    size_t j = 0;

    int LUT[256] = {0};
    assert(filename);
    

    name = fopen(filename, "r");
    if (NULL == name) 
    {
       return 1;
    }

    fseek (name, 0, SEEK_END);
    length = ftell (name);
    fseek (name, 0, SEEK_SET);

    fread (result, 1, length, name);

    fclose(name);

    for(i = 0;i < length; ++i)
    {
        ++LUT[(int)result[i]];
    }
    
    i = 0;

    while(i < length)
    {
        while(0 != LUT[j])
        {
            result[i] = j;
            --LUT[j];
            ++i;
        }
        ++j;
    }
    
    for(i = 0; i < length; ++i)
    {
        printf("%c", result[i]);
    }
    return 0;
}