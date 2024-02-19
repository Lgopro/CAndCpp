#include <stdio.h> /*printf*/
#include <stdlib.h>



static void foo1()
{
	static int g5 ;
	int l1 = 9;

}


static void foo2()
{
	static int g6 = 0;
	static int g7 = 7;
	void *p = malloc(10);
	free(p);
	p = 0;
}

extern void bar();


int main()
{	
	int g1;
	static int g2;
	static int g3 = 0;
	static int g4 = 8;
	foo1();
	foo2();
	return 0;
}
