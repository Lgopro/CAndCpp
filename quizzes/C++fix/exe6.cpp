#include <cassert>

#include "exe6.hpp"
using namespace ilrd;

template <class T>
Point<T>::Point() : t_x(0), t_y(0)
{
}
template <class T>
Point<T>::Point(T t1, T t2) : t_x(t1), t_y(t2)
{
}
template <class T>
Point<T> &Point<T>::operator=(const Point<T> &other)
{
    if (this != &other)
    {
        t_x = other.GetX();
        t_y = other.GetY();
    }
    return *this;
}
template <class T>
Point<T>::Point(const Point<T> &other) : t_x(other.t_x), t_y(other.t_y)
{
}
template <class T>
Point<T> &Point<T>::operator+=(T t1)
{
    this->SetX(GetX() + t1);
    this->SetY(GetY() + t1);
    return (*this);
}
template <class T>
Point<T> &Point<T>::operator/=(T t1)
{
    this->SetX(GetX() / t1);
    this->SetY(GetY() / t1);
    return (*this);
}
template <class T>
Point<T>::~Point()
{
}

template <class T>
Point<T> ilrd::operator+(const Point<T> p1, const Point<T> p2)
{
    Point<T> return_value;
    T x = p1.GetX() + p2.GetX();
    T y = p1.GetY() + p2.GetY();
    return_value.SetX(x);
    return_value.SetY(y);
    return return_value;
}
template <class T>
Point<T> ilrd::operator-(const Point<T> p1, const Point<T> p2)
{
    Point<T> return_value;
    T x = p1.GetX() - p2.GetX();
    T y = p1.GetY() - p2.GetY();
    return_value.SetX(x);
    return_value.SetY(y);
    return return_value;
}
template <class T>
bool ilrd::operator==(Point<int> p1, Point<int> p2)
{
    return ((p1.GetX() == p2.GetX()) && (p1.GetY() == p2.GetY()));
}

template <class T>
bool ilrd::operator==(Point<T> p1, Point<T> p2)
{
    return ((p1.GetX() == p2.GetX()) && (p1.GetY() == p2.GetY()));
}
template <class T>
T Point<T>::GetX() const
{
    return t_x;
}
template <class T>
T Point<T>::GetY() const
{
    return t_y;
}
template <class T>
void Point<T>::SetX(T value)
{
    this->t_x = value;
}
template <class T>
void Point<T>::SetY(T value)
{
    this->t_y = value;
}

int main()
{
    Point<int> p1(5, 6);
    Point<int> p2(12, 18);
    Point<int> p3;
    p3 = p1 + p2;
    Point<int> p4 = p3 - p1;
    Point<int> p5(0, 0);
    assert(p4 == p2);
    Point<int> p6(p1);
    p6 += 1;
    assert(p6 == Point<int>(6, 7));
    p2 /= 2;
    assert(p2 == Point<int>(6, 9));
}
