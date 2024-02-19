#include <dlfcn.h>
#include <stddef.h>
#include "MemoryMappingFull.h"

int main(int argc, char *argv[], char *envp[])
{
    void *explicit_lib = NULL;
	void (*FuncExplicit)();
    
    FuncStatic(); 
    FuncImplicit();
    
    explicit_lib = dlopen("libmemorymappingfullexplicit.so", RTLD_NOW);
	*(void**)(&FuncExplicit) = dlsym(explicit_lib, "FuncExplicit");
	
	FuncExplicit();
	
	dlclose(explicit_lib);

    return (0);
}
