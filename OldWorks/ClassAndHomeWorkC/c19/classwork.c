#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int Find(const int _num[], int _size)
{
	int i,c;
	c= _num[0];
	for(i=1;i<_size;i++)
	{	
		c= c ^ _num[i];
	}
	return c;

}




int main()
{
	int arr[]={1,2,3,4,5,6,1,2,3,4,5},result;
	result= Find(arr,11);
	printf("The result is: %d\n", result);
	return 0;	
	
}


