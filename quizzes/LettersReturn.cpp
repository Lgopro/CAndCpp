

#include <iostream>
#include <cassert>
#include <cstring>
#include <unordered_map>


void CLetters(char *arr)
{
    int LUT[52] = {0};
    size_t length = 0;

    assert(arr);

    length = strlen(arr);

    for(size_t i = 0; i < length; ++i)
    {
        if(arr[i] >= 'a' && arr[i] <= 'z')
        {
            ++LUT[arr[i] - 'a'];
        }

        if(arr[i] >= 'A' && arr[i] <= 'Z')
        {
            ++LUT[arr[i] - 'A' + 26];
        }
    }

    for(size_t i = 0; i < length; ++i)
    {
        if(arr[i] >= 'a' || arr[i] <= 'z')
        {
            if(LUT[arr[i] - 'a'] == 1)
            {
                std::cout << arr[i];
            }
        }

        if(arr[i] >= 'A' || arr[i] <= 'Z')
        {
            if(LUT[arr[i] - 'A' + 26] == 1)
            {
                std::cout << arr[i];
            }
        }

        if(arr[i] == ' ')
        {
            std::cout<< " ";
        }
        
    }

    std::cout << " " << std::endl;

}


int main()
{
    char arr[] = "Hello Geeks";
    CLetters(arr);

    return 0;
}