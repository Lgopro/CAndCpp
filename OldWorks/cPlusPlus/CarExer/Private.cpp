

#include <iostream>
#include "Private.h"
using namespace std;


Private_t::Private_t() : Car_t()
{
    SetCarName("Private");
    SetGear("Standard");
    m_speed = 0;
}
Private_t::Private_t(size_t _capacity) : Car_t(/* m_myCapacity */)
{
    SetCarName("Private");
    SetGear("Standard");
}

void Private_t::ReduceSpeed()
{
    (m_speed <= 10) ? m_speed == 0 : m_speed -= 10;
}