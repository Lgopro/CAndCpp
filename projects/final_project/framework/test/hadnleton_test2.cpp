/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 21/09/2023
*/

#define __ILRD_CREATOR__
#include <iostream>
#include <dlfcn.h>
#include "handleton.hpp"


int main()
{
	void *handle = NULL;
	
	void (*foo)();

    handle = dlopen("library2.so", RTLD_LAZY);
    if(NULL == handle)
    {
        std::cout << "fail1" << std::endl;
    	return 1;
    }
    *(void **)(&foo) = dlsym(handle, "bar");
   	if(NULL ==  *(void **)(&foo))
   	{
        std::cout << "fail2" << std::endl;
   		return 1;
   	}
    foo();
    dlclose(handle);

    void *handle2 = NULL;
	
	void (*foo2)();

    handle2 = dlopen("library3.so", RTLD_LAZY);
    if(NULL == handle2)
    {
        std::cout << "fail3" << std::endl;
    	return 1;
    }
    *(void **)(&foo2) = dlsym(handle2, "foo");
   	if(NULL ==  *(void **)(&foo2))
   	{
        std::cout << "fail3" << std::endl;
   		return 1;
   	}
    
    foo2();
    dlclose(handle2);
}



