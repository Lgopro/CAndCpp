#include <iostream>
#include <cassert>

void PairOfTwo(int *arr, size_t size, int num)
{
    assert(arr);
    if(size < 2)
    {
        std::cout << "No pair exist for " << num << std::endl;
    }

    for(size_t i = 0; i < size - 1; ++i)
    {
        for(size_t j = i + 1; j < size; ++j)
        {
            if(arr[i] + arr[j] == num)
            {
                std::cout << "Pair with a given sum " << num << " is (" << arr[i] << "," << arr[j] << ")" << std::endl;
                return;
            }
        }
    }

    std::cout << "No pair exist for " << num << std::endl;
}



int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    PairOfTwo(arr, sizeof(arr)/sizeof(int), -2);

    int arr1[] = {1, -2, 1, 0, 5};
    PairOfTwo(arr1, sizeof(arr1)/sizeof(int), 0);

    return 0;
}