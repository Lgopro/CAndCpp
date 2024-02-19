
/*
Rev: Ido Peled.
Dev: Leonid Golovko
status: finished
date: 10/09/2023
*/
#ifndef __BIT_ARRAY2_HPP__
#define __BIT_ARRAY2_HPP__
#include <iosfwd>
#include <algorithm> // foreach()
#include <iostream>  // size_t, cout
#include <string>    // string
#include <numeric>   // acuumulate

const size_t amount_of_chars = 256;
const size_t BITS = 64;

namespace ilrd
{
    class CountBit
    {
    public:
        CountBit() : m_counter(0){};
        void operator()(unsigned char location)
        {
            m_counter += LUT[location];
        }

        size_t m_counter;

    private:
        constexpr static unsigned char LUT[amount_of_chars] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4,
                                                               4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5,
                                                               4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
                                                               4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6,
                                                               4, 5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
                                                               4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5,
                                                               4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4,
                                                               4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                                                               4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};
    };

    template <size_t NUM_BITS>
    class BitArray
    {
    private:
        class BitProxy;

    public:
        explicit BitArray();
        ~BitArray() = default;
        BitArray(const BitArray<NUM_BITS> &) = default;
        BitArray<NUM_BITS> &operator=(const BitArray<NUM_BITS> &) = default;

        void Set(size_t index, bool val);
        void Set(bool val);
        bool Get(size_t index) const;
        void Flip(size_t index);
        void Flip();
        size_t Count() const;
        std::string ToString() const;

        bool operator[](size_t index) const;
        BitProxy operator[](size_t index);
        BitArray<NUM_BITS> &operator|=(const BitArray<NUM_BITS> &other);
        BitArray<NUM_BITS> &operator&=(const BitArray<NUM_BITS> &other);
        BitArray<NUM_BITS> &operator^=(const BitArray<NUM_BITS> &other);
        bool operator==(const BitArray<NUM_BITS> &rhs) const;
        bool operator!=(const BitArray<NUM_BITS> &rhs) const;
        

    private:
        class BitProxy
        {
        public:
            BitProxy(BitArray<NUM_BITS> &bitarray, size_t index);
            BitProxy &operator=(bool val);
            BitProxy &operator=(BitProxy &other);
            operator bool() const;

            BitProxy(BitProxy &other) = delete;

        private:
            BitArray<NUM_BITS> &m_array;
            size_t m_index;
        };

        size_t m_array[NUM_BITS / 64 + ((NUM_BITS % 64) != 0)];
        void SetLast();
        const static size_t variables_amount = NUM_BITS / 64 + ((NUM_BITS % 64) != 0);
    };
    
}
#endif

using namespace ilrd;


template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitArray()
{
    std::fill(m_array, m_array + variables_amount, 0);
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Set(size_t index, bool val)
{
    if (index >= NUM_BITS)
    {
        throw std::out_of_range("Index is out of number of bits given");
    }

    size_t array_index = index / 64;
    size_t bit_index = index % 64;
    

    if (val)
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
    
    auto SetAll = [&val](size_t &value)
    {
        size_t largestSizeT = std::numeric_limits<size_t>::max();
        value = largestSizeT * val;
    };
    std::for_each(m_array, &m_array[variables_amount], SetAll);
    SetLast();
}

template <size_t NUM_BITS>
bool BitArray<NUM_BITS>::Get(size_t index) const
{
    if (index >= NUM_BITS)
    {
        throw std::out_of_range("Index is out of number of bits given");
    }
    size_t array_index = index / 64;
    size_t bit_index = index % 64;
    
    return (m_array[array_index] & (1ULL << bit_index));
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Flip(size_t index)
{
    if (index >= NUM_BITS)
    {
        throw std::out_of_range("Index is out of number of bits given");
    }
    size_t array_index = index / 64;
    size_t bit_index = index % 64;
    m_array[array_index] ^= (1ULL << bit_index);
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::Flip()
{
    size_t largestSizeT = std::numeric_limits<size_t>::max();
    auto FlipAll = [&largestSizeT](size_t &value)
    {
        value ^= largestSizeT;
    };
    std::for_each(m_array, &m_array[variables_amount], FlipAll);
    SetLast();
}

template <size_t NUM_BITS>
void BitArray<NUM_BITS>::SetLast()
{
    size_t largestSizeT = std::numeric_limits<size_t>::max();
    size_t mask_of_last_var = largestSizeT >> (64 - (NUM_BITS % 64));
    m_array[variables_amount - 1] &= mask_of_last_var;
}

template <size_t NUM_BITS>
size_t BitArray<NUM_BITS>::Count() const
{
    size_t temp[variables_amount];
    std::copy(m_array, m_array + variables_amount, temp);
    CountBit count;
    count = std::for_each(reinterpret_cast<unsigned char *>(temp), reinterpret_cast<unsigned char *>(temp) + ((NUM_BITS / 8) + ((NUM_BITS % 8) != false)), count);
    return count.m_counter;
}

template <size_t NUM_BITS>
std::string BitArray<NUM_BITS>::ToString() const
{
    std::string str;
    str.resize(NUM_BITS);
    for (int i = 0; i < NUM_BITS; ++i)
    {
        if (0 == Get(i))
        {
            str[NUM_BITS - i - 1] = '0';
        }
        else
        {
            str[NUM_BITS - i - 1] = '1';
        }
    }
    return str;
}

template <size_t NUM_BITS>
bool BitArray<NUM_BITS>::operator[](size_t index) const
{
    return Get(index);
}

template <size_t NUM_BITS>
typename BitArray<NUM_BITS>::BitProxy BitArray<NUM_BITS>::operator[](size_t index)
{
    return BitArray::BitProxy(*this, index);
}

template <size_t NUM_BITS>
BitArray<NUM_BITS> &BitArray<NUM_BITS>::operator|=(const BitArray<NUM_BITS> &other)
{
    std::transform(m_array, &m_array[variables_amount], other.m_array, m_array, std::bit_or());
    return *this;
}

template <size_t NUM_BITS>
BitArray<NUM_BITS> &BitArray<NUM_BITS>::operator&=(const BitArray<NUM_BITS> &other)
{
    std::transform(m_array, &m_array[variables_amount], other.m_array, m_array, std::bit_and());
    return *this;
}

template <size_t NUM_BITS>
BitArray<NUM_BITS> &BitArray<NUM_BITS>::operator^=(const BitArray<NUM_BITS> &other)
{
    std::transform(m_array, &m_array[variables_amount], other.m_array, m_array, std::bit_xor());
    return *this;
}

template <size_t NUM_BITS>
bool BitArray<NUM_BITS>::operator==(const BitArray<NUM_BITS> &rhs) const
{
    return (std::equal(m_array, &m_array[variables_amount], rhs.m_array));
}

template <size_t NUM_BITS>
bool BitArray<NUM_BITS>::operator!=(const BitArray<NUM_BITS> &rhs) const
{
    return !(*this == rhs);
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy::BitProxy(BitArray<NUM_BITS> &bitarray, size_t index) : m_array(bitarray), m_index(index)
{
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy &BitArray<NUM_BITS>::BitProxy::operator=(bool val)
{
    size_t array_index = this->m_index / 64;
    size_t bit_index = this->m_index % 64;
    if (val)
    {
        m_array.m_array[array_index] |= (val << bit_index);
    }
    else
    {
        m_array.m_array[array_index] &= ~(1 << bit_index);
    }
    return (*this); 
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy &BitArray<NUM_BITS>::BitProxy::operator=(BitProxy &other)
{
    m_array.Set(other.m_index, Get(other.m_index));
}

template <size_t NUM_BITS>
BitArray<NUM_BITS>::BitProxy::operator bool() const
{
    size_t array_index = this->m_index / 64;
    size_t bit_index = this->m_index % 64;
    return ((m_array.m_array[array_index] >> bit_index) & (1));
}
