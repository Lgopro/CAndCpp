#include <iostream>

const char GREEN_COLOR[] = "\033[32m";
const char RED_COLOR[] = "\033[31m";
const char RESET_COLOR[] = "\033[0m";

int number = 5;

void Foo()
{
    std::cout << "FOFO " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    std::cout << "FOFO " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    std::cout << "FOFO " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    std::cout << "FOFO " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
}


int main()
{
    int *crash = NULL;
    Foo();

    int value = *crash;
    
    return 0;
}