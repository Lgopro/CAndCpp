#include <iostream>
#include <list>

std::list<int> FromKthToEnd(std::list<int> &list, size_t k)
{
    size_t counter = 0;
    std::list<int> return_list;
    std::list<int>::iterator iter = list.begin();
    for(iter = list.begin(); iter != list.end(); ++iter)
    {
        if(counter == k)
        {
            break;
        }
        ++counter;
    }

    while(iter != list.end())
    {
        return_list.push_back(*iter);
        ++iter;
    }

    return return_list;
}

int main()
{
    std::list<int> list = {4,5 ,3, 2, 5, 6,4 ,6 ,3 ,6, 2,4};
    std::list<int> result = FromKthToEnd(list, 6);
    for(auto iter : result)
    {
        std::cout << "iter :" << iter << std::endl;
    }
    return 0;
}