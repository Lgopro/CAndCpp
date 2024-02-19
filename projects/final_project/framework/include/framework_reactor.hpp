#ifndef __FRAMEWORK_REACTOR_HPP__
#define __FRAMEWORK_REACTOR_HPP__

#include <unordered_map>
#include <functional>
#include <vector>

#include "i_listener.hpp"
#include "reactor.hpp"

namespace ilrd
{
    class FrameWorkReactor
    {
    public:
        inline FrameWorkReactor();
        ~FrameWorkReactor() = default;
        FrameWorkReactor(const FrameWorkReactor &) = delete;
        FrameWorkReactor &operator=(const FrameWorkReactor &) = delete;

        inline void Register(int fd, IListener::Mode mode, std::function<void(IListener::Mode, int)> func);
        inline void UnRegister(int fd, IListener::Mode mode);
        inline void Run();
        inline void Stop();
        
        
    private:
        Reactor m_reactor;
        ListenHere m_listener;
    };
}

ilrd::FrameWorkReactor::FrameWorkReactor():m_reactor(&m_listener)
{
        
}

void ilrd::FrameWorkReactor::Register(int fd, IListener::Mode mode, std::function<void(IListener::Mode, int)> func)
{
    m_reactor.Register(fd, mode, func);
}

void ilrd::FrameWorkReactor::UnRegister(int fd, IListener::Mode mode)
{
    m_reactor.UnRegister(fd, mode);
}

inline void ilrd::FrameWorkReactor::Run()
{
    m_reactor.Run();
}

inline void ilrd::FrameWorkReactor::Stop()
{
    m_reactor.Stop();
}

#endif //__ILRD_REACTOR_HPP__