#include <iostream>
#include<vector>

namespace ilrd
{
    class Goblin
    {
        public:
        Goblin(size_t health = 80, size_t attack = 10);
        ~Goblin();
        Goblin(const Goblin& other) = default;
        Goblin& operator=(const Goblin& other) = default;
        
        virtual void Attack();
        virtual void Breed();
        virtual void Sleep();
        size_t GetAttackPower() const;
        private:

        size_t m_health;
        size_t m_attack;
        size_t m_magic_power;

    };

    class GoblinMage: public Goblin
    {
        public:
        GoblinMage(size_t health = 80, size_t attack = 10, size_t magic_power = 15);
        ~GoblinMage();
        GoblinMage(const GoblinMage& other) = default;
        GoblinMage& operator=(const GoblinMage& other) = default;
        
        virtual void Attack();
        void MagicArrow();
        virtual void Breed();
        virtual void Sleep();
        size_t GetAttackPower() const;

        private:

        size_t m_health;
        size_t m_attack;
        size_t m_magic_power;
    };


    class GoblinWarrior: public Goblin
    {
        public:
        GoblinWarrior(size_t health = 100, size_t attack = 25);
        ~GoblinWarrior();
        GoblinWarrior(const GoblinWarrior& other) = default;
        GoblinWarrior& operator=(const GoblinWarrior& other) = default;
        
        virtual void Attack();
        void SuperAttack();
        virtual void Breed();
        virtual void Sleep();
        size_t GetAttackPower() const;

        private:

        size_t m_health;
        size_t m_attack;
        size_t m_magic_power;
    };
}

using namespace ilrd;


Goblin::Goblin(size_t health, size_t attack):m_attack(attack), m_health(health), m_magic_power(0)
{
    std::cout<< "Goblin Ctor" << std::endl;
}


Goblin::~Goblin()
{
    std::cout<< "Goblin Dtor" << std::endl;
}

size_t Goblin::GetAttackPower() const
{
    return m_attack;
}

void Goblin::Attack()
{
    std::cout<< "assdfda Goblin Attack!" <<std::endl;
}
void Goblin::Breed()
{
    std::cout<< "Hehe ^^" <<std::endl;
}
void Goblin::Sleep()
{
    std::cout<< "zzzzz" <<std::endl;
}

GoblinMage::GoblinMage(size_t health, size_t attack, size_t magic_power):m_health(health), m_attack(attack), m_magic_power(magic_power)
{
    std::cout<< "GoblinMage Ctor" << std::endl;
}

GoblinMage::~GoblinMage()
{
    std::cout<< "GoblinMage Dtor" << std::endl;
}

void GoblinMage::Attack()
{
    std::cout<< "Mage Attack!" <<std::endl;
    MagicArrow();
}
void GoblinMage::MagicArrow()
{
    std::cout<< "Magic Arrow!" <<std::endl;
}
void GoblinMage::Breed()
{
    std::cout<< "Hehe boy^^" <<std::endl;
}
void GoblinMage::Sleep()
{
    std::cout<< "zzzz Arrow zzzz" <<std::endl;
}

GoblinWarrior::GoblinWarrior(size_t health, size_t attack):m_attack(attack), m_health(health), m_magic_power(0)
{
    std::cout<< "GoblinWarrior Ctor" << std::endl;
}

GoblinWarrior::~GoblinWarrior()
{
    std::cout<< "GoblinWarrior Dtor" << std::endl;
}


size_t GoblinWarrior::GetAttackPower() const
{
    return m_attack;
}
void GoblinWarrior::Attack()
{
    std::cout<< "ATTACK!" <<std::endl;
    SuperAttack();
}
void GoblinWarrior::SuperAttack()
{
    std::cout<< "SUPER ATTACK!" <<std::endl;
}
void GoblinWarrior::Breed()
{
    std::cout<< "LETS GO!" <<std::endl;
}
void GoblinWarrior::Sleep()
{
    std::cout<< "ZZZZZZZZZZZ" <<std::endl;
}

class SortGoblin
{
    public:
    bool operator()(const Goblin& val1, const Goblin& val2)
    {
        return (val1.GetAttackPower() < val2.GetAttackPower());
    }
};


int main()
{
    std::vector<Goblin> arr = {Goblin(15, 22), GoblinMage(10, 15, 3), GoblinWarrior(44, 33)};

    for(auto iter : arr)
    {
        iter.Attack();
        iter.Breed();
        iter.Sleep();
    }

    sort(arr.begin(), arr.end(), SortGoblin());


    for(auto iter : arr)
    {
        std::cout<< iter.GetAttackPower() <<std::endl;
    } 
    return 0;
}