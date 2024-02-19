
#include <iostream>

namespace ilrd
{
class Complex
{
    public:

    Complex(double real = 0, double imag = 0);
    ~Complex() = default;
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);

    void SetReal(double value);
    void SetImag(double value);
    double GetReal() const;
    double GetImag() const;

    Complex& operator+=(const Complex& value);
    Complex& operator-=(const Complex& value);
    Complex& operator*=(const Complex& value);
    Complex& operator/=(const Complex& value);

    private:

    double m_real;
    double m_imag;

};

    bool operator==(const Complex& value1, const Complex& value2);
    bool operator!=(const Complex& value1, const Complex& value2);
    Complex operator+(const Complex& value1, const Complex& value2);
    Complex operator-(const Complex& value1, const Complex& value2);
    Complex operator*(const Complex& value1, const Complex& value2);
    Complex operator/(const Complex& value1, const Complex& value2);
    std::ostream& operator<<(std::ostream& out, const Complex& other);
    std::istream& operator>>(std::istream& in, Complex& other);
}



using namespace ilrd;

Complex::Complex(double real, double imag):m_real(real), m_imag(imag)
{
}

Complex::Complex(const Complex& other):m_real(other.m_real), m_imag(other.m_imag)
{
}

Complex& Complex::operator=(const Complex& other)
{
    m_imag = other.m_imag;
    m_real = other.m_real;
    return *this;
}

void Complex::SetReal(double value)
{
    m_real = value;
}

void Complex::SetImag(double value)
{
    m_imag = value;
}

double Complex::GetReal() const
{
    return m_real;
}
    
double Complex::GetImag() const
{
    return m_imag;
}

Complex& Complex::operator+=(const Complex& value)
{
    m_imag += value.m_imag;
    m_real += value.m_real;
    return *this;
}

Complex& Complex::operator-=(const Complex& value)
{
    m_imag -= value.m_imag;
    m_real -= value.m_real;
    return *this;
}

Complex& Complex::operator*=(const Complex& value)
{
    m_imag *= 2;
    m_real *= 2;
    return *this;
}
    
Complex& Complex::operator/=(const Complex& value)
{
    m_imag /= 2;
    m_real /= 2;
    return *this;
}

bool operator==(const Complex& value1, const Complex& value2)
{
    return ((value1.GetImag() == value2.GetImag()) && (value1.GetReal() == value2.GetReal()));
}
    
bool operator!=(const Complex& value1, const Complex& value2)
{
    return ((value1.GetImag() != value2.GetImag()) || (value1.GetReal() != value2.GetReal()));
}

Complex operator+(const Complex& value1, const Complex& value2)
{
    Complex result;
    result.SetImag(value1.GetImag() + value2.GetImag());
    result.SetReal(value1.GetReal() + value2.GetReal());
    return result;
}
    
Complex operator-(const Complex& value1, const Complex& value2)
{
    Complex result;
    result.SetImag(value1.GetImag() - value2.GetImag());
    result.SetReal(value1.GetReal() - value2.GetReal());
    return result;
}

    
Complex operator*(const Complex& value1, const Complex& value2)
{
    Complex result;
    result.SetImag(value1.GetImag() * value2.GetImag());
    result.SetReal(value1.GetReal() * value2.GetReal());
    return result;
}
    
Complex operator/(const Complex& value1, const Complex& value2)
{
    Complex result;
    result.SetImag(value1.GetImag() / value2.GetImag());
    result.SetReal(value1.GetReal() / value2.GetReal());
    return result;
}

std::ostream& operator<<(std::ostream& out, Complex& other)
{
    out << "image: " << other.GetImag()  << " real: " << other.GetReal() << "\n";
    return out;
} 

std::istream& ilrd::operator>>(std::istream& in, Complex& other)
{
    double number[2];
    std::cout << "Please enter real number";
    in >> number[0];
    std::cout << "Please enter imag number";
    in >> number[1];
    other = Complex(number[0], number[1]);
    return in;
}



int main()
{
    Complex value(3, 2);
    Complex value1;
    std::cout << "the value is: " << value << std::endl;

    std::cin >> value1;

    std::cout << "the value is: " << value1 << std::endl;

    return 0;
}