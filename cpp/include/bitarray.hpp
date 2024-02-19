/*
Rev: Ido Isaacs.
Dev: Leonid Golovko
status: finished
date: 04/09/2023
*/
#ifndef __BIT_ARRAY_HPP__
#define __BIT_ARRAY_HPP__
#include <iostream>


namespace ilrd
{
    
    class BitArray
    {
    public:
        BitArray();
        ~BitArray();
        
    
    private:
        size_t array;
        class BitProxy
        {
            public:
            BitProxy(BitArray& bit_array, size_t size);
            void operator=(bool value);
            operator bool() const;
            

            private:
            void operator=(BitProxy& value)=delete;
            BitArray& array_bit;
            size_t index;
        };
        public:
        BitProxy operator[](size_t index);
    };
}





#endif /*__BIT_ARRAY_HPP__*/
