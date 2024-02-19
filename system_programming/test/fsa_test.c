/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date: 23.05.2023
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/


#include "fsa.h"


void FSASuggestSizeTest();
void FSAInitTest();
void FSAAllocTest();
void FSAFreeTest();
void FSACountFreeTree();


int main()
{	
	FSASuggestSizeTest();
	FSAInitTest();
	FSAAllocTest();
	FSAFreeTest();
	FSACountFreeTree();
	return 0;
}





void FSASuggestSizeTest()
{

	char *allocated = (char *)malloc(sizeof(char) * FSASuggestSize(5, 25));
	char *allocated2 = (char *)malloc(sizeof(char) * FSASuggestSize(3, 2));
	
	size_t size_of_allocated = FSASuggestSize(5, 25);
	size_t size_of_allocated2 = FSASuggestSize(3, 2);
	
	if( 32 * 5 + 8 == size_of_allocated && 3 * 8 + 8 == size_of_allocated2)
	{
		printf("FSASuggestSizeTest pass\n");
		
	}
	else
	{
		printf("FSASuggestSizeTest fail\n");
		printf("Size1 %ld\n", size_of_allocated);
		printf("Size1 %ld\n", size_of_allocated2);
	}
	
	free(allocated);
	free(allocated2);
}



void FSAInitTest()
{
	
	char *allocated = (char *)malloc(sizeof(char) * FSASuggestSize(5, 25));
	
	FSAInit((void *)allocated, FSASuggestSize(5, 25), 25);
	
	
	
	if(8 == *(size_t *)allocated && 40 == *(size_t *)(allocated + 8) && 72 == *(size_t *)(allocated + 40))
	{
		printf("FSAInitTest pass\n");
		
	}
	else
	{
		printf("FSASuggestSizeTest fail\n");
		printf("location1 = %ld\n", *(size_t *)allocated);
		printf("location2 = %ld\n", *(size_t *)((char *)allocated + 8));
		printf("location2 = %ld\n", *(size_t *)((char *)allocated + 40));
	}
	
	free(allocated);
	


}




void FSAAllocTest()
{
	void *data1 = NULL;
	void *data2 = NULL;
	void *data3 = NULL;
	char *allocated = (char *)malloc(sizeof(char) * FSASuggestSize(5, 25));
	
	FSAInit((void *)allocated, FSASuggestSize(5, 25), 25);
	
	data1 = FSAAlloc((fsa_t *)allocated);
	data2 = FSAAlloc((fsa_t *)allocated);
	data3 = FSAAlloc((fsa_t *)allocated);
	
	if(*(size_t *)data1 == *(size_t *)(allocated + 40) && *(size_t *)data2 == *(size_t *)(allocated + 72) && *(size_t *)data3 == *(size_t *)(allocated + 104) && 104 == *(size_t *)allocated)
	{
		printf("FSAInitTest pass\n");
		
	}
	else
	{
		printf("FSAAllocTest fail\n");
		printf("location = %ld\n", *(size_t *)allocated);
		
		printf("allocated + 40 = %ld\n", *(size_t *)(allocated + 40));
		printf("data1 = %ld\n", *(size_t *)data1);
		printf("allocated + 72 = %ld\n", *(size_t *)(allocated + 72));
		printf("data2 = %ld\n", *(size_t *)data2);
		printf("allocated + 104 = %ld\n", *(size_t *)(allocated + 104));
		printf("data3 = %ld\n", *(size_t *)data3);
		
	}
	
	free(allocated);
}




void FSAFreeTest()
{

	
	
	void *data2 = NULL;
	
	char *allocated = (char *)malloc(sizeof(char) * FSASuggestSize(5, 25));
	
	FSAInit((void *)allocated, FSASuggestSize(5, 25), 25);
	
	FSAAlloc((fsa_t *)allocated);
	data2 = FSAAlloc((fsa_t *)allocated);
	FSAAlloc((fsa_t *)allocated);
	FSAFree((fsa_t *)allocated, data2);
	
	
	
	if(72 == *(size_t *)allocated && 104 == *(size_t *)(allocated + 72))
	{
		printf("FSAFreeTest pass\n");
		
	}
	else
	{
		printf("FSAFreeTest fail\n");
		printf("location = %ld\n", *(size_t *)allocated);
		
		printf("allocated + 72 = %ld\n", *(size_t *)(allocated + 72));
	}
	
	free(allocated);
}


void FSACountFreeTree()
{

	
	void *data2 = NULL;
	
	char *allocated = (char *)malloc(sizeof(char) * FSASuggestSize(5, 25));
	
	FSAInit((void *)allocated, FSASuggestSize(5, 25), 25);
	
	FSAAlloc((fsa_t *)allocated);
	data2 = FSAAlloc((fsa_t *)allocated);
	FSAAlloc((fsa_t *)allocated);
	FSAFree((fsa_t *)allocated, data2);
	
	
	
	if((FSASuggestSize(5, 25) - 8 - 32 - 32)/32 == FSACountFree((const fsa_t *)allocated))
	{
		printf("FSACountFreeTree pass\n");
		
	}
	else
	{
		printf("FSACountFreeTree fail\n");
		printf("FSACountFree = %ld\n", FSACountFree((const fsa_t *)allocated));
		
		printf("FSACountFree = %ld\n", FSACountFree((const fsa_t *)allocated));
	}
	
	free(allocated);








}
