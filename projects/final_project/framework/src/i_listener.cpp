
#include <sys/select.h>
#include "i_listener.hpp"
#include <unistd.h>
#include <iostream>


int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    return y;
}

std::vector<IListener::FdModePair> ListenHere::Listen(std::vector<FdModePair>& fds)
{ 
    fd_set read_fd;
    fd_set write_fd;

    timeval timeout;
    timeout.tv_sec = 10;
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
    else
    {
        std::cout<< "Got here" << std::endl;
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
    }
    return (return_vector);
}