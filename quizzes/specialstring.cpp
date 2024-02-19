#include <string.h>
#include "specialstring.hpp"

using namespace ilrd;

size_t String::instances = 0; // Initialize the static member

String::String():m_str(Initiate("ABC"))
{

}

String::String(const char* str):m_str(Initiate(str))
{
    
}

String::String(const String& other_):m_str(Initiate(other_.m_str))
{
    
}

String::~String()
{
    --instances;
    delete[] m_str;
}

void String::operator=(const String& other_)
{
    if (this != &other_) // Check for self-assignment
    {
        delete[] m_str;
        --instances;
        m_str = Initiate(other_.m_str);
    }
    return;
}

void String::operator=(const char other_)
{
    for(size_t i = 0; i < strlen(m_str); ++i)
    {
        m_str[i] = other_;
    }
    return;
}

size_t String::Length() const 
{
    return strlen(m_str);
}

const char* String::CStr() const
{
    return m_str;
}

size_t String::GetInstances()
{
    return instances;
}


char * String::Initiate(const char* str)
{
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    ++instances;
    return m_str;
}

char String::operator[](size_t location) const
{
    if (location >= strlen(m_str))
    {
        return m_str[strlen(m_str) - 1]; // Return the last character
    }
    return m_str[location];
}

char& String::operator[](size_t location)
{
    if (location >= strlen(m_str))
    {
        return m_str[strlen(m_str) - 1]; // Return the last character
    }
    return m_str[location];
}

String::operator const char*() const
{
    return m_str;
}

String::operator std::string() const
{
    return std::string(m_str);
}


int main()
 {  
    String s1("1234");  
    s1 = '@'; // will change s1 to "@@@@"   
    String *s2 = new String;            
    std::cout<< s2->GetInstances()<<std::endl; // will print 2     
    delete s2;
      
    std::cout<< String::GetInstances()<<std::endl; // will print 1 
    String s4("1234");  
    String s0;
    std::cout<< s0.CStr() << std::endl;  
    String s3(s1);
    std::cout<< s3.CStr() << std::endl;  
    s1[0] = 'r'; 
    std::cout<< s1.CStr() << std::endl;  
    s4[0] = s1[1];
    std::cout<< s4.CStr() << std::endl; 
    s1 = "abc"; 
    std::cout<< s1.CStr() << std::endl; 
    s4 = s1; 
    std::cout<< s4.CStr() << std::endl;
    s1 = 'A';
    std::cout<< s1.CStr() << std::endl;
    /* s1 = s4 = s3; */
}



