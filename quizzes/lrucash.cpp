
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

const size_t MAX = 18446744073709551615UL;

namespace ilrd
{
template <typename KEY, typename VALUE>
class LRU
{
    public:

    LRU(size_t capacity);
    ~LRU() = default;
    
    void Put(KEY &key, VALUE &value);
    VALUE Get(KEY &key);

    private:

    size_t m_capacity;
    
    std::unordered_map<KEY , std::pair<VALUE, size_t>> m_cache;

    LRU(const LRU& other) = delete;
    LRU& operator=(const LRU& other) = delete; 

};
}

using namespace ilrd;


template <typename KEY, typename VALUE>
LRU<KEY, VALUE>::LRU(size_t capacity):m_capacity(capacity)
{
}

template <typename KEY, typename VALUE>
void LRU<KEY, VALUE>::Put(KEY &key, VALUE &value)
{
    size_t counter = MAX;
    KEY delete_key;
    if(m_cache.size() == m_capacity)
    {
        auto var = m_cache.begin();
        while(var != m_cache.end())
        {
            if(var->second.second < counter)
            {
                counter = var->second.second;
                delete_key = var->first;
            }
            ++var;
        }

        m_cache.erase(delete_key);

        m_cache[key] = std::make_pair(value, 1);
        return;
    }

    if(m_cache.end() == m_cache.find(key))
    {
        m_cache[key].first = VALUE;
        m_cache[key].second = 1;  
    }
    else
    {
        ++m_cache[key].second;
    }

}

template <typename KEY, typename VALUE>
VALUE LRU<KEY, VALUE>::Get(KEY &key)
{
    if(m_cache.end() != m_cache.find(key))
    {
        return m_cache[key].first;
    }
    else
    {
        throw std::runtime_error("Wrong Key");
    }
}