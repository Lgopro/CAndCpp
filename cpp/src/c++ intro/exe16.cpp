#include <iostream>
#include <cstdio>
using namespace std;


#include "exe16.h"
template <typename T>
T Max(T t1, T t2)
{
    (t1 > t2) ? t1 : t2;
   
}



int main()
{
     int arr[12];

    std::cout << Max<int>(3,5) << " " << Max<double>(3.7, 12.9) <<  " ";
    std::cout << Max<int *>(arr, arr + 8) << std::endl;
    std::cout << Max('a', 'b') << std::endl;
    std::cout << Max<int>(4,5) << " " << Max<double>(3.7, 12.9) <<  " ";
    std::cout << Max<int>(7,5) << " " << Max<double>(3.7, 12.9) <<  " ";
    std::cout << Min<int>(4,5) << " " << Min<double>(3.7, 12.9) <<  " ";
    std::cout << Min<int>(7,5) << " " << Min<double>(3.7, 12.9) <<  " "; 
    return 0;

}