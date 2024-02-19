#ifndef __UID_HPP__
#define __UID_HPP__

#include <stdint.h>

namespace ilrd
{
    class UID
    {
        public:

        UID():m_value(0){};
        ~UID() = default;
        UID(const UID& other) = default;
        UID& operator=(const UID& other) = default;
        
        uint32_t GenerateUID()
        {
            uint32_t value = m_value;
            ++m_value;
            return value;
        }
        
        private:
        uint32_t m_value;
    };

   

};



#endif