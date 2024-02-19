


#include "thread_pool.hpp"
#include <iostream> /*cout*/
#include <mutex> /*mutex*/
using namespace ilrd;

const int TRUE = 1;
const int stop_priority = -1;

void ThreadPool::KillThread(size_t amount)
{
    TaskAndPriority task;
    task.m_priority = stop_priority;
    for(size_t i = 0; i < amount; ++i)
    { 
        m_tasks_queue.Push(task);
    }  
}

ThreadPool::FunctionTask::FunctionTask(std::function<void()> func_):m_func(func_)
{

}

void ThreadPool::FunctionTask::Run()
{
    m_func();
}


void ThreadPool::ThreadAction(ThreadPool &its_me)
{
    while(TRUE)
    {
        std::unique_lock<std::mutex> lock(its_me.pool_mutex);
        its_me.m_condition.wait(lock, [&its_me](){ return 1 == its_me.m_pause_flag; });
        TaskAndPriority task;
        its_me.m_tasks_queue.Pop(task);
        if(stop_priority == task.m_priority)
        {
            break;
        }
        task.m_task->Run(); 
    }
} 

ThreadPool::ThreadPool(size_t num_of_threads):counter(0), m_threads(num_of_threads), m_pause_flag(1)
{
    for(size_t i = 0; i < m_threads; ++i)
    {
        thread_vector.push_back(std::thread(ThreadAction, std::ref(*this)));
    }
}

ThreadPool::~ThreadPool()
{
    KillThread(m_threads);
    for(size_t i = 0; i < thread_vector.size(); ++i)
    {
        thread_vector[i].join();
    }
}

bool ThreadPool::AddTask(std::shared_ptr<ITask> task_, Priority prio_)
{
    TaskAndPriority new_task{task_, prio_};
    m_tasks_queue.Push(new_task);
    return true;
}

void ThreadPool::SetNumThread(size_t new_num)
{
    Pause();
    if(new_num > m_threads)
    {
        while(new_num != m_threads)
        {
            thread_vector.push_back(std::thread(ThreadAction, std::ref(*this)));
            ++m_threads;
        }
    }
    else if(new_num < m_threads)
    {
        KillThread(m_threads - new_num);
        while(new_num != m_threads)
        {
            --m_threads;
        }
    }
    Resume();
}

void ThreadPool::Pause()
{
    m_pause_flag = 0;
}

void ThreadPool::Resume()
{
    m_pause_flag = 1;
    m_condition.notify_all();
} 

