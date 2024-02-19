#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/


int FlipDigitsInNum(int number);

int main()
{
	int flip = 0;
	flip = FlipDigitsInNum(-597);
	printf("The flip is: %d\n", flip);
	return 0;
}

int FlipDigitsInNum(int number)
{
	int sign = 1;
	int digit = 0;
	int flip_number = 0;
	if(0 > number)
	{
		sign = -1;
		number *= -1;
	}
	while(0 != number)
	{
		flip_number *= 10;
		digit = number % 10;
		flip_number += digit;
		number /= 10;
	}
	return flip_number * sign;
	
}
