
#include "bitarray.hpp"

using namespace ilrd;

int main()
{
    BitArray b1;
    BitArray b2;
    int i = 0;

    if (b1[i])
    {
        std::cout << "Its 1" <<std::endl;
    }
    else
    {
        std::cout << "Its 0" <<std::endl;
    }

    b1[i] = true;
    if (b1[i])
    {
        std::cout << "Its 1" <<std::endl;
    }
    else
    {
        std::cout << "Its 0" <<std::endl;
    }
    b1[i] = b2[i];
    if (b1[i])
    {
        std::cout << "Its 1" <<std::endl;
    }
    else
    {
        std::cout << "Its 0" <<std::endl;
    }
}