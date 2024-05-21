
#include <iostream>
#include <string>

namespace ilrd
{

    class String
    {
    public:
        String(std::string str);
        ~String() = default;
        String(const String &other) = default;
        String &operator=(const String &other) = default;

        std::string GetString() const;

    private:
        std::string m_str;
    };

    class ViewString
    {
    public:
        ViewString(String &str);
        ~ViewString() = default;
        ViewString(const ViewString &other) = default;
        ViewString &operator=(const ViewString &other) = default;

        String GetViewStr() const;
    private:
        String m_str;
    };

    std::ostream &operator<<(std::ostream &os, ViewString &str)
    {
        os << str.GetViewStr().GetString();
        return os;
    }

    String::String(std::string str) : m_str(str)
    {
    }

    std::string String::GetString() const
    {
        return m_str;
    }

    ViewString::ViewString(String &str) : m_str(str)
    {
    }

    String ViewString::GetViewStr() const
    {
        return m_str;
    }
}

using namespace ilrd;


void Foo(ViewString sv) 
{
    std::cout << sv; 
}

int main()
{
    String s("abc");
    Foo(s);
} 
