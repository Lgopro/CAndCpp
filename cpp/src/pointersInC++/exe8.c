


#include <stdlib.h>
#include <stddef.h>




typedef struct b
{
    int x;
    int y;
}B;

void Ctor(B *init)
{
    init->x = 0;
    init->y = 0;
}

B *CreateProcess()
{
    B *new = (B *)malloc(sizeof(B));
    if(NULL == new)
    {
        return NULL;
    }
    Ctor(new);
    return new;
}

void Dtor(B *p)
{
    free(p);
}

void DestroyProcess(B *p)
{
    Dtor(p);
}



void Foo()
{
    int i = 0;
    B array1[100];
    for(i = 0;i < 100; ++i)
    {
        Ctor(&array1[i]);
    }
    B *array2 = (B *)malloc(100 * sizeof(B));
    if(NULL == array2)
    {
        return;
    }
    for(i = 0;i < 100; ++i)
    {
        Ctor(&array2[i]);
    }
    DestroyProcess(array2);
}

int main()
{
    Foo();
    return 0;
}
