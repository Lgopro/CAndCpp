#include <iostream>
#include <dlfcn.h>
using namespace std;


typedef void(*func)(void);

int main() 
{
    func function = NULL;
	void *handle = NULL;
   
    handle = dlopen("./libcpp12work.so", RTLD_LAZY);
   
    *(void **)&function = dlsym(handle, "_Z3Foov");

    function();

    dlclose(handle);
   
    return 0;
}
