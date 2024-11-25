

#include <stdio.h>
#include <assert.h>


int Bursa(int *arr, size_t size, int *begin_var, int *end_var)
{
    assert(arr);
    assert(begin_var);
    assert(end_var);

    int result = 0;
    int begin = 0;
    int end = 1;
    int max_result = 0;
    size_t location = 0;

    while(end < (int)size)
    {
        
        if(arr[begin] < arr[end])
        {
            result = arr[end] - arr[begin];
        }
        else
        {
            begin = end;
        }

        if(result > max_result)
        {
            max_result = result;
            *begin_var = arr[begin];
            *end_var = arr[end];
        }
        ++end;
    }

}


int main()
{
    int begin = 0;
    int end = 0;
    int arr[] = {6, 12, 3, 5  ,1, 4, 9, 2};

    int result = Bursa(arr, sizeof(arr)/sizeof(int), &begin, &end);

    printf("The result is %d, with the first number is %d and the second number is %d\n", result, begin, end);
    return 0;
}