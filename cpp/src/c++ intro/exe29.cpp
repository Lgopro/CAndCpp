#include <iostream>

class X
{
    public:
    explicit X();
    X(int a_);
    explicit X(int a_, int b_);
   /*  operator int() const; */
    void Print() const;
    int GetMA() const;
    private:
    int m_a;

};

X::X() : m_a(0){}
X::X(int a_):m_a(a_){}
X::X(int a_, int b_) : m_a(a_ + b_){}

/* X::operator int() const
{
    return n_num;
} */
int X::GetMA() const
{
    return this->m_a;
}
void X::Print() const
{
    std::cout << "X::Print()" << m_a << std::endl;
}

void Fifi(X&  x_)
{
    std::cout << "Fifi()" << x_.GetMA() << std::endl;
}

void Fifi(X x_, X x1)
{
    std::cout << "Fifi()" << x_.GetMA() << " Fifi()" << x1.GetMA() <<std::endl;
}
int main()
{
    X x1(7);

    Fifi(x1); //1
    Fifi(X(7)); //2
    Fifi(9); // 3
    Fifi(3,4);

    /* return x1 *3; */
    return 0;

}