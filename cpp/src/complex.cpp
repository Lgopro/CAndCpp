/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 09/08/23
*/

#include <string.h> /*strlen*/

#include "complex.hpp"
using namespace ilrd;





Complex ilrd::operator+(const Complex& lhs_, const Complex& rhs_)
{
    Complex result(0, 0);
    double real = 0;
    double img = 0;
    real = lhs_.GetReal() + rhs_.GetReal();
    img = lhs_.GetImaginary() + rhs_.GetImaginary();
    result.SetReal(real);
    result.SetImaginary(img);
    return result;

}



Complex ilrd::operator-(const Complex& lhs_, const Complex& rhs_)
{
    Complex result(0, 0);
    double real = 0;
    double img = 0;
    real = lhs_.GetReal() - rhs_.GetReal();
    img = lhs_.GetImaginary() - rhs_.GetImaginary();
    result.SetReal(real);
    result.SetImaginary(img);
    return result;
}

Complex ilrd::operator*(const Complex& lhs_, const Complex& rhs_)
{
    Complex result(0, 0);
    double real = 0;
    double img = 0;
    real = lhs_.GetReal() * rhs_.GetReal() - lhs_.GetImaginary() * rhs_.GetImaginary();
    img = lhs_.GetImaginary() * rhs_.GetReal() + lhs_.GetReal() * rhs_.GetImaginary();
    result.SetReal(real);
    result.SetImaginary(img);
    return result;
}

Complex ilrd::operator/(const Complex& lhs_, const Complex& rhs_)
{
    Complex result(0, 0);
    double real = 0;
    double img = 0;
    real = (lhs_.GetReal() * rhs_.GetReal() + lhs_.GetImaginary() * rhs_.GetImaginary()) / 
            (rhs_.GetReal() * rhs_.GetReal() + rhs_.GetImaginary() * rhs_.GetImaginary());

    img = (lhs_.GetImaginary() * rhs_.GetReal() - lhs_.GetReal() * rhs_.GetImaginary()) /
            (rhs_.GetReal() * rhs_.GetReal() + rhs_.GetImaginary() * rhs_.GetImaginary());
    result.SetReal(real);
    result.SetImaginary(img);
    return result;
}
    
bool ilrd::operator==(const Complex& lhs_, const Complex& rhs_)
{
    return ((lhs_.GetReal() == rhs_.GetReal()) && (lhs_.GetImaginary() == rhs_.GetImaginary()));
}

bool ilrd::operator!=(const Complex& lhs_, const Complex& rhs_)
{
    return ((lhs_.GetReal() != rhs_.GetReal()) || (lhs_.GetImaginary() != rhs_.GetImaginary()));
}



Complex ilrd::operator%(const Complex lhs_, const Complex rhs_)
{
    Complex result(0, 0);
    double real = 0;
    double img = 0;
    real = lhs_.GetReal() + rhs_.GetReal();
    img = lhs_.GetImaginary() + rhs_.GetImaginary();
    result.SetReal(real);
    result.SetImaginary(img);
    return result;
}
