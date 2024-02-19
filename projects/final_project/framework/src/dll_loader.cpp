/*
Rev: Ido Issacs.
Dev: Leonid Golovko
status: finished
date: 28/09/2023
*/
#include "dll_loader.hpp"


using namespace ilrd;

void DllLoader::Load(const std::string& filename)
{
    GenericLoad(filename);
}



void *DllLoader::GenericLoad(const std::string& filename)
{
    
    void * m_handle = dlopen(filename.c_str(), RTLD_LAZY);
    if(NULL == m_handle)
    {
        throw std::runtime_error("dlopen problem");
    }
    return m_handle;
}


