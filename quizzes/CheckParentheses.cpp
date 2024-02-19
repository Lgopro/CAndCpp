

#include <iostream>
#include <stack>
#include <cassert>

bool Balanaced(char *arr)
{
    char *arr_begin = nullptr;
    std::stack<char> left;

    assert(arr);
    arr_begin = arr;
    while(*arr_begin != '\0')
    {
        if(*arr_begin == ')' || *arr_begin == ']' || *arr_begin == '}')
        {
            if(left.size() == 0)
            {
                return false;
            }
            else
            {
                if(*arr_begin == ')')
                {
                    left.top() == '(';
                    left.pop();
                }
                if(*arr_begin == ']')
                {
                    left.top() == '[';
                    left.pop();
                }
                if(*arr_begin == '}')
                {
                    left.top() == '{';
                    left.pop();
                }
            }
        }
        else if(*arr_begin == '(' || *arr_begin == '[' || *arr_begin == '{')
        {
            left.push(*arr_begin);
        }
        ++arr_begin;
    }

    if(left.size() != 0)
    {
        return false;
    }
    return true;
    
    
}

int main()
{
    char arr[] = {'(', '[', '{', '(', '[', ')', ']', '}'};
    char arr1[] = {'(', '[', '{', '(', '[', ')', ']', '}', ')', ']'};
    bool status = Balanaced(arr);
    if(status == true)
    {
        std::cout<< "Balanced" <<std::endl;
    }
    else
    {
        std::cout<< "Not Balanced" <<std::endl;
    }

    bool status1 = Balanaced(arr1);
    if(status1 == true)
    {
        std::cout<< "Balanced" <<std::endl;
    }
    else
    {
        std::cout<< "Not Balanced" <<std::endl;
    }
    return 0;
}