
/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 21/09/2023
*/

#ifndef __ILRD_HANDLETON_HPP__
#define __ILRD_HANDLETON_HPP__


#include <thread>  //thread
#include <mutex>   //mutex
#include <atomic>  //atomic

namespace ilrd
{
#ifdef __ILRD_CREATOR__

template <class T>
class Handleton
{
public:
    //Description: Get instance of template class T(class, function and so on).
    //Input variables: void.
    //Return variables: template class T.
    //Time complexity: O(1).
    //Space complexity: O(1).
    static T *GetInstance(void);

    Handleton() = delete;
    ~Handleton() = delete;
    Handleton(const Handleton&) = delete;
    Handleton(Handleton&&) = delete;
    Handleton &operator=(const Handleton&) = delete;
    Handleton &operator=(Handleton&&) = delete;
    

private:
    static std::atomic<T *> m_instance;
    //Description: Clean up at the end of the function.
    //Input variables: void.
    //Return variables: void.
    //Time complexity: O(1).
    //Space complexity: O(1).
    static void CleanUp(void);
};
template <typename T>
std::atomic<T *> Handleton<T>::m_instance = nullptr;

template <typename T>
T* Handleton<T>::GetInstance()
{
    T *m_var = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if(nullptr == m_var)
    {
        static std::mutex m_mutex;
        std::lock_guard<std::mutex> lock(m_mutex); 
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
void Handleton<T>::CleanUp()
{
    delete m_instance;
    m_instance = reinterpret_cast<T*>(0xdeadbeef);
}

#endif //__ILRD_CREATOR__
}

#endif //__ILRD_HANDLETON_HPP__
