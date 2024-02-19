class X
{
public:
     ~X() {}

private:
    double m_a;

};

class Y:public X
{
private:
    int m_b;
};
void Foo(X x)
{
    
}
int main()
{
    Y y;
     X *xp = new Y[5];
     Foo(y);
     delete[] xp;
     return 0;
}