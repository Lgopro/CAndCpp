#ifndef _STREET_T_H
#define _STREET_T_H
#include <vector>
#include <iostream>
#include "Building.h"
#include "TException_t.h"
using namespace std;

template <class STR, class BLD>
class Street_t
{
public:
    ~Street_t();
    Street_t();
    Street_t(const STR& _s);
    Street_t(const Street_t &_toCopy);
    Street_t<STR, BLD> &operator=(const Street_t<STR, BLD> &_toCopy);

    void SetStreetId(const STR &_id);
    const STR &GetStreetId() const;
    void AddBuilding2Street(Building_t<BLD> &_id);
    const Building_t<BLD> &GetBuilding(const BLD &_id)const ;

private:
    STR m_id;
    vector<Building_t<BLD> > m_vecStr;
};

template <class STR, class BLD>
Street_t<STR, BLD>::Street_t(){};


template <class STR, class BLD>
Street_t<STR, BLD>::Street_t(const STR& _s)
{
    m_id = _s;
}

template <class STR, class BLD>
Street_t<STR, BLD>::~Street_t(){};

template <class STR, class BLD>
const STR &Street_t<STR, BLD>::GetStreetId() const 
{
    return m_id;
}

template <class STR, class BLD>
void Street_t<STR, BLD>::SetStreetId(const STR &_id)
{
    m_id = _id;
}

template <class STR, class BLD>
void Street_t<STR, BLD>::AddBuilding2Street(Building_t<BLD> & _id)
{
    m_vecStr.insert(m_vecStr.end(), _id);
}

template <class STR, class BLD>
const Building_t<BLD> &Street_t<STR, BLD>::GetBuilding(const BLD &_id) const 
{
    size_t i;
    for (i = 0; i < m_vecStr.size(); ++i)
    {
        if (m_vecStr[i].GetBuildingID() == _id)
        {
            return m_vecStr[i];
        }
    }
    if(i == m_vecStr.size())
    {
		throw TException_t<BLD>(_id, __FILE__, __LINE__, "Building was not found");
    }
    return m_vecStr[i];
}

template <class STR, class BLD>
Street_t<STR, BLD>::Street_t(const Street_t &_toCopy)
{
    m_id = _toCopy.GetStreetId();
    m_vecStr = _toCopy.m_vecStr;
}

template <class STR, class BLD>
Street_t<STR, BLD> &Street_t<STR, BLD>::operator=(const Street_t &_toCopy)
{
    if (this != &_toCopy)
    {
        m_id = _toCopy.GetStreetId();
        m_vecStr = _toCopy.m_vecStr;
    }
    return *this;
}

#endif