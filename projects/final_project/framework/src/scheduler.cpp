
/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date: 25/10/2023
*/

#include "scheduler.hpp"
#include <unistd.h>
#include <functional>
#include <chrono>
#define __ILRD_CREATOR__
using namespace ilrd;

void Scheduler::ITask::SetExecutionTime(std::chrono::milliseconds execution_time)
{
    m_execution_time = execution_time;
}

std::chrono::milliseconds Scheduler::ITask::GetExecutionTime()
{
    return m_execution_time;
}


void Scheduler::UpdateTime()
{
    if(0 == m_container.IsEmpty())
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        TaskAndTime next_event;
        m_container.Peek(next_event); 
        UpdateTimer(m_timerid, next_event.m_time);
    }
}

void Scheduler::UpdateTimer(timer_t timer, std::chrono::milliseconds run_time)
{
    struct itimerspec value;

    std::chrono::seconds current_time = std::chrono::seconds(time(NULL));
    std::chrono::seconds amount_of_seconds = std::chrono::duration_cast<std::chrono::seconds>(run_time) - current_time;
     if(amount_of_seconds.count())
    {
        value.it_value.tv_sec = amount_of_seconds.count();
    }
    else
    {
       value.it_value.tv_sec = 0; 
    } 


    std::chrono::nanoseconds nano_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(run_time) - std::chrono::duration_cast<std::chrono::nanoseconds>(amount_of_seconds) - std::chrono::duration_cast<std::chrono::nanoseconds>(current_time);
    if(nano_seconds.count() > 0)
    {
        value.it_value.tv_nsec = nano_seconds.count();
    }
    else
    {
        value.it_value.tv_nsec = 1;
    } 

    value.it_interval.tv_sec = 0;
    value.it_interval.tv_nsec = 0;

    timer_settime(m_timerid, 0, &value, nullptr);
}

void Scheduler::AddTask(std::shared_ptr<ITask> task, time_t execute_time)
{
    TaskAndTime value;

    if(nullptr == task)
    {
        throw std::runtime_error("No task available");
    }
    
    value.m_task = task;
    value.m_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::seconds(time(NULL))) + std::chrono::milliseconds(execute_time);
    task->SetExecutionTime(value.m_time);
    m_container.Push(value);
    UpdateTime();
}

void Scheduler::ExecuteEvent(union sigval sig)
{
    TaskAndTime pair;
    Scheduler* scheduler = static_cast<Scheduler*>(sig.sival_ptr);
    scheduler->m_container.Peek(pair);
    pair.m_task->Execute();
    scheduler->m_container.Pop(pair);
    scheduler->UpdateTime(); 
   
}

Scheduler::Scheduler()
{
    memset(&m_its, 0, sizeof(m_its));
    memset(&m_sigevent, 0, sizeof(m_sigevent));

    m_sigevent.sigev_notify_function = &Scheduler::ExecuteEvent;
    m_sigevent.sigev_notify = SIGEV_THREAD;
    m_sigevent.sigev_signo = SIGRTMIN;
    m_sigevent.sigev_value.sival_ptr = this;

    
    if(0 != timer_create(CLOCK_REALTIME, &m_sigevent, &m_timerid))
    {
        throw std::runtime_error("Could not create timer");
    }
}

Scheduler::~Scheduler()
{
    timer_delete(m_timerid);
}

void Scheduler::ConvertToSeconds(std::chrono::milliseconds mil_sec)
{
    std::chrono::seconds current_time = std::chrono::seconds(NULL);
    std::chrono::seconds amount_of_seconds = current_time - std::chrono::duration_cast<std::chrono::seconds>(mil_sec);
    m_its.it_value.tv_sec = amount_of_seconds.count();

    std::chrono::nanoseconds nano_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(mil_sec) - std::chrono::duration_cast<std::chrono::nanoseconds>(amount_of_seconds) - std::chrono::duration_cast<std::chrono::nanoseconds>(current_time);
    m_its.it_value.tv_nsec = nano_seconds.count();
}