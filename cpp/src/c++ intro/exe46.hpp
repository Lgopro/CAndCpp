

#ifndef __ILRD_SIMPLE_SQUERE_HPP__
#define __ILRD_SIMPLE_SQUERE_HPP__

#include <iostream>
#include <iosfwd>

namespace ilrd
{
template <typename T>
class  Square 
{

public:

    Square(T);
    T GetT()
    {
        return this->length;
    }
private:

    T length;
};

}
#endif