
#include <iostream>
#include <cassert>

const int MAX = 1000000;

size_t Conversions(int *arr, size_t size)
{
    size_t counter = 0;
    int min = MAX;
    size_t location = 0;
    
    size_t conversions = 0;

    assert(arr);

    while(counter != size - 1)
    {
        min = MAX;
        location = size;

        for(size_t i = counter; i < size ; ++i)
        {
            if(arr[i] < min)
            {
                min = arr[i];
                location = i;
            }
        }

        if(location == size)
        {
            return conversions;
        }

        for(size_t j = location; j > counter; --j)
        {
            arr[j] = arr[j - 1];
        }
        arr[counter] = min;

        conversions += (location - counter);

        std::cout << "The conversions is: " << conversions << std::endl;

        ++counter;
    }
    return conversions;
}

int main()
{
    int arr[] = {8, 4, 2, 1}; //1, 8, 4, 2 counter 3.  1, 2, 8, 4 counter 5. counter 1, 2, 4, 8 counter 6.
    size_t result = Conversions(arr, sizeof(arr)/sizeof(int));
    std::cout << "The result is: " << result << std::endl;
    for(size_t i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout<< arr[i] << std::endl;
    }
    return 0;
}