#include <iostream>
#include <cstring>
#include <cassert>

void Reverce(char *arr, char *arr_reverce)
{
    assert(arr);
    assert(arr_reverce);

    size_t begin = strlen(arr) - 1;
    size_t end = strlen(arr) - 1;
    size_t reverce = 0;

    while(end != 0)
    {
        if(arr[begin] == ' ')
        {
            for(size_t i = begin + 1; i <= end; ++i)
            {
                arr_reverce[reverce] = arr[i];
                ++reverce;
            }
            arr_reverce[reverce] = ' ';
            ++reverce;
            end = begin;
        }
        if(begin == 0)
        {
            for(size_t i = begin; i <= end; ++i)
            {
                arr_reverce[reverce] = arr[i];
                ++reverce;
            }
            arr_reverce[reverce] = ' ';
            ++reverce;
            end = begin;
        }

        --begin;

    }
    arr_reverce[reverce] = '\0';
}

int main()
{

    char *arr = new char[50];
    char *reverce_arr = new char[50];

    strcpy(arr, "Hello world carry");

    Reverce(arr, reverce_arr);

    std::cout << reverce_arr << std::endl;

    delete [] arr;
    delete [] reverce_arr;

    return 0;

}