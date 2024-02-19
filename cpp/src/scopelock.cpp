/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 03/09/23
*/
#include <iostream>
#include <thread>
#include <mutex>
std::mutex mutex_t;

namespace ilrd
{
    template <class T>
    class Lock
    {
    public:
        Lock(T& value);
        ~Lock();
        
    private:
    Lock(const Lock& other)=delete;
    Lock& operator=(const Lock& other)=delete;
    T &value_t;
    
    };
}

template <class T>
ilrd::Lock<T>::Lock(T& value):value_t(value)
{
    value_t.lock();
}


template <class T>
ilrd::Lock<T>::~Lock()
{
    value_t.unlock();
}

void Test()
{
    {
        ilrd::Lock<std::mutex> obj(mutex_t);
        std::cout << "Locked." << std::endl;
        // Simulate some critical section work
        std::this_thread::sleep_for(std::chrono::seconds(2));
    } // The lock will be automatically released when obj goes out of scope

    // Now the lock is released, and you can safely access the mutex_t
    std::cout << "Lock released." << std::endl;
}

int main()
{
    Test();
}