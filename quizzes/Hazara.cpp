
#include <iostream>
#include <semaphore.h>
#include <thread>
#include <condition_variable>
#include <mutex>


sem_t prod;
sem_t cons;
std::mutex m_mutex;
std::condition_variable m_con;
bool flag = false;

void Producer()
{
    while(1)
    {
        sem_wait(&prod);
        std::cout<< "Ping" << std::endl;
        sem_post(&cons);
    }
}

void Consumer()
{
    while(1)
    {
        sem_wait(&cons);
        std::cout<< "Pong" << std::endl;
        sem_post(&prod);
    }
}

void Test1()
{
    sem_init(&prod, 0, 1);
    sem_init(&cons, 0, 0);

    std::thread t1(Producer);
    std::thread t2(Consumer);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    t1.detach();
    t2.detach();
}

void Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_con.wait(lock, [&]{return flag;});
    std::cout<< "Released" << std::endl;
}

void Release()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<< "Waiting for 2 sec" << std::endl;
    std::cout<< "Notify to release" << std::endl;
    m_con.notify_one();
    flag = true;
}

void Test2()
{
    std::thread t1(Wait);
    std::thread t2(Release);

    std::this_thread::sleep_for(std::chrono::seconds(4));

    t1.join();
    t2.join();
}

int main()
{

    /* Test1(); */

    Test2();

    return 0;
}