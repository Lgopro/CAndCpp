

#include <thread>
#include <iostream>
#include "semaphore.h"
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <vector>

namespace ilrd
{
    class Goblin
    {
        public:
        Goblin(int str = 10, int health = 20):m_str(str), m_health(health){};
        ~Goblin() = default;
        Goblin(const Goblin& other) = default;
        Goblin& operator=(const Goblin& other) = default;
        int GetStr() const{return m_str;};
        int GetHealth() const{return m_health;};
        
        bool operator>(const Goblin& val1) const
        {
            return (val1.GetStr() < this->m_str);
        }

        bool operator<(const Goblin& val1) const
        {
            return (val1.GetStr() > this->m_str);
        }

        private:
        int m_str;
        int m_health;
    };

    class HealthGoblin
    {
        public:
        HealthGoblin() = default;
        ~HealthGoblin() = default;

        bool operator()(const Goblin& val1, const Goblin& val2)
        {
            return (val1.GetHealth() > val2.GetHealth());
        }

    };
}

using namespace ilrd;

sem_t sem1;
sem_t sem2;
std::condition_variable m_var;
std::mutex m_mutex;
bool flag = false;


void Func1()
{
    while(1)
    {
        sem_wait(&sem1);
        std::cout<< "Ping" <<std::endl;
        sem_post(&sem2);
    }
}

void Func2()
{
    while(1)
    {
        sem_wait(&sem2);
        std::cout<< "Pong" <<std::endl;
        sem_post(&sem1);
    }  
}

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

int main()
{
    /* Test1(); */
    std::cout<< "Test2" << std::endl;
    Test2();
    std::cout<< "Test3" << std::endl;
    Test3();
    std::cout<< "Test4" << std::endl;
    Test4();
    std::cout<< "Test5" << std::endl;
    Test5();
    return 0;
}

void Test1()
{
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    std::thread t1(Func1);
    std::thread t2(Func2);




    sleep(1);


    t1.detach();
    t2.detach();
    sem_close(&sem1);
    sem_close(&sem2);
}



void Cond2()
{
    std::unique_lock<std::mutex> m_lock(m_mutex);
    std::cout<< "Waiting" << std::endl;
    m_var.wait(m_lock, [&]{return flag;});
    std::cout<< "Released" << std::endl;
}

void Cond1()
{
    std::cout<< "Making something" << std::endl;

    sleep(3);  
    std::cout<< "Flag true" << std::endl;
    flag = true;
    m_var.notify_one();
}

void Test2()
{
    std::thread t3(Cond1);
    std::thread t4(Cond2);

    sleep(10);
    t3.detach();
    t4.detach();
}


void Test3()
{
    std::vector<Goblin> m_goblins{Goblin(12, 14), Goblin(11, 15), Goblin(20,40), Goblin(1 ,2)};
    std::sort(m_goblins.begin(), m_goblins.end());
    for(auto iter : m_goblins)
    {
        std::cout<< " " << iter.GetStr();
    }
    std::cout<< "" << std::endl;
}


void Test4()
{
    std::vector<Goblin> m_goblins{Goblin(12, 14), Goblin(11, 15), Goblin(20,40), Goblin(1 ,2)};
    std::sort(m_goblins.begin(), m_goblins.end(), HealthGoblin());
    for(auto iter : m_goblins)
    {
        std::cout<< " " << iter.GetHealth();
    }
    std::cout<< "" << std::endl;
}


void Test5()
{
    auto lambda = [&](int value){
        int a = 8;

        if(value == a)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool status = lambda(8);
    if(status == true)
    {
        std::cout<< "Status is true at lambda" << std::endl;
    }
    else
    {
        std::cout<< "Status is false at lambda";
    }
}