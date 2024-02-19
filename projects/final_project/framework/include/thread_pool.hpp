/*
Rev: Asaf Talker.
Dev: Leonid Golovko
status: finished
date: 14/09/2023
*/
#ifndef __ILRD_THREAD_POOL_HPP__
#define __ILRD_THREAD_POOL_HPP__

#include <iostream> /*cout*/
#include <memory>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>
#include <semaphore.h>
#include <fcntl.h>          /* O_CREAT, O_EXEC          */
#include "waitable_queue.hpp"
namespace ilrd
{
    class ThreadPool
    {
    public:
        class ITask
        {
        public:
            virtual void Run() = 0;
            virtual ~ITask() = default;
        };

        class FunctionTask : public ITask
        {
        public:
            FunctionTask(std::function<void()> func_);
            void Run();

        private:
            std::function<void()> m_func;
        };

        template <typename T>
        class FutureTask : public ITask
        {
        public:
            FutureTask(std::function<T()> func_);
            void Run();
            const T &Get();
            ~FutureTask();
        private:
            std::function<T()> m_func;
            T m_res;
            sem_t *semaphore;
        };

        enum Priority
        {
            LOW,
            MID,
            HIGH
        };

        ThreadPool(size_t num_of_threads = 8);
        ThreadPool(const ThreadPool &other_) = delete;
        ThreadPool &operator=(const ThreadPool &other_) = delete;
        ~ThreadPool();

        bool AddTask(std::shared_ptr<ITask> task_, Priority prio_ = MID);
        void SetNumThread(size_t new_num);
        void Pause();
        void Resume();

        struct TaskAndPriority
        {
            std::shared_ptr<ITask> m_task;
            int m_priority;
        };
    private:
        

        class Compare
        {
        public:
            bool operator()(const TaskAndPriority &left, const TaskAndPriority &right)
            {
                return (left.m_priority < right.m_priority);
            }
        };
        WaitableQueue<TaskAndPriority,
                      PriorityQueue<TaskAndPriority,
                                    std::vector<TaskAndPriority>,
                                    Compare>>
            m_tasks_queue;
        std::vector<std::thread> thread_vector;
        std::atomic<int> counter;
        std::mutex pool_mutex;
        size_t m_threads;
        size_t m_pause_flag;
        std::condition_variable m_condition;
        static void ThreadAction(ThreadPool &its_me);
        void KillThread(size_t amount);
    };



    template <typename T>
    ThreadPool::FutureTask<T>::FutureTask(std::function<T()> func_):m_func(func_)
    {
        semaphore = sem_open("sem_t", O_CREAT, 0644, 0);
        if(NULL == semaphore)
        {
            throw("failed to open semaphore\n");
        }
    }

    template <typename T>
    void ThreadPool::FutureTask<T>::Run()
    {
        sem_post(semaphore);
        m_res = m_func();
    }

    template <typename T>
    const T & ThreadPool::FutureTask<T>::Get()
    {
        sem_wait(semaphore);
        return m_res;
    }
    template <typename T>
    ThreadPool::FutureTask<T>::~FutureTask()
    {
        sem_close(semaphore);
    }
}//Namespace
#endif //__ILRD_THREAD_POOL_HPP__
