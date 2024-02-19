

#ifndef __EXE6__
#define __EXE6__
#include <iostream>
#include <iosfwd>
namespace ilrd
{
    template <class T>
    class Point
    {
    public:
        Point();
        Point(T t1, T t2);
        Point &operator=(const Point<T> &other);
        Point(const Point<T> &other);
        Point &operator+=(T t1);
        Point &operator/=(T t1);
        ~Point();
        T GetX() const;
        T GetY() const;
        void SetX(T value);
        void SetY(T value);

    private:
        T t_x;
        T t_y;
    };

    template <class T>
    Point<T> operator+(const Point<T> p1, const Point<T> p2);
    template <class T>
    Point<T> operator-(const Point<T> p1, const Point<T> p2);
    template <class T>
    bool operator==(Point<T> p1, Point<T> p2);
    template <class T>
    bool operator==(Point<int> p1, Point<int> p2);

}

#endif