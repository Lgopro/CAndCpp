#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void *Memcpy(void *dest, void *src, size_t n)
{
    char *dest_begin = NULL;
    char *src_begin = NULL;

    assert(dest);
    assert(src);

    dest_begin = (char *)dest;
    src_begin = (char *)src;

    while(n != 0)
    {
        if((long)dest_begin % 8 != 0 || n < 8)
        {
            *dest_begin = *src_begin;
            ++dest_begin;
            ++src_begin;
            --n;
        }
        else if((long)dest_begin % 8 == 0 && n >= 8)
        {
            *(long *)dest_begin = *(long *)src_begin;
            dest_begin = dest_begin +8;
            src_begin = src_begin + 8;
            n -= 8;
        }
    }

    return dest;
}


int main()
{
    char *arr_dest = (char *)malloc(sizeof(20));
    char *arr_src = (char *)malloc(sizeof(20));
    strcpy(arr_src, "Lets go bro! plz");

    Memcpy(arr_dest, arr_src, strlen(arr_src));

    printf("%s", arr_dest);


    free(arr_dest);
    free(arr_src);
    return 0;
}