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

#include "rc_string.hpp"
using namespace ilrd;

const char GREEN_COLOR[] = "\033[32m";
const char RED_COLOR[] = "\033[31m";
const char RESET_COLOR[] = "\033[0m";

const size_t SHARED = 1;

void TestRestOfFunctions();
void TestConstructorAndDestructor();

int main()
{
    TestConstructorAndDestructor();
    TestRestOfFunctions();
    return 0;
}


void TestConstructorAndDestructor()
{
    char arr[] = "Hello";
    RCString str(arr);
    RCString st1(str);
    const char *string = NULL;
    if(5 == str.Length())
    {
        std::cout << "Test basic Ctor and Length " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
    string = str.ToCStr();
    if(0 == strcmp(string, "Hello"))
    {
        std::cout << "Test CStr " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
    if(5 == str.Length())
    {
        std::cout << "Test copy Ctor " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
    RCString str2 = str;
    if(3 == str.GetCounter())
    {
        std::cout << "Test assignment Operator and GetCounter " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
}

void TestRestOfFunctions()
{
    char arr[] = "Hello";
    char arr1[] = "Hella";
    char arr2[] = "Hellz";
    char arr3[] = "Hello";
    char arr4[] = "Leonid";
    char result = 0;
    char result1 = 0;
    RCString string;
    RCString str(arr);
    RCString str1 = str;
    RCString str2(arr1);
    RCString str3(arr2);
    RCString str4(arr3);
    const RCString str5(arr4);
    if(str1 == str)
    {
        std::cout << "Test operator == " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }

    if(str2 != str)
    {
        std::cout << "Test operator != " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }

    if(str2 > str)
    {
        std::cout << "Test operator < " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }

    if(str3 < str)
    {
        std::cout << "Test operator > " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }

    if(SHARED == IsShared(str))
    {
        std::cout << "Test IsShared " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
    
    str = "Leonid";
    if(0 == strcmp(str.ToCStr(), "Leonid") && 1 == str.GetCounter())
    {
        std::cout << "Test Imlicit declaration " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }

    result = str5[3];
    result1 = str5[35];
    if(result == 'n' && result1 == '\0')
    {
        std::cout << "Test operator[] const " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    } 
    str[3] = 's';
    if(0 == strcmp(str.ToCStr(), "Leosid"))
    {
        std::cout << "Test char& operator[] " << GREEN_COLOR << "PASSED" << RESET_COLOR << std::endl;
    }
}