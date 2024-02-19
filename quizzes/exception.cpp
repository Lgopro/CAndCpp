
#include <iostream>


int main()
{
    try
    {
        int i = 0;
        if(i == 0)
        {
            throw std::runtime_error("Its zero!!!!");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}