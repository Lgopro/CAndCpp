
#include <iostream>
#include <cassert>

void Swap(int *val1, int *val2);


void Sort(int *arr, size_t size)
{
    
    ssize_t minus_location = -1;
    size_t counter = 0;
    size_t plus_counter = 0;
    size_t minus_counter = 0;
    size_t sorted = 0;

    assert(arr);

    for(size_t i = 0; i < size ; ++i)
    {
        if(arr[i] < 0)
        {
            ++minus_counter;
        }
        else
        {
            ++plus_counter;
        }
    }

    if( minus_counter == 0 || 0 == plus_counter)
    {
        return;
    }
    else
    {
        while(sorted != minus_counter)
        {
            minus_location = - 1;
            for(size_t i = sorted ; i < size ;++i)
            {
                if(arr[i] < 0 && minus_location == -1)
                {
                    counter = i;
                    while(counter != sorted)
                    {
                        Swap(&arr[counter], &arr[counter - 1]);
                        --counter;
                    }
                    ++sorted;
                    break;
                }
            }
        }
    }
}


void Swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
 


int main()
{
    int arr[] = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    Sort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << " ";
    }
}