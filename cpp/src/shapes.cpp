/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 13/08/23
*/
#include <vector> /*vector use*/
#include <string> /*string use*/
#include <iostream> /*cout*/
#include "shapes.hpp"

using namespace ilrd;


Shape::Shape()
{
    this->m_move = 0;
}

Shape::Shape(size_t move):m_move(move)
{
}

Shape& Shape::operator=(const Shape& other_)
{
    this->m_move = other_.m_move;
    return *this;
}

void Shape::Move()
{
    for(size_t i = 0; i < this->m_move; ++i)
    {
        std::cout << " ";
    }
}

void Line::Draw()
{

    std::cout << "Line";
    std::cout << "" << std::endl;
}


void Circle::Draw()
{
    
    std::cout << "Circle";
    std::cout << "" << std::endl;
}


void Square::Draw()
{
    
    std::cout << "Square";
    std::cout << "" << std::endl;
}

void Rectangle::Draw()
{
   
    std::cout << "Rectangle";
    std::cout << "" << std::endl;
}