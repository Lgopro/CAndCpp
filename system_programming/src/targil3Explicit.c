

#include <stdio.h>
#include <dlfcn.h>


typedef void(*func)(int);

int main(int argc, char **argv) 
{
   void *handle = dlopen("libfoo.so", RTLD_LAZY);
   
   func foo = (func)dlsym(handle, "Foo");
   
   foo(50);
   
   dlclose(handle);
   
   return 0;
}
