#include <iostream>
#include <vector>
#include <utility>
#include <assert.h>


std::vector<std::pair<int, int>> OddIntegers(int *arr, size_t size)
{
    assert(arr);

    std::vector<std::pair<int, int>> m_vector;
    bool counter_flag = false;
    size_t count_size = 0;


    for(size_t i = 0; i < size; ++i)
    {
        counter_flag = false;

        if(m_vector.empty() == true)
        {
            m_vector.push_back(std::make_pair(1, arr[0]));
        }
        else
        {
            for(size_t j = 0; j < m_vector.size(); ++j)
            {
                if(m_vector[j].second == arr[i])
                {
                    ++m_vector[j].first;
                    counter_flag = true;
                }
                
            }
            if(counter_flag == false)
            {
                m_vector.push_back(std::make_pair(1, arr[i]));
            }

        }
    }
    return m_vector;
}

int main()
{
    int arr[] = {1, 3, 5, 2, 1 ,5 ,2 ,5 ,2 , 1, 5, 2, 9};

    std::vector<std::pair<int, int>> result;
    result = OddIntegers(arr, sizeof(arr)/sizeof(int));
    for(size_t i = 0; i < result.size(); ++i)
    {
        if(result[i].first % 2 != 0)
        {
            std::cout << "The number " << result[i].second << " is found an odd amount of times" << std::endl;
        }
    }

    return 0;
}