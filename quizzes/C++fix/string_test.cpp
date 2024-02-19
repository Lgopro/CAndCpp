/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 05/08/23
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <iostream>
#include "string.hpp"
using namespace ilrd;



int main()
{
    String str1 = "hello world";
    String str2(str1);
    std::cout << str1 << std::endl;
    str2 = str1;
    std::cout << str2 << std::endl;
    std::cin >> str1;
    std::cout << str1 << std::endl;
    return 0;
}




