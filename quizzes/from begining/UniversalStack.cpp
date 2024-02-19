


#include <iostream>


namespace ilrd
{
    template<typename TYPE>
    class Stack
    {
        public:
        Stack(size_t size = 10);
        ~Stack();
        Stack(const Stack& other) = default;
        Stack& operator=(const Stack& other) =default;

        void Push(const TYPE& val);
        void Pop();
        TYPE* Peek();

        private:
        TYPE *m_arr;
        size_t m_size;
        size_t m_amount_taken;

    };
}

using namespace ilrd;

template<typename TYPE>
Stack<TYPE>::Stack(size_t size):m_size(size), m_amount_taken(0)
{
    TYPE *temp = new TYPE[m_size];
    m_arr = temp;
}

template<typename TYPE>
Stack<TYPE>::~Stack()
{
    delete [] m_arr;
}

template<typename TYPE>
void Stack<TYPE>::Push(const TYPE& val)
{
    if(m_amount_taken == m_size)
    {
        return;
    }
    m_arr[m_amount_taken] = val;
    ++m_amount_taken;

}

template<typename TYPE>      
void Stack<TYPE>::Pop()
{
    if(0 == m_amount_taken)
    {
        return;
    }
    --m_amount_taken;
}

template<typename TYPE>         
TYPE* Stack<TYPE>::Peek()
{
    if(0 == m_amount_taken)
    {
        return nullptr;
    }
    else
    {
        return &m_arr[m_amount_taken - 1];
    }
}

int main()
{
    Stack<int> stack(8);
    stack.Push(4);
    stack.Push(2);
    int *result = stack.Peek();
    std::cout<< *result << std::endl;
    return 0;
}


    
