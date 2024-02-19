#include <stdio.h>
#include <string.h>
#include <assert.h>
/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:19/03/23
*/
int StrCmp(const char *s1, const char *s2);
void Test1();
void Test2();
void Test3();
void Test4();
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	return 0;
}




int StrCmp(const char *s1, const char *s2)
{
	int i = 0, result;
	assert(NULL != s1);
	assert(NULL != s2);
	while('\0' != s1[i])
	{
		result = s1[i] - s2[i];
		if(0 != result)
		{
			return result;
			
		}
		i++;
		if('\0' == s1[i] && '\0' != s2[i])
		{
			return -1;
		}
		if('\0' != s1[i] && '\0' == s2[i])
		{
			return 1;
		}
	}
	return result;
	



}
void Test1()
{
	int answer;
	char arr[] = "Hello!", arr2[] = "Hella!";
	
	answer = StrCmp(arr,arr2);
	( 0 < answer ) ? printf("Test 1 Pass\n") : printf("Test 1 failed");


}

void Test2()
{
	int answer;
	char arr[] = "Hello!", arr2[] = "Hello!aaa";
	
	answer = StrCmp(arr,arr2);
	(-1 == answer) ? printf("Test 2 Pass\n") : printf("Test 2 failed");


}

void Test3()
{
	int answer;
	char arr[] = "Hello!aaa", arr2[] = "Hello!";
	
	answer = StrCmp(arr,arr2);
	(1 == answer) ? printf("Test 3 Pass\n") : printf("Test 3 failed");


}

void Test4()
{
	int answer;
	char arr[] = "Hella!", arr2[] = "Hello!";
	
	answer = StrCmp(arr,arr2);
	(0 > answer) ? printf("Test 4 Pass\n") : printf("Test 4 failed");


}
