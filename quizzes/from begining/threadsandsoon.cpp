
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "semaphore.h"

std::mutex m_mutex;
std::mutex m_mutex1;
std::condition_variable m_condition;
sem_t m_semaphore1;
sem_t m_semaphore2;
bool value = false;

void Thread1()
{
    for(int i = 0; i < 10; ++i)
    {
        sem_wait(&m_semaphore2);
        std::cout << "Ping" << std::endl;
        sem_post(&m_semaphore1);
    }
    
}

void Thread2()
{
    for(int i = 0; i < 10; ++i)
    {
        sem_wait(&m_semaphore1);
        std::cout << "Pong" << std::endl;
        sem_post(&m_semaphore2);
    }
    
}

void Thread3()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, []{return value;});
    std::cout << "Release" << std::endl;
}


void Thread4()
{   
    std::cout << "Sleeping for 5 seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "turn flag to true" << std::endl;
    value = true; 
    m_condition.notify_all();
}




void Test1();
void Test2();
void Test3();

int main()
{
    Test1();
    Test2();
    Test3();
}




void Test1()
{
    sem_init(&m_semaphore1, 0 ,0);
    sem_init(&m_semaphore2, 0 , 1);

    std::thread t1(Thread1);
    std::thread t2(Thread2);

    sem_destroy(&m_semaphore1);
    sem_destroy(&m_semaphore2);

    t1.join();
    t2.join();
}

void Test2()
{
    std::thread t1(Thread3);
    std::thread t2(Thread4);

    std::thread t3(Thread3);
    std::thread t4(Thread3);

    std::thread t5(Thread3);
    std::thread t6(Thread3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}

size_t counter = 0;

void ThreadCheck(int data)
{
    (void)data;
    std::unique_lock<std::mutex> lock(m_mutex1);
    ++(counter);
    std::cout << "counter is: " << counter << std::endl;
    
}

void Test3()
{
    
    std::unique_lock<std::mutex> lock(m_mutex); 
    std::thread array[10];
    for(int i = 0; i < 10; ++i)
    {
        array[i] = std::thread(ThreadCheck , i);
    }

    for(int i = 0; i < 10; ++i)
    {
        array[i].join();
    }

    m_condition.wait(lock, [&]{return (counter == 10);});


}