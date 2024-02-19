


#include <stdio.h>
#include <dlfcn.h>


typedef void(*func)(void);

int main() 
{

    void *handle2 = NULL;
    func foo2 = NULL;
	void *handle = NULL;
	func foo = NULL;
	
    handle = dlopen("libglobal1.so", RTLD_LAZY);
   
    foo = (func)dlsym(handle, "Foo");
   
    foo();
   
    dlclose(handle);
   
   
   
    handle2 = dlopen("libglobal2.so", RTLD_LAZY);
   
    foo2 = (func)dlsym(handle, "Foo2");
   
    foo2();
   
    dlclose(handle2);
   
    return 0;
}
