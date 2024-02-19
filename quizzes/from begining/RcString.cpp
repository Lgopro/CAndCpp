#include <iostream>
#include "string.h"

namespace ilrd
{
    class RcString
    {
        public:

        RcString(const char* value = "");
        ~RcString();
        RcString& operator=(const RcString& other);
        RcString(const RcString& other);

        inline const char* ToCStr() const;

        inline const size_t Length() const;

        char& operator[](const size_t location);

        char operator[](const size_t location) const;

        size_t GetCounter() const;
        
        void SetCounter(size_t counter);

        private:
        
        size_t * m_counter_p;
        size_t m_counter;
        char *m_str;

        char *Init(const char* str);
    };

    bool operator==(const RcString& value1, const RcString& value2);
    bool operator!=(const RcString& value1, const RcString& value2);
    
    bool operator<(const RcString& value1, const RcString& value2);
    bool operator>(const RcString& value1, const RcString& value2);
    
}


using namespace ilrd;

void RcString::SetCounter(size_t counter)
{
    m_counter = counter;
}


size_t ilrd::RcString::GetCounter() const
{
    return m_counter;
}

RcString::RcString(const char* value):m_str(Init(value)),m_counter(1)
{
    m_counter_p = &m_counter;
}

RcString::~RcString()
{
    if(1 == *m_counter_p)
    {
        --*m_counter_p;
        delete [] m_str;
    }
    else
    {
        --*m_counter_p;
    }
    
}

RcString& RcString::operator=(const RcString& other)
{
    size_t counter = other.GetCounter();
    m_counter_p = &m_counter;
    *m_counter_p = ++counter;
    m_str = other.m_str;
    return *this;
}

RcString::RcString(const RcString& other)
{
    size_t counter = other.GetCounter();
    m_counter_p = &m_counter;
    *m_counter_p = ++counter;
    m_str = other.m_str;
}

inline const char* RcString::ToCStr() const
{
    return m_str;
}

inline const size_t RcString::Length() const
{
    return strlen(m_str);
}

char& RcString::operator[](const size_t location)
{
    return m_str[location];
}

char RcString::operator[](const size_t location) const
{
    return m_str[location];
}

bool ilrd::operator==(const RcString& value1, const RcString& value2)
{
    return (!strcmp(value1.ToCStr(), value2.ToCStr()));
}
bool ilrd::operator!=(const RcString& value1, const RcString& value2)
{
    return (strcmp(value1.ToCStr(), value2.ToCStr()));
}
    
bool ilrd::operator<(const RcString& value1, const RcString& value2)
{
    if(0 < strcmp(value1.ToCStr(), value2.ToCStr()))
    {
        return true;
    }
    return false;
}
bool ilrd::operator>(const RcString& value1, const RcString& value2)
{
    if(0 < strcmp(value1.ToCStr(), value2.ToCStr()))
    {
        return false;
    }
    return true;
}
    
char *RcString::Init(const char* str)
{
    char *temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    return temp;
}




int main()
{
    RcString string1("Hello");

    std::cout << string1.ToCStr() << "Counter is: " << string1.GetCounter()  <<std::endl;

    RcString string2(string1);

    std::cout << string2.ToCStr() << "Counter is: " << string2.GetCounter()  <<std::endl;

}