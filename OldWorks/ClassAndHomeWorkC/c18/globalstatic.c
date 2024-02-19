#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gi;
int gj=0;
int gk=5;
static int si;
static int sj=0;
static int sk=5;



int main()
{
	int bi;
	static int sl;
	static int sm=5;
	char *str="abc";
	printf("%p\n", (void*)&gi);
	printf("%p\n", (void*)&gj);
	printf("%p\n",(void*) &gk);
	printf("%p\n", (void*)&si);
	printf("%p\n",(void*) &sj);
	printf("%p\n", (void*)&sk);
	printf("%p\n", (void*)&bi);
	printf("%p\n", (void*)&sl);
	printf("%p\n", (void*)&sm);
	printf("%p\n", (void*)str);
	return 0;
}
