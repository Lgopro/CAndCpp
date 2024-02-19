
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *ItoA(int number, char *str, int base);

int main()
{
	char* string;
	string = (char *)malloc(100);
	string = ItoA(325, string, 10);
	puts(string);
	return 0;
}

char *ItoA(int number, char *str, int base)
{
	int check_number = number;
	int sign = 0;
	size_t counter = 0;
	size_t digit = 0;
	static char table[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' , 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V', 'W', 'X', 'Y', 'Z'};
	
	assert(NULL != str);
	assert( 1 < base && base < 37);
	
	if(0 > number)
	{
		sign = 1;
		number *= -1;
		++counter;
	}
	
	while(0 != check_number)
	{
		check_number /= base;
		++counter;
	}
	
	*(str + counter) = '\0';
	--counter;
	while(0 != number)
	{
		digit = number % base;
		*(str + counter) = *(table + digit);
		number /= base;
		--counter;
	}
	
	if(1 == sign)
	{
		*str = '-';
	}
	return str;
}
