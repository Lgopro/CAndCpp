
#include <iostream>
#include <assert.h>

void Swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int ConnectNRopes(int *arr, size_t size)
{
    int sum = 0;
    int array[size] = {0};
    int temp = 0;
    size_t counter = 0;

    assert(arr);

    for(int i = 0; i < size; ++i)
    {
        array[i] = arr[i];
    }

    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(array[i] > array[j])
            {
                Swap(&array[i], &array[j]);
            }
        }
    }
    
    while(counter != size - 1)
    {
        array[counter + 1] = array[counter] + array[counter + 1];
        sum += array[counter + 1];
        for(size_t i = counter + 2; i < size; ++i)
        {
            if(array[counter + 1] < array[i])
            {
                temp = array[counter + 1];
                for(size_t j = counter + 1; j < i - 1; ++j)
                {
                    array[j] = array[j + 1];
                }
                array[i - 1] = temp;
                break;
            } 
        }
        ++counter;
    }
    return sum;
}

int main()
{
    int arr[] = {4, 3, 2, 6};
    int sum = ConnectNRopes(arr, sizeof(arr)/sizeof(int));
    std::cout<< "Sum is: " << sum << std::endl;
    return 0;
}