
#include <iostream>
#include <string>

namespace ilrd
{
    class MoveStringAgain
    {
        public:

        MoveStringAgain(std::string str = "");
        ~MoveStringAgain() = default;
        MoveStringAgain(const MoveStringAgain& other);
        MoveStringAgain& operator=(const MoveStringAgain& other);

        std::string GetStr() const;
        void SeTStr(std::string new_str);

        private:

        std::string m_str;

    };

MoveStringAgain::MoveStringAgain(std::string str): m_str(str)
{

}

MoveStringAgain::MoveStringAgain(const MoveStringAgain& other)
{
    std::string str = "";
    m_str = other.GetStr();
    const_cast<MoveStringAgain *>(&other)->SeTStr(str);
}

MoveStringAgain& MoveStringAgain::operator=(const MoveStringAgain& other)
{
    std::string str = "";
    m_str = other.GetStr();
    const_cast<MoveStringAgain *>(&other)->SeTStr(str);
    return *this;
}

std::string MoveStringAgain::GetStr() const
{
    return m_str;
}

void MoveStringAgain::SeTStr(std::string new_str)
{
    m_str = new_str;
}

}


using namespace ilrd;

int main()
{

    MoveStringAgain str1("Hallo");
    MoveStringAgain str2;
    MoveStringAgain str3;

    std::cout << "str1 is " << str1.GetStr() << std::endl;
    std::cout << "str2 is " << str2.GetStr() << std::endl;
    std::cout << "str3 is " << str3.GetStr() << std::endl;

    str2 = str1;
    std::cout << "str1 is " << str1.GetStr() << std::endl;
    std::cout << "str2 is " << str2.GetStr() << std::endl;
    std::cout << "str3 is " << str3.GetStr() << std::endl;

    MoveStringAgain str4(str2);
    std::cout << "str1 is " << str1.GetStr() << std::endl;
    std::cout << "str2 is " << str2.GetStr() << std::endl;
    std::cout << "str4 is " << str4.GetStr() << std::endl;
    return 0;
}