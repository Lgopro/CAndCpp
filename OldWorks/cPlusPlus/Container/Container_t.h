#ifndef __CONTAINER_T_H__
#define __CONTAINER_T_H__
#include <stdlib.h>

template <typename CONT>
class container_t
{
public:
    container_t(): m_nOfElements(0){};
    container_t(const container_t &_cont){m_nOfElements = _cont.m_nOfElements;};
    container_t &operator=(const container_t &_cont)
    {
        if(this != &_cont)
        {
            m_nOfElements = _cont.m_nOfElements;
        }
        return *this;

    };
    virtual ~container_t(){};

    virtual bool Append(size_t _index, const CONT* _item) = 0; //i dont have to write the function because = 0;

    virtual bool Prepend(size_t _index, const CONT* _item) = 0;

    virtual bool Contains(const CONT& _item) = 0;

    size_t Count() const { return m_nOfElements; };

    virtual CONT* Find(const CONT& _value) const = 0;

    virtual int Index(const CONT& _item) const = 0;

    virtual bool Insert(const CONT* _item) = 0;

    bool IsEmpty() const { return m_nOfElements == 0; };

    virtual CONT* Remove(const CONT& _value) = 0;

    virtual void RemoveAll() = 0;

    virtual bool RemoveAndDelete(const CONT& _value) = 0;

    virtual void RemoveAndDeleteAll() = 0;
protected:
    void SetNumOfElem(size_t _size){m_nOfElements = _size;};
    size_t GetNumOfElem() const{return m_nOfElements;};
    void IncreaseSizeOf(){m_nOfElements++;};
    void DecreaseSizeOf(){m_nOfElements--;};
private:
    size_t m_nOfElements;
};

#endif //__CONTAINER_T_H__