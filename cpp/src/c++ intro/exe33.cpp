#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

using namespace std; 

class A
{
    public:
    A(int value);
    ~A(){ std::cout << "A::Dtor" << std::endl; }
    private:
    int m_value;
};
void Fifi() 
{ 
    throw BadDog("added other thing");  cerr << "Fifi() after throw" << endl; 
} 

void Foo() 
{ 
    //  X x1;     
    Fifi();     
    cerr << "Foo() after Fifi()" << endl; 
} 

int Initiate(int value)
{
    std::cout << "A::Ctor" << std::endl; 
    Foo();
    return value;
}


A::A(int value):m_value(Initiate(value))
{

}



struct BadDog: public runtime_error 
{     
    BadDog(const string& s_ = "This is a bad dog"): runtime_error(s_) {} 
}; 





void Bar() 
{ 
    Foo(); 
    cerr << "Bar() after Foo()" << endl; 
} 
int main() { 
    A x1(5);    
    try     
    {         
        Bar();     
    }     
    catch(bad_alloc&)     
    {         
        cerr << "Out of memory! exiting."; exit(2);     
    }     
    catch(BadDog& b)     
    {         
        cerr << "Bad dog exception: " << b.what(); exit(3);     
    } 
     catch(BadDog& c)     
    {         
        cerr << "Other exclude?: " << c.what(); exit(4);     
    }   
    catch( exception& r )
    {
        cerr << "unknown exception: " << r.what();
        exit(4);     
    }

    
    return 0; 
}

