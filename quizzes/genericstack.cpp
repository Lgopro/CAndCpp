#include <cassert>
#include <iostream>
#include <ostream>
#include <cstddef>

const int AMOUNT = 10;

namespace ilrd
{
    template <class T>
    class Stack
    {
    public:
        Stack();
        Stack(size_t capacity_of_stack);
        Stack &operator=(const Stack<T> &other);
        Stack(const Stack<T> &other);
        ~Stack();
        void Push(T value);
        T Peek();
        void Pop();
        T *GetStack();
        size_t GetSize();
        size_t GetCapacity();
        void SetSize(size_t size);
        void SetCapacity(size_t capacity);
        void Print();

    private:
        T *Init(T *array, size_t capacity);
        size_t capacity;
        size_t size;
        T *array;
       
    };

}

using namespace ilrd;




template <class T>
void Stack<T>::Print()
{
    T *array = GetStack();
    for(size_t i = 0; i < GetSize(); ++i)
    {
        std::cout << array[i] << std::endl;
    }
}


template <class T>
T *Stack<T>::Init(T *array, size_t capacity)
{
    array = new T[capacity];
    return array;
}

template <class T>
Stack<T>::Stack():array(Init(array, 10)), capacity(10), size(0)
{
}

template <class T>
Stack<T>::Stack(size_t capacity_of_stack):array(Init(array, capacity_of_stack)), capacity(capacity_of_stack), size(0)
{
}

template <class T>
Stack<T>::~Stack()
{
    delete [] this->array;
}

template <class T>
Stack<T>::Stack(const Stack<T> &other):array(Init(other.array, other.capacity)),capacity(other.capacity), size(other.size)
{   

}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other)
{
    T *temp_array = Init(other.array, other.capacity);

    delete [] this->array;

    this->array = temp_array;
    this->capacity = other.capacity;
    this->size = other.size;

    return (*this);
}


template <class T>
T *Stack<T>::GetStack()
{
    return this->array;
}

template <class T>
size_t Stack<T>::GetSize()
{
    return this->size;
}

template <class T>
size_t Stack<T>::GetCapacity()
{
    return this->capacity;
}

template <class T>
void Stack<T>::SetSize(size_t size)
{
    this->size = size;
}

template <class T>
void Stack<T>::SetCapacity(size_t capacity)
{
    this->capacity = capacity;
}

template <class T>
void Stack<T>::Push(T value)
{
    T *array = GetStack();

    if(GetSize() + 1 == GetCapacity())
    {
        T *temp = Init(temp, GetCapacity() * 2);
        for(size_t i = 0; i < GetSize(); ++i)
        {
            temp[i] = array[i];
        }

        T *to_delete = this->array;

        this->array = temp;
        SetCapacity(GetCapacity() * 2);
        delete [] to_delete; 
    }
    this->array[GetSize()] = value;
    SetSize(GetSize() + 1);
}

template <class T>
T Stack<T>::Peek()
{
    return array[GetSize() - 1];
}

template <class T>
void Stack<T>::Pop()
{
    SetSize(GetSize() - 1);
}


int main()
{
    Stack<int> s1;
    
    s1.Push(5);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.Push(6);
    s1.Push(7);
    int value = s1.Peek();
    std::cout<< value << std::endl;
    s1.Pop();
    int value1 = s1.Peek();
    std::cout<< value1 << std::endl;
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    s1.Push(5);
    s1.Push(1);
    size_t capacity = s1.GetCapacity();
    std::cout<< capacity << std::endl;
    size_t size = s1.GetSize();
    std::cout<< size << std::endl;
    int value2 = s1.Peek();
    std::cout<< value2 << std::endl;
}