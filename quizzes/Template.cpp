#include <iostream>


namespace ilrd
{
    template <typename T>
    class Stack
    {
        public:
        Stack(size_t capacity = 10);
        ~Stack();
        Stack(const Stack& other) = default;
        Stack& operator=(const Stack& other) = default;

        void Pop();
        T Top() const;
        void Push(const T& value);
        bool Empty() const;
        size_t Size() const;

        private:

        T *m_stack;
        size_t m_capacity;
        size_t m_size;
    };
}

using namespace ilrd;

template <typename T>
Stack<T>::Stack(size_t capacity):m_capacity(capacity), m_size(0)
{
    try
    {
        m_stack = new T[capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename T>
void Stack<T>::Pop()
{
    if(m_size != 0)
    {
        --m_size;
    }
}

template <typename T>        
T Stack<T>::Top() const
{
    return m_stack[m_size - 1];
}

template <typename T>        
void Stack<T>::Push(const T& value)
{
    if(m_size != m_capacity)
    {
        m_stack[m_size] = value;
        ++m_size;
    }

}

template <typename T>        
bool Stack<T>::Empty() const
{
   if(m_size == 0)
   {
        return true;
   }
   return false;
}

template <typename T>        
size_t Stack<T>::Size() const
{
    return m_size;
}


template <typename T>
Stack<T>::~Stack()
{
    delete [] m_stack;
}

int main()
{
    Stack<int> m_stack(15);
    m_stack.Push(3);
    m_stack.Push(5);
    m_stack.Push(1);
    m_stack.Push(22);
    m_stack.Push(66);
    m_stack.Push(55);

    while(m_stack.Empty() != true)
    {
        std::cout << m_stack.Top() << std::endl;
        m_stack.Pop();
    }
    return 0;
}