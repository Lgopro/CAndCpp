#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream> 
#include "TException_t.h"
#include "tokanizer.h"
#include "analyzer.h"
using namespace std;

class Parser
{
public:
    Parser();
    ~Parser();
    Parser(const char *_fileName);
    bool OpenFile(const char *_fileName);
    enum status
    {
        ok_e,
        cant_open_file_e
    };
    std::string GetName() const { return m_name; } 
    
protected:
   

private:
    std::string m_name;
    Tokanizer* m_tok;
    Analyzer* m_analyz;
    status m_status;
    Parser(const Parser &);
    Parser &operator=(const Parser &);
};
Parser::Parser()
{
    m_tok = new Tokanizer;
    m_analyz = new Analyzer/* (*m_tok) */;
}

Parser::~Parser()
{
    delete m_tok;
    delete m_analyz;
}
Parser::Parser(const char *_fileName)
{
    m_tok = new Tokanizer;
    m_analyz = new Analyzer/* (*m_tok) */;
    OpenFile(_fileName);
}

bool Parser::OpenFile(const char *_fileName)
{
    int lineNum = 1;
    if(_fileName == NULL)
    {
        m_status = cant_open_file_e;
        return false;
    }
    string line, word;
    ifstream myfile (_fileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            m_tok->Tokanize(line); 
            m_analyz->AnylizeSentence(m_tok->GetList() , lineNum);
            m_tok->Clear();
            lineNum++;
        }
        m_analyz->AnylizeSentence(m_tok->GetList() , -1);
        myfile.close();
    }
    else
    {
        throw TException_t<const char*>(_fileName, __FILE__, __LINE__, "Could not open file");
    }
    return true;

}
 



#endif