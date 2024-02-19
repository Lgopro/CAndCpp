#ifndef __STRING_H__
#define __STRING_H__

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <iostream>



namespace experis{
class String
{
public:
    String();
    String(const char* a_str);
    String(const String& a_str);
    String& operator = (const String& a_str);
    ~String();

    bool operator==(const String& a_str) const;
    

    const char& operator[](size_t a_number) const; 
    char& operator[](size_t a_number);

    const char* AsCString() const;
    size_t Length() const {return m_length;}
private:
    char* createFrom(const char* _str);
    char* m_string; //must be before m_length
    size_t m_length;
       
};


std::ostream& operator<< (std::ostream& os, const String& _str); 
bool operator==(const char* str_, const String& str);
} // experis
#endif