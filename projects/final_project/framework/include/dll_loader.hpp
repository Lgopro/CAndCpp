/*
Rev: Ido Issacs.
Dev: Leonid Golovko
status: finished
date: 28/09/2023
*/
#include "dispatcher.hpp"
#include <vector>
#include <dlfcn.h>

#ifndef __DLLLOADER_HPP__
#define __DLLLOADER_HPP__

namespace ilrd
{
    class DllLoader
    {
    public:
        DllLoader() = default;
        ~DllLoader()noexcept = default;

        DllLoader(const DllLoader &other) = default;
        DllLoader &operator=(const DllLoader &other) = default;

        //Description: Load a DLL. Call the GenericLoad function.
        //Input variables: name of DLL
        //Return variables: void.
        //Time complexity: O(1).
        //Space complexity: O(1).
        void Load(const std::string& filename); 

        //Description: Load a DLL.
        //Input variables: name of DLL
        //Return variables: void.
        //Time complexity: O(1).
        //Space complexity: O(1).
        void *GenericLoad(const std::string& filename);


    };
}

#endif