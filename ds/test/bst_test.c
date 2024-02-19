
/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date:04/06/2023
*/

#include <stdio.h> /*printf*/

#define MAX (2147483647)

int Compare(const void *a, const void *b)
{

	return (*(int *)a - *(int *)b);

}

int ForComp(void *a, void *b)
{
	(*(int *)a -= *(int *)b);
	return 1;

}

#include "bst.h" 

void BSTCreateTest();
void BSTInsertTest();
void BSTIsSameIterTest();
void BSTNextTest();
void BSTPrevTest();
void BSTSizeTest();
void BSTPrevTest();
void BSTFindTest();
void BSTForEachTest();
void BSTRemoveTest();


int main()
{	
	BSTCreateTest();
	BSTInsertTest();
	BSTIsSameIterTest();
	BSTNextTest();
	BSTSizeTest();
	BSTPrevTest();
	BSTFindTest();
	BSTForEachTest();
	BSTRemoveTest();
	return 0;
}


void BSTCreateTest()
{
	
	bst_t *tree = BSTCreate(Compare);
	
	
	if(NULL != tree && 1 == BSTIsEmpty((const bst_t *)tree))
	{
		printf("BSTCreateTest pass\n");
	}
	else
	{
		printf("BSTCreateTest fail\n");
	}	
	BSTDestroy(tree);	
}



void BSTInsertTest()
{
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	bst_iter_t result3 = NULL;
	bst_iter_t result4 = NULL;
	bst_iter_t result5 = NULL;
	bst_iter_t result6 = NULL;
	
	bst_t *tree = BSTCreate(Compare);
	
	result1 = BSTInsert(tree, (void *)&value1);
	result2 = BSTInsert(tree, (void *)&value2);
	result3 = BSTInsert(tree, (void *)&value3);
	result4 = BSTInsert(tree, (void *)&value4);
	result5 = BSTInsert(tree, (void *)&value5);
	result6 = BSTInsert(tree, (void *)&value6);
	
	if(NULL != tree && NULL != result1 && NULL != result2 && NULL != result3 && NULL != result4 && NULL != result5 && NULL != result6 && 0 == BSTIsEmpty((const bst_t *)tree) && value3 == *(int *)BSTGetData(BSTBegin((const bst_t *)tree)) && 1 == BSTIsSameIter(BSTGetData(BSTEnd((const bst_t *)tree)), BSTEnd((const bst_t *)tree)))
	{
		printf("BSTInsertTest pass\n");
		printf("BSTBeginTest pass\n");
		printf("BSTEndTest pass\n");
		printf("BSTIsEmptyTest pass\n");
		printf("BSTGetDataTest pass\n");
	}
	else
	{
		printf("BSTInsertTest fail\n");
		printf("BSTBeginTest fail\n");
		printf("BSTEndTest fail\n");
		printf("BSTIsEmptyTest fail\n");
		printf("BSTGetDataTest fail\n");
		printf("%d \n", *(int *)BSTGetData(result1));
		printf("%d \n", *(int *)BSTGetData(result2));
		printf("%d \n", *(int *)BSTGetData(result3));
		printf("%d \n", *(int *)BSTGetData(result4));
		printf("%d \n", *(int *)BSTGetData(result5));
		printf("%d \n", *(int *)BSTGetData(result6));
		
		printf("%d \n", *(int *)BSTGetData(BSTEnd((const bst_t *)tree)));
		
	}	
	BSTDestroy(tree);	
}



void BSTIsSameIterTest()
{
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	
	bst_t *tree = BSTCreate(Compare);
	
	result1 = BSTInsert(tree, (void *)&value1);
	result2 = BSTInsert(tree, (void *)&value2);
	BSTInsert(tree, (void *)&value3);
	BSTInsert(tree, (void *)&value4);
	BSTInsert(tree, (void *)&value5);
	BSTInsert(tree, (void *)&value6);
	
	if(1 == BSTIsSameIter(result2, result2) && 0 == BSTIsSameIter(result2, result1))
	{
		printf("BSTIsSameIterTest pass\n");
		
	}
	else
	{
		printf("BSTIsSameIter fail\n");
		
		
	}	
	BSTDestroy(tree);	
}


void BSTFindTest()
{

	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	int find1 = 2;
	int find2 = 6;
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	bst_iter_t end = NULL;
	bst_t *tree = BSTCreate(Compare);
	
	BSTInsert(tree, (void *)&value1);
	BSTInsert(tree, (void *)&value2);
	BSTInsert(tree, (void *)&value3);
	BSTInsert(tree, (void *)&value4);
	BSTInsert(tree, (void *)&value5);
	BSTInsert(tree, (void *)&value6);
	
	result1 = BSTFind(tree, (const void *)&find1);
	result2 = BSTFind(tree, (const void *)&find2);
	
	end = BSTEnd((const bst_t *)tree);
	
	
	if(0 == BSTIsSameIter(end, result1) && 1 == BSTIsSameIter(end, result2))
	{
		printf("BSTFindTest pass\n");
	}
	else
	{
		printf("BSTFindTest fail\n");
	}	
	BSTDestroy(tree);	

}


void BSTSizeTest()
{

	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	size_t size1 = 0;
	size_t size2 = 0;
	size_t size3 = 0;
	size_t size4 = 0;
	size_t size5 = 0;
	size_t size6 = 0;
	size_t size7 = 0;
	
	bst_t *tree = BSTCreate(Compare);
	
	size1 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value1);
	size2 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value2);
	size3 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value3);
	size4 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value4);
	size5 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value5);
	size6 = BSTSize((const bst_t *)tree);
	BSTInsert(tree, (void *)&value6);
	size7 = BSTSize((const bst_t *)tree);
	

	
	if(0 == size1 && 1 == size2 && 2 == size3 && 3 == size4 && 4 == size5 && 5 == size6 && 6 == size7)
	{
		printf("BSTSizeTest pass\n");
	}
	else
	{
		printf("BSTSizeTest fail\n");
	}	
	BSTDestroy(tree);	
}

void BSTForEachTest()
{
	
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	int param = 1;
	int status = 0;
	
	
	
	
	bst_t *tree = BSTCreate(Compare);
	
	BSTInsert(tree, (void *)&value1);
	BSTInsert(tree, (void *)&value2);
	BSTInsert(tree, (void *)&value3);
	BSTInsert(tree, (void *)&value4);
	BSTInsert(tree, (void *)&value5);
	BSTInsert(tree, (void *)&value6);
	
	status = BSTForEach(BSTBegin((const bst_t *)tree), BSTEnd((const bst_t *)tree), ForComp, (void *)&param);
	
	if(1 == status && 0 == *(int *)BSTGetData(BSTBegin((const bst_t *)tree)))
	{
		printf("BSTForEachTest pass\n");
	}
	else
	{
		printf("BSTForEachTest fail\n");
		printf("status %d\n", status);
		printf("status %d\n", *(int *)BSTGetData(BSTBegin((const bst_t *)tree)));
		printf("value3 %d\n", value3);
	}	
	BSTDestroy(tree);	
}


void BSTNextTest()
{
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	
	
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	bst_iter_t result3 = NULL;
	bst_iter_t result4 = NULL;
	bst_iter_t result5 = NULL;
	bst_iter_t result6 = NULL;
	
	bst_iter_t runner = NULL;
	bst_iter_t runner1 = NULL;
	bst_iter_t runner2 = NULL;
	bst_iter_t runner3 = NULL;
	bst_iter_t runner4 = NULL;
	bst_iter_t runner5 = NULL;
	
	
	bst_t *tree = BSTCreate(Compare);
	
	result1 = BSTInsert(tree, (void *)&value1);
	result2 = BSTInsert(tree, (void *)&value2);
	result3 = BSTInsert(tree, (void *)&value3);
	result4 = BSTInsert(tree, (void *)&value4);
	result5 = BSTInsert(tree, (void *)&value5);
	result6 = BSTInsert(tree, (void *)&value6);
	
	runner = BSTBegin((const bst_t *)tree);
	runner1 = BSTNext(runner);
	runner2 = BSTNext(runner1);
	runner3 = BSTNext(runner2);
	runner4 = BSTNext(runner3);
	runner5 = BSTNext(runner4);
	
	if(1 == BSTIsSameIter(runner, result3) && 1 == BSTIsSameIter(runner1, result5) && 1 == BSTIsSameIter(runner2, result4) && 1 == BSTIsSameIter(runner3, result6) && 1 == BSTIsSameIter(runner4, result1) && 1 == BSTIsSameIter(runner5, result2))
	{
		printf("BSTNextTest pass\n");
	}
	else
	{
		printf("BSTNextTest fail\n");
	}	
	BSTDestroy(tree);	
}


void BSTPrevTest()
{
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	bst_iter_t result3 = NULL;
	bst_iter_t result4 = NULL;
	bst_iter_t result5 = NULL;
	bst_iter_t result6 = NULL;
	
	bst_iter_t runner = NULL;
	bst_iter_t runner1 = NULL;
	bst_iter_t runner2 = NULL;
	bst_iter_t runner3 = NULL;
	bst_iter_t runner4 = NULL;
	bst_iter_t runner5 = NULL;
	
	
	bst_t *tree = BSTCreate(Compare);
	
	result1 = BSTInsert(tree, (void *)&value1);
	result2 = BSTInsert(tree, (void *)&value2);
	result3 = BSTInsert(tree, (void *)&value3);
	result4 = BSTInsert(tree, (void *)&value4);
	result5 = BSTInsert(tree, (void *)&value5);
	result6 = BSTInsert(tree, (void *)&value6);
	
	runner = result2;
	runner1 = BSTPrev(runner);
	runner2 = BSTPrev(runner1);
	runner3 = BSTPrev(runner2);
	runner4 = BSTPrev(runner3);
	runner5 = BSTPrev(runner4);
	
	if(1 == BSTIsSameIter(runner1, result1) && 1 == BSTIsSameIter(runner2, result6) && 1 == BSTIsSameIter(runner3, result4) && 1 == BSTIsSameIter(runner4, result5) && 1 == BSTIsSameIter(runner5, result3))
	{
		printf("BSTPrevTest pass\n");
	}
	else
	{
		printf("BSTPrevTest fail\n");
	}	
	BSTDestroy(tree);	
}

void BSTRemoveTest()
{
	
	int value1 = 12;
	int value2 = 15;
	int value3 = 1;
	int value4 = 3;
	int value5 = 2;
	int value6 = 5;
	
	bst_iter_t result1 = NULL;
	bst_iter_t result2 = NULL;
	bst_iter_t result3 = NULL;
	bst_iter_t result4 = NULL;
	
	
	bst_t *tree = BSTCreate(Compare);
	
	result1 = BSTInsert(tree, (void *)&value1);
	result2 = BSTInsert(tree, (void *)&value2);
	result3 = BSTInsert(tree, (void *)&value3);
	result4 = BSTInsert(tree, (void *)&value4);
	BSTInsert(tree, (void *)&value5);
	BSTInsert(tree, (void *)&value6);
	
	BSTRemove(result2);
	
	result1 = BSTBegin((const bst_t *)tree);
	result1 = BSTNext(result1);
	result1 = BSTNext(result1);
	
	BSTRemove(result1);
	
	result1 = BSTBegin((const bst_t *)tree);
	result2 = BSTNext(result1);
	result3 = BSTNext(result2);
	result4 = BSTNext(result3);
	
	if(value3 == *(int *)BSTGetData(BSTBegin((const bst_t *)tree)) && value5 == *(int *)BSTGetData(result2) 
	   && value6 == *(int *)BSTGetData(result3) && value1 == *(int *)BSTGetData(result4))
	{
		printf("BSTRemoveTest pass\n");
	}
	else
	{
		printf("BSTRemoveTest fail\n");
		printf("result1 %d\n", *(int *)BSTGetData(result1));
		printf("result2 %d\n", *(int *)BSTGetData(result2));
		printf("result3 %d\n", *(int *)BSTGetData(result3));
		printf("result3%d\n", *(int *)BSTGetData(result4));
		
	}	
	BSTDestroy(tree);	
}
