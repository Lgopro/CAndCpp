
#ifndef __MINNION_PROXY_HPP__
#define __MINNION_PROXY_HPP__

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include "reactor.hpp"
#include "i_listener.hpp"
#include "string.h"
#include "UDPsocket.hpp"
#include "messageheader.hpp"
#include "uid_map.hpp"
#include <thread>
#include <mutex>

namespace ilrd
{

    class MinnionProxy
    {
        public:

        MinnionProxy() = default;
        ~MinnionProxy() = default;
        MinnionProxy(const MinnionProxy& other) = default;
        MinnionProxy& operator=(const MinnionProxy& other) = default;

        char * Read(size_t amout_of_data, size_t offset_in_minnion, size_t minnion_number, UDPsocket *socket, u_int32_t uid);
        bool Write(char * data, size_t offset_in_minnion, size_t minnion_number, size_t amount_to_write, UDPsocket *socket);
        bool RegisterMinnion(int fd ,char *ip);
        bool UnregisterMinnion(int fd, char *ip);
        
        struct MyKeyHash
        {
            std::size_t operator()(const std::pair<int, char *>& key) const
            {
                static size_t value = 0;
                ++value;
                return value;
            }
        };

        struct MyKeyEqual
        {
            bool operator()(const std::pair<int, char *>& a, const std::pair<int, char *>& b)
            {
                return ((a.first == b.first) && (0 == strcmp(a.second, b.second)));
            }
        };

        std::vector <std::pair<int, char *>> GetFdList();

        void StartReceiverThreadWrite(UDPsocket *socket);
        void StartReceiverThreadRead(UDPsocket *socket);

        private:

        std::thread m_receiverThreadread;
        std::thread m_receiverThreadwrite;
        void ReceiverThreadFunctionRead(UDPsocket *socket);
        void ReceiverThreadFunctionWrite(UDPsocket *socket);
        std::mutex m_mutex_write;
        std::mutex m_mutex_read;
        std::vector <std::pair<int, char *>> m_fd_list;
    };
}

#endif