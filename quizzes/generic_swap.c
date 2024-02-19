


#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct test
{	
	int a;
	short b;
	float c;

}test_t;
void GenericSwap(char *var1, char *var2, size_t size_of_element);


int main()
{	
	test_t test1 = {0};
	test_t test2 = {0};
	test1.a = 2;
	test1.b = 9;
	test1.c = 10;
	test2.a = 8;
	test2.b = 5;
	test2.c = 99;

	GenericSwap((char *)&test1, (char *)&test2, sizeof(test_t));
	printf("%d\n" , test1.a);
	printf("%d\n" , test1.b);
	printf("%f\n" , test1.c);
	return 0;
}


void Swap(char *var1, char *var2)
{
	char temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}



void GenericSwap(char *var1, char *var2, size_t size_of_element)
{
	size_t i = 0;
	char *iter_var1 = NULL;
	char *iter_var2 = NULL;

	assert(var1);
	assert(var2);
	assert(0 < size_of_element);

	iter_var1 = var1;
	iter_var2 = var2;

	while(i < size_of_element)
	{
		Swap(iter_var1, iter_var2);
		++iter_var1;
		++iter_var2;
		++i;
	}
}
