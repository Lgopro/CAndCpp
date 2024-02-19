/*
Rev: Ido Peled.
Dev: Leonid Golovko
status: finished
date: 10/09/2023
*/
#include "bitarraypart2.hpp"
using namespace ilrd;

int main()
{
    ilrd::BitArray<75> b1;
    ilrd::BitArray<75> b2;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Print to string pass" << std::endl;
    std::cout << "Set 3rd bit as 1" << std::endl;
    b1.Set(3,1);
    std::cout << "Set One Value pass" << std::endl;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Get 3rd bit" << std::endl;
    std::cout << b1.Get(3) << std::endl;
    std::cout << "Get 1st bit" << std::endl;
    std::cout << b1.Get(1) << std::endl;
    std::cout << "Get test passed" << std::endl;
    b1.Set(1);
    std::cout << "Set all to 1" << std::endl;
    std::cout << b1.ToString() << std::endl;
    b1.Set(0);
    std::cout << "Set all to 0" << std::endl;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Set all passed" << std::endl;
    std::cout << "Flip 1st bit" << std::endl;
    b1.Flip(1);
    std::cout << b1.ToString() << std::endl;
    std::cout << "Flip one bit passed" << std::endl;
    std::cout << "Flip all bits" << std::endl;
    b1.Flip();
    std::cout << b1.ToString() << std::endl;
    std::cout << "Flip one bit passed" << std::endl;
    std::cout << "Count" << std::endl;
    std::cout << b1.Count() << std::endl;
    std::cout << "Flip all bits" << std::endl;
    b1.Flip();
    std::cout << "Count" << std::endl;
    std::cout << b1.Count() << std::endl;
    std::cout << "Count passed" << std::endl;
    std::cout << "Second Test" << std::endl;
    b2.Set(1,0);
    b1 |= b2;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Operator |= passed" << std::endl;
    b1[1] = b2[1];
    std::cout << b1.ToString() << std::endl;
    std::cout << "Operator = passed" << std::endl;
    b2.Flip();
    b1.Set(4, 1);
    b1.Set(2, 1);
    b1 &= b2;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Operator &= passed" << std::endl;
    b1 ^= b2;
    std::cout << b1.ToString() << std::endl;
    std::cout << "Operator ^= passed" << std::endl;
    std::cout << "Operator == between b1 and b2" << std::endl;
    std::cout << (b1 == b2) << std::endl;
    std::cout << "Operator == passed" << std::endl;
    std::cout << "Operator != between b1 and b2" << std::endl;
    std::cout << (b1 != b2) << std::endl;
    std::cout << !b1[10] << std::endl;

    return 0;
}