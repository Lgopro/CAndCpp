#include "string.hpp"



namespace experis{
String::String()
: m_string(createFrom(0)),
m_length(strlen(m_string)){}


String::~String(){
    delete[] m_string;
}


String::String(const char* a_str)
: m_string(createFrom(a_str)),
m_length(strlen(m_string)){}

String::String(const String& a_str)
: m_string(createFrom(a_str.AsCString())),
m_length(strlen(m_string)){}

char* String::createFrom(const char* a_str){
    if(0 == a_str){
        m_string = new char(1);
        m_string[0] = '\0';
        return m_string;
    }
    m_string = new char(strlen(a_str) + sizeof('\0'));
    strcpy(m_string, a_str);
    return m_string;
}

const char* String::AsCString() const { //getstring
    return m_string; //inline?
}

/* String& String::operator = (const String& a_str){
    if(this != &a_str)//no need for \0
    {
        m_string = createFrom(a_str.AsCString());
        m_length = a_str.Length();
    }
    return *this;
}  */

char& String::operator[](size_t a_number){
    char outOfBound = '\0';
    return (a_number >= strlen(m_string)) ? outOfBound : m_string[a_number];
}

const char& String::operator[](size_t a_number) const {
    char outOfBound = '\0';
    return (a_number >= strlen(m_string)) ? outOfBound : m_string[a_number];
}


bool String::operator==(const String& a_str) const{
    if(NULL == a_str.AsCString())//reference will come ok
    {
        return false;
    }
    return (strcmp(AsCString(), a_str.AsCString()) == 0);
}

bool operator==(const char* a_str, const String& astr){ // bool operator==(const String& a_str, const String& astr) will convert char* to string and will work.
    return (strcmp(a_str, astr.AsCString()) == 0);
}

std::ostream& operator<<(std::ostream& a_os, const String& a_str) {
    a_os << a_str.AsCString();
    return a_os;
}




String& String::operator=(const String& str_){
    char* onTheStack = m_string;
    m_string = createFrom(str_.AsCString());
    delete[] onTheStack;
    return *this;
}  

}//experis