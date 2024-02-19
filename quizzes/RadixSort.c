#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void RadixSortStrings(char **strings, size_t size)
{
    assert(strings);

    int LUT[256] = {0};

    char **begin = strings;
    size_t x = 0;
    size_t y = 0;
    for(size_t i = 0; i < size; ++i)
    {

        for(size_t j = 0; j < strlen(*begin); ++j)
        {
            ++LUT[strings[i][j]];
        }
        ++begin;
    }

    begin = strings;

    for(size_t index = 0 ; index < 256; ++index)
    {
        size_t counter = LUT[index];
        if(0 == counter)
        {
            continue;
        }

        while(y != size)
        {
            
            while(x != strlen(*begin))
            {
                strings[y][x] = LUT[index];
                --counter;
                ++x;
                if(0 == counter)
                {
                    break;
                }
            }
            if(0 == counter)
            {
                break;
            }
            ++begin;
            ++y;
            x = 0;
        }
    }
}


int main()
{
    size_t amount = 3;
    char **begin = NULL;

    char **strings = (char **)malloc(sizeof(char *) * amount);
    strings[0] = (char *)malloc(sizeof(char) * 6);
    strings[1] = (char *)malloc(sizeof(char) * 3);
    strings[2] = (char *)malloc(sizeof(char) * 4);
    
    strcpy(strings[0], "whats");
    strcpy(strings[1], "up");
    strcpy(strings[2], "bro");
    begin = strings;
    for(size_t i = 0; i < amount; ++i)
    {
        printf("%s ", *begin);
        ++begin;
    }
    printf("\n");
    RadixSortStrings(strings, 3);
    begin = strings;
    for(size_t i = 0; i < amount; ++i)
    {
        printf("%s ", *begin);
        ++begin;
    }
    return 0;
}