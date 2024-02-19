/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 03/05/2023
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/


#include "cbuffer.h"

void CBuffWriteTest();
void CBCreateTest();
void CBuffReadTest();

struct CBuff
{
	size_t capacity;
	size_t start;
	size_t end;
	char buffer[1];
};



int main()
{	
	CBCreateTest();
	CBuffWriteTest();
	CBuffReadTest();
	return 0;
}

void CBuffReadTest()
{
	char *word = "hello world";
	
	ssize_t status4 = 0;
	ssize_t status5 = 0;
	ssize_t status6 = 0;
	
	size_t status = 0;
	size_t free_space = 0;
	size_t free_space1 = 0;
	cbuff_t *cbuffer = CBuffCreate(15);
	char *reader = (char *)malloc(15);
	char *reader1 = (char *)malloc(15);
	char *reader2 = (char *)malloc(15);
	
	
	
	CBuffWrite(cbuffer, (const void *)word, 11);
	
	CBuffWrite(cbuffer, (const void *)word, 11);
	CBuffWrite(cbuffer, (const void *)word, 11);
	
	status4 = CBuffRead(cbuffer, (void *)reader, 11);
	free_space1 = CBuffFreeSpace((const cbuff_t *)cbuffer);
	status5 = CBuffRead(cbuffer, (void *)reader1, 11);
	free_space = CBuffFreeSpace((const cbuff_t *)cbuffer);
	status6 = CBuffRead(cbuffer, (void *)reader2, 11);
	status = CBuffIsEmpty((const cbuff_t *)cbuffer);
	if(11 == status4 && 4 == status5 && -1 == status6 && 1 == status && 11 == free_space1 && 15 == free_space)
	{
		printf("CBuffReadTest pass\n");
	}
	else
	{
		printf("CBuffReadTest fail\n");
		printf("status4 is %ld\n",  status4);
		printf("status5 is %ld\n",  status5);
		printf("status6 is %ld\n",  status6);
		printf("status is %ld\n",  status);
		printf("free_space1 is %ld\n", free_space1);
		printf("free_space is %ld\n", free_space);
		printf("char is %c\n", *(cbuffer->buffer + cbuffer->capacity));
	}
	
	free(reader);
	free(reader1);
	free(reader2);
	CBuffDestroy(cbuffer);

}

void CBuffWriteTest()
{
	char *word = "hello world";
	ssize_t status1 = 0;
	ssize_t status2 = 0;
	ssize_t status3 = 0;
	size_t capacity = 0;
	size_t status = 0;
	size_t free_space = 0;
	size_t free_space1 = 0;
	cbuff_t *cbuffer = CBuffCreate(15);
	
	status1 = CBuffWrite(cbuffer, (const void *)word, 11);
	free_space1 = CBuffFreeSpace((const cbuff_t *)cbuffer);
	status2 = CBuffWrite(cbuffer, (const void *)word, 11);
	status3 = CBuffWrite(cbuffer, (const void *)word, 11);
	capacity = CBuffCapacity((const cbuff_t *)cbuffer);
	status = CBuffIsEmpty((const cbuff_t *)cbuffer);
	free_space = CBuffFreeSpace((const cbuff_t *)cbuffer);
	if(11 == status1 && 4 == status2 && -1 == status3 && 15 == capacity && 0 == status && 0 == free_space && 4 == free_space1)
	{
		printf("CBuffWriteTest pass\n");
		printf("CBuffFreeSpaceTest pass\n");
		printf("CBuffCapacityTest pass\n");
		printf("CBuffIsEmptyTest pass\n");
		
		
	}
	else
	{
	
		printf("CBuffWriteTest fail\n");
		printf("CBuffFreeSpaceTest pass\n");
		printf("CBuffCapacityTest pass\n");
		printf("CBuffIsEmptyTest pass\n");
		
		printf("result is %ld\n",  status1);
		printf("capacity is %ld\n",  capacity);
		printf("status is %ld\n",  status);
		printf("free_space is %ld\n", free_space);
		printf("char is %c\n", *(cbuffer->buffer + cbuffer->capacity));
		
	}

	CBuffDestroy(cbuffer);

}



void CBCreateTest()
{
	
	size_t capacity = 0;
	size_t status = 0;
	size_t free_space = 0;
	cbuff_t *cbuffer = CBuffCreate(100);
	
	capacity = CBuffCapacity((const cbuff_t *)cbuffer);
	status = CBuffIsEmpty((const cbuff_t *)cbuffer);
	free_space = CBuffFreeSpace((const cbuff_t *)cbuffer);
	
	if(100 == capacity && 1 == status && 100 == free_space)
	{
		printf("CBCreateTest pass\n");
	}
	else
	{

		printf("CBCreateTest fail\n");
	}
	CBuffDestroy(cbuffer);
}
