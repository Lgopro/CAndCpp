#include <iostream>
#include <thread>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <condition_variable>

sem_t sem1;
sem_t sem2;
std::condition_variable cond1;
std::mutex mutex1;
bool flag = false;
void Producer()
{
    while(1)
    {
        sem_wait(&sem1);
        std::cout<< "Ping" <<std::endl;
        sem_post(&sem2);
    }
}


void Consumer()
{
    while(1)
    {
        sem_wait(&sem2);
        std::cout<< "Pong" <<std::endl;
        sem_post(&sem1);
    }
}

void Test1()
{
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);

    std::thread t1(Producer);
    std::thread t2(Consumer);

    sleep(3);


    t1.detach();
    t2.detach();
}

void Condition()
{
    std::unique_lock<std::mutex> lock(mutex1);
    std::cout<< "Locked" <<std::endl;
    cond1.wait(lock, [&]{return flag;});
    std::cout<< "Released" <<std::endl;
}

void Release()
{
    std::cout<< "Sleep to 2 sec" <<std::endl;
    sleep(2);
    cond1.notify_one();
    flag = true;
    std::cout<< "Notify one" <<std::endl;
}


void Task2()
{
    std::thread t3(Condition);
    std::thread t4(Release);

    sleep(4);


    t3.join();
    t4.join();
}

int main()
{
        


    return 0;
}


