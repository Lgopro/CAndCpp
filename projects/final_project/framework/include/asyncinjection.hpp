

/*
Rev: Ido Isaacs
Dev: Leonid Golovko
status: finished
date: 26/10/2023
*/
#include "scheduler.hpp"
#include "handleton_inst.hpp"

#include <functional>
#include <iostream>

#ifndef __ASYNC_HPP__
#define __ASYNC_HPP__

namespace ilrd
{
// AsyncInjection object must by dynamically allocated ("new"), and not deleted by the user. 
    // It deletes itslef when done. 
    class AsyncInjection
    {
    public:
        // Action is a functor returning bool, "true" - done, "false" - reschedule.
        AsyncInjection(std::function<bool()> action, int time_interval_miliseconds);
        void TaskExecute();

    private:
        class AsyncInjectionTask : public Scheduler::ITask
        {
        public:

            AsyncInjectionTask(AsyncInjection& async_injection);
            void Execute();
            

        private:

            AsyncInjection& m_async_injection;
        };

        void UpdateTimer();
        std::function<bool()> m_action;
        int m_time_interval_miliseconds;
        std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> m_run_time;
        std::shared_ptr<AsyncInjectionTask> m_async;
};
}

#endif