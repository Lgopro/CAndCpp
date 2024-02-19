
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct statusReg 
{
	unsigned char bit0	:1;
	unsigned char bit1	:1;
	unsigned char bit2  :1;
	unsigned char bit3  :1; 
	unsigned char bit4  :1;
	unsigned char bit5  :1;
	unsigned char bit6  :1;
    unsigned char bit7  :1;
};

int counter(struct statusReg* _num, char countit)
{	
	return _num->bit0+_num->bit1+_num->bit2+_num->bit3+_num->bit4+_num->bit5+_num->bit6+_num->bit7;
}


int main()
{
	char number=1;
	int result;
	struct statusReg* num=NULL;
	num=(struct statusReg*) &number;
	result=counter(num , number);
	printf("The result is: %d\n", result);
	return 0;
}
