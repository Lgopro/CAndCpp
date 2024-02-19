#include <stdio.h>
#include <stdlib.h>
int rek(int _arr[],int _n);
int main()
{
	int arr[100];
	int num,i,num1;
	printf("Please enter n array:\n");
	scanf("%d",&num);
	printf("Please enter choise\n1)casual\n2)rek:\n");
	scanf("%d",&num1);
	if(num1==1)
	{
		arr[0]=0;
		arr[1]=1;
		for(i=2;i<=num;i++)
		{
			arr[i]=arr[i-1]+arr[i-2];
		}
		printf("number is: %d\n",arr[num]);
		
	}
	else
	{
		num=rek(arr,num);
		printf("number is: %d\n",arr[num]);
	}
	return 0;

}

int rek(int _arr[],int _n)
{	
	int sum=0,first,second;
	if(_n)
	return sum;
	if(_arr==0)
	return 0;
	if(_arr==1)
	return 1;
}
