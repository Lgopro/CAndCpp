#include <iostream>
#include <list>


std::list<int> Partition(std::list<int> list, int number)
{
    std::list<int> return_list;
    while(list.size() != 0)
    {
        int value = list.front();
        list.pop_front();
        if(value >= number)
        {
            return_list.push_back(value);
        }
        else
        {
            return_list.push_front(value);
        }
    }
    return return_list;
}

int main()
{
    std::list<int> list = {4,5 ,3, 2, 5, 6,4 ,6 ,3 ,6, 2,4};
    std::list<int> result = Partition(list, 5);

    for(auto iter : result)
    {
        std::cout << "iter :" << iter << std::endl;
    }

    return 0;
}