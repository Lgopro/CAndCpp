
#include <iostream>


namespace ilrd
{
    class Base 
    {
        virtual void method () {std::cout << "BASE" << std::endl;}
    public:
        virtual ~Base() {method();}
        void otherMethod () {std::cout << "other Method" << std::endl;}
    };

    class Derived :public Base
    {
        void method () {std::cout << "Derived" << std::endl;}
        public:
            ~Derived() {method();}
    };
}

using namespace ilrd;

int main()
{
     Base *b = new Derived;
     b->otherMethod();
     delete b;
}