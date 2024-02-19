

#include <string.h>
#include <stdio.h>
#include <assert.h>


void GenericSwap(void *var1, void *var2, size_t size_of_element);


int main()
{	
	char arr2[] = "Hello";
	char arr1[20];
	GenericSwap(arr1, arr2, strlen(arr2));
	printf("%s\n" , arr1);
	return 0;
}






void GenericSwap(void *var1, void *var2, size_t size_of_element)
{
	size_t i = 0;
	char temp = 0;
	assert(var1);
	assert(var2);
	assert(0 < size_of_element);
	while(i < size_of_element)
	{
		temp = *(((char *)var1) + i);
		*(((char *)var1) + i) = *(((char *)var2) +i);
		*(((char *)var2) +i) = temp;
		++i;
	}
}
