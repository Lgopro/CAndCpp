#include <cassert>
#include <iostream>
#include <ostream>
#include <cstddef>

namespace ilrd
{
    class Person
    {
        public:
        Person();
        Person(const Person& other);
        virtual void Draw();
        ~Person();
        void Foo(Person p1, Person& p2);
        private:
        Person& operator=(const Person& other)=delete;
    
    };
    
}

using namespace ilrd;

Person::Person()
{
    std::cout<< "Person Ctor" << std::endl;
}
Person::Person(const Person& other)
{
    std::cout<< "Person CCtor" << std::endl;
}

void Person::Draw()
{
    std::cout<< "Person Draw Function" << std::endl;
}

Person::~Person()
{
    std::cout<< "Person Dtor" << std::endl;
}

void Person::Foo(Person p1, Person& p2)
{
    p1.Draw();
    p2.Draw();
}

int main()
{
    Person p1;
    Person p2;
    p1.Foo(p1, p2);
}