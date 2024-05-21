#include <iostream>
#include <string>
#include <string.h>

namespace ilrd
{

    class Proxy
    {
        public:

        Proxy(const char ch = '0', size_t loc = 0);
        ~Proxy() = default;
        Proxy(const Proxy& other) = default;
        Proxy& operator=(const Proxy& other) = default;

        void operator=(const char other);

        char GetChar() const;
        char& GetChar();
        void SetChar(const char ch);
        void SetLoc(const size_t loc);

        void PrintChar() const;

        private:

        char m_ch;
        size_t m_loc;
        
    };

    class StringGil
    {
        public:
        StringGil(const std::string str);
        StringGil(const char *arr = "");
        ~StringGil();
        
        char operator[](const size_t num) const;
        char& operator[](const size_t num); 
        void PrintString() const;

        private:

        StringGil(const StringGil& other) = delete;
        StringGil& operator=(const StringGil& other) = delete;


        Proxy *m_arr;
        size_t m_size;
    };
}


using namespace ilrd;


Proxy::Proxy(const char ch, size_t loc):m_ch(ch)
{
}


void Proxy::operator=(const char other)
{
    std::cout << "assignment to index " << m_loc << std::endl;
    m_ch = other;
}

StringGil::StringGil(const std::string str)
{
    try
    {
        m_size = str.size();
        m_arr = new Proxy[m_size];
        for(size_t i = 0; i < m_size; ++i)
        {
            m_arr[i].SetChar(str[i]);
            m_arr[i].SetLoc(i);
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
        
StringGil::StringGil(const char *arr)
{
    try
    {
        m_size = strlen(arr);
        m_arr = new Proxy[m_size];
        for(size_t i = 0; i < m_size; ++i)
        {
            m_arr[i].SetChar(arr[i]);
            m_arr[i].SetLoc(i);
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
        
StringGil::~StringGil()
{
    delete [] m_arr;
}


char StringGil::operator[](const size_t num) const
{
    return m_arr[num].GetChar();
}

char& StringGil::operator[](const size_t num)
{
    return m_arr[num].GetChar();
}

char Proxy::GetChar() const
{
    return m_ch;
}

char& Proxy::GetChar()
{
    return m_ch;
}

void Proxy::SetChar(const char ch)
{
    m_ch = ch;
}

void Proxy::SetLoc(const size_t loc)
{
    m_loc = loc;
}

void Proxy::PrintChar() const
{
    std::cout<< m_ch;
}

void StringGil::PrintString() const
{
    for(size_t i = 0; i < m_size; ++i)
    {
        m_arr[i].PrintChar();
    }
    std::cout << "" << std::endl;
}

int main()
{
    StringGil s("abc");
    char var = s[0]; 
    s[1] = 'd';
    std::cout << var << std::endl;
    s.PrintString();
}