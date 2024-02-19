#include <stdio.h>


inline void foo();

int main()
{
    foo();
    return 0;
}

inline void foo()
{
    cout << "Hello-World";
}