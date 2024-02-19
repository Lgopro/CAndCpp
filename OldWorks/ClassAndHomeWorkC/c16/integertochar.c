#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Description: Function turnes an integer into a character string.
Input: The integer number and the string.
Output: Void.
Complexity: o(n)
*/
void IntToChar(int _num,char _str[]);

int main()
{
	char str[100];
	int number;
	
	
		printf("Please enter an integer\n");
		scanf("%d", &number);
		IntToChar(number,str);
	
	return 0;
}


void IntToChar(int _num,char _str[])
{
	int i=0,j,number;
	if(_str== NULL)
	{
		return;
	}
	if(_num<0)
	{
		_str[0]='-';
		_num=-_num;
		i++;
	}
	if(_num == 0)
	{
		_str[0]= '0';/*TODO*/
		_str[1]='\0';
	}
	number=_num;
	while(number > 0)
	{
		number/=10;
		i++;
	}
	_str[i]='\0';
	for(j=i-1;j>=0;j--)
	{
		_str[j] = _num % 10 + '0' ;
		_num/=10;
		if(_num==0)
		{
			break;
		}
	}
	printf("The number is: %s\n", _str);
	if(_num == 0)
	

}
