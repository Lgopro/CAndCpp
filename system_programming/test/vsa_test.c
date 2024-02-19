/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 24.05.23
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/


typedef struct blk_hdr
{
	long size_of_chunk; /*The - say that it is already taken and + say that its free.*/
	
	#ifndef NDEBUG
	long magic_num;
	#endif /*NDEBUG*/
}blk_hdr_t;

#include "vsa.h"

void VSAInitTest();
void VSAAllocTest();
void VSAGetLargestChunkAvailableTest();
void VSAFreeTest();
void DefragmantationTest1();
void DefragmantationTest2();

int main()
{	
	VSAInitTest();
	VSAAllocTest();
	VSAGetLargestChunkAvailableTest();
	VSAFreeTest();
	DefragmantationTest1();
	DefragmantationTest2();
	return 0;
}





void VSAInitTest()
{
	vsa_t * vsa = NULL;
	char *allocated = (char *)malloc(sizeof(char) * 104);
	
	vsa = VSAInit((void *)allocated, 104);
	
	if((104 - 2 * sizeof(blk_hdr_t) == *(long *)allocated && 0 == *(long *)(allocated + 104 - sizeof(blk_hdr_t)) && NULL != vsa))
	{
		printf("VSAInitTest pass\n");
		
	}
	else
	{
		printf("VSAInitTest fail\n");
		printf("its %ld\n", *(long *)allocated);
		printf("its %ld\n", *(long *)(allocated + 104 - sizeof(blk_hdr_t)));
	}
	
	
	free(allocated);
}

void VSAAllocTest()
{
	
	
	vsa_t * vsa = NULL;
	char *data1 = NULL;
	char *data2 = NULL;
	char *data3 = NULL;
	char *allocated = NULL;
	allocated = (char *)malloc(sizeof(char) * 106);
	vsa = VSAInit((void *)allocated, 106);
	
	data1 = (char *)VSAAlloc(vsa, 10);
	data2 = (char *)VSAAlloc(vsa, 10);
	data3 = (char *)VSAAlloc(vsa, 2);
	
	if(-16 == *(long *)((char *)data1 - sizeof(blk_hdr_t)) && 16 == *(long *)&data1 - *(long *)&allocated && -16 == *(long *)((char *)data2 - sizeof(blk_hdr_t)) && 48 == *(size_t *)&data2 - *(size_t *)&allocated && -16 == *(long *)((char *)data2 - sizeof(blk_hdr_t)))
	{
		printf("VSAAllocTest pass\n");
		
	}
	else
	{
		printf("VSAAllocTest fail\n");
		printf("*(long *)data1 %ld\n", *(long *)data1 - sizeof(blk_hdr_t));
		printf("*(size_t *)&data1 - *(size_t *)&allocated %ld\n", *(long *)&data1 - *(long *)&allocated);
		
		printf("*(long *)data2 %ld\n", *(long *)data2 - sizeof(blk_hdr_t));
		printf("*(size_t *)&data2 - *(size_t *)&allocated %ld\n", *(long *)&data2 - *(long *)&allocated);
		
		printf("*(long *)data3 %ld\n", *(long *)data3 - sizeof(blk_hdr_t));
		printf("*(size_t *)&data3 - *(size_t *)&allocated %ld\n", *(long *)&data3 - *(long *)&allocated);	
	}
	free(allocated);
}


void VSAGetLargestChunkAvailableTest()
{
	vsa_t * vsa = NULL;
	size_t largest_chunk1 = 0;
	size_t largest_chunk2 = 0;
	size_t largest_chunk3 = 0;
	size_t largest_chunk4 = 0;
	char *allocated = (char *)malloc(sizeof(char) * 104);
	
	vsa = VSAInit((void *)allocated, 104);
	largest_chunk1 = VSAGetLargestChunkAvailable(vsa);
	VSAAlloc(vsa, 10);
	largest_chunk2 = VSAGetLargestChunkAvailable(vsa);
	VSAAlloc(vsa, 10);
	largest_chunk3 = VSAGetLargestChunkAvailable(vsa);
	VSAAlloc(vsa, 10);
	largest_chunk4 = VSAGetLargestChunkAvailable(vsa);
	
	if(104 - 2 * sizeof(blk_hdr_t)  == largest_chunk1 && 104 - 3 * sizeof(blk_hdr_t) - 16 == largest_chunk2 && 104 - 4 * sizeof(blk_hdr_t) - 32  == largest_chunk3 && 8 == largest_chunk4)
	{
		printf("VSAGetLargestChunkAvailableTest pass\n");
		
	}
	else
	{
		printf("VSAGetLargestChunkAvailableTest fail\n");
		printf("104 - 2 * sizeof(blk_hdr_t)  %ld\n", 104 - 2 * sizeof(blk_hdr_t));
		printf("largest_chunk1  %ld\n", largest_chunk1);
		printf("104 - 4 * sizeof(blk_hdr_t)  %ld\n", 104 - 3 * sizeof(blk_hdr_t) - 16);
		printf("largest_chunk2  %ld\n", largest_chunk2);
		printf("104 - 2 * sizeof(blk_hdr_t)   %ld\n", 104 - 4 * sizeof(blk_hdr_t) - 32);
		printf("largest_chunk3  %ld\n", largest_chunk3);
		printf("largest_chunk3  %ld\n", largest_chunk4);
	}
	free(allocated);

}


void VSAFreeTest()
{
	vsa_t * vsa = NULL;
	void *data1 = NULL;
	void *data2 = NULL;
	
	size_t largest_chunk1 = 0;
	size_t largest_chunk2 = 0;
	size_t largest_chunk3 = 0;
	char *allocated = (char *)malloc(sizeof(char) * 160);
	
	vsa = VSAInit((void *)allocated, 160);
	
	data1 = VSAAlloc(vsa, 10);
	data2 = VSAAlloc(vsa, 10);
	VSAAlloc(vsa, 10);
	largest_chunk1 = VSAGetLargestChunkAvailable(vsa);
	VSAFree(data1);
	largest_chunk2 = VSAGetLargestChunkAvailable(vsa);
	VSAFree(data2);
	largest_chunk3 = VSAGetLargestChunkAvailable(vsa);
	
	if(32 == largest_chunk1 && 32 == largest_chunk2 && 48 == largest_chunk3)
	{
		printf("VSAFreeTest pass\n");
	}
	else
	{
		printf("VSAFreeTest fail\n");
		printf("largest_chunk1  %ld\n", largest_chunk1);
		printf("largest_chunk2  %ld\n", largest_chunk2);
		printf("largest_chunk3  %ld\n", largest_chunk3);
	}
	free(allocated);
}

void DefragmantationTest1()
{


	vsa_t * vsa = NULL;
	void *data1 = NULL;
	void *data2 = NULL;
	void *data3 = NULL;
	size_t largest_chunk1 = 0;
	size_t largest_chunk2 = 0;
	size_t largest_chunk3 = 0;
	size_t largest_chunk4 = 0;
	char *allocated = (char *)malloc(sizeof(char) * 240);
	
	vsa = VSAInit((void *)allocated, 240);
	
	data1 = VSAAlloc(vsa, 80);
	data2 = VSAAlloc(vsa, 40);
	data3 = VSAAlloc(vsa, 20);
	largest_chunk1 = VSAGetLargestChunkAvailable((vsa_t *)allocated);
	VSAFree(data1);
	largest_chunk2 = VSAGetLargestChunkAvailable((vsa_t *)allocated);
	VSAFree(data2);
	largest_chunk3 = VSAGetLargestChunkAvailable((vsa_t *)allocated);
	VSAFree(data3);
	largest_chunk4 = VSAGetLargestChunkAvailable((vsa_t *)allocated);
	
	if(16 == largest_chunk1 && 80 == largest_chunk2 && 136 == largest_chunk3 && 208 == largest_chunk4)
	{
		printf("DefragmantationTest1 pass\n");
	}
	else
	{
		printf("DefragmantationTest1 fail\n");
		printf("largest_chunk1  %ld\n", largest_chunk1);
		printf("largest_chunk2  %ld\n", largest_chunk2);
		printf("largest_chunk3  %ld\n", largest_chunk3);
		printf("largest_chunk4  %ld\n", largest_chunk4);
		
		
		printf("*(long *)(data1)  %ld\n", *(long *)(data1));
		printf("*(long *)(data2)  %ld\n", *(long *)(data2));
		printf("*(long *)(data3)  %ld\n", *(long *)(data3));
		
	}
	
	
	free(allocated);
}

void DefragmantationTest2()
{
	vsa_t * vsa = NULL;
	void *data2 = NULL;
	void *data3 = NULL;
	char *allocated = (char *)malloc(sizeof(char) * 104);
	
	vsa = VSAInit((void *)allocated, 104);
	
	VSAAlloc(vsa, 10);
	data2 = VSAAlloc(vsa, 10);
	data3 = VSAAlloc(vsa, 5);
	
	VSAFree(data2);
	
	VSAFree(data3);
	data3 = VSAAlloc(vsa, 2);
	
	if(NULL != data3 && -8 == *(long *)((char *)data3 - sizeof(blk_hdr_t)))
	{
		printf("DefragmantationTest2 pass\n");
	}
	else
	{
		printf("DefragmantationTest2 fail\n");
	}
	free(allocated);
}

