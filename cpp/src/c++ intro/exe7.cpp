#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



typedef struct List List_t;
typedef struct Person Person_t;




int main()
{
    int *ptr = (int *)malloc(1000 - sizeof(int));
    delete ptr;
    int *l = new int(100);
    free(l);
    return 1;
}

