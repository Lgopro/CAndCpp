

#include <stdio.h> /*printf*/
#include <stdlib.h> /*calloc*/
#include <assert.h>
#include <string.h>
void aligned_free(void *p );
void *aligned_malloc(size_t bytes, size_t alignment);

int main()
{
    void *data = NULL;
    data = aligned_malloc(15, 5);
    aligned_free(data);
    return 0;
}

void *aligned_malloc(size_t bytes, size_t align)
{
    void *allocated_arr1 = NULL; 
    void *return_value = NULL;
    size_t address = 0;

    if(NULL == (allocated_arr1 =(void *)malloc(bytes + align  + sizeof(size_t))))
    {
        return (NULL);
    }
    address = (size_t)allocated_arr1 + bytes + align;
    return_value = (void *)(address - address % align);
    *((size_t *)return_value - 1) = (size_t)allocated_arr1;
    return (return_value);
}


void aligned_free(void *ptr)
{
    free((void *)(*((size_t *)ptr - 1)));
}

