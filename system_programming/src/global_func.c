

#include <stdio.h>
#include "globalextern.h"

int x = 5;

void PrintGlobalVariableAdress()
{
	

	printf("The adress is %p\n", (void *)&x);

}
