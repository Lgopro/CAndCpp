#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#include <assert.h>

double Sqrt(double number);

int main()
{
	
	double result1 = 0;
	double result2 = 0;
	double result3 = 0;
	double result4 = 0;
	
	result1 = Sqrt(-25);
	result2 = Sqrt(40);
	result3 = Sqrt(50);
	result4 = Sqrt(101);
	
	printf("result1 = %f\n", result1);
	printf("result2 = %f\n", result2);
	printf("result3 = %f\n", result3);
	printf("result4 = %f\n", result4);
	return 0;
}

double Sqrt(double number)
{
	double small_num = 0;
	double big_num = number;
	double mid = (small_num + big_num)/(double)2;

	while((number + 0.0000001) < mid * mid || (number - 0.0000001) > mid * mid)
	{
		if(number < mid * mid)
		{	
			big_num = mid;
			mid = (small_num + big_num)/(double)2;	
		}
		else
		{	
			small_num = mid;
			mid = (small_num + big_num)/(double)2;	
		}
		
	}
	return mid;
}
