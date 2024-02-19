/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 05/08/23
*/
#ifndef __ILRD_SIMPLE_STR_HPP__
#define __ILRD_SIMPLE_STR_HPP__

#include <iostream>
#include <iosfwd>

namespace ilrd
{

class  String 
{

public:

    String(const char* str = "");

    String(const String& other_);

    ~String();

    String& operator=(const String& other_);

    size_t Length() const;

    inline const char* CStr() const;

private:

    char* m_str;
    char *Initiate(const char *str);
};


bool operator==(const String& str1, const String& str2);

bool operator>(const String& str1, const String& str2);

bool operator<(const String& str1, const String& str2);

std::ostream& operator<<(std::ostream& out, const String& str);

std::istream& operator>>(std::istream& in, String& str);

inline const char* String::CStr() const 
{
    return (this->m_str);
}
}

#endif