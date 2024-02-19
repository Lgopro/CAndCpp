#include <stdio.h>
#include <string.h>


/*void Foo(int *ap,int *bp);*/

int main()
{
	/*int a = 4, b = 5;
	long c = 0;
	c + 5;
	(short *)c + 5;
	++(long **)&c;
	Foo(&a , &b);*/
	/*int i = 2;
	float f = 3.7;
	i + f;
	(float)i + f;
	*(float *)&i + f;*/
	double d = 5;
	float f = 8 / 6;
	int i = 12;
	unsigned int ui = 2;
	i = d / f + i * (ui - i) + ((float *)&d - &f);
	printf("%d", i);
	return 0;
}





/*void Foo(int *ap,int *bp)
{

	int a;
	int b; a = ++*ap; b = ++*bp;
	return;




}*/
