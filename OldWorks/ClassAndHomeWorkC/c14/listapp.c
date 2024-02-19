#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

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
Person class[3]={{200,"Shaul",19,&class[0]},{50,"Haim",23,&class[1]},{30,"Shlomo",44,NULL}};

int main()
{
/*ListInsertHead*/
 	test1();
 	test2();
 	test3();
 	test4();
/*ListRemoveHead*/
 	test5();
 	test6();
 	test7();
/*ListInsertByKey*/
 	test8();
 	test9();
/*ListInsertByKey*/
	test10();
	test11();
	test12();
	
	
 	return 0;
}

void test1(void)
{
	struct Person* p;
	p=ListInsertHead(NULL ,NULL);
	if( p==NULL)
	{
		printf("Test 1 Pass\n");
	}
	else
	{
		printf("Test 1 Fail\n");
	}
}


void test2(void)
{
	struct Person* p;
	p=ListInsertHead(NULL ,class);
	if( p!=NULL)
	{
		printf("Test 2 Pass\n");
	}
	else
	{
		printf("Test 2 Fail\n");
	}
}
void test3(void)
{
	struct Person* p;
	p=ListInsertHead(class ,class);
	if( p!=NULL)
	{
		printf("Test 3 Pass\n");
	}
	else
	{
		printf("Test 3 Fail\n");
	}
}

void test4(void)
{
	struct Person* p;
	p=ListInsertHead(class,NULL);
	if( p!=NULL)
	{
		printf("Test 4 Pass\n");
	}
	else
	{
		printf("Test 4 Fail\n");
	}
}

void test5(void)
{
	struct Person* p;
	p=ListRemoveHead(NULL,NULL);
	if( p==NULL)
	{
		printf("Test 5 Pass\n");
	}
	else
	{
		printf("Test 5 Fail\n");
	}
}
void test6(void)
{
	struct Person* p;
	p=ListInsertHead(NULL ,class);
	if( p!=NULL)
	{
		printf("Test 6 Pass\n");
	}
	else
	{
		printf("Test 6 Fail\n");
	}
}

void test7(void)
{
	struct Person* p;
	p=ListInsertHead(&class[1] ,class);
	if( p!=NULL)
	{
		printf("Test 7 Pass\n");
	}
	else
	{
		printf("Test 7 Fail\n");
	}
}

void test8(void)
{
	struct Person* p;
	p=ListInsertByKey(NULL, 100,class);
	if( p!=NULL)
	{
		printf("Test 8 Pass\n");
	}
	else
	{
		printf("Test 8 Fail\n");
	}
}

void test9(void)
{
	struct Person* p;
	p=ListInsertByKey(class, 100,&class[2]);
	if( p!=NULL)
	{
		printf("Test 9 Pass\n");
	}
	else
	{
		printf("Test 9 Fail\n");
	}
}

void test10(void)
{
	struct Person* p;
	p=ListRemoveByKey(NULL, 100, NULL);
	if( p==NULL)
	{
		printf("Test 10 Pass\n");
	}
	else
	{
		printf("Test 10 Fail\n");
	}
}
void test11(void)
{
	struct Person* p;
	p=ListRemoveByKey(class, 100, NULL);
	if( p==NULL)
	{
		printf("Test 11 Pass\n");
	}
	else
	{
		printf("Test 11 Fail\n");
	}
}
void test12(void)
{
	struct Person* p;
	p=ListRemoveByKey(class, 200, &p);
	if( p!=NULL)
	{
		printf("Test 12 Pass\n");
	}
	else
	{
		printf("Test 12 Fail\n");
	}
}

