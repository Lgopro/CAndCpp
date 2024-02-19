
#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;


struct myStructure
{
    int myNum;

} ;

int main()
{
    myStructure fff;
    fff.myNum = 7;
    int &str = fff.myNum;


    short ab = 4;
    short &bb = ab;
    bb = 10;
    size_t a = 4;
    size_t &pp = a;
    pp = 5;
    int i = 8;
    int &ip = i;
    ip = 9;
    std::cout << i <<std::endl;

    std::cout << pp <<std::endl;

    std::cout << bb <<std::endl;

    std::cout << str <<std::endl;


     std::cout << &ip <<std::endl;

    std::cout << &pp <<std::endl;

    std::cout << &bb <<std::endl;

    std::cout << &str <<std::endl;
    return 0;
}