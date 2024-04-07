

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <chrono>
#include <mutex>
#include <condition_variable>

sem_t cons;
sem_t prod;
std::mutex m_mutex;
std::condition_variable m_var;
bool flag = false;

void Producer()
{
    while(true)
    {
        sem_wait(&prod);
        std::cout << "Producer" << std::endl;
        sem_post(&cons);
    }

}

void Consumer()
{
    while(true)
    {
        sem_wait(&cons);
        std::cout << "Consumer" << std::endl;
        sem_post(&prod);
    }
}

void Test1()
{
    sem_init(&cons, 0, 0);
    sem_init(&prod, 0, 1);

    std::thread t1(Consumer);
    std::thread t2(Producer);


    std::this_thread::sleep_for(std::chrono::seconds(1));

    t2.detach();
    t1.detach();
}

void Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::cout << "Waiting" << std::endl;
    m_var.wait(lock, [&]{return flag;});
    std::cout << "Ended Waiting" << std::endl;
}

void Release()
{
    std::cout << "Sleep for 3 seconds before release" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    m_var.notify_one();
    flag = true;
}

int main()
{
    std::thread t3(Wait);
    std::thread t4(Release);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    t3.join();
    t4.join();
    return 0;
}

