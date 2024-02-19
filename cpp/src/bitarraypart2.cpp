

#include "bitarraypart2.hpp"

using namespace ilrd;

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitArray()
{
    std::fill_n(m_array, NUM_BITS / 64 + ((NUM_BITS % 64) != 0), 0);
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::~BitArray()
{
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Set(size_t index, bool val)
{
    size_t array_index = index / 64;
    size_t bit_index = index % 64;
    if(val)
    {
        m_array[array_index] |= (val << bit_index);
    }
    else
    {
        m_array[array_index] &= ~(1 << bit_index);
    }
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Set(bool val)
{
    for(int i = 0;i < NUM_BITS; ++i)
    {
        Set(i, val);
    }
}   

template <size_t NUM_BITS>
bool BitArray<NUM_BITS>::Get(size_t index) const
{
    return (m_array & (1ULL << index));
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Flip(size_t index)
{
    m_array^=(1ULL << index);
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Flip()
{
    for(int i = 0;i < NUM_BITS; ++i)
    {
        Flip(i);
    }
}

template <size_t NUM_BITS>
size_t BitArray<NUM_BITS>::Count() const
{
    size_t result = 0;
    size_t array_index = 0;
    size_t bit_index = 0;
    for(int i = 0;i < NUM_BITS; ++i)
    {
        array_index = i / 64;
        bit_index = i % 64;
        if(m_array[array_index] & (1ULL << bit_index))
        {
            ++result;
        }
    }
    return result;
}
template <size_t NUM_BITS>
std::string BitArray<NUM_BITS>::ToString() const
{
    std::string str;
    str.resize(NUM_BITS);
    for(int i = 0; i < NUM_BITS; ++i)
    {
        str[i] = Get(i);
    }
    return str;
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy::BitProxy(BitArray<NUM_BITS>& bitarray, size_t index):m_array(bitarray), m_index(index)
{

}

template <size_t NUM_BITS>
typename BitArray<NUM_BITS>::BitProxy& BitArray<NUM_BITS>::BitProxy::operator=(bool val)
{
    if(val)
    {
         this->m_array.m_array |= (val << this->m_index);
    }
    else
    {
        this->m_array.m_array &= ~(1 << this->m_index);
    }
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy::operator bool() const
{
    return ((m_array.m_array >> m_index) & (1));
}