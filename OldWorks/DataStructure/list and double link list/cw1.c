#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float memutza(int _str[],int _length,int _count);

int main()
{	
	int number,num,str[100],i;
	float avr=0;
	
	printf("Please enter number of integers:\n");
	scanf("%d",&num);
	getchar();
	for(i=0;i<num;i++)
	{
		printf("Please enter a number:\n");
		scanf("%d",&number);
		getchar();
		str[i]=number;
	
	}
	
	avr=memutza(str,num,1);
	printf("The avr is: %f\n", avr);
	return 0;
}	


float memutza(int _str[],int _length,int _count)
{
	int avr=0;
	if(_count==_length)
	{
		return avr;
	}
	avr=memutza(_str+1,_length,_count+1);
	return (float)(avr+*_str)/_count;
	
}
