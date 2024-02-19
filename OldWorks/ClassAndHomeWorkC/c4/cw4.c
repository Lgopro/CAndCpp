#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* CreateIntFunc(int size);
void PopulateArrayRand(int* _arr,int _size );
void PrintArr(int* arr,int size);
void SumIntArr(int *_arr, int _length);
void SortArrayInt(int *_arr,int _length);
void SumIntArr(int *_arr, int _length);
void UserInt(void);

#define INTEGER 1
#define FLOAT 2

void Swap(int *_x,int *_y)
{
	int num;
	num=*_x;
	*_x=*_y;
	*_y=num;
	return;
}

void SortArrayInt(int *_arr,int _length)
{
    int i,j;
    for(i=0;i<_length-1;i++)
    {
        for(j=i+1;j<_length;j++)
        {
            if(_arr[i]>_arr[j])
            {
            	Swap(&_arr[i],&_arr[j]);
            }
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

void SumIntArr(int *_arr, int _length)
{
    int i,sum=0;
    for(i=0;i<_length;i++)
    {
        sum+=*_arr;
        ++_arr;
    }
    printf("The sum of the string is: %d\n", sum);
    return;
}

void MaxIntArr(int *_arr,int _length)
{
    int i,maxnum;
    maxnum=*_arr;
    for(i=1;i<_length;i++)
    {
        if(*++_arr>maxnum)
        {
            maxnum=*_arr;
        }

    }
    printf("The maximum number in the array is: %d\n", maxnum);
    return;
}

int* CreateIntFunc(int size)
{
	int *arr;
	if((arr=(int*)malloc(size*sizeof(int)))==NULL)
	{
		printf("out of memory\n");
		return NULL;
	}
	return arr;

}
void PopulateArrayRand(int* _arr,int _size )
{
	int i;
	if(_arr==NULL)
	{
		return;
	}
	for( i=0;i<_size;i++)
	{
		*(_arr+i)=rand()%(100);
	}
}

void PrintArr(int* _arr,int _size)
{
	int i;
	if(_arr==NULL)
	{
		return;
	}
	printf("The elements of the array are: ");
	for( i=0;i<_size;i++)
	{
	printf("%d ", _arr[i]);
	}
	printf("\n");
}

void UserInt(void)
{
	int size,*arr;
	
	printf("please enter the amount of characters in the array\n");
	scanf("%d",&size);
	
	arr=CreateIntFunc(size);
	PopulateArrayRand(arr,size);
	PrintArr(arr,size);
	/*printf("Please enter the array input.Up to %d numbers:\nPrint '*' if you want to enter less numbers\n", size);
	arr=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	{
		result=scanf("%d", &arr[i]);
		if(result==0)
		{
			break;
		}	
	}

     if(i<size)
    {
        MaxIntArr(arr, i);
        SumIntArr(arr, i);
        SortArrayInt(arr, i);
    }
    else
    {
        MaxIntArr(arr, size);
        SumIntArr(arr, size);
        SortArrayInt(arr, size);
    }
*/
   /* ScanFun();*/
free(arr);
getchar();
    return;
}

void IntegerArray(void)
{
    int input;
    do
    {
        printf("Please enter the type of your input:\n1)User Input.\n2)Random input.\n");
        scanf("%d", &input);

    }
    while(input<1 && input>2);
    if(input==1)
    {
        UserInt();
    }
    else if(input==2)
    {
       /*RandInt();*/
    }
   return;

}



int main()
{
    int bhira;
    do
    {
        printf("Please enter what type of array you choose:\nEnter 0 to exit.\n");
        printf("1)Integer\n");
        printf("2)Float\n");
        scanf("%d", &bhira);
        if(bhira==INTEGER)
        {
            IntegerArray();
        }
        else if(bhira==FLOAT)
        {
            /*FloatArray();*/
        }
    }
    while(bhira!=0);

    return 0;
}
