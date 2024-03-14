#include <iostream>


namespace ilrd
{
    template <typename T>
    class MultiOperation
    {
        public:
        MultiOperation();
        ~MultiOperation() = default;
        T Addition(T& value1, T&value2);
        T Subtraction(T& value1, T&value2);
        T Multiplication(T& value1, T&value2);
        T Division(T& value1, T&value2);

        private:

        MultiOperation(const MultiOperation& other) = delete;
        MultiOperation& operator=(const MultiOperation& other) = delete;

    };
}

using namespace ilrd;


template <typename T>
MultiOperation<T>::MultiOperation()
{

}

template <typename T>
T MultiOperation<T>::Addition(T& value1, T&value2)
{
    return (value1 + value2);
}

template <typename T>
T MultiOperation<T>::Subtraction(T& value1, T&value2)
{
    return (value1 - value2);
}

template <typename T>
T MultiOperation<T>::Multiplication(T& value1, T&value2)
{
    return (value1 * value2);
}

template <typename T>
T MultiOperation<T>::Division(T& value1, T&value2)
{
    
}