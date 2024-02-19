
/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date: 07/05/2023
*/

#include <stdio.h> /*printf*/


#include "dlist.h"



void SListCreateTest();
void DListPushBackTest();
void DListPushTest();
void DListPopTest();
void DListFindTest();
void DListFindMultiTest();
void DListForEachTest();
void DListSpliceTest();

int Action(void *value1, void *value2)
{
	*(int *)value1 += *(int *)value2;
	return 0;
}

int Match(void *value1, const void *value2)
{
	return (*(int *)value1 == *(int *)value2);

}



int main()
{	
	SListCreateTest();
	DListPushBackTest();
	DListPushTest();
	DListPopTest();
	DListFindTest();
	DListFindMultiTest();
	DListForEachTest();
	DListSpliceTest();
	return 0;
}



void SListCreateTest()
{

	dlist_t *list = DListCreate();
	size_t size = 0;
	int status = 0;
	int status1 = 0;
	size = DListSize((const dlist_t *)list);
	status = DListIsEmpty((const dlist_t *)list);
	status1 = DListIsEqual(DListBegin((const dlist_t *)list) , DListEnd((const dlist_t *)list));
	if(1 == status && 0 == size && NULL != list && 1 == status1)
	{
		printf("SListCreateTest pass\n");
		
	}
	else
	{
		
		printf("SListCreateTest fail\n");
		
	}
	DListDestroy(list);
}




void DListPushBackTest()
{


	dlist_t *list = DListCreate();
	size_t size = 0;
	int status = 0;
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int status1 = 0;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	dlist_iter_t iter = NULL;
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	iter = DListBegin((const dlist_t *)list);

	result1 = DListGetData(iter);
	iter = DListNext(iter);
	result2 = DListGetData(iter);
	iter = DListNext(iter);
	result3 = DListGetData(iter);
	
	
	size = DListSize((const dlist_t *)list);
	status = DListIsEmpty((const dlist_t *)list);
	status1 = DListIsEqual(DListBegin((const dlist_t *)list) , DListEnd((const dlist_t *)list));
	iter = DListPrev(iter);
	iter = DListPrev(iter);
	if(0 == status && 3 == size && NULL != list && value1 == *(int *)result1 && value2 == *(int *)result2 && value3 == *(int *)result3 && 0 == status1 && iter == DListBegin((const dlist_t *)list))
	{
		printf("DListPushBackTest pass\n");
		printf("DListNextTest pass\n");
		printf("DListGetDataTest pass\n");
		printf("DListNextTest pass\n");
		printf("DListPrevTest pass\n");
		printf("DListSizeTest pass\n");
		printf("DListIsEmptyTest pass\n");
		printf("DListIsEqualTest pass\n");
		
	}
	else
	{
		
		printf("DListPushBackTest fail\n");
		printf("DListNextTest fail\n");
		printf("DListGetDataTest fail\n");
		printf("DListNextTest fail\n");
		printf("DListSizeTest fail\n");
		printf("DListIsEmptyTest fail\n");
		printf("DListIsEqualTest fail\n");
		printf("DListPrevTest fail\n");
	}
	DListDestroy(list);

}




void DListPushTest()
{

	
	dlist_t *list = DListCreate();
	size_t size = 0;
	int status = 0;
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	dlist_iter_t iter = NULL;
	DListPushBack(list, (void *)&value1);
	DListPushFront(list, (void *)&value2);
	iter = DListBegin((const dlist_t *)list);
	iter = DListNext(iter);
	DListInsert(iter, (void *)&value3);

	iter = DListBegin((const dlist_t *)list);

	result1 = DListGetData(iter);
	iter = DListNext(iter);
	result2 = DListGetData(iter);
	iter = DListNext(iter);
	result3 = DListGetData(iter);
	
	
	size = DListSize((const dlist_t *)list);
	status = DListIsEmpty((const dlist_t *)list);
	if(0 == status && 3 == size && NULL != list && value2 == *(int *)result1 && value3 == *(int *)result2 && value1 == *(int *)result3)
	{
		printf("DListPushFrontTest pass\n");
		printf("DListInsertTest pass\n");
		
		
	}
	else
	{
		
		printf("DListPushFrontTest fail\n");
		printf("DListInsertTest fail\n");
	}
	DListDestroy(list);
}



void DListPopTest()
{


	dlist_t *list = DListCreate();
	size_t size = 0;
	int status = 0;
	
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	dlist_iter_t iter = NULL;
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	
	DListPopBack(list);
	DListPopFront(list);
	iter = DListBegin((const dlist_t *)list);
	iter = DListNext(iter);
	DListRemove(iter);
	
	iter = DListBegin((const dlist_t *)list);
	
	result1 = DListGetData(iter);
	iter = DListNext(iter);
	result2 = DListGetData(iter);
	iter = DListNext(iter);
	result3 = DListGetData(iter);
	size = DListSize((const dlist_t *)list);
	status = DListIsEmpty((const dlist_t *)list);
	if(0 == status && 3 == size && NULL != list && *(int *)result1 == value2 && *(int *)result2 == value1 && *(int *)result3 == value2)
	{
		printf("DListPopTest pass\n");
		
	}
	else
	{
		
		printf("DListPopTest fail\n");
		printf("status %d\n", status);
		printf("size %ld\n", size);
		printf("one %d\n", *(int *)result1);
		printf("two %d\n", *(int *)result2);
		printf("one %d\n", *(int *)result3);
		
	}
	DListDestroy(list);
}



void DListFindTest()
{

	dlist_t *list = DListCreate();
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	void *result1 = NULL;
	dlist_iter_t iter = NULL;
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	
	iter = DListFind(DListBegin((const dlist_t *)list), DListEnd((const dlist_t *)list), Match, (const void *)&value3);
	result1 = DListGetData(iter);
	if(value3 == *(int *)result1)
	{
		printf("DListFindTest pass\n");
		
	}
	else
	{
		
		printf("DListFindTest fail\n");
		
		
	}
	DListDestroy(list);

} 


void DListFindMultiTest()
{

	dlist_t *list = DListCreate();
	dlist_t *list_new = DListCreate();
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 3;
	int status = 0;
	size_t size = 0;
	void *result1 = NULL;
	void *result2 = NULL;
	dlist_iter_t iter = NULL;
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	
	
	
	status = DListMultiFind(DListBegin((const dlist_t *)list), DListEnd((const dlist_t *)list), Match, (const void *)&value4, list_new);
	
	size = DListSize((const dlist_t *)list_new);
	iter = DListBegin((const dlist_t *)list_new);
	result1 = DListGetData(iter);
	iter = DListNext(iter);
	result2 = DListGetData(iter);
	if(1 == status && 2 == size && *(int *)result1 == value3 && *(int *)result2 == value3)
	{
		printf("DListFindMultiTest pass\n");
		
	}
	else
	{
		
		printf("DListFindMultiTest fail\n");
		
		
	}
	DListDestroy(list);
	DListDestroy(list_new);
}


void DListForEachTest()
{

	dlist_t *list = DListCreate();
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;
	int status = 0;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	dlist_iter_t iter = NULL;
	
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	
	
	status = DListForEach(DListBegin((const dlist_t *)list), DListEnd((const dlist_t *)list), Action, (void *)&value4);
	iter = DListBegin((const dlist_t *)list);
	
	result1 = DListGetData(iter);
	iter = DListNext(iter);
	result2 = DListGetData(iter);
	iter = DListNext(iter);
	result3 = DListGetData(iter);
	if(5 == *(int *)result1 && 6 == *(int *)result2 && 7 == *(int *)result3 && 0 == status)
	{
		printf("DListForEachTest pass\n");
		
	}
	else
	{
		
		printf("DListForEachTest fail\n");
		
		
	}
	DListDestroy(list);

} 



void DListSpliceTest()
{
	dlist_t *list = DListCreate();
	dlist_t *list_other = DListCreate();
	int value1 = 1;
	int value2 = 2;
	int value3 = 3;
	int value4 = 4;
	
	size_t size = 0;
	size_t size1 = 0;
	
	
	
	
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	DListPushBack(list, (void *)&value1);
	DListPushBack(list, (void *)&value2);
	DListPushBack(list, (void *)&value3);
	
	
	DListPushBack(list_other, (void *)&value4);
	DListPushBack(list_other, (void *)&value4);
	DListPushBack(list_other, (void *)&value4);
	
	
	DListSplice(DListBegin((const dlist_t *)list_other), DListBegin((const dlist_t *)list), DListEnd((const dlist_t *)list));
	
	
	size = DListSize((const dlist_t *)list);
	size1 = DListSize((const dlist_t *)list_other);
	
	if(0 == size && 9 == size1)
	{
		printf("DListSpliceTest pass\n");
		
	}
	else
	{
		
		printf("DListSpliceTest fail\n");
		printf("size %ld\n", size);
		printf("size1 %ld\n", size1);
		
	}
	DListDestroy(list);
	DListDestroy(list_other);







}
