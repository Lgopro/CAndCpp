#include <stdio.h>
#include <stdlib.h>
void Test2(int i);
void Test3(int i);
void Test4(int i);
void Test5(int i);
int main()
{
	Test2(0);
	Test3(0);
	Test4(0);
	Test5(1);
	return 0;

}



void Test2(int i)
{
	char *arr;
	if(1 == i)
	{
		
		arr =(char *)malloc(sizeof(char) * 1000);
	
		free(arr);
	}
}

void Test3(int i)
{
	int *arr;
	if(1 == i)
	{
		arr =(int *)malloc(sizeof(int) * 10);
		printf("%d", arr[11]);
	}
	free(arr);
}
void Test4(int i)
{
	int *arr;
	if(1 == i)
	{
		arr =(int *)malloc(sizeof(int) * 10);
		free(arr);
		printf("%d", arr[9]);
	}
}

void Test5(int i)
{
	int *arr;
	if(1 == i)
	{
		arr =(int *)malloc(sizeof(int) * 10);
		if(6 == arr[6])
		{
			printf("Very good");
		}
		free(arr);
		
	}
}
