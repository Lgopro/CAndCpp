#ifndef __STRING_T_H__
#define __STRING_T_H__
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;
/*To declare class String_t with following functionality:
	
    • default CTOR
    • CTOR from "const char*"	
    • copy CTOR
    • DTOR	
    • assignment operator
    • mem-function 'length' which returns length of the string
    • mem-function 'setString' which gets as a parameter "const char*"
    • mem-function 'getString' which returns "const char*"
    • mem-function 'compare' which compares 2 strings
		and returns:
		0 - if they are equal
		1 - if the object string less than parameter
		2 - if the object greater than parameter
	
		This function gets as a parameter another string
    • print
    */


class String_t
{
    public:
        String_t();
        String_t(const char* _str);
        String_t(const String_t& _str);
        ~String_t();
        String_t& operator = (const String_t& _str);
        void Upper(); /*TODO*/
        void Lower(); /*TODO*/
        void Prepend(const char* _str); /*TODO return String_t or void*/
        void Prepend(const String_t& _str); /*TODO return String_t or void*/
        unsigned int Length() const;
        void setString(const char* _string);
        const char* getString() const;
        void Print() const;
        int Compare(const char* _string) const;
        enum{SAME , SMALLER , BIGER };
        void operator+=(const char* _str); /*TODO return String_t or void*/
        void operator+=(const String_t& _str); /*TODO return String_t or void*/

        bool operator<(const String_t& _str) const ;
        bool operator>(const String_t& _str) const;
        bool operator<=(const String_t& _str) const;
        bool operator>=(const String_t& _str) const;
        bool operator==(const String_t& _str) const;
        bool operator!=(const String_t& _str) const;
        String_t operator()(uint _start,uint _len);

        int Containes(const String_t& _str) const;
        const char& operator[]( size_t _number) const;/*TODO*/
        char& operator[](int _number); /*TODO*/
        int FindFirst(char _letter) const;
        int FindLast(char _letter) const;
        inline static size_t nOfObjects();
        static bool MakeNewCaseSens();
        static size_t ReturnCurrentDefCap();
        static size_t ReturnNewDefCap();
    private:
        char* m_string;
        static size_t numOfObjects;
        size_t Capacity;
        static bool CaseSens;
        static size_t defCapacity;
        char* createFrom(const char* _str);
       
};
inline size_t String_t::nOfObjects()
{ 
    return numOfObjects; 
}

ostream& operator<< (ostream& os, const String_t& _str); 
istream& operator>> (istream& is,  String_t& _str);

inline const char* String_t::getString() const
{
    return m_string;
}

inline void String_t::setString(const char* _string)
{
    delete(m_string);
    m_string = createFrom(_string);
}

inline unsigned int String_t::Length() const 
{
    return strlen(m_string);
}


#endif