
#include <iostream>

namespace ilrd
{
    class Shape
    {
        public:
        Shape() = default;
        ~Shape() = default;
        Shape& operator=(const Shape& other) = delete;
        Shape(const Shape& other) = delete;


        virtual void Draw() = 0;
        virtual void Move(const size_t amout) = 0;
    };


    class Line : public Shape
    {
        public:
        Line();
        ~Line() = default;
        Line& operator=(const Line& other) = delete;
        Line(const Line& other) = delete;

        void Draw();
        void Move(const size_t amout);


        private:
        std::string m_string;
    };


    class Circle : public Shape
    {
        public:
        Circle();
        ~Circle() = default;
        Circle& operator=(const Circle& other) = delete;
        Circle(const Circle& other) = delete;

        void Draw();
        void Move(const size_t amout);


        private:
        std::string m_string;
    };

    class Rectangle : public Shape
    {
        public:
        Rectangle();
        ~Rectangle() = default;
        Rectangle& operator=(const Rectangle& other) = delete;
        Rectangle(const Rectangle& other) = delete;

        void Draw();
        void Move(const size_t amout);


        private:
        std::string m_string;
    };
    
    class Square : public Shape
    {
        public:
        Square();
        ~Square() = default;
        Square& operator=(const Square& other) = delete;
        Square(const Square& other) = delete;

        void Draw();
        void Move(const size_t amout);


        private:
        std::string m_string;
    };
    

}



using namespace ilrd;


Line::Line()
{
    m_string = "Its line brah";
}


Circle::Circle()
{
    m_string = "Its Circle brah";
}

Rectangle::Rectangle()
{
    m_string = "Its Rectangle brah";
}

Square::Square()
{
    m_string = "Its Square brah";
}

void Line::Draw()
{
    std::cout << m_string << std::endl;
}

void Line::Move(const size_t amout)
{
    for(size_t i = 0; i < amout; ++i)
    {
        std::cout << " ";
    }
}

void Circle::Draw()
{
    std::cout << m_string << std::endl;
}

void Circle::Move(const size_t amout)
{
    for(size_t i = 0; i < amout; ++i)
    {
        std::cout << " ";
    }
}

void Rectangle::Draw()
{
    std::cout << m_string << std::endl;
}

void Rectangle::Move(const size_t amout)
{
    for(size_t i = 0; i < amout; ++i)
    {
        std::cout << " ";
    }
}

void Square::Draw()
{
    std::cout << m_string << std::endl;
}

void Square::Move(const size_t amout)
{
    for(size_t i = 0; i < amout; ++i)
    {
        std::cout << " ";
    }
}


int main()
{

    Circle circle;
    circle.Move(5);
    circle.Draw();
    return 0;
}
