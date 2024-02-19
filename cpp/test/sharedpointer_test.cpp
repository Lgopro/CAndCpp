
/*
Rev: Ido Isaacs.
Dev: Leonid Golovko
status: finished
date: 04/09/2023
*/


#include "sharedpointer.hpp"



namespace ilrd
{
    
    class Base
        {
            public:
            Base(){std::cout<< "Base Ctor" <<std::endl;}
            virtual void Print(){std::cout<< "Im Base" <<std::endl;}
            ~Base(){std::cout<< "Base Dtor" <<std::endl;}
        };
        class Derived : public Base
        {
            public:
            Derived(){std::cout<< "Derived Ctor" <<std::endl;}
            virtual void Print(){std::cout<< "Im Derived" <<std::endl;}
            ~Derived(){std::cout<< "Derived Dtor" <<std::endl;}
        };
}



int main()
{
    SharedPointer<int> Class1(new int(5));
    int result = Class1.GetCounter();
    std::cout<< result << std::endl;
    int number = *Class1;
    std::cout<< "number" << number << std::endl;
    std::cout<< "Class" << *Class1 << std::endl;
    

    SharedPointer<Base> Class2(new Base);
    /* SharedPointer<Derived> Class3(new Base); */ /*FAIL*/
    SharedPointer<Base> Class4(new Derived);
    SharedPointer<Derived> Class5(new Derived);
    Class2 = Class5; 
    /* Class5 = Class2; */  /*FAIL*/
}
