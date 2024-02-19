#include <iostream>
#include <list>




bool Palindrom(std::list<char> list)
{
    size_t counter = 0;
    if(list.size() == 0)
    {
        return false;
    }
    else
    {
        auto begin_iter = list.begin();
        auto end_iter = list.end();
        --end_iter;
        while(counter < list.size() / 2 + 1)
        {
            if(*begin_iter == *end_iter)
            {
                std::cout << "Begin iter is: " << *begin_iter << std::endl;
                std::cout << "Begin end is: " << *end_iter << std::endl;
                ++begin_iter;
                --end_iter;
                ++counter;
            }
            else
            {
                std::cout << "Begin iter is: " << *begin_iter << std::endl;
                std::cout << "Begin end is: " << *end_iter << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{

    std::list<char> list = {'h', 'e', 'h'};
    bool status = Palindrom(list);
    if(status == true)
    {
        std::cout << "The status is true" << std::endl;
    }
    else
    {
        std::cout << "The status is false" << std::endl;
    }
    return 0;
}