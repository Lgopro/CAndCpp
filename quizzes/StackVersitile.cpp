#include <iostream>

namespace ilrd
{
    template <typename T>
    class Stack
    {
        public:

        Stack(size_t size = 10);
        ~Stack();
        bool IsEmpty() const;
        size_t Size() const;
        std::pair<bool, T> Peek() const;
        void Push(T& value);
        void Pop();

        public:

        size_t m_capacity;
        size_t m_size;
        T *m_stack;

        Stack(const Stack& other) = delete;
        Stack& operator=(const Stack& other) = delete;
    }
}

using namespace ilrd;

template <typename T>
Stack<T>::Stack(size_t size):m_capacity(size), m_size(0)
{
    try
    {
        m_stack = new T[size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

template <typename T>    
Stack<T>::~Stack()
{
    delete [] m_stack;
}

template <typename T>       
bool Stack<T>::IsEmpty() const
{
    return (m_size == 0);
}

template <typename T>       
size_t Stack<T>::Size() const
{
    return m_size;
}

template <typename T>     
std::pair<bool, T> Stack<T>::Peek() const
{
    if(m_size == 0)
    {
        return std::pair(false, 0);
    }
    else
    {
        return std::pair(true, m_stack[m_size - 1]);
    }
}

template <typename T>          
void Stack<T>::Push(T& value)
{
    if(m_size < m_capacity)
    {
        m_stack[m_size] = value;
        ++m_size;
    }
}

template <typename T> 
void Stack<T>::Pop()
{
    if(m_size > 0)
    {
        --m_size;
    }
}