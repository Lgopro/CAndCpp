#include <stdio.h> /*printf*/
#include <stdlib.h>  /*rand()*/
#include <assert.h>  /*assert*/


void MillionTimesCharPrint(unsigned char ch);

int main()
{
	size_t i = 0;
	char string[] = "Bro BRO please work WW  BBBBBBBBBB    ";
	char string1[] = "Bro BRO please work WW EHHEHEHEHEEHEHEHHEHEHEEHEHEHEHEHEHEHEEEE BBBBBBBBBB    ";
	while(i < sizeof(string))
	{
		MillionTimesCharPrint(string[i]);
		++i;
	}
	i = 0;
	while(i < sizeof(string1))
	{
		MillionTimesCharPrint(string1[i]);
		++i;
	}
	return 0;
}

void MillionTimesCharPrint(unsigned char ch)
{
	static size_t arr[255] = {0};
	static size_t counter = 0;
	static char biggest_char = 0;
	size_t i = 0; 
	
	
	if(0 == (int)ch)
	{
		printf("The char that is met the most amount of times is: %c and the amount of times it was entered was %ld times\n", biggest_char, counter);
		counter = 0;
		biggest_char = 0;
		for(i = 0; i < 256; ++i)
		{
			*(arr + i) = 0;
		}
	}
	else
	{
		*(arr + (int)ch) += 1;
		if(counter < *(arr + (int)ch))
		{
			counter = *(arr + (int)ch);
			biggest_char = ch;
		}	
	}
}
