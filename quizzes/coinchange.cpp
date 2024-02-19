
#include <iostream>

bool CoinChange(size_t *arr, size_t size, int sum, size_t *counter)
{
    bool status1 = false;
    bool status2 = false;

    if(0 == sum)
    {
        return true;
    }

    if(sum < arr[0] || sum < 0)
    {
        return false;
    }

    if(size > 0)
    {
        
        status2 = CoinChange(arr, size, sum - arr[size - 1], counter + 1);

        if(status2 == false)
        {
            *(--counter);
        }
        

        status1 = CoinChange(arr, size - 1, sum, counter + 1);
    }
    return (status1 || status2);
}


int main()
{
    bool result;
    size_t arr[] = {3, 4, 5};
    size_t counter = 0;
    result = CoinChange(arr, 3, 17, &counter);
    if(result == true)
    {
        std::cout << "True" << std::endl;
        std::cout << "The counter is: " << counter << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    return 0;
}