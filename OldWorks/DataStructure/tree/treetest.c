
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

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
	return 0;
}


void test1(void)
{
	struct Tree* Tree;
	Tree=TreeCreate();
	if(Tree != NULL)
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
	struct Tree* Tree;
	Tree=TreeCreate();
	TreeDestroy(Tree);
	Tree=TreeCreate();
	if(Tree != NULL)
	{
		printf("Test 2 pass\n");
	}
	else
	{
		printf("Test 2 fail\n");
	}
}

void test3(void)
{
	struct Tree* Tree;
	Tree=TreeCreate();
	TreeDestroy(Tree);
	printf("Test 3 pass\n");
	
}

void test4(void)
{
	
	ADTErr error;
	error=TreeInsert(NULL , 111);
	
	if(error == ERR_NOT_INITIALIZED)
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
	struct Tree* Tree;
	ADTErr error;
	Tree=TreeCreate();
	
	error=TreeInsert(Tree , 111);
	if(error == ERR_OK)
	{
		printf("Test 5 pass\n");
	}
	else
	{
		printf("Test 5 fail\n");
	}
	TreeDestroy(Tree);
}
void test6(void)
{
	ADTErr error;
	struct Tree* Tree;
	Tree=TreeCreate();
	error=TreeInsert(Tree, 100);
	if(error == ERR_OK)
	{
		printf("Test 6 pass\n");
	}
	else
	{
		printf("Test 6 fail\n");
	}
	TreeDestroy(Tree);
}

void test7(void)
{
	ADTErr error;
	struct Tree* Tree;
	Tree=TreeCreate();
	TreeInsert(Tree, 100);
	error=TreeInsert(Tree, 100);
	if(error == ERR_GENERAL)
	{
		printf("Test 7 pass\n");
	}
	else
	{
		printf("Test 7 fail\n");
	}
	TreeDestroy(Tree);
}

void test8(void)
{
	ADTErr error;
	struct Tree* Tree;
	Tree=TreeCreate();
	TreeInsert(Tree, 100);
	error=TreeInsert(Tree, 345);
	if(error == ERR_OK)
	{
		printf("Test 8 pass\n");
	}
	else
	{
		printf("Test 8 fail\n");
	}
	TreeDestroy(Tree);
}

void test9(void)
{
	int error;
	error=TreeIsDataFound(NULL, 100);
	
	if(error == NOT_INITIALIZED)
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
	struct Tree* Tree;
	int error;
	Tree=TreeCreate();
	TreeInsert(Tree, 100);
	error=TreeIsDataFound(Tree, 100);
	
	if(error == EQUALITY_FOUND)
	{
		printf("Test 10 pass\n");
	}
	else
	{
		printf("Test 10 fail\n");
	}
	TreeDestroy(Tree);
}

void test11(void)
{
	struct Tree* Tree;
	int error;
	Tree=TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1023);
	TreeInsert(Tree, 100);
	error=TreeIsDataFound(Tree, 100);
	
	if(error == EQUALITY_FOUND)
	{
		printf("Test 11 pass\n");
	}
	else
	{
		printf("Test 11 fail\n");
	}
	TreeDestroy(Tree);
}

void test12(void)
{
	struct Tree* Tree;
	int error;
	Tree=TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1023);
	TreeInsert(Tree, 100);
	error=TreeIsDataFound(Tree, 144);
	
	if(error == EQUALITY_NOT_FOUND)
	{
		printf("Test 12 pass\n");
	}
	else
	{
		printf("Test 12 fail\n");
	}
	TreeDestroy(Tree);
}

void test13(void)
{
	struct Tree* Tree;
	Tree=TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1023);
	TreeInsert(Tree, 100);
	TreePrint(Tree, PRE_ORDER);
	TreePrint(Tree, IN_ORDER);
	TreePrint(Tree, POST_ORDER);
	printf("Test 13 pass\n");
	TreeDestroy(Tree);
}

void test14(void)
{
	struct Tree* Tree;
	int num;
	Tree = TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1022);
	TreeInsert(Tree, 1023);
	num = CheckTreeLevel( Tree);
	printf("the number is: %d\n", num);
	
}
void test15(void)
{
	struct Tree* Tree;
	int result;
	Tree = TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1022);
	result = IsFullTree(Tree);
	if(result == 1)
	{
		printf("Tree is full\n");
	}
	else
	{
		printf("Tree is not full\n");
	}
	TreeDestroy(Tree);
	
}
void test16(void)
{
	struct Tree* Tree;
	struct Tree* Tree1;
	int result;
	Tree = TreeCreate();
	Tree1 = TreeCreate();
	TreeInsert(Tree, 103);
	TreeInsert(Tree, 1022);
	TreeInsert(Tree1, 103);
	TreeInsert(Tree1, 1022);
	
	
	result = AreSimilar(Tree,Tree1);
	if(result == 1)
	{
		printf("Tree is same\n");
	}
	else
	{
		printf("Tree is not same\n");
	}
	TreeDestroy(Tree);
	TreeDestroy(Tree1);
	
}




