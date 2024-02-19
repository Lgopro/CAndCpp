#include <list>
#include <utility> // For std::pair
#include <iostream>

namespace ilrd
{
    template <typename T, typename KEY>
    class HashTable
    {
        public:

        HashTable() = default;
        ~HashTable() = default;
        HashTable(const HashTable& other) = default;
        HashTable& operator=(const HashTable& other) = default;

        struct EnterValue
        {
            KEY m_key;
            T m_value; 
        };
        
        void Push(EnterValue value);
        T GetData(KEY value);

        private:

        std::list<std::pair<KEY, T>> m_list;
    };
}



using namespace ilrd;

template <typename T, typename KEY>
void HashTable<T,KEY>::Push(EnterValue value)
{
    m_list.push_back(std::make_pair(value.m_key, value.m_value));
}

template <typename T, typename KEY>
T HashTable<T,KEY>::GetData(KEY value)
{
    for(const auto&var : m_list)
    {
        if(var.first == value)
        {
            return var.second;
        }
    }
    throw std::runtime_error("Not found");
}


int main()
{
    HashTable<int, int> table;

    ilrd::HashTable<int, int>::EnterValue value1 = {1, 3};
    ilrd::HashTable<int, int>::EnterValue value2 = {3, 5};

    table.Push(value1);
    table.Push(value2);

    int data = table.GetData(1);

    std::cout << "The data is: " << data << std::endl;

    int data1 = table.GetData(3);

    std::cout << "The data is: " << data1 << std::endl;

    int data2 = table.GetData(2);

    std::cout << "The data is: " << data2 << std::endl;

    return 0;
}