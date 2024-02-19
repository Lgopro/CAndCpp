#include <vector>
#include <iostream>
#include <algorithm>

int Data();
int Get();


int main()
{
    int a = 5;
    int b = 6;

    std::vector <int> m_vector = {1, 5, 9, 3, 4};

    std::for_each(m_vector.begin(), m_vector.end(), [=](int value){if (a == value)
    {
        std::cout << "the value of this is: " << a << std::endl;
    }
    });

    Data();
    std::cout << "The value is: " << Get() << std::endl;

}

int Data()
{
    int a = 5;
    int b = 6;

    std::vector<int> m_vector = {1, 5, 9, 3, 4};

    int result = -1; // Default value

    auto lambda = [=](int value) -> int {
        if (a == value)
        {
            return value;
        }
        return -1; 
    };
    auto iter = m_vector.begin();
    while(iter != m_vector.end())
    {
        result = lambda(*iter); // Call the lambda and store the result in 'result'
        std::cout << "The result is: " << result << std::endl;
        ++iter;
    }
    
    return result;
}



int Get()
{
    std::vector <int> m_var = {1,5,3,7,8,4,3};
    int a = 8;
    int b = 3;
    auto lambda = [&](int value){
        if(value == a)
        {
            std::cout << "here " << a << " ";
            return 1;
        }
        return 0;
    };

    return lambda(8);
}