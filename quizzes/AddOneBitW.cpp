

#include <iostream>

unsigned int AddOne(unsigned int number)
{
    for(size_t i = 0 ; i < 32 ; ++i)
    {
        if(number & 1 << i)
        {
            number = number ^ (1 << i);
            
        }
        else
        {
            number = number ^ (1 << i);
            break;
        }
    }
    return number;
}

int main()
{
    unsigned int plus_one = 0;
    unsigned int number = 5;
    plus_one = AddOne(number);

    std::cout<< "The number is: "<< number << " and the plus one is: " << plus_one << std::endl;

    number = 9;
    plus_one = AddOne(number);

    std::cout<< "The number is: "<< number << " and the plus one is: " << plus_one << std::endl;

    return 0;
}