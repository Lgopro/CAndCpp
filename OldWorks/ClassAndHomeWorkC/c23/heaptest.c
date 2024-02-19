#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "heap.h"
#define INITSIZE 10
#define BLOCKSIZE 10


void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);
void test13(void);
void test14(void);
void test15(void);
void test16(void);

int main()
{
	test1();
 	test2();
 	test3();
 	test4();
	test5();
 	test6();
	test7();
 	test8();
 	test9();
 	test10();
 	test11();
 	test12();
	test13();
	test14();
	test15();
	test16();
	/*Vector* vector=NULL;
	vector=VectorCreate(8,2);
	VectorAddEnd(vector, 7);
	VectorAddEnd(vector, 20);
	VectorAddEnd(vector, 15);
	VectorAddEnd(vector, 2);
	VectorAddEnd(vector, 100);
	
	VectorPrint(vector);
	HeapBuild(vector);
	VectorPrint(vector);*/
	return 0;
}


void test1(void)
{
	struct Heap* heap;
	heap=HeapBuild(NULL);
	if(heap == NULL)
	{
		printf("Test 1 pass\n");
	}
	else
	{
		printf("Test 1 fail\n");
	}
}


void test2(void)
{
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	if(heap != NULL)
	{
		printf("Test 2 pass\n");
	}
	else
	{
		printf("Test 2 fail\n");
	}
	HeapDestroy(heap);
}

void test3(void)
{
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	HeapDestroy(heap);
	printf("Test 3 pass\n");
}

void test4(void)
{
	ADTErr status;
	status=HeapInsert(NULL , 234); 
	if(status == ERR_NOT_INITIALIZED)
	{
		printf("Test 4 pass\n");
	}
	else
	{
		printf("Test 4 fail\n");
	}
}

void test5(void)
{
	ADTErr status;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	status=HeapInsert(heap , 234); 
	if(status == ERR_OK)
	{
		printf("Test 5 pass\n");
	}
	else
	{
		printf("Test 5 fail\n");
	}
	HeapDestroy(heap);
}

void test6(void)
{
	int data;
	ADTErr status;
	status=HeapMax(NULL, &data); 
	if(status == ERR_NOT_INITIALIZED)
	{
		printf("Test 6 pass\n");
	}
	else
	{
		printf("Test 6 fail\n");
	}
}

void test7(void)
{
	
	ADTErr status;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	status=HeapMax( heap, NULL); 
	if(status == ERR_NOT_INITIALIZED)
	{
		printf("Test 7 pass\n");
	}
	else
	{
		printf("Test 7 fail\n");
	}
	HeapDestroy(heap);
}

void test8(void)
{
	
	ADTErr status;
	int data;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	status=HeapMax( heap, &data); 
	if(status == ERR_OK)
	{
		printf("Test 8 pass\n");
	}
	else
	{
		printf("Test 8 fail\n");
	}
	HeapDestroy(heap);
}


void test9(void)
{
	int data;
	ADTErr status;
	status=HeapExtractMax(NULL, &data); 
	if(status == ERR_NOT_INITIALIZED)
	{
		printf("Test 9 pass\n");
	}
	else
	{
		printf("Test 9 fail\n");
	}
}

void test10(void)
{
	
	ADTErr status;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	status=HeapExtractMax( heap, NULL); 
	if(status == ERR_NOT_INITIALIZED)
	{
		printf("Test 10 pass\n");
	}
	else
	{
		printf("Test 10 fail\n");
	}
	HeapDestroy(heap);
}

void test11(void)
{
	
	ADTErr status;
	int data;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	VectorAddEnd(vector,  50);
	VectorAddEnd(vector,  10);
	status=HeapExtractMax( heap, &data); 
	if(status == ERR_OK)
	{
		printf("Test 11 pass\n");
	}
	else
	{
		printf("Test 11 fail\n");
	}
	HeapDestroy(heap);
}


void test12(void)
{
	
	int status;
	status=HeapItemsNum(NULL);
	if(status == NOT_INIT)
	{
		printf("Test 12 pass\n");
	}
	else
	{
		printf("Test 12 fail\n");
	}
}

void test13(void)
{
	
	int status;
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	status=HeapItemsNum( heap); 
	if(status != NOT_INIT)
	{
		printf("Test 13 pass\n");
	}
	else
	{
		printf("Test 13 fail\n");
	}
	HeapDestroy(heap);
}


void test14(void)
{
	HeapPrint(NULL);
	printf("Test 14 pass\n");
	
}


void test15(void)
{
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	heap=HeapBuild(vector);
	HeapPrint(heap);
	printf("Test 15 pass\n");
}

void test16(void)
{
	struct Heap* heap;
	Vector* vector;
	vector = VectorCreate(INITSIZE,BLOCKSIZE);
	VectorAddEnd(vector,  10);
	VectorAddEnd(vector,  50);
	VectorAddEnd(vector,  10);
	heap=HeapBuild(vector);
	HeapPrint(heap);
	printf("Test 16 pass\n");
}




