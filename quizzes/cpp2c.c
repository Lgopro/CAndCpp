#include <stdio.h>


typedef struct Vptr vptr_t;
typedef struct Person_t Person;

struct Vptr
{
    void (*Draw)(Person *);
};


struct Person_t
{
    vptr_t vptr;
};

void Draw(Person *person)
{
    (void)person;
    printf("Person Draw Function\n");
}

void Foo(Person *person1, Person *person2)
{
    person1->vptr.Draw(person1);
    person2->vptr.Draw(person2);
}


void PersonCtor(Person *this)
{
    printf("Person Ctor\n");
    this->vptr.Draw = &Draw;
}

void PersonCCtor(Person *this)
{
    (void)this;
    printf("Person CCtor\n");
}

void PersonDtor(Person *this)
{
    (void)this;
    printf("Person Dtor\n");
}

int main()
{
    Person p1;
    Person p2;
    Person p1_copy;
    PersonCtor(&p1);
    PersonCtor(&p2);
    PersonCCtor(&p1);
    p1_copy = p1;
    Foo(&p1_copy, &p2);
    PersonDtor(&p1);
    PersonDtor(&p2);
    PersonDtor(&p1_copy);
    return 0;
}