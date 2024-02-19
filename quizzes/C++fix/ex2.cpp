#include <iostream>
using namespace std;

class Base
{
public:
    Base(int i): m_i(i), m_iptr(&m_i) {}
    Base(const Base& other)
    {
        this->m_i = other.m_i;
    }
    Base& operator=(const Base& other)
    {
        this->m_i = other.m_i;
        return (*this);
    }
    virtual void foo() { cout << *(m_iptr) << endl; }
    virtual void bar() { cout << m_i << endl; }

  protected:
      virtual ~Base() = 0;

  private:
      int m_i;
      int *m_iptr;
  };

inline Base::~Base() {}

  class Derived: public Base
  {
  public:
      Derived(int i, char c): m_c(c), Base(i), m_c2(c) {}
      void bar() { foo(); Base::foo(); }
        Derived(const Derived& other) : Base(other)
        {
            
            this->m_c = other.m_c;
            this->m_c2 = other.m_c2;
        }
        Derived& operator=(const Derived& other)
        {
            Base::operator=(other);
            this->m_c = other.m_c;
            this->m_c2 = other.m_c2;
            return (*this);
        }
  private:
      void foo() { cout << m_c << endl; }
      char m_c, m_c2;
  };

  class OtherDerived: public Base
  {
    public:
        OtherDerived(int i) : Base(i)
        { 
        }
        OtherDerived(const OtherDerived& other) : Base(other)
        {
        }
        OtherDerived& operator=(const OtherDerived& other)
        {
            Base::operator=(other);
            return (*this);
        }
        ~OtherDerived()
        {
        }
  };

  int main(int argc, char **argv)
  {
      Derived d1(5,'x');
      Derived d2(3,'w');

      Base *b1 = &d1;
      std::cout << "b1->foo();" << std::endl;
      b1->foo();
      std::cout << "b1->bar();" << std::endl;
      b1->bar();
 
      Base *b2 = &d2;
      *b2 = *b1;
      std::cout << "b2->foo();" << std::endl;
      b2->foo();
      std::cout << "d2.bar();" << std::endl;
      d2.bar();
        OtherDerived dd2(5);
     return 0;
 }