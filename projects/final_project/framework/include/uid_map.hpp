#ifndef __UID_MAP_HPP__
#define __UID_MAP_HPP__

#include <stdint.h>
#include <map>

namespace ilrd
{
    
    
    class UIDMap
    {
        public:

        UIDMap() = default;
        ~UIDMap() = default;
        UIDMap(const UIDMap& other) = default;
        UIDMap& operator=(const UIDMap& other) = default;

        enum Status
        {
            WAIT_TO_BE_SENT = 0,
            SENT,
            RECIEVED_MINNION,
            RECIEVED_MASTER,
            ERROR
        };

        void RegisterUID(u_int32_t uid);
        void UnregisterUID(u_int32_t uid);
        void SetUIDstatus(u_int32_t uid, Status status);
        Status GetUIDstatus(u_int32_t uid);
        void Print() const;

        private:

        std::map<u_int32_t, Status> m_uid_map;

    };

    class CheckUIDInMap
    {
        public:
            CheckUIDInMap(u_int32_t uid);
            
            bool operator()();
        private:
            u_int32_t m_uid;
    };
    
}


#endif