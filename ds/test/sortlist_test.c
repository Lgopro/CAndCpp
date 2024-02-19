
/*
Rev: 
Dev: Leonid Golovko
status: finished
date: 
*/



#include <stdio.h> /*printf*/


#include "sortlist.h"


void SortListCreateTest();
void SortListInsertTest();
void SortListPopTest();
void SortListMergeTest();
void SortFindIfTest();
void SortFindTest();

int main()
{	
	SortListCreateTest();
	SortListInsertTest();
	SortListPopTest();
	
	SortFindIfTest();
	SortFindTest();
	SortListMergeTest();
	return 0;
}
typedef struct IsMatchParam
{
	void *data;
	compare_t cmp;
}is_match_param_t;

static int IsToInsert(void *data, const void *param)
{
	compare_t cmp = ((is_match_param_t *)param)->cmp;
	void *param_data = ((is_match_param_t *)param)->data;
	return (0 <= cmp(data, param_data));	
}

static dlist_iter_t GetDListIter(sort_iter_t iterator)
{
	return iterator.iter;
}

int Equal(void *value1, const void *value2)
{
	return (*(int *)value1 == *(int *)value2);

}

int Compare(void *value1, const void *value2)
{
	return (*(int *)value1 - *(int *)value2);

}
int Action(void *value1, void *value2)
{
	(void)value2;
	printf("%d ", *(int *)value1);
	return 0;
}

void SortListCreateTest()
{
	size_t size = 0;
	int status = 0;
	int status1 = 0;
	
	sort_list_t *list = SortListCreate(Compare);
	size = SortListSize((const sort_list_t *)list);
	status = SortListIsEmpty(list);
	status1 = DListIsEqual(GetDListIter(SortListBegin((const sort_list_t *)list)) , GetDListIter(SortListEnd((const sort_list_t *)list)));
	if(1 == status1 && 1 == status && 0 == size && NULL != list)
	{
		printf("SortListCreateTest pass\n");
		
	}
	else
	{
		
		printf("SortListCreateTest fail\n");
		
	}
	SortListDestroy(list);

}


void SortListInsertTest()
{


	sort_list_t *list = SortListCreate(Compare);
	size_t size = 0;
	int status = 0;
	
	int status1 = 0;
	int value1 = 3;
	int value2 = 1;
	int value3 = -1;
	sort_iter_t iter;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;

	SortListInsert(list, (void *)&value1);
	SortListInsert(list, (void *)&value2);
	SortListInsert(list, (void *)&value3);
	status1 = DListIsEqual(GetDListIter(SortListBegin((const sort_list_t *)list)) , GetDListIter(SortListEnd((const sort_list_t *)list)));
	
	iter = SortListBegin((const sort_list_t *)list); 

	result1 = SortListGetData(iter); 
	iter = SortListNext(iter);
	result2 = SortListGetData(iter);
	iter = SortListNext(iter);
	result3 = SortListGetData(iter);
	
	SortListForEach(SortListBegin((const sort_list_t *)list), SortListEnd((const sort_list_t *)list), Action, (void *)&status);
	printf("\n");
	size = SortListSize((const sort_list_t *)list);
	
	status = SortListIsEmpty(list);
	
	
	iter = SortListPrev(iter);
	iter = SortListPrev(iter);
	if(0 == status1 && 0 == status && 3 == size && NULL != list && value3 == *(int *)result1 && value2 == *(int *)result2 && value1 == *(int *)result3 &&  GetDListIter(iter) == GetDListIter(SortListBegin((const sort_list_t *)list)))
	{
		printf("SortListInsertTest pass\n");
		printf("SortListNextTest pass\n");
		printf("SortListGetDataTest pass\n");
		printf("SortListNextTest pass\n");
		printf("SortListPrevTest pass\n");
		printf("SortListSizeTest pass\n");
		printf("SortListIsEmptyTest pass\n");
		printf("SortListInsertTest pass\n");
		
	}
	else
	{
		
		printf("SortListInsertTest fail\n");
		printf("SortListNextTest fail\n");
		printf("SortListGetDataTest fail\n");
		printf("SortListNextTest fail\n");
		printf("SortListPrevTest fail\n");
		printf("SortListSizeTest fail\n");
		printf("SortListIsEmptyTest fail\n");
		printf("SortListInsertTest fail\n");
		
	}
	SortListDestroy(list);

}


void SortListPopTest()
{


	sort_list_t *list = SortListCreate(Compare);
	size_t size = 0;
	int status = 0;
	
	int value1 = 91;
	int value2 = 22;
	int value3 = -33;
	int value4 = 3;
	int value5 = 5;
	int value6 = 1;
	void *result1 = NULL;
	void *result2 = NULL;
	void *result3 = NULL;
	void *result4 = NULL;
	void *result5 = NULL;
	sort_iter_t iter;
	
	SortListInsert(list, (void *)&value1);
	SortListInsert(list, (void *)&value2);
	SortListInsert(list, (void *)&value3);
	SortListInsert(list, (void *)&value4);
	SortListInsert(list, (void *)&value5);
	SortListInsert(list, (void *)&value6);
	
	result4 = SortListPopFront(list);
	result5 = SortListPopBack(list);
	iter = SortListBegin((const sort_list_t *)list); 
	iter = SortListNext(iter);
	SortListRemove(iter);
	
	iter = SortListBegin((const sort_list_t *)list); 

	result1 = SortListGetData(iter); 
	iter = SortListNext(iter);
	result2 = SortListGetData(iter);
	iter = SortListNext(iter);
	result3 = SortListGetData(iter);
	iter = SortListNext(iter);
	size = SortListSize((const sort_list_t *)list);
	status = SortListIsEmpty(list);
	if(0 == status && 3 == size && NULL != list && *(int *)result1 == value6 && *(int *)result2 == value5 && *(int *)result3 == value2 && *(int *)result4 == value3 && *(int *)result5 == value1)
	{
		printf("SortListPopTest pass\n");
		
	}
	else
	{
		
		printf("SortListPopTest fail\n");
		printf("The result1 is: %d\n", *(int *)result1);
		printf("The result2 is: %d\n", *(int *)result2);
		printf("The result3 is: %d\n", *(int *)result3);
		printf("The result4 is: %d\n", *(int *)result4);
		printf("The result5 is: %d\n", *(int *)result5);
		printf("The status is: %d\n", status);
		printf("The size is: %ld\n", size);
		
	}
	SortListDestroy(list);
}

void SortListMergeTest()
{

	sort_list_t *list_dest = SortListCreate(Compare);
	sort_list_t *list_src = SortListCreate(Compare);
	size_t size = 0;
	int status = 0;
	
	int value1 = 91;
	int value2 = 22;
	int value3 = -33;
	int value4 = 3;
	int value5 = 5;
	int value6 = 1;
	
	int value7 = 30;
	int value8 = 10;
	int value9 = 20;
	int value10 = 0;
	
	
	
	SortListInsert(list_src, (void *)&value1);
	SortListInsert(list_src, (void *)&value2);
	SortListInsert(list_src, (void *)&value3);
	SortListInsert(list_src, (void *)&value4);
	SortListInsert(list_src, (void *)&value5);
	SortListInsert(list_src, (void *)&value6);

	SortListInsert(list_dest, (void *)&value7);
	SortListInsert(list_dest, (void *)&value8);
	SortListInsert(list_dest, (void *)&value9);
	SortListInsert(list_dest, (void *)&value10);

	SortListMerge(list_dest, list_src);
	
	SortListForEach(SortListBegin((const sort_list_t *)list_dest), SortListEnd((const sort_list_t *)list_dest), Action, (void *)&status);
	printf("\n");
	size = SortListSize((const sort_list_t *)list_dest);
	if(10 == size)
	{
		printf("SortListMergeTest pass\n");
		
	}
	else
	{
		
		printf("SortListMergeTest fail\n");
		
		
	}
	SortListDestroy(list_dest);
	SortListDestroy(list_src);
}



void SortFindIfTest()
{
	sort_list_t *list_dest = SortListCreate(Compare);
	sort_list_t *src_dest = SortListCreate(Compare);
	int status = 0;
	
	int value1 = 91;
	int value2 = 22;
	int value3 = -33;
	int value4 = 3;
	int value5 = 5;
	int value6 = 1;
	
	int value7 = 30;
	
	int status_for_each = 0;
	sort_iter_t iter_result;
	is_match_param_t param = {0};
	
	
	void *result1 = NULL;
	param.data = (void *)&value7;
	param.cmp = Compare;
	SortListInsert(src_dest, (void *)&value1);
	
	
	
	SortListInsert(list_dest, (void *)&value1);
	SortListInsert(list_dest, (void *)&value2);
	SortListInsert(list_dest, (void *)&value3);
	SortListInsert(list_dest, (void *)&value4);
	SortListInsert(list_dest, (void *)&value5);
	SortListInsert(list_dest, (void *)&value6);

	
	iter_result = SortListFindIf(SortListBegin((const sort_list_t *)list_dest), SortListEnd((const sort_list_t *)list_dest), IsToInsert, &param);
	
	status_for_each = SortListForEach((SortListBegin((const sort_list_t *)src_dest)), SortListEnd((const sort_list_t *)list_dest), Action, (void *)&status);
	SortListForEach((SortListBegin((const sort_list_t *)list_dest)), SortListEnd((const sort_list_t *)list_dest), Action, (void *)&status);
	
	result1 = SortListGetData(iter_result); 
	printf("\n");
	
	if(*(int *)result1 == value1 && 1 == status_for_each)
	{
		printf("SortListFindIfTest pass\n");
		printf("IfnDefTest pass\n");
		printf("SortForEachTest pass\n");
	}
	else
	{
		printf("SortListFindIfTest fail\n");
		printf("IfnDefTest fail\n");
		printf("SortForEachTest fail\n");
		printf("status for each  %d \n", status_for_each);
		printf("result1 %d \n", *(int *)result1);
		
	}
	SortListDestroy(list_dest);
	SortListDestroy(src_dest);
	
}


void SortFindTest()
{
	sort_list_t *list_dest = SortListCreate(Compare);
	sort_list_t *src_dest = SortListCreate(Compare);
	int status = 0;
	
	int value1 = 91;
	int value2 = 22;
	int value3 = -33;
	int value4 = 3;
	int value5 = 5;
	int value6 = 1;
	
	sort_iter_t iter_result;
	sort_iter_t iter_result_if;
	
	void *result1 = NULL;
	
	SortListInsert(src_dest, (void *)&value1);
	
	
	
	SortListInsert(list_dest, (void *)&value1);
	SortListInsert(list_dest, (void *)&value2);
	SortListInsert(list_dest, (void *)&value3);
	SortListInsert(list_dest, (void *)&value4);
	SortListInsert(list_dest, (void *)&value5);
	SortListInsert(list_dest, (void *)&value6);


	SortListForEach((SortListBegin((const sort_list_t *)list_dest)), SortListEnd((const sort_list_t *)list_dest), Action, (void *)&status);
	
	iter_result = SortListFind(SortListBegin((const sort_list_t *)list_dest), SortListEnd((const sort_list_t *)list_dest), list_dest, (void *)&value3);
	iter_result_if = SortListFind(SortListBegin((const sort_list_t *)src_dest), SortListEnd((const sort_list_t *)list_dest), list_dest, (void *)&value3);
	
	result1 = SortListGetData(iter_result); 
	printf("\n");
	
	if(*(int *)result1 == value3 && NULL == iter_result_if.iter && NULL == iter_result_if.list)
	{
		printf("SortListFindTest pass\n");
		printf("IfnDefTest pass\n");
	}
	else
	{
		printf("SortListFindTest fail\n");
		printf("IfnDefTest fail\n");
	}
	SortListDestroy(list_dest);
	SortListDestroy(src_dest);
	
}
