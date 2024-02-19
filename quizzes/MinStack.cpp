
#include <stack>

namespace ilrd
{
    template <typename T>
    class MinStack
    {
        public:

        MinStack(size_t amount = 10);
        ~MinStack() = default;

        void Push(const T& value);
        T Top() const;
        T Min() const;
        void Pop();

        private:

        MinStack(const MinStack& other) = delete;
        MinStack& operator=(const MinStack& other) = delete;

        size_t m_capacity;
        size_t m_size;
        std::stack<T> m_stack;
        std::stack<T> m_min_stack;
        
    };
}

using namespace ilrd;

template <typename T>
MinStack<T>::MinStack(size_t amount):m_capacity(amount), m_size(0)
{
}

template <typename T>
void MinStack<T>::Push(const T& value)
{
    if(m_min_stack.size() == 0 && m_stack.size() == 0)
    {
        m_min_stack.push(value);
        m_stack.push(value);
        return;
    }
    else
    {
        m_stack.push(value);
        if(m_min_stack.top() > value)
        {
            m_min_stack.push(value);
        }
    }
}

template <typename T>
T MinStack<T>::Top() const
{
    return m_stack.top();
}

template <typename T>
T MinStack<T>::Min() const
{
    return m_min_stack.top();
}

template <typename T>
void MinStack<T>::Pop()
{
    if(m_stack.size() == 0)
    {
        return;
    }
    else if(m_min_stack.top() == m_stack.top() && m_min_stack.size() == 1 && m_stack.size() > 1)
    {
        m_stack.pop();
        return;
    }
    else
    {
        if(m_min_stack.top() == m_stack.top())
        {
            m_min_stack.pop();
        }
        m_stack.pop();
    }
}

int main()
{



    return 0;
}