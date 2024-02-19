
#include <iostream>
#include <memory>

namespace ilrd
{
    class Shape
    {
        public:

        Shape() = default;
        ~Shape(){};
        Shape(const Shape& other) = default;
        Shape& operator=(const Shape& other) = default;

        virtual void Print(){std::cout<< "Im Shape"<<std::endl;};
    };

    class Circle : public Shape
    {
        public:
        
        Circle() = default;
        ~Circle(){};
        Circle(const Circle& other) = default;
        Circle& operator=(const Circle& other) = default;

        void Print(){std::cout<< "Im Circle"<<std::endl;};
    };

    class Squere : public Shape
    {
        public:

        Squere() = default;
        ~Squere(){};
        Squere(const Squere& other) = default;
        Squere& operator=(const Squere& other) = default;

        virtual void Print(){std::cout<< "Im Squere"<<std::endl;};
    };

    class Line : public Shape
    {
        public:

        Line() = default;
        ~Line(){};
        Line(const Line& other) = default;
        Line& operator=(const Line& other) = default;

        void Print(){std::cout<< "Im Line"<<std::endl;};
    };

    class God : public Shape
    {
        public:

        God() = default;
        ~God(){};
        God(const God& other) = default;
        God& operator=(const God& other) = default;

        void Print(){std::cout<< "Im God"<<std::endl;};
    };
}

using namespace ilrd;

int main()
{
    std::unique_ptr<Shape> arr[4];

    arr[0] = std::make_unique<Circle>();
    arr[1] = std::make_unique<Squere>();
    arr[2] = std::make_unique<Line>();
    arr[3] = std::make_unique<God>();

    for(auto &iter : arr)
    {
        iter->Print();
    }
    return 0;
}