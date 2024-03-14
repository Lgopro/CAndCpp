
#include <mutex>
#include <atomic>
#include <thread>

#ifndef _H_SINGLETON_H_
#define _H_SINGLETON_H_


namespace ilrd
{
    template <typename T>
    class Singleton
    {
        public:

        static T *GetInstance();

        Singleton() = delete;
        ~Singleton() = delete;
        Singleton(const Singleton& other) = delete;
        Singleton& operator=(const Singleton& other) = delete;


        private:
        static std::atomic<T *> m_instance;

        static void Release();


    }
}





#endif