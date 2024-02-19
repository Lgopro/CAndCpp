#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;

template<typename T>
void foo(T t)
{
    std::cout << t << "Generic foo for" << typeid(t).name() << std::endl;
}

template<>
void foo<int>(int t)
{
    std::cout << t << " Specialized foo (for int param)\n";
}