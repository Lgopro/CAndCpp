#ifndef _POOL_T_H
#define _POOL_T_H

#include <string>
#include <iostream>
#include <vector>
#include "Manager.h"
#include "Page.h"
#define TRUE 1
using namespace std;

class Pool_t : public Manager_t
{
public:
    //bool IsEmpty() const{ return (m_actualPosition == 0) ? true : false; };
    //void SetPosition(size_t _Position) { (_Position <= m_actualPosition) ? m_Position = _Position : m_Position = m_actualPosition; };
    //size_t GetPosition() const { return m_Position; };
    //size_t GetActualPosition() const { return m_actualPosition; };

    Pool_t();                       //default constructor
    Pool_t(const size_t _position); //constractor with init Position


    virtual size_t Read(void *_buff, size_t _toRead)  ;
    virtual size_t Read(void *_buff, size_t _toRead, size_t _startPos) ;
    virtual size_t Write(const void *_buff, size_t _toWrite);
    virtual size_t Write(const void *_buff, size_t _toWrite, size_t _startPos) ;

    size_t FindPageNumber(size_t _startPosition);
    virtual ~Pool_t(); //Destractor

private:
    vector<Page_t*> m_pool; 
    Pool_t(const Pool_t &_page); // copy constructor
    static size_t	m_globalPageCapacity;

};

#endif