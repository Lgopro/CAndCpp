/*
Rev: Ido Isaacs
Dev: Leonid Golovko
status: finished
date: 19/09/2023
*/
#ifndef __ILRD_SINGLETON_HPP__
#define __ILRD_SINGLETON_HPP__

#include <thread>  //thread
#include <mutex>   //mutex
#include <atomic>  //atomic

namespace ilrd
{
template <typename T>
class Singleton
{
public:

    //Description: Get instance of template class T(class, function and so on).
    //Input variables: void.
    //Return variables: template class T.
    //Time complexity: O(1).
    //Space complexity: O(1).
    static T *GetInstance();

    Singleton() = delete;
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton &operator=(const Singleton&) = delete;
    Singleton &operator=(Singleton&&) = delete;
    ~Singleton() = delete;

private:

    static std::atomic<T *> m_instance;
    //Description: Clean up at the end of the function.
    //Input variables: void.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    static void CleanUp();
};

template <typename T>
std::atomic<T *> Singleton<T>::m_instance = nullptr;

template <typename T>
T* Singleton<T>::GetInstance()
{
    T *m_var = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if(nullptr == m_var)
    {
        static std::mutex m_mutex;
        std::lock_guard<std::mutex> lock(m_mutex); //only close and open
        m_var = m_instance.load(std::memory_order_relaxed);
        if(nullptr == m_var)
        {
            m_var = new T;
            m_instance.store(m_var, std::memory_order_release);
            std::atexit(CleanUp);
        }
    }
    return m_var;
}

template <typename T>
void Singleton<T>::CleanUp()
{
    delete m_instance;
    m_instance = reinterpret_cast<T*>(0xdeadbeef);
}

}
#endif //__ILRD_SINGLETON_HPP__