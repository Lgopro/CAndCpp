
/* typedef struct List
{
    void (*Base )(void);
    void (*Foo )(void);
}function_t; */
#include <stdio.h>
#include <stdlib.h>
void FooBase()
{
    printf("Im FooBase\n");
}
void DtorBase()
{
    printf("Im DtorBase\n");
}

typedef struct List
{
    void (*base_func )(void);
    void (*foo_func )(void);
}function_t;

function_t base_functions = 
{
    .base_func = DtorBase,
    .foo_func = FooBase
};

typedef struct base
{
    function_t *vptr;
    int x;
    int y;

}Base;

typedef struct derived
{
    function_t *vptr;
    Base base;
    int z;
}Derived;


void DefaultCtorBase(Base *this)
{
    this->x = 0;
    this->y = 0;
    this->vptr = &base_functions;
}

void NonDefaultCtorBase(Base *this, int x, int y)
{
    this->x = x;
    this->y = y;
    this->vptr = &base_functions;
}


void DefaultCtorDerived(Derived *this)
{
    this->base.vptr = &base_functions;
    this->base.x = 0;
    this->base.y = 0;
    this->z = 0;
}



void NonDefaultCtorDerived(Derived *this, int x, int y,int z)
{
    this->base.x = x;
    this->base.y = y;
    this->z = z;
    this->vptr = &base_functions;
}

Base *InitBase()
{
    Base *base = (Base *)malloc(sizeof(Base));
    if(base == NULL)
    {
        return NULL;
    }
    return base;
}

Derived *InitDerived()
{
    Derived *derived = (Derived *)malloc(sizeof(Derived));
    if(derived == NULL)
    {
        return NULL;
    }
    return derived;
}

void BasedDtor(Base *value)
{
    free(value);
}

void DerivedDtor(Derived *value)
{
    free(value);
}
int main()
{
    Base try;
    Derived der;
    DefaultCtorBase(&try);
    try.vptr->foo_func();
    DefaultCtorDerived(&der);
    der.base.vptr->base_func();


    /*15*/
    Base *base = InitBase();
    if(base == NULL)
    {
        return 1;
    }
    NonDefaultCtorBase(base, 5, 6);

    Derived *derive = InitDerived();
    if(derive == NULL)
    {
        return 1;
    }
    
    NonDefaultCtorDerived(derive, 5, 6, 7);

    base->vptr->foo_func();
    
    DerivedDtor(derive);
    BasedDtor(base);
    return 0;
}