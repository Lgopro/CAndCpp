

#include <iostream>
#include <list>


void RemoveDuplicate(std::list<int> &list)
{
    for(std::list<int>::iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        std::list<int>::iterator iter2 = iter;
        ++iter2;

        while(iter2 != list.end())
        {
            /* std::cout<< "Im in while" << std::endl; */
            if(*iter == *iter2)
            {
                /* std::cout<< "Im in if" << std::endl; */
                std::list<int>::iterator iter3 = iter2;
                ++iter3;
                std::cout<< "iter is: " << *iter << " iter2 is: " << *iter2 << std::endl;
                list.erase(iter2);
                iter2 = iter3;
            }
            else
            {
                ++iter2;
            }
        }
    }
}

int main()
{
    std::list<int> list = {4,5 ,3, 2, 5, 6,4 ,6 ,3 ,6, 2,4};
    RemoveDuplicate(list);

    for(auto iter : list)
    {
        std::cout << "iter :" << iter << std::endl;
    }

    return 0;
}