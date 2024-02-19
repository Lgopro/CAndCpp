


#include <iostream>
#include <vector>
#include <functional>



struct Goblin
{
    int m_health;
    int m_attack;
    Goblin(int health, int attack): m_attack(attack), m_health(health){}
    bool operator<(const Goblin& other)
    {
        return (this->m_attack > other.m_attack);
    }
};


struct GoblinCompare
{
    bool operator()(const Goblin& value1, const Goblin& value2)
    {
        return (value1.m_health < value2.m_health);
    }
};


int main()
{
    std::vector<Goblin> m_goblin{Goblin(12, 13), Goblin(11, 14), Goblin(10, 15)};
    std::sort(m_goblin.begin(), m_goblin.end());
    std::cout << "Atack compare" <<std::endl;
    for(auto iter : m_goblin)
    {
        std::cout << iter.m_attack <<std::endl;
    }
    std::sort(m_goblin.begin(), m_goblin.end(), GoblinCompare());
    std::cout << "Health compare" <<std::endl;
    for(auto iter : m_goblin)
    {
        std::cout << iter.m_health <<std::endl;
    }
    return 0;
}