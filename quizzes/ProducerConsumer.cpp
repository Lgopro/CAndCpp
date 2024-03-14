
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>
#include <mutex>

sem_t consume;
sem_t produce;

std::mutex m_mutex;

size_t counter = 0;



void Counter(size_t number)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    for(size_t i = 0; i < 10; ++i)
    {
        std::cout << counter + number << std::endl;
        ++counter;
    }
}

void Consumer()
{
    while(true)
    {
        sem_wait(&consume);
        std::cout<< "Consume" << std::endl;
        sem_post(&produce);
    } 
}


void Producer()
{
    while(true)
    {
        sem_wait(&produce);
        std::cout<< "Produce" << std::endl;
        sem_post(&consume);
    } 
}




int main()
{
    /* sem_init(&produce, 0, 1);
    sem_init(&consume, 0 ,0);
    std::thread producer(Producer);
    std::thread consumer(Consumer);
    sleep(2);

    producer.detach();
    consumer.detach(); */
    size_t i = 20;
    std::thread arr[i];
    for(size_t a = 0 ; a < i; ++a)
    {
        arr[a] = std::thread(Counter, a);
    }

    for(size_t b = 0 ; b < i; ++b)
    {
        arr[b].join();
    }

    
    return 0;
}