
#include <iostream> /*std::cout*/
#include <vector> /*vector use*/
#include <string> /*copy*/
#include <algorithm> /*reverse, find*/

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
        Domino(std::vector<std::vector<T>> &sequences);
        Domino() = default;
        
        /*
        Description: Check if this character is mergable with other templates.
        Arguments: Character to check and the number of vector
        Return: True is mergable and false if not.
        Time complexity: O(1)
        Space complexity: O(1)
        */
        bool IsMergable(char ch, int number) const;

        /*
        Description: Print all the possible Domino results.
        Arguments: None.
        Return: Void.
        Time complexity: O(n^2)
        Space complexity: O(1)
        */
        void PrintResults();
        

        void PrintLut() const;

        private:

        Domino(const Domino& other) = delete; /*No need for coppy constructor*/
        Domino& operator=(const Domino& other) = delete; /*No need for assignment operator*/

        std::vector<std::vector<T>> m_sequences;
        std::vector<std::vector<int>> m_Lut; /*Counter for all characters in all the vectors in the sequence*/
        std::vector<T> m_existring_var; /*Vector that stores all current words*/
    };

    /*
    Description: Get the word first letter.
    Arguments: T reference of the word.
    Return: The first letter of the word.
    Time complexity: O(1)
    Space complexity: O(1)
    */
    template <typename T>
    char GetWordFirstLetter(T& str);

    /*
    Description: Get the word last letter.
    Arguments: T reference of the word.
    Return: The last letter of the word.
    Time complexity: O(1)
    Space complexity: O(1)
    */
    template <typename T>
    char GetWordLastLetter(T& str);

    /*
    Description: Fleep the word letter order.
    Arguments: T reference of the word.
    Return: Void.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    void FlipWord(T& str);

    /*
    Description: Connect word1 and word2 according to Domino rules.
    Arguments: T reference to word1 and word2 that needed to be connected.
    Return: T connected word.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    T ConnectWord1Word2(T& word1, T& word2);

    /*
    Description: Connect word2 and word1 according to Domino rules.
    Arguments: T reference to word1 and word2 that needed to be connected.
    Return: T connected word.
    Time complexity: O(n)
    Space complexity: O(1)
    */
    template <typename T>
    T ConnectWord2Word1(T& word1, T& word2);
}

using namespace ilrd;

template <typename T>
void Domino<T>::PrintLut() const
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

template <typename T>
Domino<T>::Domino(std::vector<std::vector<T>> &sequences) : m_sequences(sequences)
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
            ++m_Lut[i][GetWordFirstLetter(iter)];
            ++m_Lut[i][GetWordLastLetter(iter)];
        }
    }
}

template <typename T>
char ilrd::GetWordFirstLetter(T& str) 
{
    return str[0];
}

template <typename T>
char ilrd::GetWordLastLetter(T& str)
{
    return str[str.size() - 1];
}

template <typename T>
void ilrd::FlipWord(T& str)
{
    std::reverse(str.begin(), str.end());
}

template <typename T>
bool Domino<T>::IsMergable(char ch, int number) const
{
    return (CAN_CONNECT_DOMINO == m_Lut[number][ch]); 
}

template <typename T>
void Domino<T>::PrintResults()
{
    for(size_t i = 0; i < m_sequences.size(); ++i)
    {
        std::cout<< "Vector number " << i << std::endl;

        for(auto& iter : m_sequences[i])
        {
            if(IsMergable(GetWordFirstLetter(iter), i) || IsMergable(GetWordLastLetter(iter), i))
            {

                for (auto inner_iter = m_sequences[i].begin(); inner_iter != m_sequences[i].end(); ++inner_iter)
                {
                    if(&iter == &(*inner_iter))
                    {
                        continue;
                    }

                    if(IsMergable(GetWordFirstLetter(iter), i)
                       && (GetWordFirstLetter(*inner_iter) 
                       ==  GetWordFirstLetter(iter) || 
                       GetWordLastLetter(*inner_iter) 
                       ==  GetWordFirstLetter(iter)))
                       {
                            T word1 = ConnectWord1Word2(iter, *inner_iter);
                            auto it1 = std::find(m_existring_var.begin(), m_existring_var.end(), word1);
                            if (it1 == m_existring_var.end()) 
                            {
                                std::cout << word1 << " ";
                                m_existring_var.push_back(word1);
                            } 
                            
                            T word2 = ConnectWord2Word1(iter, *inner_iter);
                            auto it2 = std::find(m_existring_var.begin(), m_existring_var.end(), word2);
                            if (it2 == m_existring_var.end()) 
                            {
                                std::cout << word2 << " ";
                                m_existring_var.push_back(word2);
                            } 
                       }

                       else if((IsMergable(GetWordLastLetter(iter), i))
                       && (GetWordFirstLetter(*inner_iter) 
                       ==  GetWordLastLetter(iter) || 
                       GetWordLastLetter(*inner_iter) 
                       ==  GetWordLastLetter(iter)))
                       {
                            T word1 = ConnectWord1Word2(iter, *inner_iter);
                            auto it1 = std::find(m_existring_var.begin(), m_existring_var.end(), word1);
                            if (it1 == m_existring_var.end()) 
                            {
                                std::cout << word1 << " ";
                                m_existring_var.push_back(word1);
                            } 
                            
                            T word2 = ConnectWord2Word1(iter, *inner_iter);
                            auto it2 = std::find(m_existring_var.begin(), m_existring_var.end(), word2);
                            if (it2 == m_existring_var.end()) 
                            {
                                std::cout << word2 << " ";
                                m_existring_var.push_back(word2);
                            } 
                       }
                }

                
            } 
            
            auto it3 = std::find(m_existring_var.begin(), m_existring_var.end(), iter);
            if (it3 == m_existring_var.end()) 
            {
                std::cout << iter << " ";
                m_existring_var.push_back(iter);
            }   
        }
        m_existring_var.clear();
        std::cout << std::endl;
    }
}

template <typename T>
T ilrd::ConnectWord1Word2(T& word1, T& word2)
{
    size_t i = 0;
    T result;

    if(GetWordFirstLetter(word1) == GetWordFirstLetter(word2))
    {
        FlipWord(word1);
    }
    else if(GetWordFirstLetter(word1) == GetWordLastLetter(word2))
    {
        FlipWord(word1);
        FlipWord(word2);
    }
    else if(GetWordLastLetter(word1) == GetWordLastLetter(word2))
    {
        FlipWord(word2);
    }

    result += word1;
    result += word2.substr(1);
    return result;
}

template <typename T>
T ilrd::ConnectWord2Word1(T& word1, T& word2)
{
    T result;

    if(GetWordFirstLetter(word2) == GetWordFirstLetter(word1))
    {
        FlipWord(word2);
    }
    else if (GetWordFirstLetter(word2) == GetWordLastLetter(word1))
    {
        FlipWord(word2);
        FlipWord(word1);
    }
    else if(GetWordLastLetter(word2) == GetWordLastLetter(word1))
    {
        FlipWord(word1);
    }

    result += word2;
    result += word1.substr(1);
    return result;
}


template <typename T>
void merge_pairs_only(std::vector<std::vector<T>> &sequences)
{
    Domino<std::string> m_domino(sequences);
    m_domino.PrintLut();
    std::cout << std::endl;
    m_domino.PrintResults();
} 

int main()
{
    std::vector<std::vector<std::string>> m_vector_arrays;

    std::vector<std::string> m_first_array; 
    std::vector<std::string> m_second_array; 
    std::vector<std::string> m_third_array; 
    std::vector<std::string> m_forth_array; 

    m_first_array.push_back("abc");
    m_first_array.push_back("cde");

    m_second_array.push_back("abc");
    m_second_array.push_back("cde");
    m_second_array.push_back("efg");

    m_third_array.push_back("abc");
    m_third_array.push_back("cde");
    m_third_array.push_back("cq");

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