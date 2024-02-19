#include <iostream>


namespace ilrd
{
    template<typename TYPE>
    class CircularBuffer
    {
        public:

        CircularBuffer(size_t capacity = 10);
        ~CircularBuffer();

        void InputToEnd(const TYPE& value);
        std::pair<bool, TYPE> Top() const;
        void RemoveFromBegining();


        private:

        CircularBuffer(const CircularBuffer& other) = delete; //can be default if needed by user
        CircularBuffer& operator=(const CircularBuffer& other) = delete; //can be default if needed by user

        TYPE *m_arr;
        size_t m_capacity;
        size_t m_amount;
        size_t m_begin;
        


    };


}

using namespace ilrd;

const int EMPTY = 0;

template<typename TYPE>
CircularBuffer<TYPE>::CircularBuffer(size_t capacity):m_capacity(capacity), m_amount(0), m_begin(0)
{
    try
    {
        m_arr = new TYPE[capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

template<typename TYPE>
CircularBuffer<TYPE>::~CircularBuffer()
{
    delete [] m_arr;
}

template<typename TYPE>
void CircularBuffer<TYPE>::InputToEnd(const TYPE& value)
{
    if(m_amount == m_capacity)
    {
        m_arr[m_begin] = value;
        m_begin = (m_begin + 1) % m_capacity;
    }
    else
    {
        m_arr[(m_begin + m_amount) % m_capacity] = value;
    }
}

template<typename TYPE>
std::pair<bool, TYPE> CircularBuffer<TYPE>::Top() const
{
    if(m_amount == EMPTY)
    {
        return std::make_pair(false, m_arr[m_begin]);
    }
    return std::make_pair(true, m_arr[m_begin]);
}

template<typename TYPE>
void CircularBuffer<TYPE>::RemoveFromBegining()
{
    if(m_amount == EMPTY)
    {
        return;
    }
    m_begin = (m_begin + 1) % m_capacity;
    --m_amount;
}


int main()
{


    return 0;
}