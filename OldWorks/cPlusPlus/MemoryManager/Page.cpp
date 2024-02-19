#include <iostream>
#include <string.h>
#include "Page.h"

using namespace std;
size_t Page_t::m_globalCapacity = 6;

Page_t::Page_t() : m_capacity(m_globalCapacity)
{
    m_begin = new char(m_globalCapacity);
}

Page_t::Page_t(const size_t _position) : m_capacity(_position)
{
    m_begin = new char(m_globalCapacity);
}

Page_t::~Page_t()
{
    delete (m_begin);
}

size_t Page_t::Write(const void *_buff, size_t _toWrite)
{
    return Write(_buff, _toWrite, GetPosition());
}

size_t Page_t::Write(const void *_buff, size_t _toWrite, size_t _startPos)
{
    
    if (_buff == NULL || _toWrite == 0 || _startPos > GetActualPosition())
    {
        return 0;
    }
    size_t Bytes = (m_capacity - _startPos) > _toWrite ? _toWrite : m_capacity - _startPos;
    memcpy(&m_begin[_startPos], _buff, Bytes);
    if(Bytes + _startPos > GetActualPosition())
    {
        SetActualPosition(Bytes + _startPos);
        SetPosition(Bytes + _startPos);
    }
    else
    {
        SetPosition(Bytes + _startPos);
    }
    /* if(Bytes + _startPos <= GetActualPosition())
    {
        SetPosition(Bytes + _startPos);
    }
    else
    {
        try
        {
            SetPosition(Bytes + _startPos);
        }
        catch(size_t _newPos)
        {
            SetActualPosition(Bytes + _startPos);
            SetPosition(Bytes + _startPos);
        }
    }
    
    try
    {
        SetPosition(Bytes + _startPos);
    }
    catch(size_t _newPos)
    {
        SetActualPosition(_newPos);
        SetPosition(_newPos);
    }
     */
    return Bytes;
}

size_t Page_t::Read(void *_buff, size_t _toRead)
{
    return Read(_buff, _toRead, GetPosition());
}

size_t Page_t::Read(void *_buff, size_t _toRead, size_t _startPos)
{
    if (_buff == NULL || _toRead == 0 || IsEmpty() == true || _startPos >  m_globalCapacity || _startPos > GetActualPosition())
    {
        return 0;
    }
    if(GetActualPosition() < m_capacity)
    {
        m_capacity = GetActualPosition();
    }
    size_t Bytes = (m_capacity - _startPos) > _toRead ? _toRead : m_capacity - _startPos;
    memcpy(_buff, &m_begin[_startPos], Bytes);
    SetPosition(_startPos +Bytes);
    m_capacity = m_globalCapacity;
    return Bytes;
}