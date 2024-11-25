#include <iostream>
#include <string>


namespace ilrd
{
    class Character
    {
        public:
        Character(int hp = 100, int mp = 100, int mp_for_skill = 50, int skill_amount = 0, int attack_power = 50, int defence = 10, std::string mame = "Char", int attack_cooldown = 5);
        ~Character() = default;
        Character(const Character& other) = default;
        Character& operator=(const Character& other) = default;

        virtual void UseSkill(Character& who_to_attack) = 0;
        
        int GetHp() const;
        int GetMp() const;
        int GetSkillAmount() const;
        int GetSkillMpAmount() const;
        int GetAttackPower() const;
        int GetDefence() const;
        void SetHp(int new_hp);
        void SetMp(int new_mp);
        void Attack(Character& who_to_attack) const;
        std::string GetName() const;

        private:

        std::string m_name;
        int m_hp;
        int m_mp;
        int m_mp_for_skill;
        int m_skill_amount;
        int m_attack_power;
        int m_defence;
        int m_skill_cooldown;
        int m_attack_cooldown;

    };


    class Goblin : public Character
    {
        public:
        Goblin(int hp = 100, int mp = 100, int mp_for_skill = 50, int skill_amount = 0, int attack_power = 50, int defence = 10, std::string mame = "Goblin", int attack_cooldown = 5);
        virtual void UseSkill(Character& who_to_attack);
    };

    class Orc : public Character
    {
        public:

        Orc(int hp = 100, int mp = 100, int mp_for_skill = 50, int skill_amount = 0, int attack_power = 50, int defence = 10, std::string mame = "Orc", int attack_cooldown = 5);
        virtual void UseSkill(Character& who_to_attack);
    };

    class Game
    {
        public:
        Game(Goblin& char1, Orc& char2);
        ~Game() = default;


        private:

    };
}

using namespace ilrd;

Character::Character(int hp, int mp, int mp_for_skill, int skill_amount, int attack_power, int defence, std::string mame, int attack_cooldown):m_hp(hp),
m_mp(mp),m_skill_amount(skill_amount),m_attack_power(attack_power), m_defence(defence), m_mp_for_skill(mp_for_skill), m_name(mame),m_attack_cooldown(attack_cooldown)
{
}

int Character::GetHp() const
{
    return m_hp;
}
int Character::GetMp() const
{
    return m_mp;
}
int Character::GetSkillAmount() const
{
    return m_skill_amount;
}
int Character::GetAttackPower() const
{
    return m_attack_power;
}
int Character::GetDefence() const
{
    return m_defence;
}
void Character::SetHp(int new_hp)
{
    m_hp = new_hp;
}
void Character::SetMp(int new_mp)
{
    m_mp = new_mp;
}


std::string Character::GetName() const
{
    return m_name;
}

int Character::GetSkillMpAmount() const
{
    return m_mp_for_skill;
}

Goblin::Goblin(int hp, int mp, int mp_for_skill, int skill_amount, int attack_power, int defence, std::string mame, int attack_cooldown):Character(hp, mp, mp_for_skill, skill_amount, attack_power, defence, mame, attack_cooldown)
{

}

void Goblin::UseSkill(Character& who_to_attack)
{
    if(GetMp() > GetSkillMpAmount())
    {
        UseSkill(who_to_attack);
        std::cout<< "Using skill on " << who_to_attack.GetName() << " by " << GetName() << std::endl;
    }
    else
    {
        who_to_attack.SetHp(who_to_attack.GetHp() + who_to_attack.GetDefence() - who_to_attack.GetAttackPower());
    }
}


Orc::Orc(int hp, int mp, int mp_for_skill, int skill_amount, int attack_power, int defence, std::string mame, int attack_cooldown):Character(hp, mp, mp_for_skill, skill_amount, attack_power, defence, mame, attack_cooldown)
{

}

void Orc::UseSkill(Character& who_to_attack)
{
    if(GetMp() > GetSkillMpAmount())
    {
        UseSkill(who_to_attack);
        std::cout<< "Using skill on " << who_to_attack.GetName() << " by " << GetName() << std::endl;
    }
    else
    {
        who_to_attack.SetHp(who_to_attack.GetHp() + who_to_attack.GetDefence() - who_to_attack.GetAttackPower());
    }
}

int main()
{


    return 0;
}