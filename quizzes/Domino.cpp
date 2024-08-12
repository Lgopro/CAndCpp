
#include "Domino.hpp"

using namespace ilrd;

void Test1()
{
    std::vector<std::vector<int>> sequences;

    std::vector<int> array1 = {1, 2, 3};
    std::vector<int> array5 = {9, 10, 11};

    sequences.push_back(array1);
    sequences.push_back(array5);

    merge_pairs_only<int>(sequences);
}

void Test2()
{
    std::vector<std::vector<int>> sequences;

    std::vector<int> array1 = {1, 2, 3};
    std::vector<int> array2 = {3, 4, 5};

    sequences.push_back(array1);
    sequences.push_back(array2);

    merge_pairs_only<int>(sequences);
}

void Test3()
{
    std::vector<std::vector<int>> sequences;

    std::vector<int> array1 = {1, 2, 3};
    std::vector<int> array2 = {3, 4, 5};
    std::vector<int> array3 = {55, 6, 2};
    std::vector<int> array4 = {7, 8, 9};
    std::vector<int> array5 = {9, 10, 11};

    sequences.push_back(array1);
    sequences.push_back(array2);
    sequences.push_back(array3);
    sequences.push_back(array4);
    sequences.push_back(array5);

    merge_pairs_only<int>(sequences);
}

void Test4()
{
    std::vector<std::vector<int>> sequences;

    std::vector<int> array1 = {1, 2, 3};
    std::vector<int> array2 = {3, 4, 5};
    std::vector<int> array3 = {5, 6, 7};
    std::vector<int> array4 = {7, 8, 9};
    std::vector<int> array5 = {9, 10, 11};

    sequences.push_back(array1);
    sequences.push_back(array2);
    sequences.push_back(array3);
    sequences.push_back(array4);
    sequences.push_back(array5);

    merge_pairs_only<int>(sequences);
}

void Test5()
{
    std::vector<std::vector<char>> sequences;

    std::vector<char> array1 = {'a', 'b', 'c'};
    std::vector<char> array2 = {'g', 'f', 'g'};
    
    sequences.push_back(array1);
    sequences.push_back(array2);

    merge_pairs_only<char>(sequences);
}

void Test6()
{
    std::vector<std::vector<char>> sequences;

    std::vector<char> array1 = {'a', 'b', 'c'};
    std::vector<char> array2 = {'c', 'd', 'e'};
    
    sequences.push_back(array1);
    sequences.push_back(array2);

    merge_pairs_only<char>(sequences);
}

void Test7()
{
    std::vector<std::vector<char>> sequences;

    std::vector<char> array1 = {'a', 'b', 'c'};
    std::vector<char> array2 = {'c', 'd', 'e'};
    std::vector<char> array3 = {'d', 'o', 'n', 't'};
    std::vector<char> array4 = {'f', 'g', 'h'};
    std::vector<char> array5 = {'i', 'j', 'k'};

    sequences.push_back(array1);
    sequences.push_back(array2);
    sequences.push_back(array3);
    sequences.push_back(array4);
    sequences.push_back(array5);

    merge_pairs_only<char>(sequences);
}

void Test8()
{
    std::vector<std::vector<char>> sequences;

    std::vector<char> array1 = {'a', 'b', 'c'};
    std::vector<char> array2 = {'c', 'd', 'e'};
    std::vector<char> array3 = {'e', 'f'};
    std::vector<char> array4 = {'f', 'g', 'h'};
    std::vector<char> array5 = {'h', 'i', 'j'};

    sequences.push_back(array1);
    sequences.push_back(array2);
    sequences.push_back(array3);
    sequences.push_back(array4);
    sequences.push_back(array5);

    merge_pairs_only<char>(sequences);
}

int main()
{
    std::cout<< "Integer tests" << std::endl;
    std::cout<< "Test1: two pieces that cannot connect" << std::endl;
    Test1();
    std::cout << std::endl;
    std::cout<< "Test2: two pieces that can connect" << std::endl;
    Test2();
    std::cout << std::endl;
    std::cout<< "Test3: five pieces that part of them can connect" << std::endl;
    Test3();
    std::cout << std::endl;
    std::cout<< "Test4: five pieces that can connect" << std::endl;
    Test4();
    std::cout << std::endl;

    std::cout<< "char tests" << std::endl;
    std::cout<< "Test1: two pieces that cannot connect" << std::endl;
    Test5();
    std::cout << std::endl;
    std::cout<< "Test2: two pieces that can connect" << std::endl;
    Test6();
    std::cout << std::endl;
    std::cout<< "Test3: five pieces that part of them can connect" << std::endl;
    Test7();
    std::cout << std::endl;
    std::cout<< "Test4: five pieces that can connect" << std::endl;
    Test8();
    return 0;
}