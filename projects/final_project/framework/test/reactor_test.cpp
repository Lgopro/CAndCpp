#include <iostream>
#include "reactor.hpp"
#include "i_listener.hpp"
#include <thread>
#include <unistd.h>

using namespace ilrd;
/* 
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
} *//* 

std::vector<IListener::FdModePair> ListenHere::Listen(std::vector<FdModePair>& fds)
{ 
    fd_set read_fd;
    fd_set write_fd;

    timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int max_fd_read = 0;
    int max_fd_write = 0;

    int status = 0;

    FD_ZERO(&read_fd);
    FD_ZERO(&write_fd);

    std::vector<IListener::FdModePair> return_vector;
    std::vector<IListener::FdModePair>::iterator iter = fds.begin();
    for(int i = 0; i < fds.size(); ++i)
    {
        if(iter->mode == IListener::READ)
        {
            FD_SET(iter->fd, &read_fd);
            max_fd_read = max(iter->fd, max_fd_read) + 1; 
        }
        if(iter->mode == IListener::WRITE)
        {
            FD_SET(iter->fd, &write_fd);
            max_fd_write = max(iter->fd, max_fd_write) + 1; 
        }
        ++iter;
    }

    status = select(max(max_fd_read, max_fd_write), &read_fd, &write_fd, NULL, &timeout);
    if(0 > status)
    {
        throw("select fail\n");
    }
    if(0 == status)
    {
        std::cout << "timeout" <<std::endl;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
    }
    iter = fds.begin();
    while(iter != fds.end())
    {
        if((iter->mode == IListener::READ && FD_ISSET(iter->fd, &read_fd)) || 
            (iter->mode == IListener::WRITE && FD_ISSET(iter->fd, &write_fd)))
        {
            return_vector.push_back(*iter);
        }
        ++iter;
    }

    return (return_vector);
} */

void FunctionGeneral(IListener::Mode mode, int fd)
{
    std::string my_mode;
    if(IListener::Mode::WRITE == mode)
    {
        my_mode = "WRITE";
    }
    else
    {
        my_mode = "READ";
    }
    std::cout<< "Im fd: " << fd << " with mode of: " <<  my_mode << std::endl;
}



ListenHere listen;
Reactor reactor(&listen);

void FunctionStop(IListener::Mode mode, int fd)
{
    std::string my_mode;
    if(IListener::Mode::WRITE == mode)
    {
        my_mode = "WRITE";
    }
    else
    {
        my_mode = "READ";
    }
    std::cout<< "Im fd: " << fd << " with mode of: " <<  my_mode << std::endl;
    reactor.Stop();
}

int main()
{
    
    IListener::FdModePair pair1;
    IListener::FdModePair pair2;
    IListener::FdModePair pair3;
    IListener::FdModePair pair4;
    IListener::FdModePair pair5;

    pair1.fd = 1;
    pair1.mode = IListener::Mode::WRITE;
    pair2.fd = 2;
    pair2.mode = IListener::Mode::WRITE;
    pair3.fd = 3;
    pair3.mode = IListener::Mode::READ;
    pair4.fd = 4;
    pair4.mode = IListener::Mode::READ;
    pair5.fd = 6;
    pair5.mode = IListener::Mode::WRITE;

    reactor.Register(pair1.fd, pair1.mode, FunctionGeneral);
    reactor.Register(pair2.fd, pair2.mode, FunctionGeneral);
    reactor.Register(pair3.fd, pair3.mode, FunctionGeneral);
    reactor.Register(pair4.fd, pair4.mode, FunctionGeneral);
    reactor.Register(pair5.fd, pair5.mode, FunctionGeneral);

    
    std::thread t1([&]{reactor.Run();});
    sleep(3);
    reactor.Stop();
    return 0;
}