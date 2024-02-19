#ifndef _HANDLER_H
#define _HANDLER_H

#include <string>
#include <iostream>
#include <new>
using namespace std;

template <class HAND>
class TException_t
{
public:
    TException_t(const HAND &_texp, const string &_file, size_t _line, const string &_text);
    //~TException_(){}// default DTOR
    const HAND &GetException() const { return m_data; };
    size_t GetLine() const { return m_line; };
    const string &GetFile() const { return m_file; };
    const string &GetText() const { return m_text; };

private:
    size_t m_line;
    string m_text;
    string m_file;
    HAND m_data;
};

template <class HAND>
TException_t<HAND>::TException_t(const HAND &_texp, const string &_file, size_t _line, const string &_text)
{
    m_data = _texp;
    m_file = _file;
    m_text = _text;
    m_line = _line;
}

#endif