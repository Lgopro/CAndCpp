#ifndef _PRIVATE_H
#define _PRIVATE_H

#include <iostream>
#include "Car.h"
using namespace std;


class Private_t : public Car_t
{
public:
    Private_t();
    Private_t(const size_t _capacity);
    Private_t(const Private_t &_speed);
    Private_t &operator=(const Car_t &_str);
    void Accelarate() { m_speed += 10; };
    void ReduceSpeed();
    size_t GetSpeed() { return m_speed; };

private:
    size_t m_speed;
    Private_t& operator=(const Private_t &_private );
};

#endif
