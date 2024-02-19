
#include "Pool.h"


using namespace std;
size_t Pool_t::m_globalPageCapacity = 6;


Pool_t::Pool_t()
{
    Page_t *page = new Page_t();
    m_pool.insert(m_pool.end(), page);
}
Pool_t::~Pool_t()
{
    size_t i;
    for (i = 0; i < m_pool.size(); i++)
    {
        delete m_pool[i];
    }
    m_pool.clear();
}

size_t Pool_t::Read(void *_buff, size_t _toRead)
{
    return Read(_buff, _toRead, GetPosition());
}
size_t Pool_t::Write(const void *_buff, size_t _toWrite)
{
    return Write(_buff, _toWrite, GetPosition());
}

size_t Pool_t::Read(void *_buff, size_t _toRead, size_t _startPos)
{
    size_t pageNumber,startPosition = _startPos;
    if(_startPos + _toRead > GetActualPosition() || _buff == NULL || _toRead == 0)
    {
        return 0;
    }
    pageNumber = FindPageNumber( startPosition);
    startPosition -= pageNumber * m_globalPageCapacity;
    size_t bytesToRead;
    bytesToRead = _toRead;
    _toRead -= m_pool[pageNumber]->Read(_buff, _toRead, startPosition);
    while(TRUE)
    {
        if(_toRead == 0)
        {
            break;
        }
        else
        {
            pageNumber++;
            _toRead -= m_pool[pageNumber]->Read((char*)_buff + bytesToRead - _toRead,_toRead, 0);
        }
    }
    SetPosition(_startPos + bytesToRead);
    return bytesToRead;
}

size_t Pool_t::Write(const void *_buff, size_t _toWrite, size_t _startPos)
{
    size_t pageNumber,startPosition = _startPos;
    if(_startPos  > GetActualPosition() || _buff == NULL || _toWrite == 0)
    {
        return 0;
    }
    pageNumber = FindPageNumber( _startPos);
    if(pageNumber == 0 && _startPos == 0)
    {
        Page_t* newPage = new Page_t();
		m_pool.insert(m_pool.end(), newPage);
    }
    startPosition = GetPosition();
    size_t maxPageNumber;
    maxPageNumber = FindPageNumber( _toWrite + _startPos);
    size_t bytesToWrite = _toWrite;
    bytesToWrite -= m_pool[pageNumber]->Write(_buff, bytesToWrite, startPosition);
    pageNumber++;
    while(TRUE)
    {
        if(bytesToWrite == 0)
        {
            break;
        }
        else if(pageNumber <= maxPageNumber)
        {
            Page_t* newPage = new Page_t();
			m_pool.insert(m_pool.end(), newPage);
            bytesToWrite -= m_pool[pageNumber]->Write((char*)_buff + _toWrite - bytesToWrite , bytesToWrite, 0);
            pageNumber++;
        }
        else
        {
            bytesToWrite -= m_pool[pageNumber]->Write((char*)_buff + _toWrite - bytesToWrite, bytesToWrite, 0);
            pageNumber++;
        }
    }
    if(_startPos + _toWrite <= GetActualPosition())
    {
        SetPosition(_startPos + _toWrite);
    }
    else
    {
        SetActualPosition(_startPos + _toWrite);
        SetPosition(_startPos + _toWrite);
    }
    /* try
    {
        SetPosition(_startPos + _toWrite);
    }
    catch(size_t _newPos)
    {
        SetActualPosition(_newPos);
        SetPosition(_newPos);
    } */
    
    

    return _toWrite;
}


size_t Pool_t::FindPageNumber(size_t _startPosition)
{
    size_t i=0;
    while(TRUE)
    {
        if(_startPosition > m_globalPageCapacity)
        {
            _startPosition -= m_globalPageCapacity;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}