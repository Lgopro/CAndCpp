/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date:16/04/23
*/

#include <stdio.h> /*printf*/
#include <string.h> /*strcpy*/
#include <stdlib.h> /*malloc*/

#include "ItoaAtoi.h"

void AtoITest();
void ItoATest();
void ItoAAnybaseTest();
void AtoIAnybaseTest();
int main()
{	
	AtoITest();
	ItoATest();
	ItoAAnybaseTest();
	AtoIAnybaseTest();
	return 0;
}
void AtoIAnybaseTest()
{
	char number1[11] = "1111";
	char number2[11] = "ABCD";
	int value = 0;
	int value1 = 0;
	if(43981 == AtoI(value, number2, 16) && 15 == AtoI(value1, number1, 2))
	{
		printf("atoi test for all bases test passed\n");
	}
	else
	{
		printf("atoi test for all bases test failed\n");
	}

}


void AtoITest()
{
	
	char number1[11] = "14536";
	char number2[11] = "-14536";
	char number3[11] = "-14536555";
	char number4[11] = "14536445";
	char number5[11] = "2147483650";
	if(atoi(number1) == AtoIBaseTen(number1) && atoi(number2) == AtoIBaseTen(number2) && atoi(number3) == AtoIBaseTen(number3) && atoi(number4) == AtoIBaseTen(number4) &&  atoi(number5) == AtoIBaseTen(number5))
	{
		printf("atoi test passed\n");
	}
	else
	{
		printf("atoi test failed\n");
	}
}

void ItoATest()
{
	char *result = (char *)malloc(sizeof(char) * 11);
	char *result1 = (char *)malloc(sizeof(char) * 11);
	char *begin = result;
	char *check = NULL;
	char compare[] = "15";
	char compare1[] = "-325";
	begin = " ";
	begin = ItoABaseTen(15, result, 10);
	check = " ";
	check = ItoABaseTen(-325, result1, 10);
	if(0 == strcmp(check, compare1) && 0 == strcmp(begin, compare))
	{
		printf("itoa test passed\n");
	}
	else
	{
		printf("itoa test failed\n");
	}
	free(result);
	free(result1);
}



void ItoAAnybaseTest()
{
	char *result = (char *)malloc(sizeof(char) * 11);
	char *result1 = (char *)malloc(sizeof(char) * 11);
	char *begin = result;
	char *check = result1;
	char compare[] = "1111";
	char compare1[] = "ABCD";
	begin = " ";
	begin = ItoA(15, result, 2);
	check = " ";
	check = ItoA(43981, result1, 16);
	
	
	if(0 == strcmp(check, compare1) && 0 == strcmp(begin, compare))
	{
		printf("itoa for all bases test passed\n");
	}
	else
	{
		printf("itoa for all bases test failed\n");
	}
	
	free(result);
	free(result1);
}
