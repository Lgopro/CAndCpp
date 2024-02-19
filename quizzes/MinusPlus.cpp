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
    int arr[] = {-1, 3, -5, -2 ,5, 6, -9, -11};

    MinusPlus(arr, sizeof(arr)/sizeof(int));

    for(size_t i = 0 ; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << " " << std::endl;
    }
    return 0;
}