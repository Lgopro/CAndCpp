
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#include "StringT.h"


size_t String_t:: numOfObjects = 0;
bool String_t:: CaseSens = true;
size_t String_t:: defCapacity = 8;


bool String_t::MakeNewCaseSens()
{
    if(CaseSens == true)
    {
        CaseSens = false;
        return true;
    }
    CaseSens = true;
    return false;
}
size_t String_t::ReturnCurrentDefCap()
{
    return defCapacity;
}
size_t String_t::ReturnNewDefCap()
{
    defCapacity *= 2;
    return defCapacity/2;
}
String_t String_t::operator()(uint _start,uint _len)
{
    String_t newString;
    if(_start > Length() || _start + _len > Length())
    {
        return newString;
    }
    char* temp = new char(_len +1);
    
    if(_start + _len < Length())
    {
        strncpy(temp, getString()+_start, _len);
        temp[_len] = '\0';
        newString.setString(temp);
    }
    delete(temp);
    return newString;
}
char* String_t::createFrom(const char* _str) 
{

    if(NULL == _str)
    {
        Capacity = defCapacity;
        char* tmp = new char(1);
        tmp[0] = '\0';
        return tmp;
    }
    if(strlen(_str)+1 <= defCapacity)
    {
        Capacity = defCapacity;
        char* tmp = new char(defCapacity);
        strcpy(tmp,_str);
        return tmp;
    }
    else
    {
        Capacity = defCapacity;
        while(Capacity < strlen(_str)+1)
        {
            defCapacity *= 2;
            Capacity = defCapacity;
        }
        char* tmp = new char(Capacity);
        strcpy(tmp,_str);
        return tmp;
    }
    
}
String_t::String_t() 
{
    numOfObjects++;
    m_string = createFrom(0); 
}
String_t::String_t(const char* _str)
{
    numOfObjects++;
    m_string = createFrom(0); 
}
String_t::String_t(const String_t& _str)
{
    numOfObjects++;
    m_string = createFrom(_str.getString()); 

}
String_t::~String_t() 
{
    numOfObjects--;
    delete(m_string); 
}


int String_t::Compare(const char* _string) const 
{
    if(CaseSens == true)
    {
        if(strncmp(_string, m_string, strlen(_string)) == 0)
        {
            return SAME;
        }
        else if(strncmp(_string, m_string, strlen(_string)) < 0)
        {
            return SMALLER;
        }
        return BIGER;
        }
    
    if(strcasecmp(_string, m_string) == 0)
    {
        return SAME;
    }
    else if(strcasecmp(_string, m_string) < 0)
    {
        return SMALLER;
    }
    return BIGER;
   
   
    
}
void String_t::Print() const 
{
    const char* string;
    string = getString();
    cout << "" << string << endl;
}

String_t& String_t::operator = (const String_t& str)
{
    if(this != &str)
    {
        delete(m_string);
        m_string = createFrom(str.m_string);
    }
    return *this;
}

void String_t::Upper()
{
    size_t i;
    for(i=0;i<strlen(m_string);i++)
    {
        if(m_string[i] >= 97 && m_string[i] <= 122 )
        {
            m_string[i] -= 32;
        }
    }
    
}

void String_t::Lower()
{
    size_t i;
    for(i=0;i<strlen(m_string);i++)
    {
        if(m_string[i] >= 65 && m_string[i] <= 90 )
        {
            m_string[i] += 32;
        }
    }
}

void String_t::Prepend(const char* _str)
{
    if(NULL == _str)
    {
        return;
    }
    char* newString = new char(strlen(_str) + Length() + 1);
    strcpy(newString,_str);
    strcat(newString, m_string);
    m_string = createFrom(newString);
    delete(newString);
    
}


 
void String_t::Prepend(const String_t& _str)
{
    if(NULL == _str.m_string)
    {
        return;
    }
    char* newString = new char(strlen(_str.m_string) + Length() + 1);
    strcpy(newString,_str.m_string);
    strcat(newString, m_string);
    m_string = createFrom(newString);
    delete(newString);
    
} 

void String_t::operator+=(const char* _str)
{
    if(NULL == _str)
    {
        return ;
    }
    char* newString = new char(strlen(_str) + Length() + 1);
    strcpy(newString,m_string);
    strcat(newString, _str);
    m_string = createFrom(newString);
    delete(newString);
    
}

void String_t::operator+=(const String_t& _str)
{
    if(NULL == _str.m_string)
    {
        return;
    }
    char* newString = new char(strlen(_str.m_string) + Length() + 1);
    strcpy(newString,m_string);
    strcat(newString, _str.m_string);
    m_string = createFrom(newString);
    delete(newString);
    
}



bool String_t::operator<(const String_t& _str) const
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) < 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) < 0) ? true : false;
    }
}

bool String_t::operator>(const String_t& _str) const 
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) > 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) > 0) ? true : false;
    }

}

bool String_t::operator<=(const String_t& _str) const 
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) <= 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) <= 0) ? true : false;
    }

}

bool String_t::operator>=(const String_t& _str) const 
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) >= 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) >= 0) ? true : false;
    }
}


bool String_t::operator==(const String_t& _str) const
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) == 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) == 0) ? true : false;
    }
    

}

bool String_t::operator!=(const String_t& _str) const
{
    if(NULL == _str.m_string)
    {
        return false;
    }
    if(_str.CaseSens == true)
    {
        return (strcmp(m_string, _str.m_string) != 0) ? true : false;
    }
    else
    {
        return (strcasecmp(m_string, _str.m_string) != 0) ? true : false;
    }

}

int String_t::Containes(const String_t& _str) const
{
    if(NULL == _str.m_string)
    {
        return 0;
    }
    return (strstr(m_string , _str.m_string) == NULL) ? 0 : 1;
}


const char& String_t::operator[](size_t _number) const 
{
    char outOfBound = '\0';
    return (_number >= strlen(m_string)) ? outOfBound : m_string[_number];
}

char& String_t::operator[](int _number)
{
    char outOfBound = '\0';
    return (_number >= (int)strlen(m_string)) ? outOfBound : m_string[_number];
}


int String_t::FindFirst(char _letter) const
{
    char* find;
    find= strchr(m_string,_letter);
    return (find == NULL) ? -1 : find-m_string;
}

int String_t::FindLast(char _letter) const
{
    char* find;
    find= strrchr(m_string,_letter);
    return (find == NULL) ? -1 : find-m_string;
}

ostream& operator<< (ostream& os, const String_t& _str) 
{
    os << _str.getString();
    return os;
}

istream& operator>> (istream& is, String_t& _str)
{
    char string[100];
    is >> string;
    _str.setString(string);
    return is;
}
