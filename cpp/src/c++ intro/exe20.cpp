#include <iostream>
#include <cstdio>

struct X
{
    explicit X(); // Default constructor
    explicit X(int a_, int b_ = 8); // Regular constructor
    ~X(); // Destructor
    X(const X& other_); // Copy constructor
    X& operator=(const X& other_); // Assignment operator

    int m_a;
    const int m_b;
};

struct Y
{
    X m_x;
    int m_i;

    Y() : m_x(0, 0), m_i(0) {}
};

X::X() : m_a(3), m_b(4)
{
    m_a = 3;
    std::cout << "this:" << this <<
        "X default Ctor. m_a:" << m_a <<
        "m_b:" << m_b << std::endl;
}

X::X(int a_, int b_) : m_a(a_), m_b(b_)
{
    std::cout << "this:" << this <<
        "X int int Ctor. m_a:" << m_a <<
        "m_b:" << m_b << std::endl;
}

X::X(const X& other_) : m_a(other_.m_a), m_b(other_.m_b)
{
    std::cout << "this:" << this <<
        "X copy Ctor. m_a:" << m_a <<
        "m_b:" << m_b << std::endl;
}

X& X::operator=(const X& other_)
{
    m_a = other_.m_b;
    std::cout << "this:" << this <<
        "X assignment operator. m_a:" << m_a <<
        "does not change m_b:" << m_b << std::endl;
    return *this;
}

X::~X()
{
    std::cout << "this:" << this <<
        "X Dtor. m_a:" << m_a <<
        "m_b:" << m_b << std::endl;
}

int main()
{
    X x1;
    X x2(7);
    Y y1;
    y1.m_x.m_a = 250;
    Y y2(y1);
    Y y3;
    double* xp = new double[10];
    X *px = new X(x2);
    X x3(9, 10);
    X x4(x1); 
    x1 = x3;

    delete[] xp;
    delete px;
    y3 = y1;
    printf("Im here\n");
    return 0;
}
