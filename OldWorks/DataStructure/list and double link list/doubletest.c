#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubledlinkedlist.h"

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
void test17(void);
void test18(void);
void test19(void);
void test20(void);
void test21(void);
void test22(void);
void test23(void);
void test24(void);
void test25(void);
void test26(void);
void test27(void);
void test28(void);
void test29(void);

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
 	test17();
 	test18();
 	test19();
 	test20();
 	test21();
	test22();
	test23();
	test24();
 	test25();
 	test26();
	test27();
	test28();
	test29();

	return 0;
}

void test1(void)
{
	struct List* List;
	List=ListCreate();
	if(List != NULL)
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
	struct List* List;
	List=ListCreate();
	ListDestroy(List);
	
		printf("Test 2 pass\n");
}

void test3(void)
{
	ADTErr error;
	error=ListPushHead(NULL,0);
	if(error == ERR_NOT_INITIALIZED)
	{
		printf("Test 3 pass\n");
	}
	else
	{
		printf("Test 3 fail\n");
	}
}
void test4(void)
{
	struct List* List;
	ADTErr error;
	List=ListCreate();
	error=ListPushHead(List,0);
	if(error == ERR_OK)
	{
		printf("Test 4 pass\n");
	}
	else
	{
		printf("Test 4 fail\n");
	}
	ListDestroy(List);
}

void test5(void)
{
	struct List* List;
	ADTErr error;
	List=ListCreate();
	error=ListPushHead(List,0);
	error=ListPushHead(List,8);
	if(error == ERR_OK)
	{
		printf("Test 5 pass\n");
	}
	else
	{
		printf("Test 5 fail\n");
	}
	ListDestroy(List);
}


void test6(void)
{
	ADTErr error;
	error=ListPushTail(NULL,5);
	if(error == ERR_NOT_INITIALIZED)
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
	struct List* List;
	ADTErr error;
	List=ListCreate();
	error=ListPushTail(List,5);
	if(error == ERR_OK)
	{
		printf("Test 7 pass\n");
	}
	else
	{
		printf("Test 7 fail\n");
	}
	ListDestroy(List);
}

void test8(void)
{
	struct List* List;
	ADTErr error;
	List=ListCreate();
	ListPushTail(List,5);
	error=ListPushTail(List,5);
	if(error == ERR_OK)
	{
		printf("Test 8 pass\n");
	}
	else
	{
		printf("Test 8 fail\n");
	}
	ListDestroy(List);
}

void test9(void)
{
	struct List* List;
	ADTErr error;
	List=ListCreate();
	ListPushTail(List,5);
	error=ListPushHead(NULL, 0);
	if(error == ERR_NOT_INITIALIZED)
	{
		printf("Test 9 pass\n");
	}
	else
	{
		printf("Test 9 fail\n");
	}
	ListDestroy(List);
}

void test10(void)
{
	struct List* List;
	ADTErr error;
	List=ListCreate();
	ListPushTail(List,5);
	error=ListPushHead(List,7);
	if(error == ERR_OK)
	{
		printf("Test 10 pass\n");
	}
	else
	{
		printf("Test 10 fail\n");
	}
	ListDestroy(List);
}

void test11(void)
{
	ADTErr error;
	int data;
	
	
	error=ListPopHead(NULL , &data);
	if(error == ERR_NOT_INITIALIZED)
	{
		printf("Test 11 pass\n");
	}
	else
	{
		printf("Test 11 fail\n");
	}
}



void test12(void)
{
	struct List* List;
	int data;
	ADTErr error;
	List=ListCreate();
	error=ListPopHead(List , &data);
	if(error == ERR_UNDERFLOW)
	{
		printf("Test 12 pass\n");
	}
	else
	{
		printf("Test 12 fail\n");
	}
	ListDestroy(List);
}

void test13(void)
{
	struct List* List;
	ADTErr error;
	int data;
	List=ListCreate();
	ListPushHead(List,7);
	error=ListPopHead(List , &data);
	if(error == ERR_OK)
	{
		printf("Test 13 pass\n");
	}
	else
	{
		printf("Test 13 fail\n");
	}
	ListDestroy(List);
}

void test14(void)
{
	struct List* List;
	int data;
	ADTErr error;
	List=ListCreate();
	ListPushTail(List,5);
	error=ListPopHead(List , &data);
	if(error == ERR_OK)
	{
		printf("Test 14 pass\n");
	}
	else
	{
		printf("Test 14 fail\n");
	}
	ListDestroy(List);
}

void test15(void)
{
	int data;
	ADTErr error;
	error=ListPopTail(NULL , &data);
	if(error == ERR_NOT_INITIALIZED)
	{
		printf("Test 15 pass\n");
	}
	else
	{
		printf("Test 15 fail\n");
	}
}



void test16(void)
{
	struct List* List;
	int data;
	ADTErr error;
	List=ListCreate();
	error=ListPopTail(List , &data);
	if(error == ERR_UNDERFLOW)
	{
		printf("Test 16 pass\n");
	}
	else
	{
		printf("Test 16 fail\n");
	}
	ListDestroy(List);
}

void test17(void)
{
	struct List* List;
	ADTErr error;
	int data;
	List=ListCreate();
	ListPushHead(List,7);
	error=ListPopTail(List , &data);
	if(error == ERR_OK)
	{
		printf("Test 17 pass\n");
	}
	else
	{
		printf("Test 17 fail\n");
	}
	ListDestroy(List);
}

void test18(void)
{
	struct List* List;
	int data;
	ADTErr error;
	List=ListCreate();
	ListPushTail(List,5);
	error=ListPopTail(List , &data);
	if(error == ERR_OK)
	{
		printf("Test 18 pass\n");
	}
	else
	{
		printf("Test 18 fail\n");
	}
	ListDestroy(List);
}

void test19(void)
{
	size_t error;
	error=ListCountItems(NULL);
	if(error == NOT_INIT)
	{
		printf("Test 19 pass\n");
	}
	else
	{
		printf("Test 19 fail\n");
	}
}

void test20(void)
{
	struct List* List;
	size_t error;
	List=ListCreate();
	error=ListCountItems(List);
	if(error == ZERO_ITEMS)
	{
		printf("Test 20 pass\n");
	}
	else
	{
		printf("Test 20 fail\n");
	}
	ListDestroy(List);
}

void test21(void)
{
	struct List* List;
	size_t error;
	List=ListCreate();
	ListPushHead(List,7);
	ListPushHead(List,8);
	ListPushHead(List,8);
	error=ListCountItems(List);
	if(error == 3)
	{
		printf("Test 21 pass\n");
	}
	else
	{
		printf("Test 21 fail\n");
	}
	ListDestroy(List);
}
void test22(void)
{
	struct List* List;
	size_t error;
	List=ListCreate();
	ListPushTail(List,7);
	ListPushTail(List,8);
	error=ListCountItems(List);
	if(error == 2)
	{
		printf("Test 22 pass\n");
	}
	else
	{
		printf("Test 22 fail\n");
	}
	ListDestroy(List);
}

void test23(void)
{
	int error;
	error=ListIsEmtpy(NULL);
	if(error == NOT_INIT)
	{
		printf("Test 23 pass\n");
	}
	else
	{
		printf("Test 23 fail\n");
	}
	
}


void test24(void)
{
	struct List* List;
	int error;
	List=ListCreate();
	error=ListIsEmtpy(List);
	if(error == EMPTY)
	{
		printf("Test 24 pass\n");
	}
	else
	{
		printf("Test 24 fail\n");
	}
	ListDestroy(List);
}

void test25(void)
{
	struct List* List;
	int error;
	List=ListCreate();
	ListPushTail(List,7);
	ListPushTail(List,8);
	error=ListIsEmtpy(List);
	if(error == NOT_EMPTY)
	{
		printf("Test 25 pass\n");
	}
	else
	{
		printf("Test 25 fail\n");
	}
	ListDestroy(List);
}

void test26(void)
{
	struct List* List;
	int error;
	List=ListCreate();
	ListPushHead(List,7);
	ListPushHead(List,8);
	error=ListIsEmtpy(List);
	if(error == NOT_EMPTY)
	{
		printf("Test 26 pass\n");
	}
	else
	{
		printf("Test 26 fail\n");
	}
	ListDestroy(List);
}
void test27(void)
{
	
	ListPrintf(NULL);
	printf("Test 27 pass\n");

	
}

void test28(void)
{
	struct List* List;
	List=ListCreate();
	ListPrintf(List);
	printf("Test 28 pass\n");
	ListDestroy(List);
}

void test29(void)
{
	struct List* List;
	List=ListCreate();
	ListPushHead(List,7);
	ListPushHead(List,8);
	ListPrintf(List);
	printf("Test 29 pass\n");
	ListDestroy(List);
}



