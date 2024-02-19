


#include <iostream>
#include <cassert>
#include <cstring>

const int BIT_IN_CHAR = 8;

bool Find(char *arr, char check_check)
{
    int sum = 500;
    
    assert(arr);



    for(size_t i = 0; i < strlen(arr); ++i)
    {
        sum *= arr[i] ^ check_check;
    }

    if(0 == sum)
    {
        return true;
    }
    return false;
}
void Test1()
{
    char ch = 'e';
    char arr[] = "Hello world";
    bool status = Find(arr, ch);
    if(status == true)
    {
        std::cout<< "Found the letter" << std::endl;
    }
    else
    {
        std::cout<< "Not found the letter" << std::endl;
    }
}

void CircularShiftInPlace(char *arr, size_t amount_of_shift)
{
    char temp;
    char temp2;
    size_t counter = 0;
    size_t location = 0;
    size_t length = strlen(arr);
    
    amount_of_shift %= length;

    assert(arr);

    size_t LUT[strlen(arr)] = {0};

    if(0 == amount_of_shift)
    {
        return;
    }


    while(counter < length)
    {
        ++LUT[(amount_of_shift + location) % length];
        if(1 < LUT[(amount_of_shift + location) % length])
        {
            for(size_t i = 0; i < length; ++i)
            {
                if(0 == LUT[i])
                {
                    location = i;
                    temp = arr[(amount_of_shift + location) % length];
                    ++LUT[(amount_of_shift + location) % length];
                }
            }
        }
        else
        {
            temp2 = temp;
            temp = arr[(amount_of_shift + location) % length];
        }
        if(counter == 0)
        {
            arr[(amount_of_shift + location) % length] = arr[location % length];
        }
        else
        {
            arr[(amount_of_shift + location) % length] = temp2;
        }
        
        location = (amount_of_shift + location) % length;
        ++counter;
    }

}

void Test2()
{
    char arr[] = "abcdefgh";
    size_t shift = 5;


    std::cout << "The string before changes is: " << arr << std::endl;

    CircularShiftInPlace(arr, shift);

    std::cout << "The string after changes is: " << arr << std::endl;

}


int main()
{
    Test1();
    Test2();
}