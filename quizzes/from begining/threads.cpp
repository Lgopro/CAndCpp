
#include <thread>
#include <semaphore.h>
#include <iostream>
#include <unistd.h>
#include <functional>
#include <vector>
#include <condition_variable>
#include <mutex>

namespace ilrd
{
    class Goblin
    {
        public:

        Goblin(size_t health, size_t attack):m_attack(attack), m_health(health){};
        ~Goblin() = default;
        Goblin(const Goblin& other) = default;
        Goblin& operator=(const Goblin& other) = default;
        size_t GetHealth() const{return m_health;};
        size_t GetAttack() const{return m_attack;};

        bool operator>(const Goblin& other) const 
        {
            return (other.m_attack > this->m_attack);
        }

        bool operator<(const Goblin &other) const
        {
            return m_attack < other.m_attack;
        }

        private:
        size_t m_health;
        size_t m_attack;

    };

    struct CompareGoblin
    {
        bool operator()(const Goblin& val1, const Goblin& val2)
        {
            return val1.GetHealth() < val2.GetHealth();
        }
    };
}


using namespace ilrd;
sem_t semaphore1;
sem_t semaphore2;
std::condition_variable m_variable;
std::mutex m_mutex;
int flag = 0;

void Function1()
{
    while(1)
    {
        sem_wait(&semaphore1);
        std::cout << "Ping" << std::endl;
        sem_post(&semaphore2);
    }
}

void Function2()
{
    while(1)
    {
        sem_wait(&semaphore2);
        std::cout << "Pong" << std::endl;
        sem_post(&semaphore1);
    }
}

void Test1()
{
    sem_init(&semaphore1, 0, 1);
    sem_init(&semaphore2, 0, 0);

    std::thread t1(Function1);
    std::thread t2(Function2);


    sleep(2);


    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);

    t1.detach();
    t2.detach();

    
}


void Test2()
{
    
    std::vector <Goblin> m_goblin{Goblin(10, 11), Goblin(9, 12), Goblin(8, 13)};
    std::sort(m_goblin.begin(), m_goblin.end());
    for(auto &iter : m_goblin)
    {
        std::cout << "Attack is: " << iter.GetAttack() << std::endl;
    }

    std::sort(m_goblin.begin(), m_goblin.end(), CompareGoblin());
    for(auto &iter : m_goblin)
    {
        std::cout << "Attack is: " << iter.GetAttack() << std::endl;
    }
}


void Condition()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    std::cout << "Waiting" << std::endl;
    m_variable.wait(lock, []{return flag == 1;});
    std::cout << "Waiting ended" << std::endl;
}

void Test3()
{
    std::thread t3(Condition);
}


int main()
{
    Test1();
    sleep(2);
    Test2();
    sleep(2);
    
    Test3();
    return 0;
}