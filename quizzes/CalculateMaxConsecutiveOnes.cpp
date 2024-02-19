
#include <iostream> /*std::cout*/


size_t CountMaxConsecutiveOnes(int *arr, size_t size, size_t N);


int main()
{
    int arr[] = {1, 1, 1, 0, 0,0, 1, 1, 0,0,1};
    size_t result = CountMaxConsecutiveOnes(arr, 11, 4);
    std::cout<< "The result is: " << result << std::endl;
    return 0;
}



size_t CountMaxConsecutiveOnes(int *arr, size_t size, size_t N)
{
    size_t first_value = 0;
    size_t last_value = 0;
    size_t return_first_value = 0;
    size_t return_last_value = 0;
    bool flag_begin = true;
    bool flag_counter = false;
    size_t count_zero = 0;

    for(size_t i = 0;i < size; ++i)
    {
       
        if(1 == arr[i] && count_zero == 0 && flag_begin == true)
        {
            first_value = i;
            flag_begin = false;
        }
        else if(0 == arr[i])
        {
            ++count_zero;
        }

        if(N == count_zero)
        {
            flag_counter = true;
            for(int j = i + 1; j < size; j++)
            {
                if(arr[j] == 0)
                {
                    last_value = j - 1;
                    break;
                }
                else
                {
                    last_value = j;
                }
            }
            if((last_value - first_value) > (return_last_value - return_first_value))
            {
                return_last_value = last_value;
                return_first_value = first_value;
            }

            count_zero = N - 1;

            for(int j = first_value + 1; j < size; ++j)
            {
                if(arr[j] == 0)
                {
                    first_value = j;
                    break;
                }
            }
        }

    }

    if(flag_counter == false)
    {
        for(int j = first_value - 1; j >= 0; --j)
        {
            if(arr[j] == 0 || j == 0)
            {
                ++count_zero;
                if(count_zero == N)
                {
                    return_first_value = j;
                }
            
            }
        }
    }

    return (return_last_value - return_first_value + 1);
}