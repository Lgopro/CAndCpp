
#ifndef __FRAMEWORK_HPP__
#define __FRAMEWORK_HPP__

#include "input_mediator.hpp"

#include <functional>
#include <iostream>

namespace ilrd
{
    class Framework
    {
        public:

        Framework() = default;
        ~Framework() = default;
        Framework& operator=(const Framework& other) = default;
        Framework(const Framework& other) = default;

        
        void Run();
        void Stop();
        void RegisterAll(std::vector<std::pair<int, int>>& fds, IProxy* proxy);

        private:
        InputMediator m_input_mediator;
    };
};


#endif