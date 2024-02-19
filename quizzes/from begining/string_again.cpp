

#include <iostream>
#include "string.h"

namespace ilrd
{
    class String
    {
        public:
        String(const char *arr = "");
        ~String();
        String(const String& other);
        String& operator=(const String& other);

        inline const char *ToStr() const;
        size_t Size() const;

        private:

        char *Init(const char * array);
        char *m_array;
    };
}


using namespace ilrd;

String::String(const char *arr):m_array(Init(arr))
{
}

String::~String()
{
    delete [] m_array;
}


String::String(const String& other):m_array(other.m_array)
{
}
        
String& String::operator=(const String& other)
{
    char *temp = Init(other.m_array);
    delete [] m_array;
    m_array = temp;
    return *this;
}

char *String::Init(const char * array)
{
    char *temp = new char[strlen(array) + 1];
    strcpy(temp, array);
    return temp;
}


const char *String::ToStr() const
{
    return m_array;
}
        
size_t String::Size() const
{
    return strlen(m_array);
}