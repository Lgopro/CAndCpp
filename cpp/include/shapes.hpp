
#ifndef __ILRD_SIMPLE_STR_HPP__
#define __ILRD_SIMPLE_STR_HPP__

#include <iostream>
#include <iosfwd>

namespace ilrd
{

class  Shape 
{

public:
   
    Shape();
    Shape(size_t move);
    Shape &operator=(const Shape& other_);
    void Move();
    virtual void Draw() = 0; /*pure virtual*/
    inline void SetMove(const size_t move);
    inline size_t GetMove() const;
    /*Dtor not needed - default enough*/
private:
    size_t m_move;  
};

class Line: public Shape
{
public:
    Line() : Shape(){}
    Line(size_t move) : Shape(move){}
    void Draw();

};

class Circle: public Shape
{

public:
    Circle() : Shape(){}
    Circle(size_t move) : Shape(move){}
    void Draw();
};

class Square: public Shape
{

public:
    Square() : Shape(){}
    Square(size_t move) : Shape(move){}
    void Draw();

};

class Rectangle: public Shape
{
public:
    Rectangle() : Shape(){}
    Rectangle(size_t move) : Shape(move){}
    void Draw();
   
};

inline void Shape::SetMove(const size_t move)
{
    this->m_move = move;
}

inline size_t Shape::GetMove() const
{
    return this->m_move;
}

}

#endif