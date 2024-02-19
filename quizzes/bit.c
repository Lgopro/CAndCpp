#include <stdio.h> /*printf*/


void Swap(int *x, int *y);
size_t CountCouple(unsigned char num);
size_t CountBits(long number);
int main()
{
	size_t result = 0;
	int x = 5, y = 11;
	result = CountCouple(30);
	printf("The result is: %ld\n", result);
	result = CountCouple(31);
	printf("The result is: %ld\n", result);
	result = CountCouple(32);
	printf("The result is: %ld\n", result);
	Swap(&x, &y);
	printf("x is %d and y is %d\n", x, y);
	result = CountBits(124);
	printf("The result is: %ld\n", result);
	
	
	return 0;
}

size_t CountCouple(unsigned char num)
{
	size_t i = 0;
	size_t counter = 0;
	size_t flag = 0;
	for(i = 0; i < 8; ++i)
	{
		if(num & (1 << i) && 1 == flag)
		{
			++counter;
			flag = 1;
		}
		else if(num & (1 << i))
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	
	}
	return counter;
}

void Swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

size_t CountBits(long number)
{
	size_t count = 0;
	while(0 != number)
	{
		number = number&(number-1);
		++count;
	}
	return count;


}
