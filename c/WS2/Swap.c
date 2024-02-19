#include <stdio.h>
/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:19/03/23
*/
void Swap(int* first_number, int* second_number);
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



void Swap(int* first_number, int* second_number)
{
	int swap;
	swap = *first_number;
	*first_number = *second_number;
	*second_number = swap;


}


void Test1()
{
	int num1 = 5, num2 = 6;
	Swap(&num1, &num2);
	(6 == num1 && 5 == num2) ? printf("Test 1 Pass\n") : printf("Test 1 failed");
	return;

}
void Test2()
{
	int num1 = -10, num2 = 6;
	Swap(&num1, &num2);
	(6 == num1 && -10 == num2) ? printf("Test 2 Pass\n") : printf("Test 2 failed");
	return;

}
void Test3()
{
	int num1 = 0, num2 = 6;
	Swap(&num1, &num2);
	(6 == num1 && 0 == num2) ? printf("Test 3 Pass\n") : printf("Test 3 failed");
	return;

}
void Test4()
{
	int num1 = -5, num2 = -6;
	Swap(&num1, &num2);
	(-6 == num1 && -5 == num2) ? printf("Test 4 Pass\n") : printf("Test 4 failed");
	return;

}
