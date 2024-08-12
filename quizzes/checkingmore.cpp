

#include <iostream>
#include <vector>

namespace ilrd
{
    class Goblin
    {
        public:

        Goblin(unsigned int health = 20, unsigned int attack_power = 10);
        ~Goblin() = default;
        Goblin(const Goblin& other) = default;
        Goblin& operator=(const Goblin& other) = default;

        unsigned int GetHealth() const;
        unsigned int GetAttackPower() const;

        private:
        unsigned int m_health;
        unsigned int m_attack_power;


    };

    class CompareGoblin
    {
        public:
        bool operator()(const Goblin& goblin1, const Goblin& goblin2)
        {
            if(goblin1.GetHealth() >= goblin2.GetHealth())
            {
                return true;
            }
            return false;
        }
    };

}

using namespace ilrd;


Goblin::Goblin(unsigned int health, unsigned int attack_power):m_health(health), m_attack_power(attack_power)
{
}

unsigned int Goblin::GetHealth() const
{
    return m_health;
}
        
unsigned int Goblin::GetAttackPower() const
{
    return m_attack_power;
}


int main()
{
    std::vector<Goblin> goblin_vec = {Goblin(12, 22), Goblin(), Goblin(100, 200), Goblin(400, 333)};
    std::sort(goblin_vec.begin(), goblin_vec.end(), CompareGoblin());

    for(auto &iter : goblin_vec)
    {
        std::cout<< "The health is: " << iter.GetHealth() << " the attack power is: " << iter.GetAttackPower() << std::endl;
    }


    return 0;
}