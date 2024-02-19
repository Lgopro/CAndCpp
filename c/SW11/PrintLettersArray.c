#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/ 

void PrintChars(char *print_from_me1, char *print_from_me2, char *dont_print_from_me);



int main()
{	
	char print_me1[] = "Print me abc!";
	char print_me2[] = "NO! Print me eha!";
	char dont_print_me[] = "HEHE.. dont print them";
	PrintChars(print_me1, print_me2, dont_print_me);
	return 0;
}

static int *PrintMe(char *print_from_me1, int *small_and_big_letters)
{
	while('\0' != *print_from_me1)
	{
		if(0 <=*print_from_me1 - 'a' && 26 > *print_from_me1 - 'a')
		{
			small_and_big_letters[(*print_from_me1 - 'a')] = 1;
		}
		else if(0 <= (*print_from_me1 - 'A') && 26 > (*print_from_me1 - 'A'))
		{
			small_and_big_letters[(*print_from_me1 - 'A') + 26] = 1;
		}
		++print_from_me1;
	}
	return small_and_big_letters;
}

static int *PrintMeTwo(char *print_from_me2, int *small_and_big_letters)
{
	while('\0' != *print_from_me2)
	{
		if(0 <=*print_from_me2 - 'a' && 26 > *print_from_me2 - 'a' && 1 == small_and_big_letters[(*print_from_me2 - 'a')])
		{
			small_and_big_letters[(*print_from_me2 - 'a')] = 2;
		}
		else if(0 <= (*print_from_me2 - 'A') && 26 > (*print_from_me2 - 'A') && 1 == small_and_big_letters[(*print_from_me2 - 'A') + 26])
		{
			small_and_big_letters[(*print_from_me2 - 'A') + 26] = 2;
		}
		++print_from_me2;
	}
	return small_and_big_letters;
}

static int *DontPrintMe(char * print_from_me1, int *small_and_big_letters)
{
	
	while('\0' != *print_from_me1)
	{
		if(0 <=*print_from_me1 - 'a' && 26 > *print_from_me1 - 'a')
		{
			small_and_big_letters[(*print_from_me1 - 'a')] = 0;
		}
		else if(0 <=*print_from_me1 - 'A' && 26 > *print_from_me1 - 'A')
		{
			small_and_big_letters[(*print_from_me1 - 'A') + 26] = 0;
		}
		++print_from_me1;
	}
	return small_and_big_letters;



}

static void Print(int *print_from_me)
{
	size_t i = 0;
	for(i = 0; i < 26; ++i)
	{
		if( 2 == *(print_from_me + i))
		{
			printf("%c, ", (char)(i + 97));
		}
	}
	for(i = 26; i < 52; ++i)
	{
		if( 2 == *(print_from_me + i))
		{
			printf("%c, ", (char)(i + 39));
		}
	}
	printf("\n");

}


void PrintChars(char *print_from_me1, char *print_from_me2, char *dont_print_from_me)
{
	int *small_and_big_letters = calloc(52, sizeof(int));
	
	assert(NULL != print_from_me1);
	assert(NULL != print_from_me2);
	assert(NULL != dont_print_from_me);
	
	if(NULL == small_and_big_letters)
	{
		return;
	}
	
	small_and_big_letters = PrintMe(print_from_me1 ,small_and_big_letters);
	small_and_big_letters = PrintMeTwo(print_from_me2, small_and_big_letters);
	small_and_big_letters = DontPrintMe(dont_print_from_me, small_and_big_letters);
	Print(small_and_big_letters);
	free(small_and_big_letters);
}
