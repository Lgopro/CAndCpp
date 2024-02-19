#include <stdio.h>
#include <stdlib.h>
int rek(int n);
int key(int n,int k);
int main()
{
	int n,num,k;
	printf("Please enter a number\n");
	scanf("%d",&n);
	num=rek(n);
	printf("Result:%d\n",num);
	printf("Please enter a number k\n");
	scanf("%d",&k);
	num=key(n,k);
	printf("Result:%d\n",num);
	return 0;
	
}
int rek(n)
{	
	if(n==1)
	{
		return n;
	}
	return rek(n-1)*n;
}


int key(int n,int k)
{
	if(k==0)
	{
		return 1;
	}
	else return n*key(n,k-1);



}
