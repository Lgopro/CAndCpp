#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> sequences;

    std::vector<int> arr1 = {1, 2, 3, 6, 7};
    std::vector<int> arr2 = {3, 4, 5, 4};
    std::vector<int> arr3 = {5, 6, 7};

    sequences.push_back(arr1);
    sequences.push_back(arr2);
    sequences.push_back(arr3);

    for (auto &iter : sequences)
    {
        std::cout << "Array size: " << iter.size() << std::endl;
        for (auto &elem : iter)
        {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
