


#include <iostream>
#include "string.h"

namespace ilrd
{
    class String
    {  
        public:

        String(const char * arr = "");
        ~String();
        String(const String& other);
        String& operator=(const String& other);

        inline char *ToStr() const;
        size_t Length() const;

        private:

        char *Init(const char *array);
        char *m_arr;
    };

}

using namespace ilrd;

String::String(const char * arr):m_arr(Init(arr))
{
}
        
String::~String()
{
    delete [] m_arr;
}

String::String(const String& other):m_arr(Init(other.m_arr))
{
}


String& String::operator=(const String& other)
{
    char *temp = Init(other.m_arr);
    delete m_arr;
    m_arr = temp;
    return *this;
}

char *String::ToStr() const
{
    return m_arr;
}
        
size_t String::Length() const
{
    return strlen(m_arr);
}

char *String::Init(const char *array)
{
    char *temp = new char[strlen(array) + 1];
    strcpy(temp, array);
    return temp;
}

int main()
{
    char array[] = "What?";
    String arr(array);

    std::cout<< arr.ToStr() << std::endl;

    return 0;
}