#include <stdio.h>
#include <stdlib.h>
int MxxInArray(int _arr[],int _n);
int main()
{
	int arr[]={1,5,7,4,8};
	int num;
	num=MxxInArray(arr,5);
	printf("%d\n",num);
	return 0;
	
}

int MxxInArray(int _arr[],int _n)
{
	int max;
	if(_n==1)
	return _arr[0];
	max=MxxInArray(_arr,_n-1);
	
	if(max>_arr[_n-1])
	{
		return max;
	}
	else
	{

		return _arr[_n-1];
	}
	
	



}
