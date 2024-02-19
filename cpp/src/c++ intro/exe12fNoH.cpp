#include <iostream>
#include <dlfcn.h>
using namespace std;


typedef void(*func)(void);

int main() 
{
    func function = NULL;
	void *handle = NULL;
   
    handle = dlopen("libfooexe12.so", RTLD_LAZY);
   
    *(void **)&function = dlsym(handle, "Foo");

    function();

    dlclose(handle);
   
    return 0;
}