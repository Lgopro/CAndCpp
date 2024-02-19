#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>

void Reverse(char *str,size_t length, char* copy_str);

int main()
{
	char arr1[] = "HEllo woRLD", arr2[12] = {0};
	Reverse(arr1, 11, arr2);
	puts(arr2);
	return 0;
}

void Reverse(char *str,size_t length, char* copy_str)
{
	assert(NULL != str && NULL != copy_str);
	copy_str = copy_str + length - 1;
	while('\0' != *str)
	{
		
			
		*copy_str = tolower(*str);
		--copy_str;
		++str;
		
	
	}





}
