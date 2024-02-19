


#include "exe46.hpp"

namespace ilrd
{
    template <typename T>
    Square<T>::Square(T length) : length(length)
    {

    }
   
}




int main()
{
    int result = 0;
    ilrd::Square<int> sq(3);
    result = sq.GetT();
    std::cout << result << std::endl;
    return 0;

}