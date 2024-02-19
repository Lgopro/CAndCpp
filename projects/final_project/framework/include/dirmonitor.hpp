/*
Rev: Ido Issacs.
Dev: Leonid Golovko
status: finished
date: 28/09/2023
*/
#ifndef __DIRMONITOR_HPP__
#define __DIRMONITOR_HPP__

#include "dispatcher.hpp"
#include <sys/inotify.h>
#include <iostream>
#include <thread>

namespace ilrd
{
    class DirMonitor
    {
    public:
        explicit DirMonitor(const std::string& path_name);
        ~DirMonitor() noexcept;

        DirMonitor(const DirMonitor &other) = delete;
        DirMonitor &operator=(const DirMonitor &other) = delete;
        //Description: Register an call back to be able to broadcast to all the users registered.
        //Input variables: ACallBack class with a string.
        //Return variables: void.
        //Time complexity: O(1).
        //Space complexity: O(1).
        inline void Register(ACallBack<std::string> *callback); 
        //Description: Unregister an call back to be able to broadcast to all the users registered.
        //Input variables: ACallBack class with a string.
        //Return variables: void.
        //Time complexity: O(1).
        //Space complexity: O(1).
        inline void UnRegister(ACallBack<std::string> *callback); 
        //Description: Run the monitor by creating a thread and calling Monitor.
        //Input variables: void.
        //Return variables: void.
        //Time complexity: O(n).
        //Space complexity: O(1).
        void Run();

       
    private:

        static void Monitor(DirMonitor &d_monitor);

        

        Dispatcher<std::string> m_dispatcher;
        std::string m_dir_path;
        std::thread *m_thread;
        bool m_continue_loop = true;
    };

inline void DirMonitor::Register(ACallBack<std::string>* callback)
{
    m_dispatcher.Register(callback);
}

inline void DirMonitor::UnRegister(ACallBack<std::string>* callback)
{
    m_dispatcher.UnRegister(callback);
}

}

#endif