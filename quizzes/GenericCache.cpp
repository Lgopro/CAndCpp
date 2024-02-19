#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

namespace ilrd
{
    template <typename KEY, typename VALUE>
    class GenericCache
    {
        public:
        GenericCache(size_t capacity = 5);
        ~GenericCache() = default;


        struct ValueAndAmount
        {
            VALUE m_value;
            size_t m_amount;
        };


        void Input(const KEY& key, const ValueAndAmount& value);
        std::pair<bool, VALUE> GetValue(const KEY& key) const;
        bool DoKeyExist(const KEY& key) const;
        void PrintAll() const;

        private:

        GenericCache(const GenericCache& other) = delete;
        GenericCache& operator=(const GenericCache& other) = delete;

        std::list<std::pair<KEY, ValueAndAmount>> m_list;
        size_t m_capacity;
        size_t m_amount;
    };
}

using namespace ilrd;

template <typename KEY, typename VALUE>
GenericCache<KEY, VALUE>::GenericCache(size_t capacity):m_capacity(capacity), m_amount(0)
{
}

template <typename KEY, typename VALUE>
void GenericCache<KEY, VALUE>::Input(const KEY& key, const ValueAndAmount& value)
{
    ValueAndAmount variable;
    value.m_amount = 1;
    value.m_value = value;
    auto iter = std::find_if(m_list.begin(), m_list.end(), [&key](const auto& pair){return pair.first == key;});
    if(iter == m_list.end())
    {
        m_list.push_front(std::make_pair(key, variable));
    }
    else
    {
        ++iter->second.m_amount;
        iter->second.m_value = value.m_value;
    }
}

template <typename KEY, typename VALUE>     
std::pair<bool, VALUE> GenericCache<KEY, VALUE>::GetValue(const KEY& key) const
{
    auto iter = std::find_if(m_list.begin(), m_list.end(),[&key](const auto& pair){return pair.first == key;});
    if(iter == m_list.end())
    {
        iter = m_list.begin();
        return std::make_pair(false, iter.first.m_value);
    }
    else
    {
        return std::make_pair(true, iter.first.m_value);
    }
}

template <typename KEY, typename VALUE>  
bool GenericCache<KEY, VALUE>::DoKeyExist(const KEY& key) const
{
    auto iter = std::find_if(m_list.begin(), m_list.end(),[&key](const auto& pair){return pair.first == key;});
    if(iter == m_list.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename KEY, typename VALUE>      
void GenericCache<KEY, VALUE>::PrintAll() const
{
    for(auto& iter : m_list)
    {
        std::cout<< "The key is: " << iter.first << " The value is: " << iter.second.m_value << std::endl;
    }
}

int main()
{
    GenericCache<int, int> m_cache;
    ValueAndAmount val1;
    
    m_cache.Input(1,);
    m_cache.PrintAll();



    return 0;
}