
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Description: Function prints the value of the inserted character in bits.
Input: the value of the integer in bits.
Output: the number is succesful and 0 if not.
Complexity: o(n).
*/
int check1(unsigned char _b);
/*
Description: Function prints the value of the inserted integer in bits.
Input: the value of the integer in bits.
Output: the number is succesful and 0 if not.
Complexity: o(n).
*/
int check(unsigned int _b);
/*
Description: Function gets x and pointer to y and prints x in bits and y is the oposite of x.
Input: unsigned char and pointer to unsigned char.
Output: 1 is succesful and 0 if not.
Complexity: o(n).
*/
int checkXtoY(unsigned char _x,unsigned char* _y);
/*
Description: Function prints the inserted characters as bits.
Input: unsigned char .
Output: Prints the character as an bit.
Complexity: o(n).
*/
static void PrintBit(unsigned char _x);
/*
Description: Function rotate the bit number by n steps left.
Input: unsigned char and number of steps.
Output: returns 1 after finishing the action.
Complexity: o(n).
*/
int Rotate(unsigned char _x, int _n);
/*
Description: Function gets a string and compress every 2 characters into 1.
Input: The string entered by the user.
Output: void.
Complexity: o(n).
*/
void Compressing(char _str[]);
int main()
{
	
/*****targil 1******/	
	/*int a;
	a=check(4294967295);
	printf("The result is: %d\n", a);*/
/**********targil 2***********/
	/*unsigned char x=0,y;
	checkXtoY(x,&y);*/
	
	
/****targil3***/
	/*Rotate(1,1);
	return 0;*/
	
/****targil7****/
	/*char str[100]="aaa";
	PrintBit(str[0]);
	Compressing(str);
	PrintBit(str[0]);
	PrintBit(str[1]);*/
	PrintBit(52);
	return 0;
}



int check(unsigned int _b)
{

	int i,work=0;
	
	
	
	for(i=0;i<sizeof(unsigned int)*8;i++)
	{
		if( _b&(1<<i))
		{
			work++;
		}
		
	}
	return work;

}


int check1(unsigned char _b)
{

	int i,work=0;
	
	
	
	for(i=0;i<8;i++)
	{
		if( _b&(1<<i))
		{
		work++;
		}
		
	}
	return work;

}

int checkXtoY(unsigned char _x,unsigned char* _y)
{

	int i=0;
	if(NULL == _y)
	{
		return 0;
	}
	*_y=_x;
	for(i=0;i<sizeof(unsigned int)*8;i++)
	{
		*_y^=(1<<i);
	}
	printf("The x is:");
	PrintBit(_x);
	printf("\n");
	printf("The y is:");
	PrintBit(*_y);
	printf("\n");
	
	return 1;
}

static void PrintBit(unsigned char _x)
{
	int i=0;

	for(i=7;i>=0;--i)
	{
		if( _x&(1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		
		}
	}
	printf("\n");
}


int Rotate(unsigned char _x, int _n)
{

	int i,bit;
	_n%=8;
	printf("The y is:");
	PrintBit(_x);
	printf("\n");
	
	for(i=0;i<_n;i++)
	{
		bit=0;
		if( _x &(1<<7))
		{
				bit=1;	
			
		}
		_x=_x <<1;
		if(bit == 1)
		{
			_x |= (1<<0);
		}
	}
	printf("The x is:");
	PrintBit(_x);
	printf("\n");
	return 1;

}

void Compressing(char _str[])
{
	int i,jump=0,length;
	char c1,c2;
	
	
	length=strlen(_str)-1;
	for(i=0, jump=0 ; i<length ; i+=2, jump++) 
	{
		c1= _str[i]-'a'+1;
		c2= _str[i+1]-'a'+1;
		_str[jump]= c1 <<4| c2;
	}
	
	if(strlen(_str) % 2!= 0)
	{
		c1=_str[i-1]- 'a' +1;
		c2= 0;
		_str [jump]= c1<<4 | c2;
	}
	
	return;
}

