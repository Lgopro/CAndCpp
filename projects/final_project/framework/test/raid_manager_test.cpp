
#include "raid_manager.hpp"
#include "minnionproxy.hpp"
#include "stdio.h"
#include "handleton_inst.hpp"

using namespace ilrd;

int main()
{
    RAIDManager manager;
    size_t offset1 = 1777;
    size_t offset2 = 1023;

    char arr1[] = "Hello bro!";
    char arr2[] = "Oh no im a a mistake of nature";

    char ip1[] = "192.1.2.3";
    char ip2[] = "192.1.2.4";
    char ip3[] = "192.1.2.5";

    int fd1 = 1;
    int fd2 = 2;
    int fd3 = 3;

    manager.GetMinnion()->RegisterMinnion(fd1, ip1);
    manager.GetMinnion()->RegisterMinnion(fd2, ip2);
    manager.GetMinnion()->RegisterMinnion(fd3, ip3);

    size_t minnion_number1 = manager.GetRightMinnionNumber(offset1);
    size_t minnion_number2 = manager.GetRightMinnionNumber(offset2);

    std::cout << "minnion_number1 is: " << minnion_number1 << " and minnion_number2 is: " << minnion_number2 << std::endl;


    size_t offset_in_minnion1 = manager.GetOffsetInMinnion(1777);
    size_t offset_in_minnion2 = manager.GetOffsetInMinnion(1023);

    std::cout << "offset_in_minnion1 is: " << offset_in_minnion1 << " and offset_in_minnion2 is: " << offset_in_minnion2 << std::endl;
    

    bool status = manager.GetMinnion()->Write(arr1, offset_in_minnion1, minnion_number1);
    bool status2 = manager.GetMinnion()->Write(arr1, offset_in_minnion2, minnion_number2);

    std::cout << "status is: " << status <<std::endl;
    std::cout << "status2 is: " << status2 <<std::endl;

    return 0;
    
}