

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* LongestSubstringKUnique(const char* str, size_t amount_of_letters)
{
    int LUT[256] = {0};
    int location = 0;
    int begin = 0;
    size_t counter = 0;

    assert(str);
    size_t size = strlen(str);

    if(size < amount_of_letters)
    {
        return NULL;
    }

    while(str[location] != '\0')
    {
        ++LUT[str[location]];
        if(LUT[str[location]] > 1)
        {
            ++location;
            for(int i = 0; i < 256; ++i)
            {
                LUT[i] = 0;
            }
            begin = location;
            continue;
        }

        ++counter;
        if(counter == amount_of_letters)
        {
            return (char *)&str[begin];
        }
        ++location;
    }

    return NULL;
}

int main()
{
    char arr[20] = "abcdefabbc";
    size_t val = 10;
    char *result = LongestSubstringKUnique(arr, val);
    if(result == NULL)
    {
        printf("No result\n");
    }
    else
    {
        for(size_t i = 0; i < val; ++i)
        {
            printf("%c", *result);
            ++result;
        }
        
    }
    return 0;
}