#include <stdio.h>
#include <dlfcn.h>


typedef void(*func)(void);

int main() 
{
    func function = NULL;
	void *handle = NULL;
   
    handle = dlopen("./libfooexe12.so", RTLD_LAZY);
    if(NULL == handle)
    {
        printf("Im done\n");
    }
    *(void **)&function = dlsym(handle, "Foo");

    function();

    dlclose(handle);
   
    return 0;
}