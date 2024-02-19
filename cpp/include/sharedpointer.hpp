/*
Rev: Ido Isaacs.
Dev: Leonid Golovko
status: finished
date: 04/09/2023
*/
#ifndef __SHARED_POINTER_HPP__
#define __SHARED_POINTER_HPP__
#include <iostream>


namespace ilrd
{
    template <class T>
    class SharedPointer
    {
    public:
        SharedPointer(T *real);
        SharedPointer(const SharedPointer &other);
        ~SharedPointer();
        T& operator*() const;
        T* operator->() const;
        int GetCounter();
        SharedPointer& operator=(const SharedPointer &other);


        template <typename U>
        SharedPointer(const SharedPointer<U> &other);

        template <typename U>
        SharedPointer<T>& operator=(const SharedPointer<U> &other);

        template <typename U>
        friend class SharedPointer;

    private:
        T *pointer_T;
        int *counter_pointer;
        void Remove(T *pointer, int *counter);
    };

}

using namespace ilrd;
template <class T>
SharedPointer<T>::SharedPointer(T *real)/*Make here catch if new makes exception, throw.*/
{
    try
    {
        pointer_T = real; 
        counter_pointer = new int(1);
    }
    catch(const std::bad_alloc& alloc)
    {
        std::cerr << "Memory allocation failed: " <<alloc.what() << '\n';
        throw (alloc);
    }
    
    
}   

template <class T>
SharedPointer<T>::~SharedPointer()
{
    Remove(this->pointer_T, this->counter_pointer);
}

template <class T> 
SharedPointer<T>::SharedPointer(const SharedPointer &other):pointer_T(other.pointer_T), counter_pointer(other.counter_pointer)
{
    ++(*this->counter_pointer);
}

template <class T> 
int ilrd::SharedPointer<T>::GetCounter()
{
    return (*this->counter_pointer);
}   

template <class T> 
T& ilrd::SharedPointer<T>::operator*() const
{
    return *(this->pointer_T);
}

template <class T> 
T* ilrd::SharedPointer<T>::operator->() const
{
    return (this->pointer_T);
}

template <class T> 
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& other)
{
    ++(*other.counter_pointer);
    Remove(this->pointer_T, this->counter_pointer);
    this->counter_pointer = other.counter_pointer;
    this->pointer_T = other.pointer_T;
    /* ++(*this->counter_pointer); */
    return (*this);
}

template <class T> 
template <typename U>
SharedPointer<T>::SharedPointer(const SharedPointer<U> &other)
{
    this->counter_pointer = other.counter_pointer;
    this->pointer_T = other.pointer_T;
    ++(*this->counter_pointer);
}


template <class T> 
template <typename U>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<U> &other) /*Send myself*/
{
    ++(*other.counter_pointer);
    Remove(this->pointer_T, this->counter_pointer);
    this->counter_pointer = other.counter_pointer;
    this->pointer_T = other.pointer_T;
    return *this;
}
template <class T> 
void SharedPointer<T>::Remove(T *Pointer_t, int *counter_pointer)
{
    --(*counter_pointer);
    if(0 == *counter_pointer)
    {
        delete Pointer_t;
        delete counter_pointer;
    }
}



#endif /*__SHARED_POINTER_HPP__*/
