#ifndef _CAR_T_H
#define _CAR_T_H

#include <string>
#include <iostream>
#include "StringT.h"
using namespace std;

class Car_t
{
public:
	Car_t(); 						//default constructor
	Car_t(const size_t _capacity);  //constractor with init capacity
	Car_t(const Car_t &_car);		// copy constructor
	bool operator<(const Car_t &_str) const;

	void createFrom(const char *_str);

	void SetID();
	size_t GetCapacity() const  { return m_myCapacity; };
	String_t GetName() const { return m_carName; };
	String_t GetGearName() const { return m_gearType; };

	
protected:
	~Car_t();
	void SetGear(const char *_gear) { m_gearType = _gear; };
	void SetCarName(const char *_name) { m_carName = _name; };
	void SetCarCapacity(size_t _capacity) { m_myCapacity = _capacity; };

private:
	Car_t &operator=(const Car_t &_str);
	const size_t m_myID;
	static size_t m_defCapacity;
	size_t m_myCapacity;
	String_t m_gearType;
	static size_t m_globalID;
	String_t m_carName;
};

#endif
