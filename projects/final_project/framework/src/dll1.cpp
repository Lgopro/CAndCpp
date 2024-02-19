/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 21/09/2023
*/

#include <iostream>
#include "singleton.hpp"
class CheckClass
{
    public:
    void Print(){std::cout << "Addr is: "<< this << std::endl;};
};


extern "C" CheckClass* foo()
{
    CheckClass *check = ilrd::Singleton<CheckClass>::GetInstance();
    check->Print();
    return check;
}