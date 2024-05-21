
#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

namespace ilrd
{
    class Proxy
    {
        public:

        Proxy();
        ~Proxy() = default;
        Proxy(const Proxy& other) = default;
        Proxy& operator=(const Proxy& other) = default;

        char operator=(char m_ch);
        
        char& GetValue();
        char GetValue() const;
        void PrintChar() const;


        private:
        char m_value;

    };

    class String
    {
        public:

        String(const std::string word);
        String(const char* word = "");
        ~String();

        String(const String& other) = default;
        String& operator=(const String& other) = default;

        char operator[](size_t value) const;
        char& operator[](size_t value);
        void PrintString() const;

        private:

        Proxy *m_word;
        size_t m_size;
    };

        String::String(const std::string word)
        {
            m_size = word.size();
            m_word = new Proxy[m_size];

            for(size_t i = 0; i < m_size; ++i)
            {
                m_word[i].GetValue() = word[i];
            }
        }

        String::String(const char* word)
        {
            m_size = strlen(word);
            m_word = new Proxy[m_size];

            for(size_t i = 0; i < m_size; ++i)
            {
                m_word[i].GetValue() = word[i];
            }
        }

        String::~String()
        {
            delete [] m_word;
        }
        
        
        char String::operator[](size_t value) const
        {
            if(value >= m_size)
            {
                throw std::out_of_range("out of range");
            }
            return m_word[value].GetValue();
        }

        char& String::operator[](size_t value)
        {
            if(value >= m_size)
            {
                throw std::out_of_range("out of range");
            }
            return m_word[value].GetValue();
        }

        void String::PrintString() const
        {
            for(size_t i = 0; i < m_size; ++i)
            {
                m_word[i].PrintChar();
            }
            std::cout << "" << std::endl;
        }

        Proxy::Proxy() : m_value('0')
        {

        }

        char Proxy::GetValue() const
        {
            return m_value;
        }

        char& Proxy::GetValue()
        {
            return m_value;
        }

        void Proxy::PrintChar() const
        {
            std::cout << m_value;
        }

        char Proxy::operator=(char m_ch)
        {
            m_value = m_ch;
            return m_value;
        }
}


using namespace ilrd;

int main()
{
    String s("abc");
    char var = s[0]; // var is assigned ‘a’. “read from index 0” is printed.
    s[1] = 'd'; // s[1] is assigned ‘d’. “assignment to index 1” is printed.

    s.PrintString();


    return 0;
}
