#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

std::unordered_map<int,int> CountOccurences(std::list<int> &list)
{
    std::unordered_map<int,int> counter;

    for(const auto& iter: list)
    {
        if(counter.end() == counter.find(iter))
        {
            counter.insert(std::pair<int,int>(iter, 1));
        }
        else
        {
            ++counter[iter];
        }
    }
    return counter;

}




int main()
{

    std::list<int> list = {1, 2, 3, 1, 2, 1, 4, 5, 4, 3, 6, 7, 7};

    std::unordered_map<int, int> result = CountOccurences(list);

    for(const auto &iter : result)
    {
        std::cout<< "Value is:" << iter.first << " Amount is :" << iter.second << std::endl;
    }
    return 0;
}