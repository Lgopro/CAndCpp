#include <iostream>
#include <cstdio>
using namespace std;

#include "exe15.h"
inline void foo();


int main()
{
    foo();
    Definition();
    return 0;
}

inline void foo()
{
    cout << "Hello-World";
}



void Definition()
{
    cout << "Definition";
}


void inline HHHHHHHHHH()
{
    cout << "Definition1";
}