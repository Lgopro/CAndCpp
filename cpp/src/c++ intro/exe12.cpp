#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



void Foo()
{
    printf("Im printf void\n");
};
void Foo(int i)
{
    printf("Im printf int %d\n", i);
};
void Foo(char c)
{
    printf("Im printf char %c\n", c);
};

int main()
{
    /*int *value = NULL;
    int b = 5;
    value = &b;*/
    Foo();
    Foo(5);
    Foo('a');
    Foo((unsigned char)'b');
    Foo((float)8);
    /*Foo(value);*/
    /*Foo(NULL);*/

    return 1;
}