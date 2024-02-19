

#include <iostream>
#include <cstdio>


struct X
{
    explicit X();  //Initialization function without parameters is named default constructor (often abbreviated as :default ctor)
    explicit X(int a_, int b_ = 8); //Regular(non default) Ctor
    ~X(); //Deinitialization function is called destructor (Dtor)
    X(const X& other_); //Copy initialization function is called copy costructor or CCtor.
    X& operator=(const X& other_); //Assignment operator

    int m_a;
    const int m_b;
};
struct Y
{
    X m_x;
    int m_i;

    // Constructor for Y that initializes m_x using X's non-default constructor
    Y(int a, int b, int i) : m_x(a, b), m_i(i) {}
};


int main()
{
    X x1;
    X x2(7);

    // Create a Y object using the new constructor
    Y y1(5, 6, 123);

    y1.m_x.m_a = 250;

    Y y2(y1);
    Y y3;

    // ... rest of the code ...
    return 0;
}