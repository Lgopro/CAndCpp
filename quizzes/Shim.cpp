#include <iostream> //std::cout
#include <cmath> //sin
#include <vector> // std::vector
#include <utility>// std:: pair


const float two_pi = 360;
const int OTHER_DIRECTION = -1;
const int UP_TO_360 = 61;
const int CHANGE_AMOUNT = 2;

namespace ilrd
{
    class Shim
    {
        public:

        Shim(int begin_location, int step = 6, bool direction_up = true);
        ~Shim() = default;
        Shim(const Shim& other) = default; 
        Shim& operator=(const Shim& other) = default; 
        bool operator==(const Shim& other) const;

        void PrintShim() const;
        std::vector<std::pair<float, int>> GetShim() const;

        private:

        std::vector<std::pair<float, int>> m_shim; //first int is sinX and Y is just the angle from 

    };


    class ShimArr
    {
        public:

        ShimArr() = default;
        ~ShimArr() = default;
        ShimArr(const ShimArr& other) = default; 
        ShimArr& operator=(const ShimArr& other) = default; 

        void AddShim(Shim& shim_to_add);
        void DeleteShim(Shim& shim_to_delete);

        private:
        
        std::vector<Shim> m_shim_arr;

    };

}


using namespace ilrd;

Shim::Shim(int begin_location, int step, bool direction_up)
{
    float step_from_zero_to_hundred = (100 / two_pi) * 6;
    int sign = 1;
    int amount_to_move_to_other_direction = 0;
    int direction_change = 2;
    int counter = 0;

    if(direction_up == false)
    {  
        sign = -1;
    }

    for(int i = 0; i < UP_TO_360; ++i)
    {
        float current_location = sin(begin_location + step_from_zero_to_hundred * sign * counter + amount_to_move_to_other_direction * step_from_zero_to_hundred * sign * OTHER_DIRECTION);

        m_shim.push_back(std::make_pair(current_location, step * i));
        
        if((begin_location + step_from_zero_to_hundred * sign * counter > 100 && direction_up == true) || (begin_location + step_from_zero_to_hundred * sign * counter < 0 && direction_up == false))
        {
            ++direction_change;
        }

        if(direction_change % CHANGE_AMOUNT == 0) //if direction change is %2 == 0 than counter will grow, else other counter will grow
        {
            ++counter;
        }
        else
        {
            ++amount_to_move_to_other_direction;
        }
    }
    
}

bool Shim::operator==(const Shim& other) const
{
    return m_shim == other.m_shim; 
}

void Shim::PrintShim() const
{
    for(auto& iter : m_shim)
    {
        std::cout << "The sinX from 0 to 100 is " << asin(iter.first) << " and the degree is " << iter.second << std::endl;
    }
    std::cout<< ""<< std::endl;
}
        
std::vector<std::pair<float, int>> Shim::GetShim() const
{
    return m_shim;
}

void ShimArr::AddShim(Shim& shim_to_add)
{
    m_shim_arr.push_back(shim_to_add);
}

void ShimArr::DeleteShim(Shim& shim_to_delete)
{
    for (auto iter = m_shim_arr.begin(); iter != m_shim_arr.end(); ++iter)
    {
        if (*iter == shim_to_delete)
        {
            m_shim_arr.erase(iter);
            break;
        }
    }

}

int main()
{
    Shim m_shim1(0 , 6, true);
    Shim m_shim2(100, 6, false);
    Shim m_shim3(50, 6, false);

    m_shim1.PrintShim();
    m_shim2.PrintShim();
    m_shim3.PrintShim();
    //can be added to ShimArr that i added if needed
    return 0;
}