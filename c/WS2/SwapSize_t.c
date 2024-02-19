#include <stdio.h>
/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:19/03/23
*/
void Swap(long unsigned int *first_number, long unsigned int *second_number);
void SwapTwoSizet(long unsigned int **first_number, long unsigned int **second_number);
void SwapTwoPointers(void **first_pointer, void **second_pointer);
void Test1();
void Test2();
void Test3();



int main()
{
	Test1();
	Test2();
	Test3();
	return 0;

}



void Swap(long unsigned int *first_number, long unsigned int *second_number)
{
	long unsigned int swap;
	swap = *first_number;
	*first_number = *second_number;
	*second_number = swap;


}
void SwapTwoSizet(long unsigned int **first_number, long unsigned int **second_number)
{
	long unsigned int *swap;
	swap = *first_number;
	*first_number = *second_number;
	*second_number = swap;

}
void SwapTwoPointers(void **first_pointer, void **second_pointer)
{

	SwapTwoSizet((long unsigned int**) first_pointer, (long unsigned int**) second_pointer);

}

void Test1()
{
	long unsigned int num1 = 5, num2 = 6;
	Swap(&num1, &num2);
	(6 == num1 && 5 == num2) ? printf("Test 1 Pass\n") : printf("Test 1 failed");
	return;

}



void Test2()
{
	long unsigned int number1 = 15, number2= 16;
	long unsigned int* num1 = &number1;
	long unsigned int* num2 = &number2;
	SwapTwoSizet(&num1, &num2);
	(16 == *num1 && 15 == *num2) ? printf("Test 2 Pass\n") : printf("Test 2 failed\n");
	return;

}


void Test3()
{
	long unsigned int number1 = 15, number2= 16;
	long unsigned int* num1 = &number1;
	long unsigned int* num2 = &number2;
	SwapTwoPointers((void**)&num1, (void**)&num2);
	(16 == *num1 && 15 == *num2) ? printf("Test 3 Pass\n") : printf("Test 3 failed");
	return;

}




