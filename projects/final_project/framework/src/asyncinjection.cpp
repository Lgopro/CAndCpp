/*
Rev: Ido Isaacs
Dev: Leonid Golovko
status: finished
date: 26/10/2023
*/

#include "asyncinjection.hpp"
#include "scheduler.hpp"
#include "handleton.hpp"

#include <chrono>
#include <iostream>

using namespace ilrd;

void AsyncInjection::TaskExecute()
{
    bool status;

    status = m_action();
    if(false == status)
    {
        UpdateTimer();
        return;
    }
    delete this;
}

void AsyncInjection::UpdateTimer()
{
    m_run_time += std::chrono::milliseconds(m_time_interval_miliseconds);
    GetSchedulerInstance()->AddTask(m_async, m_time_interval_miliseconds);
}

AsyncInjection::AsyncInjection(std::function<bool()> action,int time_interval_miliseconds):m_action(action), 
m_time_interval_miliseconds(time_interval_miliseconds), m_run_time(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now())), m_async(new AsyncInjectionTask(*this))
{
    Scheduler *scheduler = GetSchedulerInstance();
    scheduler->AddTask(m_async, m_time_interval_miliseconds);
}

AsyncInjection::AsyncInjectionTask::AsyncInjectionTask(AsyncInjection& async_injection):m_async_injection(async_injection)
{
}

void AsyncInjection::AsyncInjectionTask::Execute()
{
    m_async_injection.TaskExecute();
}