#ifndef __ILRD_SIMPLE_RCRCString_HPP__
#define __ILRD_SIMPLE_RCRCString_HPP__

#include <iostream>
#include <iosfwd>

static const int EXIST = 1;

namespace ilrd
{

class  RCString 
{
public:
    RCString(const char* str = "");

    RCString(const RCString& other_);

    ~RCString();

    RCString& operator=(const RCString& other_);

    RCString& operator=(const char* str);

    inline size_t Length() const;

    inline const char* ToCStr() const;

    inline bool IsShared(const RCString& other_);

    inline size_t GetCounter() const;

    char operator[](size_t location) const; /*return*/

    char& operator[](size_t location); /*change*/

private:
    typedef struct String
    {
        size_t m_counter;
        char m_str[1];
    }rs_string_t;
    rs_string_t* string_struct;
    rs_string_t* Initiate(const char* str);
};



bool operator==(const RCString& str1, const RCString& str2);

bool operator!=(const RCString& str1, const RCString& str2);

bool operator>(const RCString& str1, const RCString& str2);

bool operator<(const RCString& str1, const RCString& str2);

inline const char* RCString::ToCStr() const 
{
    return (this->string_struct->m_str);
}

inline size_t RCString::GetCounter() const
{
    return (this->string_struct->m_counter);
}

inline bool IsShared(const RCString& other_)
{
    return (EXIST < other_.GetCounter());
}

inline size_t RCString::Length() const 
{
    return strlen(this->string_struct->m_str);
}

}

#endif