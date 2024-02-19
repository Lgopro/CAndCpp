#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharToInt(char _str[]);
int main(int argc, char *argv[])
{
	int num1,num2;
	
	
	/*sscanf(argv[1],"%d", &num1);
	sscanf(argv[2],"%d", &num2);*/
	num1=	CharToInt(argv[1]);
	num2= CharToInt(argv[2]);
	printf("The num1*num2= %d\n", num1*num2);
	printf("The num1+num2= %d\n", num1+num2);
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
	for(i=0; i<strlen(_str);i++)
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


