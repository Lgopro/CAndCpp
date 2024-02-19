#include <stdio.h>
#include <dlfcn.h>
#include "globalextern.h"





int main()
{
	
	Foo();
	Foo2();
	PrintGlobalVariableAdress();
	
	return 0;
  
}
