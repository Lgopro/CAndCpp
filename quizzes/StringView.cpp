
#include <iostream>
#include <string.h>
#include <string>

namespace ilrd
{
    
    class String
    {
        public:

        String(const std::string arr = "");
        ~String() = default;

        String(const String& other) = default;
        String& operator=(const String& other) = default;
        std::string GetArr();

        private:

        std::string m_arr;

    };

    class StringView
    {
        public:

        StringView(String& str);
        ~StringView() = default;

        StringView(const StringView& other) = default;
        StringView& operator=(const StringView& other) = default;
        String GetString() const;
        

        private:

        String m_str;
    };

    String StringView::GetString() const
    {
        return m_str;
    }

    std::ostream& operator<<(std::ostream& out, StringView& sv)
    {
        out << sv.GetString().GetArr();
        return out;
    }
    void Foo(StringView sv) 
    {
        std::cout << sv; 
    }

    String::String(const std::string arr):m_arr(arr)
    {

    }

    std::string String::GetArr()
    {
        return m_arr;
    }

    template <typename T>
    void Swap(T& str1, T& str2)
    {
        T str = str1;
        str1 = str2;
        str2 = str;
    }

    StringView::StringView(String& str)
    {
        m_str = str;
    }
}

using namespace ilrd;

int main()
{
    std::string arr = "Hello";
    std::string arr1 = "Hehe Boy!";

    String str(arr);
    String str1(arr1);

    Swap(str, str1);

    std::cout << "str is: " << str.GetArr() << " after swap." << std::endl;
    std::cout << "str1 is: " << str1.GetArr() << " after swap." << std::endl;

    Foo(str);
    return 0;
}