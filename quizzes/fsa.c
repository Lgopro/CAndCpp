#include <stddef.h>
#include <stdio.h>

typedef struct FSA fsa;

struct FSA
{
    size_t m_next;
};

fsa *FSAInit(void *ptr_to_memory, size_t allocated_size, size_t block_size)
{
    char *arr_begin = (char *)ptr_to_memory;
    fsa my_fsa;
    my_fsa.m_next = 8;
    size_t alloc_size_left = allocated_size;
    size_t next = 0;
    size_t end = 0;

    if(allocated_size == 0 || block_size == 0 || ptr_to_memory == NULL)
    {
        return NULL;
    }

    arr_begin = (char *)&my_fsa;
    next = my_fsa.m_next;
    arr_begin = arr_begin + sizeof(fsa);
     
    while(alloc_size_left - block_size > sizeof(fsa))
    {
        next += block_size;
        arr_begin = (char *)&next;
        arr_begin = arr_begin + block_size;
        alloc_size_left -= block_size;
    }

    arr_begin = (char *)&end;

    return (fsa *)ptr_to_memory;
}


void *Alloc(fsa *fsa)
{
    if(fsa == NULL || fsa->m_next == 0)
    {
        return NULL;
    }

    fsa->m_next = *(size_t *)((char *)fsa + fsa->m_next); 
    return (void *)((char *)fsa + fsa->m_next);
}

void Free(fsa *fsa, void *block_to_free)
{
    size_t temp = 0;
    if(fsa == NULL || block_to_free == NULL)
    {
        return;
    }

    temp = fsa->m_next;
    fsa->m_next = (size_t)block_to_free - (size_t)fsa;
    block_to_free = &temp;
}


int main()
{

    

    return 0;
}



