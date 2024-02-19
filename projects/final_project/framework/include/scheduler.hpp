
/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date: 25/10/2023
*/
#ifndef __SCHEDULER_HPP__
#define __SCHEDULER_HPP__

#include <iostream>
#include <ctime>
#include <signal.h>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include "waitable_queue.hpp"
#include "handleton.hpp"


namespace ilrd
{
    template <typename T> class Handleton;
    class Scheduler
    {
    public:
        Scheduler();
        ~Scheduler();
        class ITask;
        void ConvertToSeconds(std::chrono::milliseconds mil_sec);
        
        struct TaskAndTime
        {
            std::shared_ptr<ITask> m_task;
            std::chrono::milliseconds m_time;
        };
        
        void AddTask(std::shared_ptr<ITask> task, time_t time);
        
        friend class Handleton<Scheduler>;


        class ITask
        {
        public:

            inline virtual ~ITask(){};
            virtual void Execute() = 0;
            void SetExecutionTime(std::chrono::milliseconds execution_time);
            std::chrono::milliseconds GetExecutionTime();
            private:
            std::chrono::milliseconds m_execution_time;

        };

        void UpdateTimer(timer_t timer, std::chrono::milliseconds run_time);
        static void ExecuteEvent(union sigval sig);
        void UpdateTime();
        
        class Compare
        {
        public:
            bool operator()(const TaskAndTime &left, const TaskAndTime &right)
            {
                return (left.m_time >= right.m_time);
            }
        };
    
        
    private:

       
        
        Scheduler& operator=(const Scheduler& other) = delete;
        Scheduler(const Scheduler& other) = delete;
        
        WaitableQueue<TaskAndTime,
                      PriorityQueue<TaskAndTime,
                                    std::vector<TaskAndTime>,
                                    Compare>>
            m_container;



        std::mutex m_mutex;
        sigevent m_sigevent;
        timer_t m_timerid;
        ::time_t m_current_time;
        itimerspec m_its;


    };
}

#endif