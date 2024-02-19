/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date:16/04/23
*/

#include <stdio.h> /*printf*/
#include <string.h> /*strcpy*/
#include <stdlib.h> /*strcpy*/
#include <assert.h> /*assert*/ 

#include "ItoaAtoi.h"

#define CHARTOINT 48
#define LETTERTOINT 55
#define MAXINT 2147483647
#define MININT -2147483648

int AtoIBaseTen(const char *nptr)
{
	long number = 0;
	int sign = 1;
	
	assert(NULL != nptr);
	
	if( '-' == *nptr)
	{
		sign = -1;
		++nptr;
	
	}
	
	if( '+' == *nptr)
	{
		++nptr;
	}
	
	while('\0' != *nptr)
	{
		number *= 10;
		number += (long)*nptr - CHARTOINT;
		++nptr;
	}
	
	while(MAXINT < number)
	{
		number -= -2 * MININT;
	}
	
	while(MININT > number)
	{
		number += -2 * MININT;
	}
	return (int)number * sign;
}


char *ItoABaseTen(int number, char *str, int base)
{
	size_t i = 0;
	size_t sign = 0;
	size_t counter = 0;
	
	assert(NULL != str);
	assert( 1 < base && base < 37);
	
	(void)base;
	if(0 > number)
	{
		*str = '-';
		sign = 1;
		++counter;
		number *= -1;
	}
	if(0 == number)
	{
		*str = '0';
		*(str + 1) = '\0';
	}
	while(0 != number)
	{
		i = counter;
		*(str + sign) = (char)(number % 10 + CHARTOINT);
		++counter;
		if(0 != number && 0 == number / 10)
		{
			break;
		}
		else if(0 != number)
		{
			while(sign - 1!= i)
			{
				str[i + 1] = str[i];
				--i;
			}
			
		}
		else
		{
			break;
		
		}
		number /= 10;
	}
	*(str + counter) = '\0';
	return str;
}


char *ItoA(int value, char *str, int base)
{
	size_t result = 0;
	int i = 0;
	size_t counter = 0;
	char *runner = str;
	static char table[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' , 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T','U', 'V', 'W', 'X', 'Y', 'Z'};
	
	assert(NULL != str);
	assert( 1 < base && base < 37);
	
	if(10 == base)
	{
		return ItoABaseTen(value, str, 10);
	} 
	
	while(0 != value)
	{
		i = (int)counter;
			
		result = value % base; 
		str[0] = table[result];
		value /= base; 
			
		++runner;
		++counter;
			
		if(0 == value)
		{
			break;
		}
		else
		{
			while(-1 != i)
			{
				str[i + 1] = str[i];
				--i;
			}
		}
			
			
	}
	*runner = '\0';
	
	return str;
}

int AtoI(int value, char *str, int base)
{
	int number = 0;
	int increase = 1;
	size_t length = strlen(str);
	
	assert(NULL != str);
	assert( 1 < base && base < 37);
	
	if(10 == base)
	{
		return AtoIBaseTen((const char *)str);
	} 
	while(-1 != (int)length - 1)
	{
		if( '0' <= str[length - 1] && '9' >= str[length - 1])
		{
			number = str[length - 1] - CHARTOINT;
			value += number * increase;

		}
		else
		{
			number = str[length - 1] - LETTERTOINT;
			value += number * increase;
		}
		--length;
		increase *= base;
	}
	
	return value;
}






