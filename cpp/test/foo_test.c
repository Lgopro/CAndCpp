
#include <stdio.h>
#include <dlfcn.h>

#include "foo.h"

typedef void(*func)(void);

int main(int argc, char *argv[]) 
{

    
    func function = NULL;
	void *handle = NULL;
    if(argc < 3)
    {
        return 1;
    }
    handle = dlopen(argv[1], RTLD_LAZY);
   
    *(void **)&function = dlsym(handle, argv[2]);

    function();

    dlclose(handle);
   
    return 0;
}