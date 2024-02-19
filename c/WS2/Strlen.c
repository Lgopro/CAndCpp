#include <stdio.h>
#include <assert.h>
#define LENGTH 6
/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:19/03/23
*/
size_t Strlen(const char *s);

int main()
{
	int answer;
	char arr[] = "Hello!";
	answer = Strlen(arr);
	if(LENGTH == answer)
	{
		printf("Test pass\n");
		
	}
	return 0;
}




size_t Strlen(const char *s)
{
	int i = 0;
	assert(NULL != s);
	while('\0' != s[i])
	{
		i++;
	}
	return i;
	



}
