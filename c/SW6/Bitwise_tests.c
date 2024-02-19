#include <stdio.h> /*printf*/

#include "Bitwise.h"



void CheckPowTargil1();
void CheckPowTargil2();
void PlusOne();
void Count3Bits();
void ByteMiror();
void NoIf();
void SmallerDivideBy16();
void SwapBetween();
void BitCount();


#define SUR 0.000000001 


int main()
{	
	CheckPowTargil1();
	CheckPowTargil2();
	PlusOne();
	Count3Bits();
	ByteMiror();
	NoIf();
	SmallerDivideBy16();
	SwapBetween();
	BitCount();
	
	
	return 0;
}


void CheckPowTargil1()
{
	long result = 12;
	long func_result = Pow2(3, 2);
	if(result + SUR >= func_result && result - SUR <= func_result)
	{
		printf("Test Pow targil1 Pass\n");
	}
}
void CheckPowTargil2()
{
	if(0 == PowOfTwoWithFor(1) && 0 == PowOfTwoWithFor(0) && 1 == PowOfTwoWithFor(2) && 1 == PowOfTwoWithFor(4) && 0 == PowOfTwoWithFor(5))
	{
		printf("Test Pow targil2 with loop Pass\n");
	}
	
	if(1== PowOfTwoWithIf(4) && 0 == PowOfTwoWithIf(12) && 1 == PowOfTwoWithIf(8) && 1 == PowOfTwoWithIf(16) && 0 == PowOfTwoWithIf(5))
	{
		printf("Test Pow targil2 with if Pass\n");
	}
}


void PlusOne()
{

	if(4 == Plus1(3) && 5 == Plus1(4) && 46 == Plus1(45) && -2 == Plus1(-3) && 0 == Plus1(-1))
	{
		printf("Test Plus one Pass\n");
	}

}

void Count3Bits()
{
	unsigned int arr[3] = {7 , 14, 16};
	size_t size = 3;
	Count3(arr, size);
	printf("Count 3 bits pass\n");
	printf("\n");
}


void ByteMiror()
{

	if(15 == MirWithLoop(240) && 240 == MirWithLoop(15))
	{
		printf("Mirror test with loop pass\n");
	}
	
	if(15 == MirWithNoLoop(240) && 240 == MirWithNoLoop(15))
	{
		printf("Mirror test with no loop pass\n");
	}
	

}

void NoIf()
{
	if(0 == SixAndTwo(126) && 0 == SixAndTwo(127) && 1 == SixAndTwo(128) && 1 == SixAndTwo(129))
	{
		printf("Test No If part 1 passed\n");
	
	}
	if(0 == SixOrTwo(11) && 0 == SixOrTwo(32) && 1 == SixOrTwo(8) && 1 == SixOrTwo(5))
	{
		printf("Test No If part 2 passed\n");
	
	}
	if(16 == SwapBit(4, 2, 4) && 17 == SwapBit(5, 2, 4))
	{
		printf("Test No If part 3 passed\n");
	
	}
}
void SmallerDivideBy16()
{
	if(32 == DivideBy16(35) && 64 == DivideBy16(65) && 16 == DivideBy16(18) && 0 == DivideBy16(5) && 112 == DivideBy16(126) && 128 == DivideBy16(132))
	{
		printf("Test Smaller Divided by 16 pass\n");
	}
}

void SwapBetween()
{
	int number1 = 35;
	int number2 = 10;
	Swap(&number1, &number2);
	if(10 == number1 && 35 == number2)
	{
	
		printf("Test Swap pass\n");
	
	}

}
void BitCount()
{
	if(1 == BitCounterWithLoop(1) && 32 == BitCounterWithLoop(-1) && 4 == BitCounterWithLoop(15) && 29 == BitCounterWithLoop(-15))
	{
	
		printf("Test bit counter with loop pass\n");
	
	}
	if(1 == BitCounterWithNoLoop(1) && 32 == BitCounterWithNoLoop(-1) && 4 == BitCounterWithNoLoop(15) && 29 == BitCounterWithNoLoop(-15))
	{
	
		printf("Test bit counter with no loop pass\n");
	
	}


}



