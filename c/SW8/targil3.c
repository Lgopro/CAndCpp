#include <stdio.h> /*printf*/

struct X
{
	int x;
	char c;
	double d;
	short s;
};

union numbers
{
	int i;
	float f;
	double d;
};

struct card
{
	unsigned int suit: 2;
	unsigned int face_value: 4;
};

int main()
{	
	struct X p;
	union numbers num;
	struct card cr;
	printf("size of struct X is %ld\n",sizeof(p));
	printf("size of union numbers is %ld\n",sizeof(num));
	printf("size of struct card is %ld\n",sizeof(cr));
	return 0;
}

