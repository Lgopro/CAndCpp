

#include <thread>
#include <unistd.h>
#include <semaphore.h>
#include <iostream>
sem_t producer;
sem_t consumer;

const int FOREVER = 1;

void Producer()
{
    while(FOREVER)
    {
        sem_wait(&producer);
        std::cout<< "Ping" << std::endl;
        sem_post(&consumer);
    }
}


void Consumer()
{
    while(FOREVER)
    {
        sem_wait(&consumer);
        std::cout<< "Pong" << std::endl;
        sem_post(&producer);
    }
}

int main()
{
    sem_init(&producer, 0, 1);
    sem_init(&consumer, 0, 0);
    std::thread t1(Consumer);
    std::thread t2(Producer);


    sleep(2);


    t1.detach();
    t2.detach();




    return 0;


}