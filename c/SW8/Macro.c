/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:04/04/23
*/



#include <stdio.h> /*printf*/
#define MAX2(a,b) ((a > b) ? a : b)
#define MAX3(a,b,c) ((a > b && a > c) ? a : (b > c) ? b : c)
#define SIZEOF_VAR(var) ((size_t)(&var + 1) - (size_t)(&var))
#define SIZEOF_TYPE(type) ((size_t)((type *)0 + 1))


void Max2Check();
void Max3Check();
void SizeOfVar();
void SizeOfType();


int main()
{	
	Max2Check();
	Max3Check();
	SizeOfVar();
	SizeOfType();
	return 0;
}


void SizeOfType()
{

	if(4 == SIZEOF_TYPE(int) && 2 == SIZEOF_TYPE(short) && 4 == SIZEOF_TYPE(float) && 1 == SIZEOF_TYPE(char))
	{
		printf("Test type pass\n");
	
	}
}
void SizeOfVar()
{
	int i = 5;
	char a = 'a';
	short b = 2;
	long c = 4;
	int result = 0;
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	result = SIZEOF_VAR(i);
	result1 = SIZEOF_VAR(a);
	result2 = SIZEOF_VAR(b);
	result3 = SIZEOF_VAR(c);
	if(4 == result && 1 == result1 && 2 == result2 && 8 == result3)
	{
		printf("Test VAR pass\n");	
	
	}


}

void Max2Check()
{
	int x = 1;
	int y = 2;
	int a = 5;
	int result = 0;
	int result1 = 0;
	result = MAX2(x, y);
	result1 = MAX2(a, y);
	if(2 == result && 5 == result1)
	{
		printf("Test Max2 pass\n");	
	
	}


}

void Max3Check()
{
	int x = 1;
	int y = 2;
	int a = 5;
	int result = 0;
	int result1 = 0;
	int result2 = 0;
	result = MAX3(x, a, y);
	result1 = MAX3(y, x, a);
	result2 = MAX3(a, x, y);
	if(5 == result && 5 == result1 && 5 == result2)
	{
		printf("Test Max3 pass\n");	
	
	}


}
