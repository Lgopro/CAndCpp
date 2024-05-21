
#include <iostream>
#include <vector> /*vector use*/

namespace ilrd
{
    template <typename T>
    class Domino
    {
        public:

        Domino(std::vector<std::vector<T>> &sequences);
        Domino() = default;

        std::vector<std::vector<T>> GetSequences() const;
        char GetWordFirstLetter(T& str) const;
        char GetWordLastLetter(T& str) const;
        void FlipWord(T& str);
        bool IsMergable(char ch) const;
        size_t GetCurrentVectorNumber() const;
        size_t GetMaxVectorAmount() const;
        void PrintResults();

        /*func for me*/
        void PrintAll() const;
        void PrintAllLut() const;

        private:

        Domino(const Domino& other) = delete; /*No need for coppy constructor*/
        Domino& operator=(const Domino& other) = delete; /*No need for assignment operator*/

        std::vector<std::vector<T>> m_sequences;
        std::vector<std::vector<int>> m_Lut;

        size_t m_vector_number;
        size_t m_max_vector_amount;
    };
}

using namespace ilrd;


template <typename T>
Domino<T>::Domino(std::vector<std::vector<T>> &sequences) : m_sequences(sequences), 
                                                            m_max_vector_amount(sequences.capacity()),
                                                            m_vector_number(0)
{
    m_Lut.resize(sequences.size());

    for (size_t i = 0; i < m_Lut.size(); ++i)
    {
        m_Lut[i] = std::vector<int>(256, 0);
    }

    for(size_t i = 0; i < sequences.size(); ++i)
    {
        for(auto iter : m_sequences[i])
        {
            ++m_Lut[i][GetWordFirstLetter(iter)];
            ++m_Lut[i][GetWordLastLetter(iter)];
        }
    }
}

template <typename T>
std::vector<std::vector<T>> Domino<T>::GetSequences() const
{
    return m_sequences;
}

template <typename T>
char Domino<T>::GetWordFirstLetter(T& str) const
{
    return str[0];
}

template <typename T>
char Domino<T>::GetWordLastLetter(T& str) const
{
    return str[sizeof(str)/sizeof(T) - 1];
}

template <typename T>
void Domino<T>::FlipWord(T& str)
{
    size_t start = 0;
    size_t end = str.size() - 1;
    T temp;

    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        ++start;
        --end;
    }
}

template <typename T>
bool Domino<T>::IsMergable(char ch) const
{
    if(m_Lut[m_vector_number][ch] == 2)
    {
        return true;
    }
    return false;
}

template <typename T>
size_t Domino<T>::GetCurrentVectorNumber() const
{
    return m_vector_number;
}

template <typename T>
size_t Domino<T>::GetMaxVectorAmount() const
{
    return m_max_vector_amount;
}

template <typename T>
void Domino<T>::PrintResults()
{

}

template <typename T>
void merge_pairs_only(std::vector<std::vector<T>> &sequences)
{
    Domino<std::string> m_domino(sequences);
    m_domino.PrintAll();
}

template <typename T>
void Domino<T>::PrintAll() const
{
    for(size_t i = 0; i < m_max_vector_amount; ++i)
    {
        std::cout<< "Vector number " << i << std::endl;

        for(auto iter : m_sequences[i])
        {
            std::cout << iter << " ";
        }
        std::cout << " " << std::endl;
    }
}

template <typename T>
void Domino<T>::PrintAllLut() const
{
    
}

int main()
{
    std::vector<std::vector<std::string>> m_vector_arrays;

    std::vector<std::string> m_first_array; 

    m_first_array.push_back("abc");
    m_first_array.push_back("cde");

    std::vector<std::string> m_second_array; 

    m_second_array.push_back("abc");
    m_second_array.push_back("cde");
    m_second_array.push_back("efg");

    std::vector<std::string> m_third_array; 

    m_third_array.push_back("abc");
    m_third_array.push_back("cde");
    m_third_array.push_back("cq");

    std::vector<std::string> m_forth_array; 

    m_forth_array.push_back("xa");
    m_forth_array.push_back("ya");
    m_forth_array.push_back("ab");
    m_forth_array.push_back("bc");


    m_vector_arrays.push_back(m_first_array);
    m_vector_arrays.push_back(m_second_array);
    m_vector_arrays.push_back(m_third_array);
    m_vector_arrays.push_back(m_forth_array);

    merge_pairs_only(m_vector_arrays);

    return 0;
}