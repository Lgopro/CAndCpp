


#include <iostream>
#include <assert.h>
const int MAX = 100000;

int FindIfItsHere(int *arr, size_t size, int number)
{
    int sum = MAX;

    assert(arr);

    for(size_t i = 0; i < size; ++i)
    {
        sum *= number ^ arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {3, 4, 6, 5, 2, 7};

    int result = FindIfItsHere(arr, sizeof(arr)/sizeof(int), 7);
    int result1 = FindIfItsHere(arr, sizeof(arr)/sizeof(int), 8);

    if(result == 0)
    {
        std::cout<< "result Is in the array" <<std::endl;
    }
    else
    {
        std::cout<< "result Is not in the array" <<std::endl;
    }

    if(result1 == 0)
    {
        std::cout<< "result1 Is in the array" <<std::endl;
    }
    else
    {
        std::cout<< "result1 Is not in the array" <<std::endl;
    }

    return 0;
}