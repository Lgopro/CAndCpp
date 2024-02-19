/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 21/09/2023
*/
#include <iostream>
#include <dlfcn.h>
#include "singleton.hpp"

class CheckClass
{
    public:
    void Print(){std::cout << "Addr is: "<< this << std::endl;};
};


int main()
{
	CheckClass *check1 = ilrd::Singleton<CheckClass>::GetInstance();
    check1->Print();
	void *handle = NULL;
	
	void (*foo)();

    handle = dlopen("library1.so", RTLD_LAZY);
    if(NULL == handle)
    {
        std::cout << "fail1" << std::endl;
    	return 1;
    }
    *(void **)(&foo) = dlsym(handle, "foo");
   	if(NULL ==  *(void **)(&foo))
   	{
        std::cout << "fail2" << std::endl;
   		return 1;
   	}
    foo();
   
    dlclose(handle);
}



