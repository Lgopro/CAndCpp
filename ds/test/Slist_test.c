/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 1/05/2023
*/

#include <stdio.h> /*printf*/


#include "Slist.h"


void SListCreateTest();
void SListCountTest();
void SListRemoveTest();
void SListSetAndGetTest();
void SListForEachTest();
void SListFindTest();
void SListIterIsEqualTest();

int Action(void *value1, void *value2)
{
	*(int *)value1 += *(int *)value2;
	return 0;
}

int Match(void *value1, void *value2)
{
	return (*(int *)value1 == *(int *)value2);

}


int main()
{	
	SListCreateTest();
	SListCountTest();
	SListRemoveTest();
	SListSetAndGetTest();
	SListIterIsEqualTest();
	SListFindTest();
	SListForEachTest();
	
	return 0;
}

void SListForEachTest()
{
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	iter_t iterator2 = NULL;
	iter_t iterator3 = NULL;
	iter_t iterator4 = NULL; 
	void * changed_value1 = NULL;
	void * changed_value2 = NULL;
	void * changed_value3 = NULL;
	void * changed_value4 = NULL;
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	int change = 88;
	list = SListCreate();
	iterator1 = SListBegin(list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value1);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value2);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value3);
	iterator1 = SListNext(iterator1);
	iterator2 = SListBegin(list);
	SListForEach(*(&(iterator2)), *(&iterator1), Action, (void *)&change);
	iterator1 = SListBegin(list);
	changed_value1 = SListGet(iterator1);
	iterator2 = SListNext(iterator1);
	changed_value2 = SListGet(iterator2);
	iterator3 = SListNext(iterator2);
	changed_value3 = SListGet(iterator3);
	iterator4 = SListNext(iterator3);
	changed_value4 = SListGet(iterator4);
	if(89 == *(int *)changed_value1 && 90 == *(int *)changed_value2 && 91 == *(int *)changed_value3 && 92 == *(int *)changed_value4)
	{
		printf("SListForEachTest pass\n");
	}
	else
	{
		printf("Value is: %d\n", *(int *)changed_value1);
		printf("Value is: %d\n", *(int *)changed_value2);
		printf("Value is: %d\n", *(int *)changed_value3);
		printf("Value is: %d\n", *(int *)changed_value4);
		printf("SListForEachTest fail\n");
	}
	
	
	SListDestroy(list);
}

void SListIterIsEqualTest()
{
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	iter_t iterator2 = NULL;
	int status1 = 0;
	int status2 = 0;
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	list = SListCreate();
	iterator1 = SListBegin(list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListInsert(iterator1, (void *)&value1);
	iterator1 = SListInsert(iterator1, (void *)&value2);
	iterator1 = SListInsert(iterator1, (void *)&value3);
	iterator1 = SListNext(iterator1);
	iterator1 = SListNext(iterator1);
	iterator2 = SListBegin(list);
	
	status1 = SListIterIsEqual(iterator1 , iterator2);
	status2 = SListIterIsEqual(iterator1 , iterator1);
	
	if(0 != status1 && 0 == status2)
	{
		printf("SListIterIsEqualTest pass\n");
	}
	else
	{
		printf("Status 1: %d, status 2: %d\n", status1, status2);
		printf("SListIterIsEqualTest fail\n");
	}
	SListDestroy(list);




}

void SListFindTest()
{
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	list = SListCreate();
	iterator1 = SListBegin(list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value1);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value2);
	iterator1 = SListNext(iterator1);
	iterator1 = SListInsert(iterator1, (void *)&value3);
	iterator1 = SListNext(iterator1);
	iterator1 = SListBegin(list);
	iterator1 = SListNext(iterator1);
	iterator1 = SListNext(iterator1);
	iterator1 = SListFind(SListBegin(list), iterator1, (const void *)&value2, Match);
	
	if(value2 == *(int *)SListGet(iterator1))
	{
		printf("SListFindTest pass\n");
	}
	else
	{
		printf("SListFindTest fail\n");
	}
	SListDestroy(list);

}



void SListCreateTest()
{
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	iter_t iterator2 = NULL;
	
	list = SListCreate();
	iterator1 = SListBegin(list);
	iterator2 = SListEnd(list);
	if(iterator1 == iterator2)
	{
		printf("SListCreateTest pass\n");
		printf("SListBeginTest pass\n");
		printf("SListEndTest pass\n");
	}
	else
	{
		printf("SListCreateTest fail\n");
	
	}
	
	
	SListDestroy(list);
}

void SListCountTest()
{

	
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	int value = 1;
	int value1 = 2;
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	list = SListCreate();
	iterator1 = SListBegin(list);
	size1 = SListCount((const slist_t *)list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	size2 = SListCount((const slist_t *)list);
	iterator1 = SListInsert(iterator1, (void *)&value1);
	size3 = SListCount((const slist_t *)list);
	if(0 == size1 && 1 == size2 && 2 == size3 )
	{
		printf("SListCountTest pass\n");
		printf("SListInsertTest pass\n");
	}
	else
	{
		printf("Size is: %ld\n", size1);
		printf("Size is: %ld\n", size2);
		printf("Size is: %ld\n", size3);
		printf("SListCountTest fail\n");
		printf("SListInsertTest fail\n");
	}
	
	
	SListDestroy(list);
}

void SListRemoveTest()
{

	
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	int value = 1;
	int value1 = 2;
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	size_t size4 = 0;
	size_t size5 = 0;
	list = SListCreate();
	iterator1 = SListBegin(list);
	size1 = SListCount((const slist_t *)list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	size2 = SListCount((const slist_t *)list);
	iterator1 = SListInsert(iterator1, (void *)&value1);
	size3 = SListCount((const slist_t *)list);
	iterator1 = SListRemove(iterator1);
	size4 = SListCount((const slist_t *)list);
	iterator1 = SListRemove(iterator1);
	
	size5 = SListCount((const slist_t *)list);
	
	if(0 == size1 && 1 == size2 && 2 == size3 &&  0 == size5 && 1 == size4)
	{
		printf("SListRemoveTest pass\n");
	}
	else
	{
		printf("SListRemoveTest fail\n");
	}
	
	
	SListDestroy(list);
}

void SListSetAndGetTest()
{

	
	slist_t *list = NULL;
	iter_t iterator1 = NULL;
	void * changed_value1 = NULL;
	void * changed_value2 = NULL;
	void * changed_value3 = NULL;
	int value = 1;
	int value1 = 2;
	int value2 = 3;
	int value3 = 4;
	list = SListCreate();
	iterator1 = SListBegin(list);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListInsert(iterator1, (void *)&value);
	iterator1 = SListBegin(list);
	SListSet(iterator1, (void *)&value1);
	changed_value1 = SListGet(iterator1);
	iterator1 = SListNext(iterator1);
	SListSet(iterator1, (void *)&value2);
	changed_value2 = SListGet(iterator1);
	iterator1 = SListNext(iterator1);
	SListSet(iterator1, (void *)&value3);
	changed_value3 = SListGet(iterator1);
	if(4 == *(int *)changed_value3 && 3 == *(int *)changed_value2 && 2 == *(int *)changed_value1)
	{
		printf("SListSetTest pass\n");
		printf("SListGetTest pass\n");
	}
	else
	{
		
		printf("SListSetTest fail\n");
		printf("SListGetTest fail\n");
	}
	
	
	SListDestroy(list);
}

