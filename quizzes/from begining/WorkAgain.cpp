#include <iostream>
#include <thread>
#include "semaphore.h"
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <functional>
#include <vector>

class Goblin
{
    public:
    Goblin(int health, int attack):m_attack(attack), m_health(health){}
    ~Goblin() = default;
    Goblin(const Goblin& other) = default;

    bool operator>(const Goblin& other) const
    {
        return (this->m_attack < other.m_attack);
    }

    bool operator<(const Goblin& other) const
    {
        return (this->m_attack > other.m_attack);
    }

    int GetHealth() const{return m_health;}
    int GetAttack() const{return m_attack;}
    private:
    int m_health;
    int m_attack;
};

class CompareGoblin
{
    public:
    CompareGoblin() = default;
    ~CompareGoblin() = default;
    bool operator()(const Goblin& value1, const Goblin& value2)
    {
        return (value1.GetHealth() > value2.GetHealth());
    }
};


sem_t sem1;
sem_t sem2;
std::condition_variable m_cond;
std::mutex m_mutex;
bool flag = false;

void Func1()
{
    while(1)
    {
        sem_wait(&sem2);
        std::cout<<"Ping"<<std::endl;
        sem_post(&sem1);
    }
}

void Func2()
{
    while(1)
    {
        sem_wait(&sem1);
        std::cout<<"Pong"<<std::endl;
        sem_post(&sem2);
    }
}

void Test1()
{
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 1);
    std::thread t1(Func1);
    std::thread t2(Func2);

    sleep(1);

    t1.detach();
    t2.detach();
}

void Cond1()
{
    std::unique_lock<std::mutex> m_lock(m_mutex);
    std::cout<<"Waiting in lock"<<std::endl;
    m_cond.wait(m_lock, [&]{return flag;});
    std::cout<<"Released"<<std::endl;
}

void Cond2()
{
    std::cout<<"Sleep 2 seconds"<<std::endl;
    sleep(2);
    std::cout<<"flag true"<<std::endl;
    flag = true;
    m_cond.notify_one();
}

void Test2()
{
    std::thread t3(Cond1);
    std::thread t4(Cond2);

    sleep(5);

    t3.detach();
    t4.detach();
}

void Lambda()
{
    int var = 8;
    auto lambda = ([&](int var)
    {
        int a = 8;
        int b = 9;
        return (var == a || var == b);
    
    });

    if(true == lambda(8))
    {
        std::cout<<"true"<<std::endl;
    }
    else
    {
        std::cout<<"false"<<std::endl;
    }
}

void Functor()
{
    std::vector<Goblin> goblins{Goblin(1,10), Goblin(2,9), Goblin(3, 8)};
    std::sort(goblins.begin(), goblins.end());
    for(auto iter : goblins)
    {
        std::cout<<"Goblin Attack is :" << iter.GetAttack() <<std::endl;
    }

    std::sort(goblins.begin(), goblins.end(), CompareGoblin());
    for(auto iter : goblins)
    {
        std::cout<<"Goblin Health is :" << iter.GetHealth() <<std::endl;
    }
}

int main()
{
    /* Test1();
    
    Test2(); 
    Lambda();*/
    Functor();
}