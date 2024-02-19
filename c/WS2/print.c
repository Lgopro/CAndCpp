#include <stdio.h>
#include <stdlib.h>


int main()
{
	static int s_i = 7;
	int i = 7;
	int *ptr = &i;
	int **ptr3;
	int *ptr2 = (int*)malloc(sizeof(int));
	int* p = (int*)17;
	size_t ii = 3;
	size_t array[] = {0, 1, 2, 3, 4, 5};
	printf("%lu\n", ii[array]);
	printf("%lu\n", array[ii]);
	printf("%lu\n", *(array + ii));
	printf("%lu\n", *(ii + array));
	printf("%lu\n", ((size_t)3)[array]);
	
	printf("%d\n", (int)(long)(p+4));
	
	printf("The static var adress is: %p\n", (void*)&s_i);
	printf("The int var adress is: %p\n", (void*)&i);
	printf("The ptr var adress is: %p\n", (void*)ptr);
	printf("The ptr2 var adress is: %p\n", (void*)ptr2);
	
	if(ptr)
	{
	
		 ptr3 = &ptr;
	
	}
	
	printf("The ptr3 var adress is: %p\n", (void*)*ptr3);
	free(ptr2);
	
	
	
	return 0;
}
