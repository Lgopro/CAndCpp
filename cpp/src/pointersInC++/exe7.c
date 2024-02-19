


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



int main()
{
    B b;
    b.x = 5;
    b.y = 6;
    B *p = CreateProcess();
    p->x = 5;
    p->y = 6;
    DestroyProcess(p);
    return 0;
}
