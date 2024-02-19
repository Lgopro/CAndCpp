#include <iostream>
#include "Manager.h"
using namespace std;

size_t Manager_t::m_actualPosition = 0;

Manager_t::Manager_t()
{
    m_Position = m_actualPosition;
}
Manager_t::~Manager_t()
{
}