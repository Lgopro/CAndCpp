
#include <iostream>



int main()
{
    int a = 7;
    int *ptr = &a;

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    *(char *)&ptr = 1;

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
    return 0;
}