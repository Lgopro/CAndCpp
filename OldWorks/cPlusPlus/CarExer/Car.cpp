

#include <iostream>
#include "Car.h"
using namespace std;


size_t Car_t::m_globalID = 1;
size_t Car_t::m_defCapacity = 1600;


Car_t::Car_t():m_myID(++m_globalID)
{
	SetCarCapacity( m_defCapacity) ;
}
Car_t::Car_t(const size_t _capacity):m_myID(++m_globalID)
{
	SetCarCapacity( _capacity) ; 
}

Car_t::Car_t(const Car_t &_car):m_myID(++m_globalID)
{
	m_carName = _car.GetName();
	m_gearType = _car.GetGearName();
	/* m_myCapacity = _car.SetCapacity(); */
}

Car_t &Car_t::operator=(const Car_t &_str)
{
	
	m_carName = _str.GetName();
	m_gearType = _str.GetGearName();
	/* m_myCapacity = _str.SetCapacity(); */
	return *this;
}

bool Car_t::operator<(const Car_t &_car) const
{
	return GetCapacity() < _car.GetCapacity();
}
Car_t::~Car_t(){}