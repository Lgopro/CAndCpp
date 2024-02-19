#ifndef __VECTOR_T_H__
#define __VECTOR_T_H__
#include "Container_t.h"
#include "TException_t.h"
#include <cstring>
template <class VEC>
class vector_t: public container_t<VEC>
{
public:
    size_t Count() const {return this->GetNumOfElem();};
    bool IsEmpty() const {return this->GetNumOfElem() == 0;};

    vector_t(const vector_t &_copy)
    {
       size_t i;
        m_capacity = _copy.m_capacity;
        m_elements = new VEC[_copy.Count()];
        for(i=0; i<_copy.Count(); i++)
        {
            m_elements[i] = _copy.m_elements[i];
        } 
    }
    vector_t &operator=(const vector_t & _copy)
    {
        if(this != &_copy)
        {
            size_t i;
            m_capacity = _copy.m_capacity;
            m_elements = new VEC[_copy.Count()];
            for(i=0; i<_copy.Count(); i++)
            {
                m_elements[i] = _copy.m_elements[i];
            }
        }
        return *this;
    }
    vector_t():m_capacity(m_defcapacity)
    {
        m_elements = new VEC*[m_capacity];
    };
    
    vector_t(size_t _size):m_capacity(_size)
    {
        m_elements = new VEC*[m_capacity];
    };
    ~vector_t()
    {
        if(m_elements != NULL)
        {
            delete [] m_elements;
        }
    };

    virtual bool Append(size_t _index, const VEC* _item)
    {
        if(_item == NULL || _index > m_capacity)
        {
            return false;
        }
        if(_index >= Count() )
        {
            m_elements[Count()] = (VEC*)_item;
            this->IncreaseSizeOf();
            return true;
        }
        MoveToInsert(_index +1, Count());
        m_elements[_index + 1] = (VEC*)_item;
        this->IncreaseSizeOf();
        return true;

        
    };

    virtual bool Prepend(size_t _index, const VEC* _item)
    {
        if(_item == NULL || _index == 0 || _index > m_capacity)
        {
            return false;
        }
        if(_index > Count())
        {
            m_elements[Count()] = (VEC*)_item;
            this->IncreaseSizeOf();
            return true;
        }
        MoveToInsert(_index - 1, Count());
        m_elements[_index - 1] = (VEC*)_item;
        this->IncreaseSizeOf();
        return true;
    };
    
    virtual bool Contains(const VEC& _item)
    {
        size_t i;
        for(i = 0 ; i < Count() ; ++i)
        {
            if(*m_elements[i] == _item)
            {
                return true;
            }
        }
        return false;
    };
    
    virtual VEC* Find(const VEC& _item) const
    {
        size_t i;
        for(i = 0 ; i < Count() ; ++i)
        {
            if(*m_elements[i] == _item)
            {
                return m_elements[i];
            }
        }
        return NULL;
    };

    virtual int Index(const VEC& _item) const
    {
        size_t i;

        for(i = 0 ; i < Count() ; ++i)
        {
            if(*m_elements[i] == _item)
            {
                return i;
            }
        }
        return -1;
    };

    virtual bool Insert(const VEC* _item)
    {
        if(_item == NULL)
        {
            return false;
        }
        
        m_elements[Count()] = (VEC*)_item;
        this->IncreaseSizeOf();
        return true;
        
    }

    virtual VEC* Remove(const VEC& _item)
    {
        size_t i,j;
        VEC* temp;

        for(i = 0 ; i < Count() ; ++i)
        {
            if(*m_elements[i] == _item)
            {
                temp = m_elements[i];
                for(j = i; j < Count(); ++j)
                {
                    m_elements[i] = m_elements[i+1];
                }
                return temp;
            }
        }
        this->DecreaseSizeOf();
        return NULL;
    }

    virtual bool RemoveAndDelete(const VEC& _item)
    {
        size_t i,j;
        VEC* temp;

        for(i = 0 ; i < Count() ; ++i)
        {
            if(*m_elements[i] == _item)
            {
                temp = m_elements[i];
                for(j = i; j < Count(); ++j)
                {
                    m_elements[i] = m_elements[i+1];
                }
                m_elements[Count() - 1] = temp;
                delete m_elements[Count() - 1];
                this->DecreaseSizeOf();
                return true;
            }
        }
        return false;
    }
    
    virtual void RemoveAll()
    {
        this->SetNumOfElem(0);

    }

    virtual void RemoveAndDeleteAll()
    {
        delete [] m_elements;
        this->SetNumOfElem(0);
    }

private:
    VEC** m_elements;
    size_t m_capacity;
    static size_t m_defcapacity;


    void Increasesize(void)
    {
        VEC** temp = new VEC*[m_capacity * 2];
        memcpy(*temp, *m_elements, sizeof(VEC*) * m_capacity);
        delete [] m_elements;
        m_elements = temp;
        m_capacity *= 2;
    };
    void MoveToInsert(size_t _begin, size_t _end)
    {
        size_t i;
        if(_end +1 > m_capacity)
        {
            this->Increasesize();
        }
        for(i = _end - 1 ; i >= _begin ; i--)
        {
            m_elements[i + 1] = m_elements[i]; 
        }
    }
};

template <class VEC> size_t vector_t<VEC>::m_defcapacity = 20;

#endif 
