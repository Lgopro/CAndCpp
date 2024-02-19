


#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <condition_variable>
#include <mutex>


sem_t sem1;
sem_t sem2;
std::condition_variable m_variable;
std::mutex mutex1;
bool m_flag = false;



void Test();

void Cond1()
{
    std::unique_lock<std::mutex> lock(mutex1);
    std::cout<< "mutex locked" << std::endl;
    m_variable.wait(lock, [&]{return m_flag;});
    std::cout<< "Im free" << std::endl;

}

void Cond2()
{
    std::cout<< "Wait for 2 sec" << std::endl;
    sleep(2);
    std::cout<< "Make flag true" << std::endl;
    m_flag = true;
    m_variable.notify_one();
}

void Test1()
{
    std::thread t1(Cond1);
    std::thread t2(Cond2);

    sleep(5);

    t1.detach();
    t2.detach();
}

int main()
{
    /* Test(); */
    Test1();
    return 0;
}

void Func1()
{
    while(1)
    {
        sem_wait(&sem2);
        std::cout<< "Ping" << std::endl;
        sem_post(&sem1);
    }
}

void Func2()
{
    while(1)
    {
        sem_wait(&sem1);
        std::cout<< "Pong" << std::endl;
        sem_post(&sem2);
    }
}

void Test()
{
    std::thread t1(Func1);
    std::thread t2(Func2);

    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 1);

    sleep(1);

    t1.detach();
    t2.detach();
}