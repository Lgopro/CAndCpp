#include <iostream>
#include <cassert>

const int MAX = 100000;


void Swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


int KLargestElement(int *arr, size_t size, size_t K)
{
    int min = MAX;
    size_t index = 0;

    assert(arr);

    for(size_t i = 0;i < K ; ++i)
    {
        min = MAX;
        for(size_t j = i; j < size; ++j)
        {
            if(arr[j] < min)
            {
                index = j;
                min = arr[j];
            }
        }
        Swap(&arr[i], &arr[index]);
    }
    return arr[K - 1];
}


int main()
{
    int arr[] = {1, 5, -2, -10 ,5 ,-1, 6, 4};

    int value = KLargestElement(arr, sizeof(arr)/sizeof(int), 5);

    std::cout<< "The result is: "<< value <<std::endl;
    return 0;
}