#include <iostream>
#include <queue>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

namespace ilrd
{
    class SyncWrititngReading
    {
    public:
        SyncWrititngReading();
        ~SyncWrititngReading() = default;
        void StartRead();
        void EndRead();
        void StartWrite();
        void EndWrite();

    private:
        SyncWrititngReading(const SyncWrititngReading& other) = delete;
        SyncWrititngReading& operator=(const SyncWrititngReading& other) = delete;
        std::mutex reader_mutex;
        std::atomic<int> counter;
    };
}

using namespace ilrd;


SyncWrititngReading::SyncWrititngReading():counter(0)
{
    
}

void SyncWrititngReading::StartRead()
{
    reader_mutex.lock();
    ++counter;
    #ifndef NDEBUG
    std::cout << "Read" << std::endl;
    #endif
    reader_mutex.unlock();
}

void SyncWrititngReading::EndRead()
{
    --counter;
}

void SyncWrititngReading::StartWrite()
{
    reader_mutex.lock();
    while(0 != counter)
    {

    }
    #ifndef NDEBUG
    std::cout << "Write" << std::endl;
    #endif
}

void SyncWrititngReading::EndWrite()
{
    
    reader_mutex.unlock();
}

void Write(SyncWrititngReading& sync)
{
    sync.StartWrite();
    sync.EndWrite();
}

void Read(SyncWrititngReading& sync)
{
    sync.StartRead();
    sync.EndRead();
}

int main()
{
    int argument;
    const int amount = 10;
    SyncWrititngReading sync; 
    std::thread output[amount];
    
    
    for (int i = 0; i < amount; ++i)
    {
        output[i] = std::thread(Read, std::ref(sync)); 
    }
    std::thread push(Write, std::ref(sync)); 
    push.join();

    for (int i = 0; i < amount; ++i)
    {
        output[i].join();
    }

    return 0;
}