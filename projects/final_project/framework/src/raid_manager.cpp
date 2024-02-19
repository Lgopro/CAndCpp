
#include "raid_manager.hpp"
#include "handleton_inst.hpp"
#include <iostream>
#include "string.h"

using namespace ilrd;


RAIDManager::RAIDManager():m_size_of_minnion(1024)
{
    m_minnion_proxy = new MinnionProxy;
}   

RAIDManager::~RAIDManager()
{
    delete m_minnion_proxy;
} 

size_t RAIDManager::GetRightMinnionNumber(size_t offset)
{
    return offset/m_size_of_minnion;
}

size_t RAIDManager::GetOffsetInMinnion(size_t offset) 
{
    return offset % m_size_of_minnion;
}

MinnionProxy *RAIDManager::GetMinnion()
{
    return GetMinnionInstance();
}