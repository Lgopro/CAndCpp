


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <semaphore.h>

std::mutex m_mutex;
std::condition_variable m_cond;
sem_t sem1;
sem_t sem2;
bool flag = false;

void Ping()
{
    while(1)
    {
        sem_wait(&sem1);
        std::cout<< "Ping" << std::endl;
        sem_post(&sem2);
    }
}

void Pong()
{
    while(1)
    {
        sem_wait(&sem2);
        std::cout<< "Pong" << std::endl;
        sem_post(&sem1);
    }
}


bool IsPowerTwoWithNoLoop(unsigned int var)
{
    size_t counter = 0;

    while(var != 0)
    {
        var = var & (var - 1);
        ++counter;
    }

    if(counter == 1)
    {
        return true;
    }
    return false;
}

bool IsPowerTwoWithLoop(unsigned int var)
{
    size_t counter = 0;
    
    for(size_t i = 0; i < 32; ++i)
    {
        if(var & (1 << i))
        {
            ++counter;
        }
    }

    if(counter == 1)
    {
        return true;
    }
    return false;
}


unsigned int PlusOne(unsigned int num)
{
    for(size_t i = 0; i < 32; ++i)
    {
        if(!(num & (1 << i)))
        {
            num = num ^ (1 << i);
            break;
        }
        else
        {
            num = num ^ (1 << i);
        }
    }
    return num;
}

size_t Count(unsigned int num)
{
    size_t counter = 0;

    for(size_t i = 0; i < 32; ++i)
    {
        if(num & (1 << i))
        {
            ++counter;
        }
    }
    return counter;
}

void PrintOnly3Bits(unsigned int *arr, size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        size_t counter = Count(arr[i]);
        if(counter == 3)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "" << std::endl;
}

void Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    
    m_cond.wait(lock, [&]{return flag;});
}

void Release()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    flag = true;

    m_cond.notify_one();
}


int main()
{
    bool result = IsPowerTwoWithNoLoop(32);
    if(result == true)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    bool result1 = IsPowerTwoWithNoLoop(123);
    if(result1 == true)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    bool result2 = IsPowerTwoWithLoop(32);
    if(result2 == true)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    bool result3 = IsPowerTwoWithLoop(123);
    if(result3 == true)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    unsigned int num = PlusOne(5);
    std::cout << num << std::endl;
    unsigned int arr[] = {5, 16, 33, 7, 64, 14};

    PrintOnly3Bits(arr, sizeof(arr)/sizeof(unsigned int));

    /* sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    
    std::thread t1(Ping);
    std::thread t2(Pong);

    std::this_thread::sleep_for(std::chrono::seconds(2));

    t1.detach();
    t2.detach(); */



    std::thread t3(Wait);
    std::thread t4(Release);

    std::this_thread::sleep_for(std::chrono::seconds(5));


    t3.join();
    t4.join();
    return 0;
}