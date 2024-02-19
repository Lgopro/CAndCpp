#include <string.h> /*strlen*/
#include <cstddef>
#include "rc_string.hpp"
using namespace ilrd;

static const int SET = 1;
static const int EQUAL = 1;
static const char FAIL = '\0';

RCString::RCString(const char* str):string_struct(Initiate(str))
{
    
}

RCString::RCString(const RCString& other_)
{
    this->string_struct = other_.string_struct;
    ++this->string_struct->m_counter;
}

RCString::~RCString()
{
    if(SET != this->string_struct->m_counter)
    {
        --this->string_struct->m_counter;
        return;
    }
    else
    {
        delete this->string_struct;
    }
}

RCString& RCString::operator=(const RCString& other_)
{
    this->string_struct = other_.string_struct;
    ++this->string_struct->m_counter;
    return (*this);
}

RCString& RCString::operator=(const char* str)
{
    rs_string_t* temp = static_cast<rs_string_t *>(operator new(offsetof(rs_string_t, m_str) + strlen(str) + 1));
    if(SET == this->string_struct->m_counter)
    {
        delete[] this->string_struct;
    }
    else
    {
        --this->string_struct->m_counter;
    } 
    this->string_struct = temp;
    this->string_struct->m_counter = SET;
    strcpy(this->string_struct->m_str, str);
    return (*this);
}


bool ilrd::operator==(const RCString& str1, const RCString& str2)
{
    return (EQUAL == strcmp(str1.ToCStr(), str2.ToCStr()));
}   

bool ilrd::operator!=(const RCString& str1, const RCString& str2)
{
    return (EQUAL != strcmp(str1.ToCStr(), str2.ToCStr()));
} 
   
bool ilrd::operator>(const RCString& str1, const RCString& str2)
{
    return (EQUAL > strcmp(str1.ToCStr(), str2.ToCStr()));
}

bool ilrd::operator<(const RCString& str1, const RCString& str2)
{
    return (EQUAL < strcmp(str1.ToCStr(), str2.ToCStr()));
}

RCString::rs_string_t* RCString::Initiate(const char* str)
{
    this->string_struct = static_cast<rs_string_t *>(operator new(offsetof(rs_string_t, m_str) + strlen(str) + 1));
    this->string_struct->m_counter = SET;
    strcpy(this->string_struct->m_str, str);
    return (this->string_struct);
}


char RCString::operator[](size_t location) const
{
    if(location >= strlen(this->string_struct->m_str))
    {
        return FAIL;
    }
    return this->string_struct->m_str[location];
}

char& RCString::operator[](size_t location)
{
    if(location >= strlen(this->string_struct->m_str))
    {
        return this->string_struct->m_str[strlen(this->string_struct->m_str)];
    }
    if(SET == this->string_struct->m_counter)
    {
        return this->string_struct->m_str[location];
    }
    --this->string_struct->m_counter;
    return this->string_struct->m_str[location];
}