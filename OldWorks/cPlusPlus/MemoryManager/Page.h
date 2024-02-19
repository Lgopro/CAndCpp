#ifndef _PAGE_T_H
#define _PAGE_T_H

#include <string>
#include <iostream>
#include "Manager.h"
using namespace std;

class Page_t : public Manager_t
{
public:
    //bool IsEmpty() const{ return (m_actualPosition == 0) ? true : false; };
    //void SetPosition(size_t _Position) { (_Position <= m_actualPosition) ? m_Position = _Position : m_Position = m_actualPosition; };
    //size_t GetPosition() const { return m_Position; };
    //size_t GetActualPosition() const { return m_actualPosition; };

    Page_t();                       //default constructor
    Page_t(const size_t _position); //constractor with init Position


    virtual size_t Read(void *_buff, size_t _toRead);
    virtual size_t Read(void *_buff, size_t _toRead, size_t _startPos);
    virtual size_t Write(const void *_buff, size_t _toWrite);
    virtual size_t Write(const void *_buff, size_t _toWrite, size_t _startPos);

    ~Page_t(); //Destractor

private:
    Page_t(const Page_t &_page); // copy constructor
    Page_t& operator = (const Page_t&); //Assigment operator
    char* m_begin;
    size_t			m_capacity;
	static size_t	m_globalCapacity;
};

#endif