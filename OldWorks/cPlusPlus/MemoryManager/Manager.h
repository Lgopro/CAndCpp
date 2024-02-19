#ifndef _MANAGER_T_H
#define _MANAGER_T_H

#include <string>
#include <iostream>
using namespace std;

class Manager_t
{
public:
    Manager_t(); //default constructor
    bool IsEmpty() const { return (m_actualPosition == 0) ? true : false; };

    virtual size_t Read(void *_buff, size_t _toRead) = 0;
    virtual size_t Read(void *_buff, size_t _toRead, size_t _startPos) = 0;
    virtual size_t Write(const void *_buff, size_t _toWrite) = 0;
    virtual size_t Write(const void *_buff, size_t _toWrite, size_t _startPos) = 0;

    void SetPosition(size_t _Position) { (_Position <= m_actualPosition) ? m_Position = _Position : /* throw(_Position) */  m_Position = m_actualPosition ; };

    size_t GetPosition() const { return m_Position; };
    size_t GetActualPosition() const { return m_actualPosition; };

protected:
    virtual ~Manager_t(); //Destractor
    void SetActualPosition(size_t _Position) { m_actualPosition = _Position; };

private:
    Manager_t(const Manager_t &_manager); // copy constructor
    Manager_t &operator=(const Manager_t &);
    size_t m_Position;
    static size_t m_actualPosition;
};

#endif