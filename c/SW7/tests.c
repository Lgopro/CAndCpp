#include <stdio.h> /*printf*/
#include <stdlib.h>








int main()
{	
	char str1[20];
	char *str2 = malloc(sizeof(*str2) *20);
	char *str3 = "whatever";
	char str4[] = "whatever";
	str3[1] = 'a';
	return 0;
}
