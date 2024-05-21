

#include <iostream>
#include <string>



namespace ilrd
{
    template<typename T>
    class SpecialArray
    {
        public:

        SpecialArray(size_t size = 10);
        ~SpecialArray();

        SpecialArray(const SpecialArray& other) = default;
        SpecialArray& operator=(const SpecialArray& other) = default;

        T operator[](size_t place);

        private:

        T* m_str;
        size_t m_size;

    };


    template<typename T>
    SpecialArray<T>::SpecialArray(size_t size):m_size(size)
    {
        if(size == 0)
        {
            std::cerr << "Wrong length" << std::endl;
        }

        try
        {
            m_str = new T[size];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    template<typename T>
    SpecialArray<T>::~SpecialArray()
    {
        delete [] m_str;
    }

    template<typename T>
    T SpecialArray<T>::operator[](size_t place)
    {
        if(place >= m_size)
        {
            throw std::length_error("Wrong location");
        }
        return m_str[place];
    }
}



using namespace ilrd;


int main()
{




    return 0;
    
}