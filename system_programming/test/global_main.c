#include <stdio.h>
#include <dlfcn.h>
#include "globalextern.h"



void Case1();
void Case2();

int main()
{
	
	Case1();
	Case2();
	
	return 0;
  
}



void Case1()
{

	void *handle2 = NULL;
    
	void *handle = NULL;
	
	void (*foo)();
	void (*foo2)();
	printf("One close other open\n");
    handle = dlopen("libglobal1.so", RTLD_LAZY);
    if(NULL == handle)
    {
    	return ;
    }
    *(void **)(&foo) = dlsym(handle, "Foo");
   	if(NULL ==  *(void **)(&foo))
   	{
   		return ;
   	}
    foo();
   
    dlclose(handle);
   
   
    handle2 = dlopen("libglobal2.so", RTLD_LAZY);
   	if(NULL == handle2)
    {
    	return ;
    }
    *(void **)(&foo2) = dlsym(handle2, "Foo2");
    if(NULL ==  *(void **)(&foo2))
   	{
   		return;
   	}
    foo2();
   
    
    dlclose(handle2);



}
void Case2()
{

	void *handle2 = NULL;
    
	void *handle = NULL;
	
	void (*foo)();
	void (*foo2)();
	printf("Two open\n");
    handle = dlopen("libglobal1.so", RTLD_LAZY);
    if(NULL == handle)
    {
    	return ;
    }
    *(void **)(&foo) = dlsym(handle, "Foo");
   	if(NULL ==  *(void **)(&foo))
   	{
   		return ;
   	}
    foo();
   
    
   
   
    handle2 = dlopen("libglobal2.so", RTLD_LAZY);
   	if(NULL == handle2)
    {
    	return ;
    }
    *(void **)(&foo2) = dlsym(handle2, "Foo2");
    if(NULL ==  *(void **)(&foo2))
   	{
   		return ;
   	}
    foo2();
   
    dlclose(handle);
    dlclose(handle2);

}
