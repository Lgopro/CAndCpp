


#include <queue>
#include <chrono> /*chrono*/
#include <mutex>
#include <condition_variable>
#include <iostream>


namespace ilrd
{

    template <typename T, typename CONTAINER = std::queue<T>>
    class WaitableQueue
    {
        public:

        WaitableQueue() = default;
        ~WaitableQueue() = default;
        WaitableQueue(const WaitableQueue& other) = delete;
        WaitableQueue& operator=(const WaitableQueue& other) = delete;

        void Push(const T& value);
        void Pop(T& value);
        void Pop(std::chrono::milliseconds time, T&value);
        void Peek(T& value);

        private:

        CONTAINER m_container;
        std::mutex m_mutex;
        std::condition_variable m_condition;
    }

}


using namespace ilrd;

template <typename T, typename CONTAINER>
void WaitableQueue<T, CONTAINER>::Push(const T& value)
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_container.push(value);

    }
    m_condition.notifyone();
}
        
        
void Pop(T& value)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::m_condition.wait(lock, [this]{return !m_container.isempty();});
    value = m_container.front();
    m_containter.pop();
}

void Pop(std::chrono::milliseconds time, T& value)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::m_condition.wait(lock, time, [this]{return !m_container.isempty();});
    value = m_container.front();
    m_container.pop();
}

void Peek(T& value)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::m_condition.wait(lock, [this]{return !m_container.isempty();});
    value = m_container.front();
}



int main()
{






    return 0;
}