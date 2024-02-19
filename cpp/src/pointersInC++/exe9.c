


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



B Bar(B b1, B *b2, B *b3)
{
    return b1;
}

int main()
{
    B b1;
    B b2;
    B b3;

    Ctor(&b1);
    Ctor(&b1);
    Ctor(&b1);
    B b4 = Bar(b1, &b2, &b3);
    return 0;
}