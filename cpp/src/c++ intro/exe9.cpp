#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;



void foo(int, int i = 3, float = 4);

int main()
{
    foo(3);
    foo(6, 5);
    foo(4, 7, 8.7);
    return 1;
}

void foo(int number , int number2, float number3)
{
    printf("Im number1 %d\n", number);
    printf("Im number2 %d\n", number2);
    printf("Im number3 %f\n", number3);
}