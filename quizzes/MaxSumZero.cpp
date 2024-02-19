#include <iostream>
#include <assert.h>

const int ERROR = -1;


ssize_t MaxSumArrayZero(int *arr, size_t *begin, size_t *end, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    int sum = 0;

    ssize_t difference = ERROR;
    assert(arr);

    for(i = 0; i < size - 1 ; ++i)
    {
        sum = 0;
        for(j = i; j < size; ++j)
        {
            sum += arr[j];
            if((0 == sum) && (ssize_t(j - i + 1) > difference))
            {
                *begin = i;
                *end = j;
                difference = j - i + 1;
            }
        }
    }
    return difference;
}


int main()
{
    size_t begin = 0;
    size_t end = 0;

    int arr[] = {1, -1, 0, 5, 2, 5, 2, 5, -20, -10, -2, 5, 4, 3};

    ssize_t length = MaxSumArrayZero(arr, &begin, &end, sizeof(arr)/sizeof(int));
    if(ERROR == length)
    {
        std::cout<< "There is no sum of zero. Try again."<<std::endl;
    }
    else
    {
        std::cout<< "The length is:"<< length << " begins with: "<< begin << " and ends with: " << end <<std::endl;
        std::cout<< "The array numbers are:"<<std::endl;
        for(size_t i = begin; i <= end; ++i)
        {
            std::cout<< arr[i] << " ";
        }
        std::cout<< "" <<std::endl;
    }

    return 0;
}