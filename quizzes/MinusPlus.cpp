#include <iostream>
#include <cassert>

void Swap(int *value1, int *value2)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void MinusPlus(int *arr, size_t size)
{
    ssize_t plus_counter = 0;
    ssize_t minus_counter = 0;
    size_t minus_location = 0;
    size_t counter = 0;
    int i = 0;

    assert(arr);
    assert(size > 1);

    while(i < size)
    {
        if(arr[i] >= 0)
        {
            ++plus_counter;
        }
        else if(arr[i] < 0 && minus_counter == 0)
        {
            ++minus_counter;
            minus_location = i;
        }
        else
        {
            ++minus_counter;
        }

        if((plus_counter > 0 && minus_counter > 0) || (i == size - 1 && minus_counter > 0))
        {
            for(int j = minus_location; j > counter; --j)
            {
                Swap(&arr[j], &arr[j - 1]);
            }

            plus_counter = 0;
            minus_counter = 0;
            ++counter;
            i = counter;
            minus_location = 0;
        }
        ++i;
    }


}

int main()
{
   
    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    int arr1[] = {-12, 11, 0, -5, 6, -7, 5, -3, -6};

    MinusPlus(arr, sizeof(arr)/sizeof(int));

    for(size_t i = 0 ; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << " " << std::endl;

    MinusPlus(arr1, sizeof(arr1)/sizeof(int));

    for(size_t i = 0 ; i < sizeof(arr1)/sizeof(int); ++i)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << " " << std::endl;
    return 0;
}