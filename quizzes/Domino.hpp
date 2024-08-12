#ifndef __DOMINO_HPP__
#define __DOMINO_HPP__

#include <iostream>      /*std::cout*/
#include <vector>        /*vector use*/
#include <algorithm>     /*reverse, find*/
#include <unordered_map> /*unordered_map use*/

const int CAN_CONNECT_DOMINO = 2;

namespace ilrd
{
    template <typename T>
    class Domino
    {
    public:
        /*
        Description: Create the Domino class.
        Arguments: Sequences of template vectors
        Return: None.
        Time complexity: O(n^2)
        Space complexity: O(1)
        */
        Domino(std::vector<std::vector<T> > &sequences);
        Domino() = default;

        /*
        Description: Check if this character is mergable with other templates.
        Arguments: Character to check and the number of vector
        Return: True is mergable and false if not.
        Time complexity: O(1)
        Space complexity: O(1)
        */
        bool IsMergable(T ch) const;

        /*
        Description: Print all the possible Domino results.
        Arguments: None.
        Return: Void.
        Time complexity: O(n^2)
        Space complexity: O(1)
        */
        void PrintResults();

        #ifdef DEBUG
        /*
        Description: Print the LUT of all numbers or characters to check if they can be merged.
        Arguments: None.
        Return: Void.
        Time complexity: O(n)
        Space complexity: O(1)
        */
        void PrintLut() const;
        #endif

    private:
        Domino(const Domino &other) = delete;            /*No need for coppy constructor*/
        Domino &operator=(const Domino &other) = delete; /*No need for assignment operator*/

        std::vector<std::vector<T>> m_sequences;
        std::unordered_map<T, int> m_Lut; /*Counter for all characters in all the vectors in the sequence*/
    };

    /*
    Description: Get the word first letter.
    Arguments: T reference of the word.
    Return: The first letter of the word.
    Time complexity: O(1)
    Space complexity: O(1)
    */
    template <typename T>
    T GetWordFirstLetter(std::vector<T>& str);

    /*
    Description: Get the word last letter.
    Arguments: T reference of the word.
    Return: The last letter of the word.
    Time complexity: O(1)
    Space complexity: O(1)
    */
    template <typename T>
    T GetWordLastLetter(std::vector<T>& str);

    /*
    Description: Fleep the word letter order.
    Arguments: T reference of the word.
    Return: Void.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    void FlipWord(std::vector<T>& str);

    /*
    Description: Connect word1 and word2 according to Domino rules.
    Arguments: T reference to the vector of word1 and word2 that needed to be connected.
    Return: T connected word.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    std::vector<T> ConnectWord1Word2(std::vector<T>& word1, std::vector<T>& word2);

    /*
    Description: Get vector size.
    Arguments: T reference to value.
    Return: Size of the vector.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    size_t GetSize(std::vector<T>& value);

}

using namespace ilrd;


template <typename T>
size_t ilrd::GetSize(std::vector<T>& value)
{
    return value.size();
}

template <typename T>
Domino<T>::Domino(std::vector<std::vector<T>> &sequences) : m_sequences(sequences)
{
    for (auto &iter : sequences)
    {
        ++m_Lut[GetWordFirstLetter<T>(iter)];
        ++m_Lut[GetWordLastLetter<T>(iter)];
    }
    
    #ifdef DEBUG
    std::cout << "Debug: m_Lut contents after initialization:\n";
    PrintLut();
    #endif
}

template <typename T>
T ilrd::GetWordFirstLetter(std::vector<T>& str)
{
    return str.front();
}

template <typename T>
T ilrd::GetWordLastLetter(std::vector<T>& str)
{
    return str.back();
}

template <typename T>
void ilrd::FlipWord(std::vector<T>& str)
{
    std::reverse(str.begin(), str.end());
}

template <typename T>
bool Domino<T>::IsMergable(T ch) const
{
    return (m_Lut.at(ch) == CAN_CONNECT_DOMINO);
}


#ifdef DEBUG
template <typename T>
void Domino<T>::PrintLut() const
{
    for (const auto &pair : m_Lut)
    {
        if (pair.second > 0)
        {
            std::cout << "var " <<static_cast<T>(pair.first) << ": " << pair.second << " times" << " " << std::endl;;
        }
    }
    std::cout << std::endl;
}
#endif

template <typename T>
void Domino<T>::PrintResults()
{
    bool flag = false;
    std::vector<std::vector<T>> m_seq_copy = m_sequences;
    
    auto iter = m_seq_copy.begin();
    while (iter != m_seq_copy.end())
    {
        size_t size_iter;
        flag = false;
        size_iter = GetSize<T>(*iter);

        if (IsMergable(GetWordFirstLetter<T>(*iter)) || IsMergable(GetWordLastLetter<T>(*iter)))
        {
            auto inner_iter = m_seq_copy.begin();
            while (inner_iter != m_seq_copy.end())
            {
                if (iter == inner_iter)
                {
                    ++inner_iter;
                    continue;
                }

                size_t size_inner_iter;
                size_inner_iter = GetSize<T>(*inner_iter); 
                /*Check if the the first or last variable of iter is mergable and
                if the inner_itter also has this variable as a first or last letter as well*/
                if ((IsMergable(GetWordFirstLetter<T>(*iter)) && 
                    (GetWordFirstLetter<T>(*inner_iter) == GetWordFirstLetter<T>(*iter) ||
                    GetWordLastLetter<T>(*inner_iter) == GetWordFirstLetter<T>(*iter))) ||
                    (IsMergable(GetWordLastLetter<T>(*iter)) 
                    && (GetWordFirstLetter<T>(*inner_iter) == GetWordLastLetter<T>(*iter) ||
                    GetWordLastLetter<T>(*inner_iter) == GetWordLastLetter<T>(*iter))))
                    {
                        std::vector<T> word1 = ConnectWord1Word2<T>(*iter, *inner_iter); 
                        iter = m_seq_copy.erase(iter);
                        --inner_iter;
                        inner_iter = m_seq_copy.erase(inner_iter);
                        m_seq_copy.push_back(word1);
                        flag = true;
                        break;
                    }
                    ++inner_iter;
            }
            if(flag == false)
            {
                break;
            }
            else
            {
                continue;
            }
        }  
        ++iter;
    } 

    std::cout<< "The result after Domino merge is:" << std::endl;

    size_t i = 1;

    for(auto &iter_print: m_seq_copy)
    {
        std::cout<< "Array " << i << ": ";
        for(auto &variables : iter_print)
        {
            std::cout << variables << " ";
        }  
        ++i;
        std::cout << std::endl;
    }
    
}     

template <typename T>
std::vector<T> ilrd::ConnectWord1Word2(std::vector<T>& word1, std::vector<T>& word2)
{
    std::vector<T> temp_word1 = word1;
    std::vector<T> temp_word2 = word2;

    if (GetWordFirstLetter<T>(temp_word1) == GetWordFirstLetter<T>(temp_word2))
    {
        FlipWord<T>(temp_word1);
    }
    else if (GetWordFirstLetter<T>(temp_word1) == GetWordLastLetter<T>(temp_word2))
    {
        FlipWord<T>(temp_word1);
        FlipWord<T>(temp_word2);
    }
    else if (GetWordLastLetter<T>(temp_word1) == GetWordLastLetter<T>(temp_word2))
    {
        FlipWord<T>(temp_word2);
    }

    std::vector<T> result;
    result.insert(result.end(), temp_word1.begin(), temp_word1.end());
    result.insert(result.end(), temp_word2.begin() + 1, temp_word2.end());
    
    return result;
}

template <typename T>
void merge_pairs_only(std::vector<std::vector<T>> &sequences)
{
    Domino<T> m_domino(sequences);
    std::cout << std::endl;
    m_domino.PrintResults();
}

#endif /*__DOMINO_HPP__*/