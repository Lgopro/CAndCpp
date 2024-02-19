#include <iostream>
#include <assert.h>


void NextGreaterNubmer(int *arr, size_t size)
{
    assert(arr);
    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = i + 1 ; j <= size ; ++j)
        {
            if(j == size)
            {
                std::cout << "The next greater value for: "<< arr[i] << " is -1" << std::endl;
                break;
            }
            if(arr[i] < arr[j])
            {
                std::cout << "The next greater value for: "<< arr[i] << " is " << arr[j] << std::endl;
                break; 
            }
        }
    }
}



int main()
{

    int arr[] = {1, 3, 5, 2, 3, -1 , -5};

    NextGreaterNubmer(arr, sizeof(arr)/sizeof(int));

    return 0;

}