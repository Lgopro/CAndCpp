#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/

#define OFFSETOF(STRUCT, ELEMENT) ((size_t)&(((STRUCT *)0)->ELEMENT))

struct Try
{
	char arr[50];
	char arr1[40];
	int hello;
	char arr2[30];

};

int main()
{
	
	printf("It is in: %ld\n", OFFSETOF(struct Try, arr));
	printf("It is in: %ld\n", OFFSETOF(struct Try, arr1));
	printf("It is in: %ld\n", OFFSETOF(struct Try, arr2));
	
	
	return 0;
}


