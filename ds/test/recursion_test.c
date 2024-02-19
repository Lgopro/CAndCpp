/*
Rev: 
Dev: Leonid Golovko
status: finished
date: 04/06/2023
*/
#include <stdlib.h> /*malloc*/
#include <stdio.h> /*print*/
#include <string.h> /*strfunc*/
#include "recursion.h"



void StrlenTest();
void FlipListTest();
void TestFibonacci();
void StrCmpTest();
void StrCpyTest();
void StrStrTest();
void StrCatTest();
void CheckStackRecursion();


struct Node
{
	void *data;
	Node *next;
};


int main()
{	
	FlipListTest();
	StrlenTest();
	StrCmpTest();
	TestFibonacci();
	StrCpyTest();
	StrStrTest();
	StrCatTest();
	CheckStackRecursion();
	return 0;
}

void StrCatTest()
{
	char arr1[100] = "fgfgfhelln";
	char arr[100] = "hell";
	char arr2[100] = "fgfgfhelln";
	char arr3[100] = "hell";
	
	if(0 == strcmp(strcat(arr1, arr), StrCat(arr2, arr3)))
	{
		printf("Test StrCatTest pass\n");
	}
	else
	{
		printf("Test StrCatTest fail\n");
	}
}


void StrStrTest()
{
	char arr1[100] = "fgfgfhelln";
	char arr[100] = "hell";
	char arr2[100] = "fgfgfhelln";
	char arr3[100] = "hell";
	if(0 == strcmp(StrStr(arr1, arr), StrStr(arr2, arr3)))
	{
		printf("Test StrStrTest pass\n");
	}
	else
	{
		printf("Test StrStrTest fail\n");
	}


}

void StrCpyTest()
{
	
	char arr1[100] = "helln";
	char arr[100]= "";
	StrCpy(arr, arr1);
	if(0 == StrCmp(arr, arr1))
	{
		printf("Test StrCpyTest pass\n");
	}
	else
	{
		printf("Test StrCpyTest fail\n");
	}

}

void StrCmpTest()
{
	char arr[] = "hello";
	char arr1[] = "helln";
	char arr2[] = "hellp";
	if(0 == StrCmp(arr, arr) && 1 == StrCmp(arr, arr1) && -1 == StrCmp(arr, arr2))
	{
		printf("Test StrCmpTest pass\n");
	}
	else
	{
		printf("StrCmp(arr, arr)  %d\n", StrCmp(arr, arr));
		printf("StrCmp(arr, arr1)  %d\n", StrCmp(arr, arr1));
		printf("StrCmp(arr, arr2)  %d\n", StrCmp(arr, arr2));
		printf("Test StrCmpTest fail\n");
	}


}
void TestFibonacci()
{
	
	if(1 == FibonacciIterative(2) && 34 == FibonacciIterative(9) && 1 == FibonacciRecurcive(2) && 34 == FibonacciRecurcive(9))
	{
		printf("Test TestFibonacciTest pass\n");
	}
	else
	{
		printf("Test TestFibonacciTest fail\n");
	}

}

void FlipListTest()
{
	int val1 = 1;
	int val2 = 2;
	int val3 = 3;
	int val4 = 4;
	int val5 = 5;
	
	Node * node1 = (Node *)malloc(sizeof(Node));
	Node * node2 = (Node *)malloc(sizeof(Node));
	Node * node3 = (Node *)malloc(sizeof(Node));
	Node * node4 = (Node *)malloc(sizeof(Node));
	Node * node5 = (Node *)malloc(sizeof(Node));
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	node1->data = (void *)&val1;
	node2->data = (void *)&val2;
	node3->data = (void *)&val3;
	node4->data = (void *)&val4;
	node5->data = (void *)&val5;
	
	FlipList(node1);
	
	if(NULL == node1->next && node1 == node2->next && node4 == node5->next)
	{
		printf("Test FlipListTest pass\n");
	}
	else
	{
		
		printf("Test FlipListTest fail\n");
	}
	
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}


void StrlenTest()
{
	char *arr = (char *)malloc(sizeof(char) * 10);
	char * begin = NULL;
	begin = arr;
	arr = "CountMe";
	
	if(7 == Strlen((const char *)arr))
	{
		printf("Test StrlenTest pass\n");
	}
	else
	{
		printf("The value is %ld\n", Strlen((const char *)arr));
		printf("Test StrlenTest fail\n");
	}
	arr = begin;
	free(arr);
}


void CheckStackRecursion()
{
	int value = 0;
	int value1 = 5;
	int value2 = 2;
	int value3 = 8;
	int value4 = 1;
	int value5 = 3;
	int value6 = 0;
	stack_t *stack = StackCreate(10, sizeof(int));
	
	
	
	StackPush(stack, (const void *)&value1);
	StackPush(stack, (const void *)&value2);
	StackPush(stack, (const void *)&value3);
	StackPush(stack, (const void *)&value4);
	StackPush(stack, (const void *)&value5);
	StackPush(stack, (const void *)&value6);
	Sort(stack);
	
	while(1 != StackIsEmpty((const stack_t *)stack))
	{
		value = *(int *)StackPeek((const stack_t *)stack);
		printf("Value is %d ,", value);
    	StackPop(stack);
	}
	printf("\nTest CheckStackRecursion pass\n");

	StackDestroy(stack);
}
