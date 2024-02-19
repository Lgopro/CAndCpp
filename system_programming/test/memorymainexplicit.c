#include <stdio.h>
#include <dlfcn.h>
#include "MemoryMappingFull.h"



int main() 
{

    
	void *handle = NULL;
	
	void (*Func)();
	
    handle = dlopen("libmemory.so", RTLD_LAZY);
    if(NULL == handle)
    {
    	return 1;
    }
    *(void **)(&Func) = dlsym(handle, "Func");
   	if(NULL ==  *(void **)(&Func))
   	{
   		return 1;
   	}
    Func();
   
    dlclose(handle);
   
    return 0;
}







