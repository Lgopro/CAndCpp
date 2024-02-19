#include <iostream>
#include <list>


int SumLists(std::list<int> list1, std::list<int> list2)
{
    int sum = 0;
    int kaful = 1;
    while(1)
    {
        if(list1.size() != 0 && list2.size() != 0)
        {
            sum += list1.back() * kaful + list2.back() * kaful;
            list1.pop_back();
            list2.pop_back();
        }
        else if(list1.size() != 0 && list2.size() == 0)
        {
            sum += list1.back() * kaful;
            list1.pop_back();
        }
        else if(list1.size() == 0 && list2.size() != 0)
        {
            sum += list2.back() * kaful;
            list2.pop_back();
        }
        else
        {
            return sum;
        }
        kaful *= 10;
    }
}

int main()
{
    std::list<int> list1 = {1, 6, 2, 5};
    std::list<int> list2 = {2, 6, 4, 5};

    int sum = SumLists(list1, list2);
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}