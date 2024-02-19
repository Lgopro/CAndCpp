#include <iostream>


void PrintDistinct(std::string array)
{
    int LUT[256] = {0};
    for(size_t i = 0; i < array.length(); ++i)
    {
        ++LUT[array[i]];
    }
    for(size_t i = 0; i < array.length(); ++i)
    {
        if(LUT[array[i]] == 1)
        {
            std::cout<< array[i];
        }
    }
}


int main()
{
    std::string m_str = "Geeks Quiz";
    PrintDistinct(m_str);



    return 0;
}