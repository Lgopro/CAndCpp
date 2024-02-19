
#include <iostream>
#include "string.h"

namespace ilrd
{
    class String
    {
        public:
        String(const char* str= "");
        ~String();
        String& operator=(const String& other);
        String(const String& other);

        const char*GetCStr();
        const size_t GetLength() const;


        private:
        char *m_str;
        char* InitString(const char* str);
    };
}


using namespace ilrd;
const char* String::GetCStr()
{
    return m_str;
}

const size_t String::GetLength() const
{
    return strlen(m_str);
}
String::String(const char* str):m_str(InitString(str))
{
}

String::~String()
{
    delete [] m_str;
}

String& String::operator=(const String& other)
{
    char* temp = InitString(other.m_str);
    delete [] m_str;
    m_str = temp;

}


String::String(const String& other):m_str(InitString(other.m_str))
{

}

char *String::InitString(const char* str)
{
    char *temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    return temp;
}




int main()
{
    String s1("Hello");
    String s2(s1);
    s1 = s2;
    s1.GetLength();
    s1.GetCStr();
    return 0;
}