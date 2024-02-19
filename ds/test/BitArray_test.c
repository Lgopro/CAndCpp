/*
Rev: Greg Markovski
Dev: Leonid Golovko
status: finished
date:19/04/23
*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/

#include "BitArray.h"

#define MAX 0xffffffffffffffff

void BitArrSetOnTest();
void BitArrSetOffTest();
void BitArrSetTest();
void BitArrGetValTest();
void BitArrSetAllTest();
void BitArrResetAllTest();
void BitArrCountOnTest();
void BitArrCountOffTest();
void BitArrFlipTest();
void BitArrRotateLeftTest();
void BitArrRotateRightTest();
void BitArrMirrorTest();
void BitArrToStringTest();
void BitCounterWithLUTTest();
void BitMirrorWithLUTTest();

int main()
{	
	BitArrSetOnTest();
	BitArrSetOffTest();
	BitArrSetTest();
	BitArrGetValTest();
	BitArrSetAllTest();
	BitArrResetAllTest();
	BitArrCountOnTest();
	BitArrCountOffTest();
	BitArrFlipTest();
	BitArrRotateLeftTest();
	BitArrRotateRightTest();
	BitArrMirrorTest();
	BitArrToStringTest();
	BitCounterWithLUTTest();
	BitMirrorWithLUTTest();
	return 0;
}

void BitArrSetTest()
{
	if(1 == BitArrSet(0, 0, 1) && 2 == BitArrSet(0, 1, 1) && 4 == BitArrSet(0, 2, 1))
	{
		printf("Test BitArrSetOnTest pass\n");
	}
	else
	{
		printf("Test BitArrSetOnTest fail\n");
	}


}

void BitArrSetOnTest()
{
	if(1 == BitArrSetOn(0, 0) && 2 == BitArrSetOn(0, 1) && 4 == BitArrSetOn(0, 2) && 8 == BitArrSetOn(0, 3))
	{
		printf("Test BitArrSetOnTest pass\n");
	}
	else
	{
		printf("Test BitArrSetOnTest fail\n");
	}
}

void BitArrSetOffTest()
{
	if(14 == BitArrSetOff(15, 0) && 13 == BitArrSetOff(15, 1) && 11 == BitArrSetOff(15, 2) && 7 == BitArrSetOff(15, 3))
	{
		printf("Test BitArrSetOffTest pass\n");
	}
	else
	{
		printf("Test BitArrSetOffTest fail\n");
	}	
}

void BitArrGetValTest()
{
	
	if(1 == BitArrGetVal(15, 0) && 1 == BitArrGetVal(15, 1) && 0 == BitArrGetVal(15, 7) && 1 == BitArrGetVal(15, 3))
	{
		printf("Test BitArrGetVal pass\n");
	}
	else
	{
		printf("Test BitArrGetVal fail\n");
		
	}	
}
void BitArrResetAllTest()
{
	if(0 == BitArrResetAll(999) && 0 == BitArrResetAll(222))
	{
		printf("Test BitArrResetAllTest pass\n");
	}
	else
	{
		printf("Test BitArrResetAllTest fail\n");
		
	}	
}
void BitArrCountOnTest()
{
	if(4 == BitArrCountOn(15) && 1 == BitArrCountOn(32) && 5 == BitArrCountOn(31))
	{
		printf("Test BitArrCountOnTest pass\n");
	}
	else
	{
		printf("Test BitArrCountOnTest fail\n");
		
	}	


}
void BitArrCountOffTest()
{
	if(60 == BitArrCountOff(15) && 63 == BitArrCountOff(32) && 59 == BitArrCountOff(31))
	{
		printf("Test BitArrCountOffTest pass\n");
	}
	else
	{
		printf("Test BitArrCountOffTest fail\n");
		
	}	


}

void BitArrFlipTest()
{
	if(31 == BitArrFlip(15, 4) && 13 == BitArrFlip(15, 1) && 7 == BitArrFlip(15, 3))
	{
		printf("Test BitArrFlipTest pass\n");
	}
	else
	{
		printf("Test BitArrFlipTest fail\n");
		
	}	


}
void BitArrSetAllTest()
{
	if(MAX == BitArrSetAll(2323))
	{
		printf("Test BitArrSetAllTest pass\n");
	}
	else
	{
		printf("Test BitArrSetAllTest fail\n");
	}	
}

void BitArrRotateLeftTest()
{
	if(30 == BitArrRotateLeft(15, 1) && 15 == BitArrRotateLeft(15, 64) && 30 == BitArrRotateLeft(15, 65))
	{
		printf("Test BitArrRotateLeftTest pass\n");
	}
	else
	{
		printf("Test BitArrRotateLeftTest fail\n");
	}	


}

void BitArrRotateRightTest()
{
	if(0x8000000000000007 == BitArrRotateRight(15, 1) && 15 == BitArrRotateRight(15, 64) && 0x8000000000000007 == BitArrRotateRight(15, 65))
	{
		printf("Test BitArrRotateRightTest pass\n");
	}
	else
	{
		printf("Test BitArrRotateRightTest fail\n");
	}	


}

void BitArrMirrorTest()
{
	if(0x8000000000000000 == BitArrMirror(1) && 0xE000000000000000 == BitArrMirror(7))
	{
		printf("Test BitArrMirrorTest pass\n");
	}
	else
	{
		printf("Test BitArrMirrorTest fail\n");
	}	
}
void BitMirrorWithLUTTest()
{
	if(0x8000000000000000 == BitArrMirrorLUT(1) && 0xE000000000000000 == BitArrMirrorLUT(7))
	{
		printf("Test BitMirrorWithLUTTest pass\n");
	}
	else
	{
		printf("Test BitMirrorWithLUTTest fail\n");
	}	

}

void BitArrToStringTest()
{
	char result[65] = "0000000000000000000000000000000000000000000000000000000000000111";
	char *result1 = malloc(65);
	if(0 == strcmp(result, BitArrToString(7, result1)))
	{
		printf("Test BitArrToStringTest pass\n");
		
	}
	else
	{
		printf("Test BitArrMirrorTest fail\n");
	}	

	free(result1);


}


void BitCounterWithLUTTest()
{
	if(4 == BitArrCountLUT(15) && 1 == BitArrCountLUT(32) && 5 == BitArrCountLUT(31))
	{
		printf("Test BitCounterWithLUTTest pass\n");
	}
	else
	{
		printf("Test BitCounterWithLUTTest fail\n");
		
	}	


}



