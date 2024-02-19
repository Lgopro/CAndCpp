



#include <iostream>
#include <cassert>

void FindAllSubArray(int *arr, int begin, int end, int sum, int size, int status)
{
    assert(arr);

    if(begin == size && end == size)
    {
        return;
    }


    if(begin != size && end == size)
    {
        FindAllSubArray(arr, begin + 1, begin + 1, 0, size, 1);
        return;
    }
    
    sum += arr[end];

    if(0 == sum && status == 0)
    {
        std::cout<< "Subarray found from index " << begin << " to " << end << std::endl;
    }

    FindAllSubArray(arr, begin, end + 1, sum, size, 0);
}


int main()
{
    int arr[] =  {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    FindAllSubArray(arr, 0, 0, 0, 11, 1);
    return 0;
}

