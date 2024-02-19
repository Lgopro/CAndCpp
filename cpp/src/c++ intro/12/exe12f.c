#include <stdio.h>
#include <dlfcn.h>


typedef void(*func)(void);

int main() 
{
    func function = NULL;
	void *handle = NULL;
   
    handle = dlopen("libfooexe12noh.so", RTLD_LAZY);
   
    *(void **)&function = dlsym(handle, "Foo");

    function();

    dlclose(handle);
   
    return 0;
}
