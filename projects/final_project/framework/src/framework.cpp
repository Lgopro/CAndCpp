


#include "framework.hpp"

#include <algorithm>
using namespace ilrd;


void Framework::Run()
{
    GetFrameWorkReactor()->Run();
}

void Framework::Stop()
{
    GetFrameWorkReactor()->Stop();
}

void Framework::RegisterAll(std::vector<std::pair<int, int>>& fds, IProxy* proxy)
{
    IListener::Mode value;
    for(const auto& fd_pair :fds)
    {
        if(0 == fd_pair.second)
        {
             value = IListener::Mode::READ;
        }
        else
        {
            value = IListener::Mode::WRITE;
        }
        this->m_input_mediator.Register(fd_pair.first, value, proxy);
    }
}

