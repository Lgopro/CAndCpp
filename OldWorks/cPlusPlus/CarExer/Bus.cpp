
#include <iostream>
#include "Bus.h"
using namespace std;


Bus_t::Bus_t() : Car_t()
{
    SetCarName("Bus");
    SetGear("Automatic");
}

Bus_t::Bus_t(const size_t _capacity) : Car_t()
{
    SetCarName("Bus");
    SetGear("Automatic");
}