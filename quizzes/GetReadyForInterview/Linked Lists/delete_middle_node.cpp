#include <iostream>
#include <list>


void DeleteMiddleNode(std::list<int> &list)
{
    size_t counter = 1;
    size_t middle = list.size()/2;
    std::list<int>::iterator iter = list.begin();

    while(counter != middle)
    {
        ++iter;
        ++counter;
    }

    list.erase(iter);
}

int main()
{
    std::list<int> list = {4,5 ,3, 2, 5, 6,4 ,6 ,3 ,6, 2,4};
    DeleteMiddleNode(list);
    for(auto iter : list)
    {
        std::cout << "iter :" << iter << std::endl;
    }
    return 0;
}