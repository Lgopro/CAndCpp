/*
Rev: Ido Issacs.
Dev: Leonid Golovko
status: finished
date: 28/09/2023
*/
#define _POSIX_SOURCE
#include <unistd.h>
#include <string.h>
#include <thread>
#include "dispatcher.hpp"
#include "dirmonitor.hpp"
using namespace ilrd;

const int FAIL = -1;
const int UNTIL_END = 1;
const int SIZE = 300;
const int READ_SIZE = 20000;


void DirMonitor::Run()
{
    m_thread = new std::thread (Monitor, std::ref(*this));
}


void DirMonitor::Monitor(DirMonitor &d_monitor)
{

    int inotify_data = inotify_init();
    if(FAIL == inotify_data)
    {
        throw std::runtime_error("Cannot open inotify_data");
        return;
    }

    int watch = inotify_add_watch(inotify_data, d_monitor.m_dir_path.c_str(), IN_CREATE | IN_DELETE | IN_MODIFY);

    if(FAIL == watch)
    {
        throw std::runtime_error("Failed to add_watch");
        close(inotify_data);
        return;
    }

    int fd;
    char buffer[READ_SIZE];
    ssize_t amount_of_data;
    while(d_monitor.m_continue_loop)
    {
        fd_set read_fds;
        fd = inotify_data;
        FD_ZERO(&read_fds);
        FD_SET(fd, &read_fds);
        
        timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int ready = select(inotify_data + 1, &read_fds, NULL, NULL, &timeout);
        if(ready > 0)
        {
            amount_of_data = read(inotify_data, buffer, READ_SIZE);
            if(FAIL == amount_of_data)
            {
                throw std::runtime_error("Failed to read");
                return;
            }
            size_t counter = 0;
            while(counter != amount_of_data)
            {
                inotify_event *event = reinterpret_cast<inotify_event *>(&buffer[counter]);
                d_monitor.m_dispatcher.Broadcast(event->name);
                counter += sizeof(struct inotify_event) + event->len;
            }
        }
    }
    inotify_rm_watch(inotify_data, watch);
    close(inotify_data);
}


DirMonitor::DirMonitor(const std::string& path_name):m_dir_path(path_name)
{
}

DirMonitor::~DirMonitor() noexcept
{
    m_continue_loop = false;
    m_thread->join();
    delete m_thread;

}
