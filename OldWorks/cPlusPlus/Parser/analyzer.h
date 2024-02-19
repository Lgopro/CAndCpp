#ifndef ANALYZER_H
#define ANALYZER_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include "TException_t.h"
#include "parser.h"
using namespace std;

static string KeyWords[11] = {"if", "else", "for" , "while", "class", "private", "public", "protected", "main", "const", "virtual"};

static string Operators[9] = {"=", "+", "-", "*", "&", "<", ">", ",", ";"};

static string DataTypes[7] ={ "char", "short", "int", "long", "float", "double", "void" };

static string Brackets[6] = {"}", "{", "(", ")", "[" , "]"};

class Analyzer
{
public:
    std::vector<string>::iterator it;
    Analyzer():m_operators(&Operators[0], &Operators[9]),
							m_types(&DataTypes[0], &DataTypes[7]),
							m_keyWords(&KeyWords[0], &KeyWords[11])
                            {
                                m_bracket1Counter = 0;
                                m_bracket2Counter = 0;
                                m_bracket3Counter = 0;
                                m_mainFlag = 0;
                                m_keyWordFlag = 0;
                                m_DataTypesFlag = 0;
                                m_lastLineFlag = 0;
                                m_ifFlag = 0;
                            }
    ~Analyzer(){}
    Analyzer(const Tokanizer& _tok){}
    bool IsWord(const string& _word);
    bool IsOperator(const string& _word);
    bool IsDataTypes(const string& _word);
    void IsBracket(const string& _word);
    void BracketOutput();
    bool FindMain(const string& _word);
    void MainOutput() const;
    void KeyWordOutput() const;
    void IfElseOutput(const string& _word) ;
    void IfElseOutput(const string& _word) const;
    void AnylizeSentence(list <string> _sentence , int _line);
    bool FindIf(const string& _word);
    void DataTypeOutput() ;
    void EnterDataName(const string& _word);
    void CheckVariable(const string& _word);
    void OperatorHandler(const string& _word);
    void Begin();
    void End();
    void NotDeclared(const string& _word);
private:
    Tokanizer* m_tok;
    Analyzer(const Analyzer &){}
    Analyzer &operator=(const Analyzer &){return *this;}
    int m_bracket1Counter;
    int m_bracket2Counter;
    int m_bracket3Counter;
    int m_bracket1Line;
    int m_bracket2Line;
    int m_bracket3Line;
    int m_operatorCounter;
    size_t m_operatorFlag;
    size_t m_brack1flag;
    size_t m_brack2flag;
    size_t m_brack3flag;
    size_t m_line;
    size_t m_mainFlag;
    size_t m_keyWordFlag;
    size_t m_DataTypesFlag;
    size_t m_lastLineFlag;
    size_t m_ifFlag;
    string m_lastToken;
    set<string>	m_brackets;
	set<string>	m_operators;
	set<string>	m_types;
	set<string>	m_keyWords;
    vector <string> m_dataName;
    vector <string> m_funcName;

};





void Analyzer::AnylizeSentence(list <string> _sentence , int _line)
{   
    string word;
    m_line = _line; 
    Begin();
    if(_line == -1)
    {
        m_lastLineFlag = 1;
        BracketOutput();
        m_dataName.clear();
        m_funcName.clear();
    } 
    else
    {
        while(_sentence.empty() != true)
        {
            word = _sentence.front();
            _sentence.pop_front();
            if(m_DataTypesFlag > 0)
            {   
                if(m_types.end() == m_types.find(word) )
                {
                    CheckVariable(word);
                }
            }
            IsOperator(word);
            
            OperatorHandler(word);
               
            
            IsWord(word);
            IsDataTypes(word);
            IsBracket(word);
            FindMain(word);
            FindIf(word);
            IfElseOutput(word);
            DataTypeOutput();
            
            
        }
        BracketOutput();
        if(_line == 1)
        {
            MainOutput();
        }
        KeyWordOutput();
        DataTypeOutput();
    }

    End();
    
}
void Analyzer::Begin()
{
    m_bracket1Line = 0;
    m_bracket2Line = 0;
    m_bracket3Line = 0;
    m_brack1flag = 0;
    m_brack2flag = 0;
    m_brack3flag = 0;
}
void Analyzer::End()
{
    m_bracket1Line = 0;
    m_bracket2Line = 0;
    m_bracket3Line = 0;
    m_brack1flag = 0;
    m_brack2flag = 0;
    m_brack3flag = 0;
    m_keyWordFlag = 0;
}
bool Analyzer::IsWord(const string& _word)
{
    return (m_keyWords.end() != m_keyWords.find(_word)) ? true : false;
}

bool Analyzer::IsOperator(const string& _word)
{
    return (m_operators.end() != m_operators.find(_word)) ? m_operatorCounter++, m_operatorFlag = 1, true :m_operatorCounter = 0, m_operatorFlag = 0, false;
}

bool Analyzer::IsDataTypes(const string& _word)
{
    return (m_types.end() != m_types.find(_word)) ? m_DataTypesFlag++, true : false;
}

void Analyzer::IsBracket(const string& _word)
{
    
    (_word == "{") ? m_bracket1Line++ ,m_bracket1Counter++ : m_bracket1Counter = m_bracket1Counter;
    (_word == "[") ? m_bracket2Line++ ,m_bracket2Counter++ : m_bracket2Counter = m_bracket2Counter;
    (_word == "(") ? m_bracket3Line++ ,m_bracket3Counter++ : m_bracket3Counter = m_bracket3Counter;
    (_word == "}") ? m_bracket1Line--, m_bracket1Counter--: m_bracket1Counter = m_bracket1Counter;
    (_word == "]") ? m_bracket2Line--, m_bracket2Counter-- : m_bracket2Counter = m_bracket2Counter;
    (_word == ")") ? m_bracket3Line--, m_bracket3Counter-- : m_bracket3Counter = m_bracket3Counter;
    if(m_bracket1Line < 0)
    {
        m_brack1flag = 1;
    }
    if(m_bracket2Line < 0)
    {
        m_brack2flag = 1;
    }
    if(m_bracket3Line < 0)
    {
        m_brack3flag = 1;
    }
}

void Analyzer::BracketOutput()
{
    if(m_bracket1Counter < 0 && m_brack1flag == 1 && m_lastLineFlag == 0)
    {
        cout << "line " << m_line << "- error, '}' without '{' " << endl;
    }
    if(m_bracket2Counter < 0 && m_brack2flag == 1 && m_lastLineFlag == 0)
    {
        cout << "line " << m_line << "- error, ']' without '[' " << endl;
    }
    if(m_bracket3Counter < 0 && m_brack3flag == 1 && m_lastLineFlag == 0)
    {
        cout << "line " << m_line << "- error, ')' without '(' " << endl;
    }


    if(m_bracket2Counter > 0  && m_lastLineFlag == 1)
    {
        cout << "error, 1 '[' not closed " << endl;
    }
    if(m_bracket1Counter > 0  && m_lastLineFlag == 1)
    {
        cout << "error, 2 '{' not closed " << endl;
    }
    if(m_bracket3Counter > 0  && m_lastLineFlag == 1)
    {
        cout << "error, 3 '(' not closed " << endl;
    }

}

void Analyzer::MainOutput() const
{
    if(m_mainFlag == 1 && m_line != 1)
    {
        return;
    }  
    cout << "line " << m_line << "- error, no main before " << endl;
    
    
}

void Analyzer::KeyWordOutput() const
{
    if(m_keyWordFlag % 2 == 0 && m_keyWordFlag > 0)
    {
        cout << "line " << m_line << "- error, multiple type " << endl;
        
    }  
}

void Analyzer::IfElseOutput(const string& _word) 
{
    if(m_ifFlag == 0 && _word == "else")
    {
        cout << "line " << m_line << "- error, 'else' without 'if'" << endl;
    }  
}
void Analyzer::DataTypeOutput() 
{
    if(m_DataTypesFlag % 2 == 0 && m_DataTypesFlag > 0)
    {
        cout << "line " << m_line << "- error, multiple type declaration" << endl;
        m_DataTypesFlag = 0;
    }  
}
bool Analyzer::FindIf(const string& _word)
{
    if(_word == "if")
    {
        m_ifFlag = 1;
        return true;
    }  
    return false;
}

bool Analyzer::FindMain(const string& _word)
{
    if(_word == "main" && m_line == 1)
    {
        m_mainFlag = 1;
        return true;
    }  
    return false;
}

void Analyzer::EnterDataName(const string& _word)
{
    it = find(m_dataName.begin(),m_dataName.end(), _word);
    if(it != m_dataName.end())
    {
        cout << "line " << m_line << "- error, variable"<< _word << "not declared" << endl;
    }
    else
    {
        m_dataName.push_back(_word);
    }
    
}
void Analyzer::NotDeclared(const string& _word)
{
    if((m_keyWords.end() == m_keyWords.find(_word) && (m_operators.end() == m_operators.find(_word)) && m_types.end() == m_types.find(_word) && m_brackets.end() == m_brackets.find(_word) ))
    {
        if(m_DataTypesFlag == 0)
        {
            cout << "line " << m_line << "- error, variable "<< _word << " not declared" << endl;
        }
    }
}
void Analyzer::CheckVariable(const string& _word)
{
    if((m_keyWords.end() == m_keyWords.find(_word) && (m_operators.end() == m_operators.find(_word)) && m_types.end() == m_types.find(_word) && m_brackets.end() == m_brackets.find(_word) ))
    {
        if(m_DataTypesFlag == 0)
        {
            cout << "line " << m_line << "- error, variable "<< _word << " not declared" << endl;
        }
        if(m_DataTypesFlag > 0)
        {
            
            if(!((_word[0] >=65 && _word[0] <= 90) || (_word[0] == '_' ) || (_word[0] >=97 && _word[0] <= 122)))
            {
                cout << "line " << m_line << "- error, illegal variable name " << _word <<  endl;
            }
            it = find(m_dataName.begin(),m_dataName.end(), _word);
            if(it != m_dataName.end())
            {
                cout << "line " << m_line << "- error, variable "<< _word << " already declared" << endl;
            }
            else
            {
                m_dataName.push_back(_word);
            }
            m_DataTypesFlag = 0;
        }
    }
    else
    {
        cout << "line " << m_line << "- error, key word: "<< _word << " cannot be declared as a variable" << endl;
        m_DataTypesFlag = 0;
    }
    
}

void Analyzer::OperatorHandler(const string& _word)
{
    if(m_operatorCounter == 1)
    {
        m_lastToken = _word ;
    }
    if(m_operatorCounter == 3 && _word == m_lastToken  && (m_lastToken == "+" || m_lastToken == "-")  )
    {
        cout << "line " << m_line << "- error, no operator "<< _word << _word << _word  << endl;
    }
    if(m_operatorCounter > 0)
    {
        if(_word == m_lastToken)
        {
            m_lastToken = _word;
            return;
        }
        
        m_operatorCounter = 0;
    }
}
#endif