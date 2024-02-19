#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Description: Function turnes a character string into a integer number;
Input: The string.
Output: The integer number.
Complexity: o(n).
*/
int CharToInt(char _str[]);

int main()
{
	char str1[100];
	int num;
	
	
	printf("Please enter the integer string\n");
	fgets(str1,100,stdin);
	num=CharToInt(str1);
	printf("number is: %d\n", num);
	
	return 0;
}
int CharToInt(char _str[])
{
	int i,n,number=0,hezka=1,minus=0;
	
	if(_str== NULL)
	{
		printf("No function\n");
	}
	/*i=SkipBlank(str);*/
	/*i=checkSign(str,i,&sign)*/
	if(_str[0] == '-')
	{
	 minus=1;
	 for(i=0;i<strlen(_str);i++)
	 {
	 	_str[i]=_str[i+1];
	 }
	
	}
	for(i=0; i<strlen(_str)-1;i++)
	{
		hezka=1;
		n=strlen(_str)-2-i;
		while(n>0)
		{
			hezka*=10;
			n--;
		}
		number += (_str[i] - '0') * hezka;
	
	}
	/*result= calculateNum(_str, i, sign)*/
	if(minus == 1)
	{
	 return number*(-1);
	}
	else
	{
		return number;
	}
}



