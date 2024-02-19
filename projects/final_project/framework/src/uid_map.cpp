

#include "uid_map.hpp"
#include <iostream>
#include "string.h"
#include "handleton_inst.hpp"

using namespace ilrd;


void UIDMap::RegisterUID(u_int32_t uid)
{
    auto iter = m_uid_map.find(uid);

    if(iter == m_uid_map.end())
    {
        m_uid_map[uid] = WAIT_TO_BE_SENT;
    }
    else
    {
        std::cout << "This UID is already registered!" << std::endl;
    }
}
        
void UIDMap::UnregisterUID(u_int32_t uid)
{
    auto iter = m_uid_map.find(uid);
    if(iter != m_uid_map.end())
    {
        m_uid_map.erase(uid);
    }
}
        
void UIDMap::SetUIDstatus(u_int32_t uid, UIDMap::Status status)
{
    auto iter = m_uid_map.find(uid);

    if(iter != m_uid_map.end())
    {
        m_uid_map[uid] = status;
    }
    else
    {
        std::cout << "This UID dont exist!" << std::endl;
    }
}
       
UIDMap::Status UIDMap::GetUIDstatus(u_int32_t uid)
{
    auto iter = m_uid_map.find(uid);
    if(iter != m_uid_map.end())
    {
        return m_uid_map[uid];
    }
    return ERROR;
}



void UIDMap::Print() const
{
    char arr[100];
    for(auto iter : m_uid_map)
    {
        if(iter.second == WAIT_TO_BE_SENT)
        {
            strcpy(arr, "WAIT_TO_BE_SENT");
        }
        if(iter.second == SENT)
        {
            strcpy(arr, "SENT");
        }
        if(iter.second == RECIEVED_MASTER)
        {
            strcpy(arr, "RECIEVED_MASTER");
        }
        if(iter.second == ERROR)
        {
            strcpy(arr, "ERROR");
        }
        std::cout << "uid is: " << iter.first << " status is: " << arr << std::endl;
    }
}


CheckUIDInMap::CheckUIDInMap(u_int32_t uid):m_uid(uid)
{
}

bool CheckUIDInMap::operator()()
{
    UIDMap::Status status = GetUIDMap()->GetUIDstatus(m_uid);
    if(status == UIDMap::Status::WAIT_TO_BE_SENT || status == UIDMap::Status::ERROR)
    {
        std::cout << "Status false" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Status true" << std::endl;
        return true;
    }
}