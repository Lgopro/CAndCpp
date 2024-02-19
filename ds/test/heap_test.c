/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 20/06/2023
*/
#include <stdio.h> /*print*/

#include "heap.h"

int cmpfunc(const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int IsMatch(const void * a, const void * b) 
{
   return ( *(int*)a == *(int*)b );
}

void HeapCreateTest();
void HeapPushTest();
void HeapPopTest();
void HeapRemoveTest();

int main()
{	
	
    HeapCreateTest();
	HeapPushTest();
	HeapPopTest();
	HeapRemoveTest();
	return 0;
}


void HeapCreateTest()
{
    heap_t *heap = HeapCreate(cmpfunc);
    if(NULL != heap && 1 == HeapIsEmpty((const heap_t *)heap) && 0 == HeapSize((const heap_t *)heap) && NULL == HeapPeek((const heap_t *)heap))
	{
		printf("HeapCreateTest pass\n");
	}
	else
	{
		printf("HeapCreateTest fail\n");
	}
    HeapDestroy(heap);
}


void HeapPushTest()
{
	int data1 = 5;
	int data2 = 6;
	int data3 = 0;
	int data4 = -2;
	
	void *data =NULL;
	size_t i = 0;
	heap_t *heap = HeapCreate(cmpfunc);


	HeapPush(heap, (const void *)&data1);
	HeapPush(heap, (const void *)&data2);
	HeapPush(heap, (const void *)&data3);
	HeapPush(heap, (const void *)&data4);
	for(i = 0;i < HeapSize((const heap_t *)heap); ++i)
	{
		data = *(void **)DVectorGetAccessToElement(heap->arr, i);
		printf("%d ", *(int *)data);
	}
	printf("\n");
    if(NULL != heap && 0 == HeapIsEmpty((const heap_t *)heap) && 
	   4 == HeapSize((const heap_t *)heap) && -2 == *(int *)HeapPeek((const heap_t *)heap) && 
	   -2 == *(int *)*(void **)DVectorGetAccessToElement(heap->arr, 0) && 0 == *(int *)*(void **)DVectorGetAccessToElement(heap->arr, 1)
	   && 5 == *(int *)*(void **)DVectorGetAccessToElement(heap->arr, 2) && 6 == *(int *)*(void **)DVectorGetAccessToElement(heap->arr, 3))
	{
		printf("HeapPushTest pass\n");
	}
	else
	{
		printf("HeapPushTest fail\n");
	}
    HeapDestroy(heap);
}


void HeapPopTest()
{
	
	void *data = NULL;
	heap_t *heap = HeapCreate(cmpfunc);
	int arr[] = {4, 2, 7, 1, 3, 6, 7};
	size_t i = 0;
	for(i = 0;i < sizeof(arr)/sizeof(int); ++i)
	{
		HeapPush(heap, (const void *)&arr[i]);
	}
	printf("after insert:\n");
	for(i = 0;i < sizeof(arr)/sizeof(int); ++i)
	{
		data = *(void **)DVectorGetAccessToElement(heap->arr, i);
		printf("%d ", *(int *)data);
	}
	printf("\n");
	HeapPop(heap);
	printf("after pop:\n");
	for(i = 0;i < sizeof(arr)/sizeof(int) - 1; ++i)
	{
		data = *(void **)DVectorGetAccessToElement(heap->arr, i);
		printf("%d ", *(int *)data);
	}
	printf("\n");
    if(NULL != heap && 0 == HeapIsEmpty((const heap_t *)heap) && 
	   6 == HeapSize((const heap_t *)heap) && 2 == *(int *)HeapPeek((const heap_t *)heap))
	{
		printf("HeapPopTest pass\n");
	}
	else
	{
		printf("HeapPopTest fail\n");
	}
    HeapDestroy(heap);
}


void HeapRemoveTest()
{
	size_t i = 0;
	void *data = NULL;
	int data_to_remove = 6;
	int data_to_remove1 = 1;
	int data_to_remove2 = 8;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	heap_t *heap = HeapCreate(cmpfunc);
	int arr[] = {4, 2, 7, 1, 3, 6, 7};
	for(i = 0;i < sizeof(arr)/sizeof(int); ++i)
	{
		HeapPush(heap, (const void *)&arr[i]);
	}
	printf("after insert:\n");
	for(i = 0;i < sizeof(arr)/sizeof(int); ++i)
	{
		data = *(void **)DVectorGetAccessToElement(heap->arr, i);
		printf("%d ", *(int *)data);
	}
	printf("\n");

	result1 = HeapRemove(heap, &data_to_remove, IsMatch);
	result2 = HeapRemove(heap, &data_to_remove1, IsMatch);
	result3 = HeapRemove(heap, &data_to_remove2, IsMatch);
	printf("after HeapRemove:\n");
	for(i = 0;i < sizeof(arr)/sizeof(int) - 2; ++i)
	{
		data = *(void **)DVectorGetAccessToElement(heap->arr, i);
		printf("%d ", *(int *)data);
	}
	printf("\n");
    if(NULL != heap && 0 == HeapIsEmpty((const heap_t *)heap) && 
	   5 == HeapSize((const heap_t *)heap) && 2 == *(int *)HeapPeek((const heap_t *)heap)
	   && NULL != result1 && NULL != result2 && NULL == result3)
	{
		printf("HeapRemoveTest pass\n");
	}
	else
	{
		printf("HeapRemoveTest fail\n");
	}
    HeapDestroy(heap);
}
