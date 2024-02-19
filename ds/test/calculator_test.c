/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date:11/06/2023
*/

#include <stdio.h> /*printf*/
#include "calculator.h"

void CheckOfPlusMinus1();
void CheckOfPlusMinus2();
void CheckOfPlusMinus3();
void CheckOfPlusMinus4();
void CheckOfMyltDivide1();
void CheckOfMyltDivide2();
void CheckOfMyltDivide3();
void CheckOfMyltPow1();
void CheckOfMyltPow2();
void CheckOfMyltPow3();
void CheckOfMyltPow4();
void CheckOfMyltPow5();
void CheckOfMyltParentesis1();
void CheckOfMyltParentesis2();
void CheckOfMyltParentesis3();
void CheckOfMyltParentesis4();
void CheckOfMyltParentesis5();
void CheckOfMyltParentesis6();


void MentorChecks1();
void MentorChecks2();
void MentorChecks3();
void MentorChecks4();
void MentorChecks5();
void MentorChecks6();
void MentorChecks7();


int main()
{	
	
	
	CheckOfPlusMinus1();
	CheckOfPlusMinus2();
	CheckOfPlusMinus3();
	CheckOfPlusMinus4();
	
	CheckOfMyltDivide1();
	CheckOfMyltDivide2();
	CheckOfMyltDivide3();
	CheckOfMyltPow1();
	CheckOfMyltPow2();
	CheckOfMyltPow3();
	CheckOfMyltPow4();
	CheckOfMyltPow5();
	CheckOfMyltParentesis1();
	CheckOfMyltParentesis2();
	CheckOfMyltParentesis3();
	CheckOfMyltParentesis4();
	CheckOfMyltParentesis5();
	CheckOfMyltParentesis6();

	MentorChecks1();
	MentorChecks2();
	MentorChecks3();
	MentorChecks4();
	MentorChecks5();
	MentorChecks6();
	MentorChecks7();
	
	
	
	return 0;
}
void MentorChecks1()
{
	const char arr[] = "7+8";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(15 == result && SUCCESS == status)
	{
		printf("MentorChecks1 pass\n");
	}
	else
	{
		printf("MentorChecks1 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void MentorChecks2()
{
	const char arr[] = "8+8*3+-2^5";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(0 == result && SUCCESS == status)
	{
		printf("MentorChecks2 pass\n");
	}
	else
	{
		printf("MentorChecks2 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void MentorChecks3()
{
	const char arr[] = "8+8*3-2^";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(0 == result && SYNTAX_ERR == status)
	{
		printf("MentorChecks3 pass\n");
	}
	else
	{
		printf("MentorChecks3 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void MentorChecks4()
{
	const char arr[] = "2/0";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(0 == result && MATH_ERR == status)
	{
		printf("MentorChecks4 pass\n");
	}
	else
	{
		printf("MentorChecks4 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void MentorChecks5()
{
	const char arr[] = "8++8*((3-2)*5)";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(48 == result && SUCCESS == status)
	{
		printf("MentorChecks5 pass\n");
	}
	else
	{
		printf("MentorChecks5 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void MentorChecks6()
{
	const char arr[] = "3-2)*5";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(0 == result && SYNTAX_ERR == status)
	{
		printf("MentorChecks6 pass\n");
	}
	else
	{
		printf("MentorChecks6 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void MentorChecks7()
{
	const char arr[] = "(3-2)*5+ 5*(4+4+4";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(0 == result && SYNTAX_ERR == status)
	{
		printf("MentorChecks7 pass\n");
	}
	else
	{
		printf("MentorChecks7 fail\n");
		printf("Status 1: %f\n", result);
	}
}
void CheckOfMyltParentesis1()
{
	const char arr[] = "(5*3+2)*2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(34 == result && SUCCESS == status)
	{
		printf("CheckOfMyltParentesis1 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis1 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltParentesis2()
{
	const char arr[] = "(5*3+2)]*2";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(SUCCESS != status)
	{
		printf("CheckOfMyltParentesis2 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis2 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltParentesis3()
{
	const char arr[] = "(5*3+2)]*2";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(SUCCESS != status)
	{
		printf("CheckOfMyltParentesis3 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis3 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltParentesis4()
{
	const char arr[] = "(5*3+1)/2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(8 == result && SUCCESS == status)
	{
		printf("CheckOfMyltParentesis4 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis4 fail\n");
		printf("Status 1: %f\n", result);
	}
}


void CheckOfMyltParentesis5()
{
	const char arr[] = "{[(2+2)]}";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(4 == result && SUCCESS == status)
	{
		printf("CheckOfMyltParentesis5 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis5 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltParentesis6()
{
	const char arr[] = "{[(2+2])}";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(SUCCESS != status)
	{
		printf("CheckOfMyltParentesis6 pass\n");
	}
	else
	{
		printf("CheckOfMyltParentesis6 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltPow1()
{
	const char arr[] = "-3^3-1";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-28 == result && SUCCESS == status)
	{
		printf("CheckOfMyltPow1 pass\n");
	}
	else
	{
		printf("CheckOfMyltPow1 fail\n");
		printf("Status 1: %f\n", result);
	}
	
}

void CheckOfMyltPow2()
{
	const char arr[] = "-3*5^3-1";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-376 == result && SUCCESS == status)
	{
		printf("CheckOfMyltPow2 pass\n");
	}
	else
	{
		printf("CheckOfMyltPow2 fail\n");
		printf("Status 1: %f\n", result);
	}	
}

void CheckOfMyltPow3()
{
	const char arr[] = "-5^3-1";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-126 == result && SUCCESS == status)
	{
		printf("CheckOfMyltPow3 pass\n");
	}
	else
	{
		printf("CheckOfMyltPow3 fail\n");
		printf("Status 1: %f\n", result);
	}	
}

void CheckOfMyltPow4()
{
	const char arr[] = "-5^^3-1";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(SUCCESS != status)
	{
		printf("CheckOfMyltPow4 pass\n");
	}
	else
	{
		printf("CheckOfMyltPow4 fail\n");
		printf("Status 1: %f\n", result);
	}	
}

void CheckOfMyltPow5()
{
	const char arr[] = "2^3^2";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(512 == result && SUCCESS == status)
	{
		printf("CheckOfMyltPow5 pass\n");
	}
	else
	{
		printf("CheckOfMyltPow5 fail\n");
		printf("Status 1: %f\n", result);
	}	
}
void CheckOfMyltDivide1()
{
	const char arr[] = "-3*5+3-1";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-13 == result && SUCCESS == status)
	{
		printf("CheckOfMyltDivide1 pass\n");
	}
	else
	{
		printf("CheckOfMyltDivide1 fail\n");
		printf("Status 1: %f\n", result);
	}
	
}

void CheckOfMyltDivide2()
{
	const char arr[] = "-31+5*3+1";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-15 == result && SUCCESS == status)
	{
		printf("CheckOfMyltDivide2 pass\n");
	}
	else
	{
		printf("CheckOfMyltDivide2 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfMyltDivide3()
{
	const char arr[] = "-31+5**3+1";
	double result = 0;
	calculator_status_t status = 0;
	status = Calculator(arr, &result);
	if(SUCCESS != status)
	{
		printf("CheckOfMyltDivide3 pass\n");
	}
	else
	{
		printf("CheckOfMyltDivide3 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfPlusMinus1()
{
	const char arr[] = "-3+5-2-5-6-2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-13 == result && SUCCESS == status)
	{
		printf("CheckOfPlusMinus1 pass\n");
	}
	else
	{
		printf("CheckOfPlusMinus1 fail\n");
		printf("Status 1: %f\n", result);
	}
}

void CheckOfPlusMinus2()
{
	const char arr[] = "-3+5.5-2-5-6-2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-12.5 == result && SUCCESS == status)
	{
		printf("CheckOfPlusMinus2 pass\n");
	}
	else
	{
		printf("CheckOfPlusMinus2 fail\n");
		printf("Status 2: %f\n", result);
	}
}


void CheckOfPlusMinus3()
{
	const char arr[] = "-3.3+5.5-2.2-5-6-2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-13 == result && SUCCESS == status)
	{
		printf("CheckOfPlusMinus3 pass\n");
	}
	else
	{
		printf("CheckOfPlusMinus3 fail\n");
		printf("Status 2: %f\n", result);
	}
}

void CheckOfPlusMinus4()
{
	const char arr[] = "3.3+5.5-2.2-5-6-2";
	double result = 0;
	calculator_status_t status = 0;
	Calculator(arr, &result);
	if(-6.4 > (result - 0.00001)&& -6.4 < (result + 0.00001) && SUCCESS == status)
	{
		printf("CheckOfPlusMinus4 pass\n");
	}
	else
	{
		printf("CheckOfPlusMinus4 fail\n");
		printf("Status 2: %f\n", result);
	}
}


