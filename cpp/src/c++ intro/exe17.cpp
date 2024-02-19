
#include "exe17.h"

int main()
{
    foo(4.2);
    std::cout << "*************************\n";
    foo(5);
    std::cout << "*************************\n";
    foo<int>(5);
    return 0;
}