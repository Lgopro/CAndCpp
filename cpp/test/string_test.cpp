/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 05/08/23
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h> 
#include <iostream>
#include "string.hpp"
using namespace ilrd;

void TestConstructorAndDestructor();
void TestOperator();

int main()
{
    TestConstructorAndDestructor();
    TestOperator();
    return 0;
}




void TestConstructorAndDestructor()
{
    char arr[] = "Hello";
    String str(arr);
    String st1(str);
    const char *string = NULL;
    if(5 == str.Length())
    {
        std::cout <<"Test basic Ctor and Length passed" << std::endl;
    }
    string = str.CStr();
    if(0 == strcmp(string, "Hello"))
    {
        std::cout <<"Test CStr passed" << std::endl;
    }
    if(5 == str.Length())
    {
        std::cout <<"Test copy Ctor" << std::endl;
    }

}

void TestOperator()
{
    char arr[] = "Hello";
    char arr1[] = "Hella";
    char arr2[] = "Hellz";
    char arr3[] = "Hello";
    String string;
    String str(arr);
    String str1 = str;
    String str2(arr1);
    String str3(arr2);
    String str4(arr3);

    if(5 == str.Length())
    {
        std::cout <<"Test operator = passed" << std::endl;
    }

    if(str4 == str)
    {
        std::cout <<"Test operator == passed" << std::endl;
    }

    if(str2 > str)
    {
        std::cout <<"Test operator < passed" << std::endl;
    }

    if(str3 < str)
    {
        std::cout <<"Test operator > passed" << std::endl;
    }

    std::cout << "String print:" << str << std::endl;
    std::cout <<"Test operator >> passed" << std::endl;

    std::cout <<"Please enter a string" << std::endl;

    std::cin >> string;
    std::cout << "String print:" << string << std::endl;
    std::cout <<"Test operator << passed" << std::endl;


    if("Hello" == str)
    {
        std::cout <<"Hello is Hello" << std::endl;
    }


}