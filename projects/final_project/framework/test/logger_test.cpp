
#define __ILRD_CREATOR__
#include "logger.hpp"
#include "handleton.hpp"
using namespace ilrd;

int main()
{
    Logger *check1 = ilrd::Handleton<Logger>::GetInstance();
    for(int i = 0; i < 100; i++)
    {
        check1->Log("hehe boy", Logger::ERROR);
        check1->Log("hihi", Logger::DEBUG);
        check1->Log("otherara", Logger::OTHER);
    }



    return 0;
}