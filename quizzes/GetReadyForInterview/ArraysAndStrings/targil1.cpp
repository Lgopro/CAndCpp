#include <iostream>
#include <cstring>
#include <list>
#include <utility>
#include <tuple>
#include "string.h"

bool CheckUniqueChar(char *array)
{
    int LUT[256] = {0};
    for(size_t i = 0; i < strlen(array); ++i)
    {
        ++LUT[(size_t)array[i]];
    }
    for(size_t i = 0; i < strlen(array); ++i)
    {
        if(LUT[(size_t)array[i]] > 1)
        {
            return false;
        }
    }
    return true;
}

bool CheckUniqueCharPartTwo(char *array)
{
    size_t counter = 1;
    for(size_t i = 0; i < strlen(array) - 1; ++i)
    {
        counter = 1;
        for(size_t j = i + 1; j < strlen(array); ++j)
        {
            if(array[i] == array[j])
            {
                return false;
            }
        }
    }
    return true;
}

void Reverse(char *before_reverse, char *after_reverese)
{
    size_t length = strlen(before_reverse) - 1;
    size_t end = length + 1;
    size_t begin = 0;

    while(begin != length + 1)
    {
        --end;
        after_reverese[end] = before_reverse[begin];
        ++begin;
    }
    after_reverese[length + 1] = '\0';
}

std::string EliminateDuplicate(std::string string)
{
    size_t counter = 0;
    for(size_t i = 0; i < string.length() - 1 ; ++i)
    {
        for(size_t j = i + 1; j < string.length() - counter; ++j)
        {
            while(string[i] == string[j])
            {
                for(size_t k = j ; k < string.length() - 1; ++k)
                {
                    string[k] = string[k + 1];
                }
                ++counter;
                string[string.length() - 1] = '\0';
            }
        }
    }
    return string;
}

bool Anagrams(std::string str1, std::string str2)
{
    int LUT[256] = {0};
    for(size_t i = 0; i < str1.length(); ++i)
    {
        ++LUT[str1[i]];
    }

    for(size_t j = 0; j < str2.length(); ++j)
    {
        --LUT[str2[j]];
    }

    for(size_t i = 0; i < 256; ++i)
    {
        if(LUT[i] < 0)
        {
            return false;
        }
    }
    return true;
}

std::string ChangeSpace(std::string string)
{
    char return_string[200];
    size_t j = 0;
    for(size_t i = 0; i <= string.length(); ++i)
    {
        if(string[i] == ' ')
        {
            return_string[j] = '%';
            ++j;
            return_string[j] = '2';
            ++j;
            return_string[j] = '0';
            ++j;
        }
        else
        {
            return_string[j] = string[i];
            ++j;
        }
    }

    std::cout << return_string << std::endl;
    return return_string;
}


void Rotate90(char **arr, size_t rows, size_t coulmns)
{

}

void RowAndCoulmnZero(int arr[5][5], size_t rows, size_t coulmns)
{
    std::list<std::pair<int, int>> m_list;

    for(size_t i = 0; i < rows; ++i)
    {
        for(size_t j = 0; j < coulmns; ++j)
        {
            if(arr[i][j] == 0)
            {
                m_list.push_back(std::make_pair(i,j));
            }
        }
    }
    for(auto iter : m_list)
    {
        int x = iter.first;
        int y = iter.second;
        for(int i = 0; i < rows; ++i)
        {
            arr[i][y] = 0;
        }
        for(int j = 0; j < coulmns; ++j)
        {
            arr[x][j] = 0;
        }
    }
}

bool IsSubString(std::string sub, std::string full)
{
    return (full.find(sub) != std::string::npos);
}

std::string Rotate(std::string to_rotate, size_t i)
{
    size_t size = 0;
    char array[to_rotate.length()];
    while(size < to_rotate.length())
    {
        array[size] = to_rotate[i];
        i = (i + 1) % (to_rotate.length());
        to_rotate[to_rotate.length()] = '\0';
        ++size;
    }
    std::cout<< array <<std::endl;
    return array;
}

bool IsRotation(std::string sub, std::string full)
{
    for(size_t i = 0; i < full.length(); ++i)
    {
        if(full[i] == sub[0])
        {
            full = Rotate(full, i);
            std::cout<< full <<std::endl;
            bool value = IsSubString(sub, full);
            if(value == true)
            {
                return true;
            }
        }

    }
    return false;
}

#include <iostream>
#include <vector>

void RotateMatrix(std::vector<std::vector<int>>& matrix) 
{
    int n = matrix.size();
    std::cout<< "The size is: " << n << std::endl;

    for (int layer = 0; layer < n / 2; ++layer) 
    {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; ++i) 
        {
            int offset = i - first;

            // Save top
            int top = matrix[first][i];

            // Move left to top
            matrix[first][i] = matrix[last - offset][first];

            // Move bottom to left
            matrix[last - offset][first] = matrix[last][last - offset];

            // Move right to bottom
            matrix[last][last - offset] = matrix[i][last];

            // Move top to right
            matrix[i][last] = top;
        }
    }
}



int main()
{
    char array[] = "What Bro?";
    char array1[10] = "Hello";
    char array2[10];
    std::string string = "wwwhhhaaattttttttt?";
    std::string str_result = EliminateDuplicate(string);
    std::cout << str_result << std::endl;
    Reverse(array1, array2);

    std::cout << array2 << std::endl;
    bool result = CheckUniqueChar(array);
    if(result == true)
    {
        std::cout << "CheckUniqueChar True" << std::endl;
    }
    else
    {
        std::cout << "CheckUniqueChar False" << std::endl;
    }


    bool result1 = CheckUniqueCharPartTwo(array);
    if(result1 == true)
    {
        std::cout << "CheckUniqueCharPartTwo True" << std::endl;
    }
    else
    {
        std::cout << "CheckUniqueCharPartTwo False" << std::endl;
    }

    std::string try1 = "listen";
    std::string try2 = "silent";

    bool result3 = Anagrams(try1, try2);
    if(result3 == true)
    {
        std::cout << "True Anagrams test1" << std::endl;
    }
    else
    {
        std::cout << "False Anagrams test1" << std::endl;
    }


    std::string try3 = "Hello";
    std::string try4 = "Hallo";

    bool result4 = Anagrams(try3, try4);
    if(result4 == true)
    {
        std::cout << "True Anagrams test2" << std::endl;
    }
    else
    {
        std::cout << "False Anagrams test2" << std::endl;
    }
    
    std::string space = "Carry me";
    std::string space_string = ChangeSpace(space);

    std::cout <<"New string is: " << space_string << std::endl;


    int arr[5][5];
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            arr[i][j] = 1;
        }
    }
    arr[2][3] = 0;
    arr[1][1] = 0;
    RowAndCoulmnZero(arr, 5, 5);

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }


    std::string sub = "Hello";
    std::string full = "oWhat Hell";

    bool rotation_status = IsRotation(sub, full);
    if(rotation_status == true)
    {
        std::cout << "True IsRotation test" << std::endl;
    }
    else
    {
        std::cout << "False IsRotation test" << std::endl;
    }


    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

/*
  13 9  5 1
  14 10 6 2
  15 11 7 3
  16 12 8 4
*/
    RotateMatrix(matrix);

    // Print the rotated matrix
    for (const auto& row : matrix) 
    {
        for (int value : row) 
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

