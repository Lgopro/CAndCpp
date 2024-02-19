#include <stdio.h>

void Swap(int* firstNumber, int* SecondNumber);
void Test1();
void Test2();
void Test3();
void Test4();
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	
	return 0;

}



void Swap(int* firstNumber, int* secondNumber)
{
	int swap;
	swap = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = swap;


}


void Test1()
{
	int num1 = 5, num2 = 6;
	Swap(&num1, &num2);
	(num1 == 6 && num2 == 5) ? printf("Test 1 Pass\n") : printf("Test 1 failed");
	return;

}
void Test2()
{
	int num1 = -10, num2 = 6;
	Swap(&num1, &num2);
	(num1 == 6 && num2 == -10) ? printf("Test 2 Pass\n") : printf("Test 2 failed");
	return;

}
void Test3()
{
	int num1 = 0, num2 = 6;
	Swap(&num1, &num2);
	(num1 == 6 && num2 == 0) ? printf("Test 3 Pass\n") : printf("Test 3 failed");
	return;

}
void Test4()
{
	int num1 = -5, num2 = -6;
	Swap(&num1, &num2);
	(num1 == -6 && num2 == -5) ? printf("Test 4 Pass\n") : printf("Test 4 failed");
	return;

}
