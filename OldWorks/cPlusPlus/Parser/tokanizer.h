#ifndef TOKANIZER_H
#define TOKANIZER_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include "TException_t.h"
#include "parser.h"
using namespace std;
class Tokanizer
{
public:
    Tokanizer(){}
    ~Tokanizer(){}
    void Tokanize(string _str);
    bool ListIsEmpty(){return (m_list.empty()) ? true : false;}
    void Clear();
    list <string> GetList();
private:
    Tokanizer(const Tokanizer &);
    Tokanizer &operator=(const Tokanizer &);
    list <string> m_list;
};

void Tokanizer::Tokanize(string _line)
{
    size_t pos = _line.find_first_of("+-=->=+-*&<>)([]{};,\r\t ");
	size_t start = 0;
	size_t len;
	
	while(pos!=string::npos) 
    {
		len = pos - start;
		if(len>0) 
        {
			m_list.push_back(_line.substr(start,len));
		}
		if(!isspace(_line[pos])) 
        {
			m_list.push_back(_line.substr(pos,1));
		}
		start = pos+1;
		pos =  _line.find_first_of("+-=->=+-*&<>)([]{};,\t\r ",pos+1);
	}	

	if(!isspace(_line[start]) && _line[start]!='\0') 
    {
		if(isspace(_line[_line.size()-1])) 
        {
			m_list.push_back(_line.substr(start,_line.size()-1-start));	
		} 
        else 
        {
			m_list.push_back(_line.substr(start,_line.size()-start));
		}	
	}
}

list <string> Tokanizer::GetList()
{
    return m_list;
}
void Tokanizer::Clear()
{
    m_list.clear();
    
}
#endif