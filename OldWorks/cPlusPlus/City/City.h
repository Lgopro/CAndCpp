#ifndef _CITY_T_H
#define _CITY_T_H
#include <vector>
#include <iostream>
#include "Street.h"
#include "Building.h"
#include "TException_t.h"
using namespace std;

template <class CTY,class STR,class BLD>
class City_t
{
public:
    ~City_t();
    City_t();
    City_t(const CTY& _c);
    City_t<CTY, STR, BLD>& operator = (const City_t<CTY, STR, BLD>& _toCopy);
    City_t(const City_t<CTY, STR, BLD>& _toCopy);

    const void setCityID(const CTY& _id);
    CTY& getCityID() const;
    void AddStreet(Street_t<STR, BLD>& _id);
    const Street_t<STR, BLD>& GetStreet(const STR& _id) const ;

private:
    CTY m_id;
    vector<Street_t<STR, BLD> > m_vecCity;
};



template <class CTY,class STR,class BLD> 
City_t<CTY,STR,BLD>::City_t(){}

template <class CTY,class STR,class BLD> 
City_t<CTY,STR,BLD>::City_t(const CTY& _c)
{
    m_id = _c;
}

template <class CTY,class STR,class BLD> 
City_t<CTY,STR,BLD>::~City_t(){}

template <class CTY,class STR,class BLD> 
City_t<CTY,STR,BLD>::City_t(const City_t& _toCopy)
{
    m_id =_toCopy.getCityID();
}

template <class CTY,class STR,class BLD> 
CTY& City_t<CTY,STR,BLD>::getCityID() const
{
    return m_id;
}

template <class CTY,class STR,class BLD> 
const void City_t<CTY,STR,BLD>::setCityID(const CTY& _id) 
{
    m_id = _id;
}

template <class CTY,class STR,class BLD> 
void City_t<CTY,STR,BLD>::AddStreet(Street_t<STR, BLD>& _id)
{
     m_vecCity.insert(m_vecCity.end(), _id);
}


template <class CTY,class STR,class BLD> 
const Street_t<STR, BLD>& City_t<CTY,STR,BLD>::GetStreet(const STR& _id) const 
{
    size_t i;
    for(i=0;i<m_vecCity.size();i++)
    {
        if(m_vecCity[i] == _id)
        {
            return m_vecCity[i];
        }
    }
    return m_vecCity[i];
}

template <class CTY,class STR,class BLD> 
City_t<CTY, STR, BLD>& City_t<CTY, STR, BLD>::operator = (const City_t<CTY, STR, BLD>& _toCopy)
{
    if(this != &_toCopy)
    {
        m_id = _toCopy.getCityID();

    }
    return *this;
}

#endif
