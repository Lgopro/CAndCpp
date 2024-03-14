#include <iostream>
#include <thread>
#include <semaphore.h>
#include <mutex>
#include <unistd.h>
#include <condition_variable>
#include <atomic>


sem_t ping;
sem_t pong;

const int TRUE = 1;
enum direction
{
    LEFT = 0,
    RIGHT = 1

};


std::atomic<int> number_left(0);
std::atomic<int> number_right(0);

std::atomic<int> passing_left(0);
std::atomic<int> passing_right(0);

std::mutex m_mutex_right;
std::mutex m_mutex_left;

std::mutex m_pass;

std::condition_variable m_cond_left;
std::condition_variable m_cond_right;

sem_t left;
sem_t right;

bool flag_left = false;
bool flag_right = false;

void Ping()
{
    while (TRUE)
    {
        sem_wait(&ping);
        std::cout << "Ping" << std::endl;
        sem_post(&pong);
    }
}

void Pong()
{
    while (TRUE)
    {
        sem_wait(&pong);
        std::cout << "Pong" << std::endl;
        sem_post(&ping);
    }
}

void PingPong()
{

    sem_init(&ping, 0, 1);
    sem_init(&pong, 0, 0);
    std::thread t1(Ping);
    std::thread t2(Pong);

    sleep(2);

    t1.detach();
    t2.detach();
}

void PassBridge(enum direction dir)
{
    if(dir == LEFT && passing_right == 0)
    {   
        std::unique_lock<std::mutex> lock(m_pass);
        usleep(10);
        std::cout<< "Tank from left passed" << std::endl;
    }
    else if(dir == RIGHT && passing_left == 0)
    {
        std::unique_lock<std::mutex> lock(m_pass);
        usleep(10);
        std::cout<< "Tank from right passed" << std::endl;
    }
}

void Thread_counter()
{

    while (true)
    {
        if (number_left == 0 && number_right > 0)
        {
            flag_right = true;
            m_cond_right.notify_all();
            flag_right = false;
        }
        else if (number_left > 0 && number_right == 0)
        {
            flag_left = true;
            m_cond_left.notify_all();
            flag_left = false;
        }
        else if (number_left > 0 && number_right > 0)
        {
            if (number_left > number_right)
            {
                flag_left = true;
                while (number_left != number_right)
                {
                    m_cond_left.notify_one();
                }
                flag_left = false;
            }
            else if (number_left < number_right)
            {
                flag_right = true;
                while (number_left != number_right)
                {
                    m_cond_right.notify_one();
                }
                flag_right = false;
            }

            if (number_left == number_right && number_left != 0)
            {
                flag_left = true;
                m_cond_left.notify_all();
                flag_left = false;
            }
        }
    }
}

void TankCrossBridge(enum direction dir)
{

    if (dir == RIGHT)
    {
        ++number_right;
    }
    else
    {
        ++number_left;
    }

    if (dir == LEFT)
    {
        std::unique_lock<std::mutex> lock(m_mutex_left);
        m_cond_left.wait(lock, [&]{ return flag_left; });
        PassBridge(dir);
        --number_left;
    }
    if (dir == RIGHT)
    {
        std::unique_lock<std::mutex> lock(m_mutex_right);
        m_cond_right.wait(lock, [&]{ return flag_right; });
        PassBridge(dir);
        --number_right; 
    }
}


int main()
{
    std::thread counting(Thread_counter);
    /* PingPong(); */
    for(size_t i = 0; i < 55; ++i)
    {
        TankCrossBridge(RIGHT);
    }
    for(size_t j = 0; j < 35; ++j)
    {
        TankCrossBridge(LEFT);
    }

    sleep(10);
    counting.detach();
    return 0;
}