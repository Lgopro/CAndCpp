/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 09/08/23
*/


#include <ctime> /*clock_t*/
#include "complex.hpp"
using namespace ilrd;

void Test();
void PlusOperatorTest();

int main()
{

    Test();
    PlusOperatorTest();
    return 0;
}


void PlusOperatorTest()
{
    std::clock_t start;
    size_t i = 0;
    double duration;
    double number1 = 1;
    double number2 = 2;
    double number3 = 1;
    double number4 = 1;
    Complex result(0, 0);
    Complex complex1(number1, number2);
    Complex complex2(number3, number4);
    start = std::clock();

    for(i = 0;i < 100000000; ++i)
    {
        result = complex1 % complex2;
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"by value: "<< duration <<'\n';


    start = std::clock();

    for(i = 0;i < 100000000; ++i)
    {
        result = complex1 + complex2;
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"by reference: "<< duration <<'\n';
}


void Test()
{
    double number1 = 1;
    double number2 = 2;
    double number3 = 1;
    double number4 = 1;

    Complex complex1(number1, number2);
    Complex complex2(number3, number4);
    Complex result(0, 0);

    if(1 == complex1.GetReal() && 2 == complex1.GetImaginary())
    {
        std::cout <<"Test constructor passed" << std::endl;
        std::cout <<"Test GetReal passed" << std::endl;
        std::cout <<"Test GetImaginary passed" << std::endl;
    }

    complex1.SetReal(6);
    complex1.SetImaginary(6);

    if(6 == complex1.GetReal() && 6 == complex1.GetImaginary())
    {
        std::cout <<"Test SetReal passed" << std::endl;
        std::cout <<"Test SetImaginary passed" << std::endl;
    }

    complex1 += complex2;
    if(7 == complex1.GetReal() && 7 == complex1.GetImaginary())
    {
        std::cout <<"Test operator += passed" << std::endl;
    }

    complex1 -= complex2;
    if(6 == complex1.GetReal() && 6 == complex1.GetImaginary())
    {
        std::cout <<"Test operator -= passed" << std::endl;
    }

    complex1.SetReal(1);
    complex1.SetImaginary(1);

    complex1 *= complex2;
    if(0 == complex1.GetReal() && 2 == complex1.GetImaginary())
    {
        std::cout <<"Test operator *= passed" << std::endl;
    }
    else
    {
        std::cout <<"complex1.GetReal(): " << complex1.GetReal() << "complex1.GetImaginary():" << complex1.GetImaginary() <<std::endl;
    }

    complex1.SetReal(1);
    complex1.SetImaginary(1);
    complex1 /= complex2;
    if(1 == complex1.GetReal() && 0 == complex1.GetImaginary())
    {
        std::cout <<"Test operator /= passed" << std::endl;
    }
    
    complex1.SetImaginary(1);

    result = complex1 + complex2;
    if(2 == result.GetReal() && 2 == result.GetImaginary())
    {
        std::cout <<"Test operator + passed" << std::endl;
    }

    result = complex1 - complex2;
    if(0 == result.GetReal() && 0 == result.GetImaginary())
    {
        std::cout <<"Test operator - passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }

    result = complex1 * complex2;
    if(0 == result.GetReal() && 2 == result.GetImaginary())
    {
        std::cout <<"Test operator * passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }

    result = complex1 / complex2;
    if(1 == result.GetReal() && 0 == result.GetImaginary())
    {
        std::cout <<"Test operator / passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }

    if(complex1 == complex2)
    {
        std::cout <<"Test operator == passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }

    if(complex1 == complex2)
    {
        std::cout <<"Test operator == passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }

    if(result != complex2)
    {
        std::cout <<"Test operator != passed" << std::endl;
    }
    else
    {
        std::cout <<"result.GetReal(): " << result.GetReal() << "result.GetImaginary():" << result.GetImaginary() <<std::endl;
    }
    complex1.SetReal(4);
    complex1.SetImaginary(88);
    std::cout << "Complex number print:" << complex1 << std::endl;

    std::cin >> complex1;
    std::cout << "Complex number print:" << complex1 << std::endl;
    
}

