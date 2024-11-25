
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <semaphore.h>
#include <thread>
#include <chrono>


sem_t produce;
sem_t consume;
bool flag_ping_pong = true;


std::mutex m_mutex;
std::condition_variable m_cond;
bool flag = false;

void ProducerFunc()
{
    while(flag_ping_pong)
    {
        sem_wait(&produce);
        std::cout<< "Ping" << std::endl;
        sem_post(&consume);
    }
    
}

void ConsumerFunc()
{
    while(flag_ping_pong)
    {
        sem_wait(&consume);
        std::cout<< "Pong" << std::endl;
        sem_post(&produce);
    }

}

void PingPong()
{
    sem_init(&produce, 0, 1);
    sem_init(&consume, 0, 0);

    std::thread Producer(ProducerFunc);
    std::thread Consumer(ConsumerFunc);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    flag_ping_pong = false;

    Producer.join();
    Consumer.join();

    sem_close(&produce);
    sem_close(&consume);


}


void WaitFunc()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::cout<< "Wait for release" << std::endl;
    m_cond.wait(lock, [&]{return flag;});
    std::cout<< "Released" << std::endl;
    
}

void ReleaseFunc()
{
    std::cout<< "Sleep for 5 seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    m_cond.notify_one();
    flag = true;
}

int main()
{
    std::thread wait(WaitFunc);
    std::thread release(ReleaseFunc);

    wait.join();
    release.join();

    return 0;
}