
/*
Rev: Ido Isaacs
Dev: Leonid Golovko
status: finished
date: 26/10/2023
*/
#include "asyncinjection.hpp"
#include<unistd.h>

using namespace ilrd;

bool Action1()
{
    static int value = 3;
    while(0 != value)
    {
        std::cout<< "First function not finished" <<std::endl;
        --value;
        return false;
    }
    std::cout<< "First function finished" <<std::endl;
    return true;
}

bool Action2()
{
    static int value = 2;
    while(0 != value)
    {
        std::cout<< "Second function not finished" <<std::endl;
        --value;
        return false;
    }
    std::cout<< "Second function finished" <<std::endl;
    return true;
}
bool Action3()
{
    static int value = 1;
    while(0 != value)
    {
        std::cout<< "Third function not finished" <<std::endl;
        --value;
        return false;
    }
    std::cout<< "Third function finished" <<std::endl;
    return true;
}

bool Action4()
{
    static int value = 4;
    while(0 != value)
    {
        std::cout<< "Forth function not finished" <<std::endl;
        --value;
        return false;
    }
    std::cout<< "Forth function finished" <<std::endl;
    return true;
}

int main()
{
    AsyncInjection *value1 = new AsyncInjection(Action1, 4000);
    AsyncInjection *value2 = new AsyncInjection(Action2, 2000);
    AsyncInjection *value3 = new AsyncInjection(Action3, 3000);
    AsyncInjection *value4 = new AsyncInjection(Action4, 1000);


    sleep(30);
    return 0;
}
