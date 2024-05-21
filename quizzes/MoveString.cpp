
#include "MoveString.hpp"

using namespace ilrd;

MoveString::MoveString(std::string name) : m_name(name)
{
}

MoveString::MoveString(const char* name) : m_name(name)
{
    
}

MoveString::MoveString(MoveString& other)
{
    m_name = other.GetString();
    other.EmptyString();
}
        
MoveString& MoveString::operator=(MoveString& other)
{
    m_name = other.GetString();
    other.EmptyString();
    return *this;
}


std::string MoveString::GetString() const
{
    return m_name;
}

void MoveString::EmptyString()
{
    m_name = "";
}

std::ostream& ilrd::operator<<(std::ostream& out, const MoveString& value)
{
    out << value.GetString();
    return out;
}



int main()
{
	MoveString s1("abcdefg");
	std::cout << "s1 is: " << s1 << std::endl; 

	MoveString s2;
	s2 = s1;
    std::cout << "s1 is: " << s1 << std::endl; 
	std::cout << "s2 is: " << s2 << std::endl;  

	MoveString s3(s2); 
   
    std::cout << "s1 is: " << s1 << std::endl; 
	std::cout << "s2 is: " << s2 << std::endl;  
	std::cout << "s3 is: " << s3 << std::endl;  
} 
