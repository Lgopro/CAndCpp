#include <stdio.h> /*printf*/

struct point
{
	int x;
	int y;
};

int main()
{	
	struct point p = {1, 2};
	int n = *(int *)&p;
	printf("%d",n);
	return 0;
}


