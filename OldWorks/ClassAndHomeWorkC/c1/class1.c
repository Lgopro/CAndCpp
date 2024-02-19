#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void PrintArray(char _arr[], int _num);
void PrintArray(char _arr[], int _num)
{
	int i;
	printf("The string is:\n");
	for(i=0;i<_num;i++)
	{
			
		printf("%c", _arr[i]);
	}
	return;
}




int main()
{
	char arr[100];
	printf("Please enter an array up to 100 digits:\n");
	fgets(arr, 100, stdin);
	PrintArray(arr,strlen(arr));
	return 0;
}
