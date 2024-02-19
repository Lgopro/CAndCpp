#ifndef _BUS_H
#define _BUS_H

#include <iostream>
#include "Car.h"
using namespace std;

class Bus_t : public Car_t
{
public:
	Bus_t();
	Bus_t(const size_t _capacity);
	Bus_t(const Car_t &_capacity);
	Bus_t &operator=(const Car_t &_str);
	void SetSeats(size_t _seats) { m_numSeats = _seats; };
	void SetLineNum(size_t _line) { m_lineNumber = _line; };

private:
	static size_t m_numSeats;
	static size_t m_lineNumber;
};

#endif
