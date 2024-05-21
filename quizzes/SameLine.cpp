#include <iostream>
#include <array>

const int ERROR = 0;

template <size_t size>
size_t SameLine(std::array<std::pair<int, int>, size>& arr)
{
    size_t max_counter = 2;
    size_t counter = 0;
    int m = 0;
    size_t location = 0;

    if(size == 1)
    {
        return ERROR;
    }

    for(size_t i = 0; i < size; ++i)
    {
        
        for(size_t location = 0; location < size; ++location)
        {
            if(i == location || arr[location].first - arr[i].first == 0)
            {
                continue;
            }

            m = (arr[location].second - arr[i].second) / (arr[location].first - arr[i].first);
            counter = 2;
            for(size_t j = 0; j < size; ++j)
            {
                if(i == j || location == j)
                {
                    continue;
                }
                if(arr[j].second - arr[location].second == m * (arr[j].first - arr[location].first))
                {
                    ++counter;
                    if(counter > max_counter)
                    {
                        max_counter = counter;
                    }
                }
            }
        }
    }
    return max_counter;
}

int main()
{
    std::array<std::pair<int, int>, 6> pairArray1 = 
    {
        std::make_pair(-1, 1),
        std::make_pair(0, 0),
        std::make_pair(1, 1),
        std::make_pair(2, 2),
        std::make_pair(3, 3),
        std::make_pair(3, 4)
    };
    

    size_t result = SameLine(pairArray1);
    std::cout << "The result is: " << result << std::endl;

    return 0;
}