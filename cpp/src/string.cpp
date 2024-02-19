/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 05/08/23
*/
#include <string.h> /*strlen*/

#include "string.hpp"
using namespace ilrd;

static const int EQUAL = 0;
static const int BUFFER_SIZE = 1000;


String::String(const char* str):m_str(Initiate(str))
{
    
}

String::String(const String& other_):m_str(Initiate(other_.m_str))
{
    
}

String::~String()
{
    delete[] this->m_str;
}

String& String::operator=(const String& other_)
{
    char *temp = Initiate(other_.m_str);
    delete [] this->m_str;
    this->m_str = temp;
    return *this;
}

size_t String::Length() const 
{
    return strlen(this->m_str);
}


bool ilrd::operator==(const String& str1, const String& str2)
{
    return (EQUAL == strcmp(str1.CStr(), str2.CStr()));
}   
   
bool ilrd::operator>(const String& str1, const String& str2)
{
    return (EQUAL > strcmp(str1.CStr(), str2.CStr()));
}

bool ilrd::operator<(const String& str1, const String& str2)
{
    return (EQUAL < strcmp(str1.CStr(), str2.CStr()));
}

std::ostream& ilrd::operator<<(std::ostream& out, const String& str)
{
    out << str.CStr();
    return out;
}

std::istream& ilrd::operator>>(std::istream& in, String& str)
{
    char buffer[BUFFER_SIZE] = {0}; 
    in >> buffer;
    str =  String(buffer); 
    return in;
}



char *String::Initiate(const char *str)
{
    char *temp = new char[strlen(str) + 1];
    strcpy(temp, str);
    return temp;
}