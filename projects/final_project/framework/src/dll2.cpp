/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 21/09/2023
*/
#define __ILRD_CREATOR__
#include <iostream>
#include "handleton.hpp"
#include "handleton_inst.hpp"

using namespace ilrd;

extern "C" CheckClass* bar()
{
    return foo();
}
