/*
Rev: Gil Fridman.
Dev: Leonid Golovko
status: finished
date: 11/09/2023
*/

#ifndef __WAITABLE_QUEUE__
#define __WAITABLE_QUEUE__

#include <iostream> /*cout*/
#include <queue> /*queue*/
#include <chrono> /*chrono*/
#include <mutex> /*mutex*/
#include <condition_variable> /*condition varibale*/


namespace ilrd
{
    template <typename T, typename CONTAINER = std::queue<T>>
    class WaitableQueue
    {
    public:
        WaitableQueue() = default;
        ~WaitableQueue() = default;
        WaitableQueue(const WaitableQueue<T, CONTAINER> &other_) = delete;
        WaitableQueue<T, CONTAINER> &operator=(const WaitableQueue<T, CONTAINER> &other_) = delete;
        void Push(const T &data_);
        void Pop(T &outparam_);
        bool Pop(std::chrono::milliseconds timeout_, T &outparam_);
        bool IsEmpty() const;
        void Peek(T &outparam_);

    private:
        CONTAINER m_container;
        mutable std::mutex m_mutex;
        std::condition_variable m_condition;
    };

    template <typename T ,typename Container = std::vector<T>,typename Compare = std::less<typename Container::value_type>>
    class PriorityQueue : private std::priority_queue<T, Container, Compare>
    {
        public:
        inline T front();
        using std::priority_queue<T, Container, Compare>::pop;
        using std::priority_queue<T, Container, Compare>::push;
        using std::priority_queue<T, Container, Compare>::empty;
    };



template <typename T ,typename Container,typename Compare >
inline T PriorityQueue<T, Container, Compare>::front()
{
    return std::priority_queue<T, Container, Compare>::top();
} 

template <typename T, typename CONTAINER>
void WaitableQueue<T, CONTAINER>::Push(const T &data_)
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_container.push(data_);
        /* #ifndef NDEBUG
        std::cout << "Push: " << data_ << std::endl;
        #endif */
    }
    m_condition.notify_one();
}

template <typename T, typename CONTAINER>
void WaitableQueue<T, CONTAINER>::Pop(T &outparam_)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [this](){ return !m_container.empty(); });
    outparam_ = m_container.front();
    m_container.pop();
    /* #ifndef NDEBUG
    std::cout << "Pop: " << outparam_ << std::endl;
    #endif */
}

template <typename T, typename CONTAINER>
void WaitableQueue<T, CONTAINER>::Peek(T &outparam_)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [this](){ return !m_container.empty(); });
    outparam_ = m_container.front();
}
template <typename T, typename CONTAINER>
bool WaitableQueue<T, CONTAINER>::Pop(std::chrono::milliseconds timeout_, T &outparam_)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    // Use a condition variable to wait for data or timeout
    if (!m_condition.wait_for(lock, timeout_, [this] { return !m_container.empty(); })) 
    {
        // Timeout occurred, no data available
        return false;
    }
    outparam_ = m_container.front();
    m_container.pop();
    /* #ifndef NDEBUG
    std::cout << "Pop: " << outparam_ << std::endl;
    #endif */
    return true;
}

template <typename T, typename CONTAINER>
bool WaitableQueue<T, CONTAINER>::IsEmpty() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_container.empty();
}

}
#endif