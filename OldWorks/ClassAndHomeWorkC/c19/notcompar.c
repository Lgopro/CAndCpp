#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int _a, int _b);

int main()
{
	Max(5,3);

	return 0;
}

int Max(int _a, int _b)
{
	int c = _a - _b;
	c = c >>(sizeof(int)-1) & 1;
	return a*(1-c)+b*c;





}
