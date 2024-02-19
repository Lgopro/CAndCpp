/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 09/08/23
*/
#ifndef __ILRD_COMPLEX_HPP__
#define __ILRD_COMPLEX_HPP__

#include <iostream>
#include <iosfwd>

#define AMOUNT (2)

namespace ilrd
{
class Complex
{
public:
    inline Complex(double real_ = 0.0, double img_ = 0.0);
   

    inline void SetReal(double real_);
   
    inline void SetImaginary(double imaginary_);
   
    inline double GetReal() const;
    
    inline double GetImaginary() const;
    
    
    inline Complex& operator+=(const Complex& other_);
   
    inline Complex& operator-=(const Complex& other_);
    
    inline Complex& operator*=(const Complex& other_);
    
    inline Complex& operator/=(const Complex& other_);

private:
    double m_real;
    double m_img;
    Complex Initiate(double real, double img);
};


    Complex operator+(const Complex& lhs_, const Complex& rhs_);
    Complex operator%(const Complex lhs_, const Complex rhs_);
    Complex operator-(const Complex& lhs_, const Complex& rhs_);
    Complex operator*(const Complex& lhs_, const Complex& rhs_);
    Complex operator/(const Complex& lhs_, const Complex& rhs_);
    
    bool operator==(const Complex& lhs_, const Complex& rhs_);
    bool operator!=(const Complex& lhs_, const Complex& rhs_);
    
    inline std::ostream& operator<<(std::ostream& out_, const Complex& complex_);
    inline std::istream& operator>>(std::istream& in_, Complex& complex_);


    



    inline Complex::Complex(double real_, double img_):m_real(real_),m_img(img_)
    {
    }

    inline void Complex::SetReal(double real_)
    {
        this->m_real = real_;
    }

    inline void Complex::SetImaginary(double imaginary_)
    {
        this->m_img = imaginary_;
    }

    inline double Complex::GetReal() const
    {
        return (this->m_real);
    }

    inline double Complex::GetImaginary() const
    {
        return (this->m_img);
    }
    
    inline Complex& Complex::operator+=(const Complex& other_)
    {
        this->m_img += other_.m_img;
        this->m_real += other_.m_real;
        return (*this);
    }

    inline Complex& Complex::operator-=(const Complex& other_)
    {
        this->m_img -= other_.m_img;
        this->m_real -= other_.m_real;
        return (*this);
    }

    inline Complex& Complex::operator*=(const Complex& other_)
    {
        double real = 0;
        double img = 0;
        real = this->m_real * other_.m_real - this->m_img * other_.m_img;
        img = this->m_real * other_.m_img + this->m_img * other_.m_real;

        this->m_real = real;
        this->m_img = img;
        

        return (*this);
    }

    inline Complex& Complex::operator/=(const Complex& other_)
    {
        this->m_real = (this->m_real * other_.m_real + this->m_img * other_.m_img) / 
           (other_.m_real * other_.m_real + other_.m_img * other_.m_img);

        this->m_img = (this->m_img * other_.m_real - this->m_real * other_.m_img) /
          (other_.m_real * other_.m_real + other_.m_img * other_.m_img);

        return (*this);
    }

inline std::ostream& operator<<(std::ostream& out_, const Complex& complex_)
{
    out_ << complex_.GetReal() << " + " << complex_.GetImaginary() << "*i";
    return (out_);
}

inline std::istream& operator>>(std::istream& in_, Complex& complex_)
{
    double buffer[AMOUNT] = {0}; 
    std::cout <<"Enter real number:" << std::endl;
    in_ >> buffer[0];
    std::cout <<"Enter imaginary number:" << std::endl;
    in_ >> buffer[1];
    complex_ =  Complex(buffer[0], buffer[1]); 
    return (in_);
}
}




#endif
