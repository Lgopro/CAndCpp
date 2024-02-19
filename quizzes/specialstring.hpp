#ifndef __ILRD_SIMPLE_STR_HPP__
#define __ILRD_SIMPLE_STR_HPP__

#include <iostream>
#include <string>

namespace ilrd
{

class String 
{
public:
    String();
    String(const char* str);
    String(const String& other_);
    ~String();

    void operator=(const char other_);
    void operator=(const String& other_);

    size_t Length() const;
    const char* CStr() const;
    static size_t GetInstances();

    operator const char*() const; // Conversion to char *
    operator std::string() const; // Conversion to std::string

    char operator[](size_t location) const;
    char& operator[](size_t location); 

private:
    char* m_str; 
    static size_t instances;

    char * Initiate(const char* str); 
};




} 

#endif



