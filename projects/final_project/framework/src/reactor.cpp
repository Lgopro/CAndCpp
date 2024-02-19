
#include "reactor.hpp"
#include <iostream>
#include <unistd.h>
using namespace ilrd;

Reactor::Reactor(IListener *listener) : m_listener(listener)
{
}

Reactor::~Reactor()
{
    m_to_stop = true;
}

void Reactor::Register(int fd, IListener::Mode mode, std::function<void(IListener::Mode, int)> func)
{
    IListener::FdModePair pair;
    pair.fd = fd;
    pair.mode = mode;
    m_func_map.insert(std::make_pair(pair, func));
}

void Reactor::UnRegister(int fd, IListener::Mode mode)
{
    IListener::FdModePair pair;
    pair.fd = fd;
    pair.mode = mode;
    m_func_map.erase(pair);
}

void Reactor::Run()
{
    IListener::FdModePair pair;

    m_to_stop = false;
    
    while(m_to_stop == false)
    {
        auto iter = m_func_map.begin();
        std::vector<IListener::FdModePair> vec;
        while(iter != m_func_map.end())
        {
            pair = iter->first;
            vec.push_back(pair);
            ++iter;
        }

        vec = m_listener->Listen(vec);
        
        std::vector<IListener::FdModePair>::iterator iter2 = vec.begin();
        while(iter2 != vec.end())
        {
            std::function<void(IListener::Mode, int)> func = m_func_map[*iter2];
            func(iter2->mode, iter2->fd);
            ++iter2;
        } 

        /* vec.clear(); */
        /* m_func_map.clear(); *///got it here
    }
}

void Reactor::Stop()
{
    m_to_stop = true;
}