
#include <iostream>

namespace ilrd
{
    template <typename TYPE>
    class CirculalBuffer
    {
        public:

        CirculalBuffer(size_t size = 10);
        ~CirculalBuffer();

        void AddElement(TYPE& type);
        void DeleteOldest();
        TYPE Read(size_t location);
        void Write(size_t location, TYPE& new_data);
        bool IsEmpty() const;
        bool IsFull() const;
        void PrintAll() const;

        private:

        CirculalBuffer(const CirculalBuffer& other) = delete;
        CirculalBuffer& operator=(const CirculalBuffer& other) = delete;

        TYPE *m_arr;
        size_t m_capacity;
        size_t m_amount;

    };

}

using namespace ilrd;

template <typename TYPE>
CirculalBuffer<TYPE>::CirculalBuffer(size_t size):m_capacity(size), m_amount(0)
{
    m_arr = new TYPE[size];
}

template <typename TYPE>
CirculalBuffer<TYPE>::~CirculalBuffer()
{
    delete [] m_arr;
}

template <typename TYPE>
void CirculalBuffer<TYPE>::AddElement(TYPE& type)
{
    if(m_capacity != m_amount)
    {
        m_arr[m_amount] = type;
    }
    ++m_amount;
}

template <typename TYPE>
void CirculalBuffer<TYPE>::DeleteOldest()
{
    if(m_amount == 0)
    {
        return;
    }
    --m_amount;
}

template <typename TYPE>
TYPE CirculalBuffer<TYPE>::Read(size_t location)
{
    if(location < m_amount)
    {
        return m_arr[location - 1];
    }
    else
    {
        std::__throw_logic_error("Wrong location bro\n");
    }
}

template <typename TYPE>
void CirculalBuffer<TYPE>::Write(size_t location, TYPE& new_data)
{
    if(location < m_amount)
    {
        m_arr[location] = new_data;
    }
    else
    {
        std::__throw_logic_error("Wrong location bro\n");
    }
}

template <typename TYPE>     
bool CirculalBuffer<TYPE>::IsEmpty() const
{
    if(m_amount == 0)
    {
        return true;
    }
    return false;
}

template <typename TYPE>
bool CirculalBuffer<TYPE>::IsFull() const
{
    if(m_capacity == m_amount)
    {
        return true;
    }
    return false;
}


template <typename TYPE>
void CirculalBuffer<TYPE>::PrintAll() const
{
    for(size_t i = 0; i < m_amount; ++i)
    {
        std::cout<< m_arr[i] << " " << std::endl;
    }
}

int main()
{
    CirculalBuffer<int> int_buffer;
    int var1 = 5;
    int var2 = 2;
    int var3 = 6;
    int var4 = 8;
    int var5 = 0;
    int var6 = -55;

    bool status = int_buffer.IsEmpty();
    bool status1 = int_buffer.IsFull();

    if(status == true && status1 == false)
    {
        std::cout<< "Circular  is empty" <<std::endl;
    }

    int_buffer.AddElement(var1);
    int_buffer.AddElement(var2);
    int_buffer.AddElement(var3);
    int_buffer.AddElement(var4);
    int_buffer.AddElement(var5);
    int_buffer.PrintAll();
    int_buffer.DeleteOldest();
    int_buffer.DeleteOldest();
    std::cout<< "Deleted two oldest" <<std::endl;
    int_buffer.PrintAll();
    int_buffer.Write(1, var6);
    std::cout<< "Changed to -55" <<std::endl;
    int_buffer.PrintAll();

    return 0;
}