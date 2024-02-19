#ifndef __ILRD_REACTOR_HPP__
#define __ILRD_REACTOR_HPP__

#include <unordered_map>
#include <functional>
#include <vector>

#include "i_listener.hpp"

namespace ilrd
{
    class Reactor
    {
    public:
        Reactor(IListener *listener);
        ~Reactor();
        Reactor(const Reactor &) = delete;
        Reactor &operator=(const Reactor &) = delete;

        void Register(int fd, IListener::Mode mode, std::function<void(IListener::Mode, int)> func);
        void UnRegister(int fd, IListener::Mode mode);
        void Run();
        void Stop();
        
        
    private:
        struct HashFunction
        {
            size_t operator()(const IListener::FdModePair &pair) const
            {
                size_t fd_hash = std::hash<int>{}(pair.fd);
                size_t mode_hash = std::hash<int>{}(static_cast<int>(pair.mode));

                return fd_hash ^ (mode_hash << 2);
            }
        };

        std::unordered_map<IListener::FdModePair, std::function<void(IListener::Mode, int)>, HashFunction>
            m_func_map;
        IListener *m_listener;
        bool m_to_stop = false;
    };
}

#endif //__ILRD_REACTOR_HPP__