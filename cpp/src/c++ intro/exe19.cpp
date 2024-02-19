#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;


void Foo(const double&);
void Bar (double&);

int main()
{
    int c = 5;
    int *g = &c;
    double &a = reinterpret_cast<double &>(g);
    double &b = reinterpret_cast< double &>(g);
    double &yy = reinterpret_cast<double &>(c);
    double &hh = reinterpret_cast< double &>(c);

    Foo(a);
    Bar(b);
    Foo(yy);
    Bar(hh);

    return 0;
}


void Foo(const double& arr)
{
    std::cout << "Generic foo Foo " << arr <<std::endl;
}


void Bar(double& arr)
{
    std::cout << "Generic foo Bar " << arr <<std::endl;
}

