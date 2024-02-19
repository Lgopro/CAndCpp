#include <stdio.h> /*printf*/
#include <stdlib.h>

#ifndef DEBUG
#error "Only Debug builds are supported"
#endif




void foo();

int main()
{	
	foo();
	return 0;
}

void foo()
{

	printf("Hallo\n");
	
}
