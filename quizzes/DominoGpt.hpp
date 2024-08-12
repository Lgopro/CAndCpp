#ifndef __DOMINO_HPP__
#define __DOMINO_HPP__

#include <iostream> /* std::cout */
#include <vector> /* std::vector */
#include <string> /* std::string */
#include <algorithm> /* std::reverse, std::find */
#include <cstring> /* std::strlen */

const int CAN_CONNECT_DOMINO = 2;

namespace ilrd
{
    template <typename T, typename P>
    class Domino
    {
        public:
        Domino(std::vector<std::vector<T>> &sequences);
        Domino() = default;
        
        bool IsMergable(P ch, int number) const;

        void PrintResults();

        void PrintLut() const;

        private:

        Domino(const Domino& other) = delete; /* No need for copy constructor */
        Domino& operator=(const Domino& other) = delete; /* No need for assignment operator */

        std::vector<std::vector<T>> m_sequences;
        std::vector<std::vector<int>> m_Lut; /* Counter for all characters in all the vectors in the sequence */
        std::vector<std::vector<P>> m_existing_var; /* Vector that stores all current words */
    };

    template <typename T, typename P>
    P GetWordFirstLetter(T& str);

    template <typename T, typename P>
    P GetWordLastLetter(T& str);

    template <typename T, typename P>
    void FlipWord(T& str);

    template <typename T, typename P>
    std::vector<P> ConnectWord1Word2(T& word1, T& word2);

    template <typename T, typename P>
    std::vector<P> ConnectWord2Word1(T& word1, T& word2);

    template <typename T, typename P>
    std::vector<P> TurnWordIntoVector(T& word1);
}

using namespace ilrd;

template <typename T, typename P>
Domino<T,P>::Domino(std::vector<std::vector<T>> &sequences) : m_sequences(sequences)
{
    m_Lut.resize(sequences.size());

    for (size_t i = 0; i < m_Lut.size(); ++i)
    {
        m_Lut[i] = std::vector<int>(256, 0);
    }

    for(size_t i = 0; i < sequences.size(); ++i)
    {
        for(auto& iter : m_sequences[i])
        {
            ++m_Lut[i][GetWordFirstLetter<T,P>(iter)];
            ++m_Lut[i][GetWordLastLetter<T,P>(iter)];
        }
    }
}

template <typename T, typename P>
P ilrd::GetWordFirstLetter(T& str) 
{
    if constexpr (std::is_pointer_v<T>)
    {
        return str[0];
    }
    else
    {
        return str[0];
    }
}

template <typename T, typename P>
P ilrd::GetWordLastLetter(T& str)
{
    
    return str[str.size() - 1];
    
}

template <typename T, typename P>
std::vector<P> ilrd::TurnWordIntoVector(T& word1)
{
    std::vector<P> result;

    if constexpr (std::is_pointer_v<T>)
    {
        for(size_t i = 0; i < std::strlen(word1); ++i)
        {
            result.push_back(word1[i]);
        }
    }
    else
    {
        for(size_t i = 0; i < word1.size(); ++i)
        {
            result.push_back(word1[i]);
        }
    }

    return result;
}

template <typename T, typename P>
void ilrd::FlipWord(T& str)
{
    if constexpr (std::is_pointer_v<T>)
    {
        std::reverse(str, str + std::strlen(str));
    }
    else
    {
        std::reverse(str.begin(), str.end());
    }
}

template <typename T, typename P>
bool Domino<T,P>::IsMergable(P ch, int number) const
{
    return (CAN_CONNECT_DOMINO == m_Lut[number][ch]); 
}

template <typename T, typename P>
void Domino<T, P>::PrintLut() const
{
    for(size_t i = 0; i < m_Lut.size(); ++i)
    {
        std::cout << "Lut for vector " << i << ":\n";
        for(size_t j = 0; j < m_Lut[i].size(); ++j)
        {
            if(m_Lut[i][j] > 0)
            {
                std::cout << static_cast<char>(j) << ": " << m_Lut[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

template <typename T, typename P>
void Domino<T,P>::PrintResults()
{
    for(size_t i = 0; i < m_sequences.size(); ++i)
    {
        std::cout << "Vector number " << i << std::endl;

        for(auto& iter : m_sequences[i])
        {
            if(IsMergable(GetWordFirstLetter<T,P>(iter), i) || IsMergable(GetWordLastLetter<T,P>(iter), i))
            {
                for(auto inner_iter = m_sequences[i].begin(); inner_iter != m_sequences[i].end(); ++inner_iter)
                {
                    if(&iter == &(*inner_iter))
                    {
                        continue;
                    }

                    if((IsMergable(GetWordFirstLetter<T,P>(iter), i)
                       && (GetWordFirstLetter<T,P>(*inner_iter) 
                       == GetWordFirstLetter<T,P>(iter) || 
                       GetWordLastLetter<T,P>(*inner_iter) 
                       == GetWordFirstLetter<T,P>(iter)))
                       || 
                       (IsMergable(GetWordLastLetter<T,P>(iter), i)
                       && (GetWordFirstLetter<T,P>(*inner_iter) 
                       == GetWordLastLetter<T,P>(iter) || 
                       GetWordLastLetter<T,P>(*inner_iter) 
                       == GetWordLastLetter<T,P>(iter))))
                    {
                        std::vector<P> word1 = ConnectWord1Word2<T,P>(iter, *inner_iter);
                        auto it1 = std::find(m_existing_var.begin(), m_existing_var.end(), word1);
                        if (it1 == m_existing_var.end()) 
                        {
                            for(auto vec_iter : word1)
                            {
                                std::cout << vec_iter;
                            }
                            std::cout << " ";
                            m_existing_var.push_back(word1);
                        } 
                        
                        std::vector<P> word2 = ConnectWord2Word1<T,P>(iter, *inner_iter);
                        auto it2 = std::find(m_existing_var.begin(), m_existing_var.end(), word2);
                        if (it2 == m_existing_var.end()) 
                        {
                            for(auto vec_iter : word2)
                            {
                                std::cout << vec_iter;
                            }
                            std::cout << " ";
                            m_existing_var.push_back(word2);
                        } 
                    }
                }
            } 
            
            std::vector<P> iter_vector = TurnWordIntoVector<T, P>(iter);
            auto it3 = std::find(m_existing_var.begin(), m_existing_var.end(), iter_vector);
            if (it3 == m_existing_var.end()) 
            {
                for(auto vec_iter : iter_vector)
                {
                    std::cout << vec_iter;
                }
                std::cout << " ";
                m_existing_var.push_back(iter_vector);
            }   
        }
        m_existing_var.clear();
        std::cout << std::endl;
    }
}

template <typename T, typename P>
std::vector<P> ilrd::ConnectWord1Word2(T& word1, T& word2)
{
    std::vector<P> result;
    size_t total_loc = 0;
    size_t loc_sec_word = 1;

    result.resize(word1.size() + word2.size());
    
    if(GetWordFirstLetter<T,P>(word1) == GetWordFirstLetter<T,P>(word2))
    {
        FlipWord<T,P>(word1);
    }
    else if(GetWordFirstLetter<T,P>(word1) == GetWordLastLetter<T,P>(word2))
    {
        FlipWord<T,P>(word1);
        FlipWord<T,P>(word2);
    }
    else if(GetWordLastLetter<T,P>(word1) == GetWordLastLetter<T,P>(word2))
    {
        FlipWord<T,P>(word2);
    }

    if constexpr (std::is_pointer_v<T>)
    {
        while(total_loc < std::strlen(word1))
        {
            result[total_loc] = word1[total_loc];
            ++total_loc;
        }

        while(loc_sec_word < std::strlen(word2))
        {
            result[total_loc] = word2[loc_sec_word];
            ++total_loc;
            ++loc_sec_word;
        }
    }
    else
    {
        while(total_loc < word1.size())
        {
            result[total_loc] = word1[total_loc];
            ++total_loc;
        }

        while(loc_sec_word < word2.size())
        {
            result[total_loc] = word2[loc_sec_word];
            ++total_loc;
            ++loc_sec_word;
        }
    }
    
    return result;
}

template <typename T, typename P>
std::vector<P> ilrd::ConnectWord2Word1(T& word1, T& word2)
{
    std::vector<P> result;
    size_t total_loc = 0;
    size_t loc_sec_word = 1;

    if constexpr (std::is_pointer_v<T>)
    {
        result.resize(std::strlen(word1) + std::strlen(word2));
    }
    else
    {
        result.resize(word1.size() + word2.size());
    }

    if(GetWordFirstLetter<T,P>(word2) == GetWordFirstLetter<T,P>(word1))
    {
        FlipWord<T,P>(word2);
    }
    else if (GetWordFirstLetter<T,P>(word2) == GetWordLastLetter<T,P>(word1))
    {
        FlipWord<T,P>(word2);
        FlipWord<T,P>(word1);
    }
    else if(GetWordLastLetter<T,P>(word2) == GetWordLastLetter<T,P>(word1))
    {
        FlipWord<T,P>(word1);
    }

    if constexpr (std::is_pointer_v<T>)
    {
        while(total_loc < std::strlen(word2))
        {
            result[total_loc] = word2[total_loc];
            ++total_loc;
        }

        while(loc_sec_word < std::strlen(word1))
        {
            result[total_loc] = word1[loc_sec_word];
            ++total_loc;
            ++loc_sec_word;
        }
    }
    else
    {
        while(total_loc < word2.size())
        {
            result[total_loc] = word2[total_loc];
            ++total_loc;
        }

        while(loc_sec_word < word1.size())
        {
            result[total_loc] = word1[loc_sec_word];
            ++total_loc;
            ++loc_sec_word;
        }
    }

    return result;
}

template <typename T, typename P>
void merge_pairs_only(std::vector<std::vector<T>> &sequences)
{
    Domino<T, P> m_domino(sequences);
    m_domino.PrintLut();
    m_domino.PrintResults();
}

#endif /*__DOMINO_HPP__*/
