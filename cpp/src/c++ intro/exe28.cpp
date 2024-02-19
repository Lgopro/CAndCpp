#include <iostream>

using namespace std;

class X;

int operator+(const X& x1_, const X& x2_)
{
	return (7);
}

class X
{
public:
	bool operator==(const X& o_) const { return m_a == o_.m_a; }
	inline X& operator+=(const X& other_)
	{
		this->m_a += other_.m_a;
        return (*this);
	}
   
    inline X& operator-=(const X& other_)
	{
		this->m_a -= other_.m_a;
        return (*this);
	}
    
    inline X& operator*=(const X& other_)
	{
		this->m_a *= other_.m_a;
        return (*this);
	}
    
    inline X& operator/=(const X& other_)
	{
		this->m_a /= other_.m_a;
        return (*this);
	}
	/* int GetMA() const; */
private:
	friend ostream& operator<<(ostream& os_, const X& x_);
	int m_a; 
};
/* int X::GetMA() const 
{
	return m_a;
} */
int main()
{
	X x1;
	X x2;

	cout << " x1+x2:" << x1 + x2 << 
		 	" x1==x2:" << (x1 == x2) <<
			" x1:" << x1 <<
			" x2:" << x2 << endl;

	return(0);
}


ostream& operator<<(ostream& os_, const X& x_)
{
	os_ << x_.m_a;
	return (os_);
}



