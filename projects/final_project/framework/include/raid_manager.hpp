
#ifndef __RAID_MANAGER_HPP__
#define __RAID_MANAGER_HPP__


#include <unordered_map>
#include <vector>
#include "minnionproxy.hpp"


namespace ilrd
{
    class RAIDManager
    {
        public:

        RAIDManager();
        ~RAIDManager();
        RAIDManager(const RAIDManager& other) = delete;
        RAIDManager& operator=(const RAIDManager& other) = delete;

        size_t GetRightMinnionNumber(size_t offset);
        size_t GetOffsetInMinnion(size_t offset);
        MinnionProxy *GetMinnion();

        private:

        size_t m_size_of_minnion;
        MinnionProxy *m_minnion_proxy;  
    };
}

#endif