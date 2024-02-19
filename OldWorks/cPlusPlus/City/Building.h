#ifndef _BUILDING_H
#define _BUILDING_H

#include <iostream>
using namespace std;

template <class BLD>
class Building_t
{
public:
    Building_t();
    ~Building_t();
    Building_t(const BLD &_b);
    Building_t<BLD> &operator=(const Building_t<BLD> &_b);
    Building_t(const Building_t<BLD> &_b);

    void SetBuildingID(const BLD &_BLD);
    const BLD &GetBuildingID() const;

private:
    BLD m_id;
};

template <class BLD>
Building_t<BLD>::Building_t() {}

template <class BLD>
Building_t<BLD>::~Building_t() {}

template <class BLD>
Building_t<BLD>::Building_t(const BLD &_id)
{
    m_id = _id;
}

template <class BLD>
Building_t<BLD>::Building_t(const Building_t<BLD> &_copy)
{
    m_id = _copy.GetBuildingID();
}

template <class BLD>
Building_t<BLD> &Building_t<BLD>::operator=(const Building_t<BLD> &_copy)
{
    if (this != &_copy)
    {
        m_id = _copy.GetBuildingID();
    }
    return *this;
}

template <class BLD>
const BLD &Building_t<BLD>::GetBuildingID() const
{
    return m_id;
}

template <class BLD>
void Building_t<BLD>::SetBuildingID(const BLD &_id)
{
    m_id = _id;
}

#endif