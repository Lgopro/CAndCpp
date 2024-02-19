#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"

void testStackCreate1();
void testStackCreate2();
void testStackCreate3();
void testStackCreate4();
void testStackPush1();
int main()
{
 	
	testStackCreate1();
    testStackCreate2();
    testStackCreate3();
    testStackCreate4();
    testStackPush1();
    return 0;
	
}



void testStackCreate1(void)
{
	struct Stack* Stack=NULL;
	Stack=StackCreate (2,2);
	if(NULL == Stack)
	{
		printf("Fail\n");
	}
	else
	{
		printf("Pass\n");
	}
	StackDestroy(Stack);
}
void testStackCreate2(void)
{
	struct Stack* Stack=NULL;
	Stack=StackCreate (0,0);
	if(NULL == Stack)
	{
		printf("Pass\n");
	}
	else
	{
		printf("Fail\n");
	}
}
void testStackCreate3(void)
{
	struct Stack* Stack=NULL;
	Stack=StackCreate (2,0);
	if(NULL == Stack)
	{
		printf("Fail\n");
	}
	else
	{
		printf("Pass\n");
	}
	StackDestroy(Stack);
}
void testStackCreate4(void)
{
	struct Stack* Stack=NULL;
	Stack=StackCreate (0,2);
	if(NULL == Stack)
	{
		printf("Fail\n");
	}
	else
	{
		printf("Pass\n");
	}
	StackDestroy(Stack);
}
void testStackPush1()
{
	struct Stack* Stack=NULL;
	
	StackPush(Stack, 5);
	if(



}

