

#include <iostream>
#include <thread>
#include <chrono>
#include<semaphore.h>
#include <mutex>
#include <condition_variable>

std::mutex m_mutex;
std::condition_variable m_cond;
bool flag = false;

sem_t write;
sem_t read;

void ProducerFunc()
{
    while(1)
    {
        sem_wait(&write);
        std::cout << "Ping" << std::endl;
        sem_post(&read);
    }
}



void ConsumerFunc()
{
    while(1)
    {
        sem_wait(&read);
        std::cout << "Pong" << std::endl;
        sem_post(&write);
    }
}

void PingPong()
{
    sem_init(&write, 0, 1);
    sem_init(&read, 0, 0);

    std::thread Producer(ProducerFunc);
    std::thread Consumer(ConsumerFunc);




    std::this_thread::sleep_for(std::chrono::seconds(5));


    Producer.detach();
    Consumer.detach();
}

void ConditionVarFunc()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::cout<< "Entered Condition func" << std::endl;
    m_cond.wait(lock, [&]{return flag;});
    std::cout<< "Released" << std::endl;
}


void ReleaseFunction()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<< "Slept for 2 sec. Releasing now." << std::endl;
    flag = true;
    m_cond.notify_one();   

}

int main()
{
    std::thread Cond(ConditionVarFunc);
    std::thread Release(ReleaseFunction);

   
    std::this_thread::sleep_for(std::chrono::seconds(8));

    Cond.join();
    Release.join();

    return 0;
}