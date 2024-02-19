#include <stdio.h> /*printf*/

#include "Bitwise.h" /*add functions*/



void PrintBit(unsigned char x);
int PowOfTwoWithIf(unsigned int x);
int PowOfTwoWithFor(unsigned int x);
void PrintFloat(float number);
void Count3(unsigned int *arr, size_t size);
static size_t BitCounter(int x);
int BitCounterWithNoLoop(int x);
int BitCounterWithLoop(int x);
int MirWithLoop(unsigned char x);
int SixAndTwo(int number);
int SixOrTwo(int number);
int SwapBit(unsigned char number, unsigned int location1, unsigned int location2);
unsigned int DivideBy16(unsigned int number);
int MirWithNoLoop(unsigned char x);
int MirWithLoop(unsigned char x);
void Swap(int *number1, int *number2);
int Plus1(int number);

#define MAX 31

long Pow2(unsigned int x, unsigned int y)
{
	return (long)x << y;
}

int PowOfTwoWithFor(unsigned int x) /*done*//*fix*/
{
	size_t i = 1;
	int counter = 0;
	
	if(!(x & (1 << 0)))
	{
		while(2 != counter && MAX != i)
		{
			if( x & (1 << i))
			{
				++counter;
			}
			++i;
		} 
		if(1 == counter)
		{
			return 1;
		}
	}
	return 0;
}

int PowOfTwoWithIf(unsigned int x) /*done*/
{
	return (!(x & (x-1)));
	
}

int Plus1(int number) /*done*/
{
	int i = 0;
	for(i = 0; i <= MAX; ++i)
	{
		if( number & (1 << i))
		{
			number^=(1 << i);
		}
		else
		{
			number^=(1 << i);

			break;
		}
	}
	return number;
}

int SixAndTwo(int number)/*done*/
{

	return !((number & (1 << 5 )) && (number & (1 << 1 )));
	
}


int SixOrTwo(int number) /*done*/
{

	return !( number & (1 << 5 ) || number & (1 << 1 ) );
}

int SwapBit(unsigned char number, unsigned int location1, unsigned int location2) /*done*/
{
	unsigned int bit1 = 0;
	unsigned int bit2 = 0;
	int xor_num = 0;
	int num2 = 0;
	bit1 = ((number >> location1) & 1);
	bit2 = ((number >> location2) & 1);
	xor_num = (bit1^bit2);
	num2 = (xor_num << location1)|(xor_num << location2);
	return number^num2;
}


unsigned int DivideBy16(unsigned int number) /*done*/
{
	number = number >> 4;
	number = number << 4;
	return number;
}

void Count3(unsigned int *arr, size_t size) /*done*/
{
	size_t i = 0;
	unsigned int counter = 0;
	while(i < size)
	{
		counter = BitCounter(*arr);
		if(3 == counter)
		{
			printf("The number is %d\n", *arr);
		}
		++i;
		++arr;
	}
}

unsigned char MirWithLoop(unsigned char x)    /*done*/
{

	int i = 0;
	int y = 0;
	int j = 7;
	
	for(i = 0; i <= 7; ++i)
	{
		if( x & (1 << i))
		{
			y^=(1 << j);
		}
		--j;
	}

	
	return y;
	
}
int MirWithNoLoop(unsigned char num)   /*done*/
{
	static int flag = 0;
	static int Table[256] = {0};
	size_t i = 0;
	if(0 == flag)
	{
		
		flag = 1;
		for(i = 0; i < 256; ++i)
		{
			Table[i] = MirWithLoop(i);
		}
		
	}
	return Table[num];
}




static size_t BitCounter(int x) /*done*/
{
	int i = 0;
	int counter = 0;
	
	for(i = 31; i >= 0; --i)
	{
		if( x & (1 << i))
		{
			counter++;
		}
	}
	return counter;
}
void PrintBit(unsigned char x)
{
	int i=0;

	for(i=7;i>=0;--i)
	{
		if( x & (1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		
		}
	}
	printf("\n");
}


int BitCounterWithLoop(int x) /*done*/
{
	size_t counter = 0;
	while(0 != x)
	{
		x = x & (x-1);
		++counter;
	
	}
	return counter;
}

int BitCounterWithNoLoop(int x) /*done*/
{
	static int Table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	int result = 0;
	int i = 0;	
	for(i = 0; i < 8; ++i)
	{
		result += Table[x & 15];
		x = x >> 4;
	}
	return result;
}
void Swap(int *number1, int *number2) /*done*/
{
	*number1 = *number1^*number2;
	*number2 = *number2^*number1;
	*number1 = *number1^*number2;
}



void PrintFloat(float number) /*done*/
{
	int i = 0;
	int *pointer = NULL;
	pointer = (int *)&number;
	
	for(i = MAX; i >= 0; --i)
	{
		if( *pointer & (1 << i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		
		}
	}
	printf("\n");
}
