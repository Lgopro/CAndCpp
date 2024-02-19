#include <cstdio>
class X
{
    /* public: */
    explicit X(int a_);
    void Foo();

    int GetMA() const;

    private:
    int m_a;
};

X::X(int a_):m_a(a_)
{}
int X::GetMA() const
{
    return this->m_a;
}

void X::Foo()
{
    printf("%d\n", m_a);
}

void Foo(const X &x_)
{
    printf("%d\n", x_.GetMA());
}

int main()
{
    X x1(40);
    x1.Foo();
    printf("%d\n", x1.GetMA());
    Foo(x1);
    return 0;
}