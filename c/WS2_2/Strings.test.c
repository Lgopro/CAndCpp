/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:21/03/23
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*free*/
#include <string.h> /*strcmp*/
#include "Strings.h"

void TestStrCpy();
void TestStrNCpy();
void TestStrChr();
void TestStrCat();
void TestStrNCat();
void TestStrNCmp();
void TestStrCaseCmp();
void TestStrDup();
void TestStrStr();
void TestPalindrom();
void TestStrSpn();
void TestBoom();

int main()
{

	TestStrCpy();
	TestStrNCpy();
	TestStrChr();
	TestStrCat();
	TestStrNCat();
	TestStrNCmp();
	TestStrCaseCmp();
	TestStrDup();
	TestStrStr();
	TestPalindrom();
	TestStrSpn();
	TestBoom();
	return 0;
}


void TestBoom()
{
	char* arr;
	char arr_test[1000] = "690 691 692 BOOM 694 695 696 BOOM 698 699 BOOM BOOM ";
	arr = Boom(690, 701);
	if(0 == strcmp(arr, arr_test))
	{
		printf("Test BOOM pass\n");
	
	}
	free(arr);


}
void TestStrSpn()
{
	char arr1[100] = "Infinity", arr2[100] = "nfaai", arr3[] = "nfinity", arr4[] = "nII";
	if((int)strspn(arr2, arr1) == (int)StrSpn(arr2, arr1) && (int)strspn(arr3, arr1) == (int)StrSpn(arr3, arr1) && (int)strspn(arr1, arr3) == (int)StrSpn(arr1, arr3) && (int)strspn(arr1, arr4) == (int)StrSpn(arr1, arr4))
	{
	
		printf("Test StrSpn pass\n");
	
	}
}
void TestPalindrom()
{
	char arr1[100] = "abccba", arr2[100] = "abcba", arr3[] = "Infinity";
	if(0 == Palindrom(arr1) && 0 == Palindrom(arr2) && 1 == Palindrom(arr3))
	{
		
		printf("Test Palindrom pass\n");
	}


}


void TestStrStr()
{
	char arr1[100] = "Infinity", arr2[100] = "nfi", arr3[] = "nfinity";
	char* arr;
	arr = StrStr(arr1, arr2);
	
	if(0 == strcmp(arr, arr3))
	{
		
		printf("Test StrStr pass\n");
	}
	

}
void TestStrDup()
{
	char arr1[100] = "Infinity";
	char* cp;
	cp = StrDup(arr1);
	if(0 == strcmp(cp, arr1))
	{
		
		printf("Test StrDup pass\n");
	}
	free(cp);


}

void TestStrCaseCmp()
{
	char arr1[100] = "Infinity", arr2[100] = "Infiz", arr3[100] = "Infia", arr4[100] = "Infinityl";
	if(0 > StrCaseCmp(arr1, arr2) && 0 < StrCaseCmp(arr2, arr3) && 0 < StrCaseCmp(arr1, arr3) && 0 > StrCaseCmp(arr1, arr4))
	{
		
		printf("Test StrCaseCmp pass\n");
	}

}


void TestStrCpy()
{
	char arr1[100] = "Infinity";
	char* arr;
	arr = (char*)malloc(sizeof(char) * 4);
	StrCpy(arr, arr1);
	
	if(0 == strcmp(arr, arr1))
	{
		printf("Test StrCpy pass\n");
	}
}

void TestStrNCpy()
{
	char arr1[100] = "Infinity", arr2[100] = "Infi";
	char* arr;
	arr = (char*)malloc(sizeof(char) * 4);
	StrNCpy(arr, arr1, 4);
	
	if(0 == strcmp(arr, arr2))
	{
		printf("Test StrNCpy pass\n");
	}
}
void TestStrChr()
{
	char arr1[100] = "Infinity", arr2[100] = "inity";
	char* arr;
	arr = StrChr(arr1, 'i');
	if(0 == strcmp(arr, arr2))
	{
		printf("Test StrChr pass\n");
	}


}

void TestStrCat()
{
	char arr1[100] = "Infinity", arr2[100] = " Labs", arr3[100] = "Infinity Labs";
	
	StrCat(arr1, arr2);
	if(0 == strcmp(arr1, arr3))
	{
		printf("Test StrCat pass\n");
	}


}


void TestStrNCat()
{
	char arr1[100] = "Infinity", arr2[100] = " Labs", arr3[100] = "Infinity La";
	
	StrNCat(arr1, arr2, 3);
	if(0 == strcmp(arr1, arr3))
	{
		printf("Test StrNCat pass\n");
	}


}

void TestStrNCmp()
{
	char arr1[100] = "Infinity", arr2[100] = "Infiz", arr3[100] = "Infia", arr4[100] = "Infinityl";
	if(0 == StrNCmp(arr1, arr2, 3) && 0 > StrNCmp(arr1, arr2, 5) && 0 < StrNCmp(arr1, arr3, 5) && 0 > StrNCmp(arr1, arr4, 100))
	{
		
		printf("Test StrNCmp pass\n");
	}

}



