#include <iostream>
using namespace std;



typedef struct List List_t;
typedef struct Person Person_t;

struct List
{
    void* value;
};

struct Person
{
    int age;
    char * name;
};

void * ll_find(int num, int key)
{
    return NULL;
}
void foo(List_t *ll, int key, int age)
{
    void *vv = ll_find(11, key);
    Person_t *p =  reinterpret_cast<Person_t*>/* (Person_t*) */(ll);
    /* p->age = age; */
}

int main()
{
    return 0;
}
