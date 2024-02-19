
/*
Rev: Ido Isaacs.
Dev: Leonid Golovko
status: finished
date: 04/09/2023
*/

#include "bitarray.hpp"

using namespace ilrd;

BitArray::BitArray():array(0)
{
}

BitArray::~BitArray()
{

}

BitArray::BitProxy BitArray::operator[](size_t index)
{
    return BitArray::BitProxy(*this, index);
}


BitArray::BitProxy::operator bool() const
{
    return ((array_bit.array >> index) & (1));
}

BitArray::BitProxy::BitProxy(BitArray& bit_array, size_t size):array_bit(bit_array), index(size)
{

}

void BitArray::BitProxy::operator=(bool value)
{
    if(value)
    {
         this->array_bit.array |= (value << this->index);
    }
    else
    {
        this->array_bit.array &= ~(1 << this->index);
    }
}


