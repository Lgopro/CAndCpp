#include <stdio.h>
#define NUMNEG -1;
#define TURNPOS -1;
#define FAIL 0;

/** 
 * @brief flipts number digits
 * 
 * @returns int number with flipped digits
 * @retval 0 if number is bigger than the max int number
 */
int Flip(int number);
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;

}



int Flip(int number)
{
	int swapNumber = 0, digit, flag = 0;
	if(number < 0)
	{
		flag = NUMNEG;
		number *= TURNPOS;
	}

	while(number >= 10)
	{	
		digit = number % 10;
		swapNumber += digit;
		swapNumber *= 10;
		if(swapNumber > 214748365)
		{
			return FAIL;
		}
		number /= 10;
	}
	if(flag == -1)
	{
		return flag * (swapNumber + number) ; 
	}
	return (swapNumber + number);
	


}

void Test1()
{
	int result;
	result = Flip(5);
	(result == 5) ? printf("Test 1 Pass\n") : printf("Test 1 failed");
	return;

}
void Test2()
{
	int result;
	result = Flip(-5);
	(result == -5) ? printf("Test 2 Pass\n") : printf("Test 2 failed");
	return;

}
void Test3()
{
	int result;
	result = Flip(-4675);
	(result == -5764) ? printf("Test 3 Pass\n") : printf("Test 3 failed");
	return;

}
void Test4()
{
	int result;
	result = Flip(1234567);
	(result == 7654321) ? printf("Test 4 Pass\n") : printf("Test 4 failed");
	return;

}
void Test5()
{
	int result;
	result = Flip(2147483646);
	(result == 0) ? printf("Test 5 Pass\n") : printf("Test 5 failed");
	return;

}
