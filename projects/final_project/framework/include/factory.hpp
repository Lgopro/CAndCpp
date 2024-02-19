/*
Rev: Yarone Margalit.
Dev: Leonid Golovko
status: finished
date: 15/09/2023
*/
#ifndef __Factory_HPP__
#define __Factory_HPP__

#include <iostream>
#include <functional>
#include <unordered_map>

namespace ilrd
{
    template <typename KEY,typename BASE, typename ...ARG>
    class Factory
    {
        public:

        Factory() = default;
        ~Factory() = default;
        Factory& operator=(const Factory& other) = default;
        Factory(const Factory& other) = default;
        //Description: Add a funtion to the hash map with unlimited amount of arguments.
        //Input variables: key value of hash map, function with N amount of arguments and BASE return value.
        //Return variables: void.
        //Time complexity: O(1).
        //Space complexity: O(1).
        void Register(KEY key, std::function<BASE(ARG...)> func);
        //Description: According to the arguments and key entered returns a BASE.
        //Input variables: key value of hash map, N arguments.
        //Return variables: BASE.
        //Time complexity: O(1).
        //Space complexity: O(1).
        BASE Create(KEY key, ARG... arg);

        private:
        std::unordered_map<KEY, std::function<BASE(ARG...)>> m_map;
    };

    template <typename KEY,typename BASE, typename ...ARG>
    void Factory<KEY, BASE, ARG...>::Register(KEY key, std::function<BASE(ARG...)> func)
    {
        m_map[key] = func;
    }

    template <typename KEY,typename BASE, typename ...ARG>
    BASE Factory<KEY, BASE, ARG...>::Create(KEY key, ARG... arg)
    {
        BASE return_value;
        try
        {
            return_value = m_map[key](arg...);
        }
        catch (const std::exception& ex) 
        {
            std::cerr << "Exception caught: " << ex.what() << std::endl;
        }
        return return_value;
    }
}


#endif