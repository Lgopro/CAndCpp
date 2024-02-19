#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ACCURACY 0.0000000001

/** 
 * @brief power ten by number
 * 
 * @returns double number of the result
 * @retval -1 if number is bigger than 20
 */
double PowTen(int number);

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



double PowTen(int number)
{
	int i = 0, answer = 1, flag = 0;
	if(number < 0)
	{
		flag = 1;
		number *= -1;
	}
	if(number > 20)
	{
		return -1;
		
	}
	while(i != number)
	{
		answer *= 10;
		i++;
	
	}
	return (flag == 0) ? answer : (float)1/answer;


}

void Test1()
{
	double result;
	result = PowTen(2);
	(result == 100) ? printf("Test 1 Pass\n") : printf("Test 1 failed\n");
	return;

}
void Test2()
{
	double result, test = 0.000010;
	result = PowTen(-5);
	((result - test) < ACCURACY && (result - test) > -ACCURACY) ? printf("Test 2 Pass\n") : printf("Test 2 failed\n");
	return;

}
void Test3()
{
	double result;
	result = PowTen(2);
	(result == 100) ? printf("Test 3 Pass\n") : printf("Test 3 failed\n");
	return;

}
void Test4()
{
	double result, test = 0.000100;
	result = PowTen(-4);
	((result - test) < ACCURACY && (result - test) > -ACCURACY) ? printf("Test 4 Pass\n") : printf("Test 4 failed\n");
	return;

}

void Test5()
{
	double result;
	result = PowTen(21);
	(result == -1) ? printf("Test 5 Pass\n") : printf("Test 5 failed\n");
	return;

}
