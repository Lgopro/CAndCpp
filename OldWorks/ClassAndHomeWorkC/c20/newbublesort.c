
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newbuble.h"


int PrintMenu(void);
int MinToMax(int first,int second)
{
	return (first > second)? 1:0;
}

int MaxToMin(int first,int second)
{
	return (first < second)? 1:0;
}
int MaxToMinLastDigit(int first,int second)
{
	return (first % 10 < second % 10)? 1:0;
}
int MinToMaxLastDigit(int first,int second)
{
	return (first % 10 > second % 10)? 1:0;
}
void SortArrayInt(int(*Condition)(int,int), int _arr[],int _length)
{
    int i,j,num,flag;
    for(i=0;i<_length-1;i++)
    {
    	flag=0;
        for(j=i+1;j<_length;j++)
        {
            if(Condition(_arr[i],_arr[j]))
            {
               num=_arr[j];
               _arr[j]=_arr[i];
               _arr[i]=num;
               flag=1;
            }
        }
        if(flag == 0)
        {
        	break;
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<_length;i++)
    {
        printf("%d ", _arr[i]);
    }
    printf("\n");
    return;
}

int main()
{	
	int choise;
	int i,arr[100],seed,r,num;
	choise = PrintMenu();
	while(choise!=EXIT)
	{
    	printf("Please the seed number please\n");
    	scanf("%d", &seed);
    	printf("Please enter the number of random inputs in the array:\n");
    	scanf("%d", &num);
    	srand(seed);
    	for(i=0;i<num;i++)
    	{
       		r=rand()%100;
       		arr[i]=r;
    	}
    
		if(choise == 1)
		{
			SortArrayInt(MinToMax,arr,num);
		}
		if(choise == 2)
		{
			SortArrayInt(MaxToMin,arr,num);
		}
		if(choise == 3)
		{
			SortArrayInt(MinToMaxLastDigit,arr,num);
		}
		if(choise == 4)
		{
			SortArrayInt(MaxToMinLastDigit,arr,num);
		}
		choise = PrintMenu();
	}
	return 0;
	
}


int PrintMenu(void)
{

	int num;
	do
	{
    	printf("Please enter one of the folloing options\n");
    	printf("1)sort from smallest number to biggest\n");
    	printf("2)sort from bigest number to smallest\n");
    	printf("3)sort by last digit from smallest to biggest \n");
    	printf("4)sort by last digit from biggest to smallest\n");
    	printf("Please enter %d to exit\n", EXIT);
    	scanf("%d", &num);
    	getchar();
	}while(num<0 || num>4);
	return num;

}
