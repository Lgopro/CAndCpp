#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define EQUAL 0
/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:19/03/23
*/
void Copy(char *init,int size_t, char *copied);

int main()
{
	char arr[] = "Infinity", arr_copy[sizeof(arr)/sizeof(arr[0])];
	Copy(arr, sizeof(arr)/sizeof(arr[0]), arr_copy);
	
	
	if(EQUAL == strcmp(arr, arr_copy))
	{
		printf("Test pass");
	
	}
	
	printf("\n");
	return 0;
}




void Copy(char *init,int length, char *copied)
{
	int i;
	assert(NULL != init);
	assert(NULL != copied);
	for(i = 0; i < length; i++)
	{
		copied[i] = init[i];
		
	
	}
	copied[i] = '\0';
	
	return;


}
