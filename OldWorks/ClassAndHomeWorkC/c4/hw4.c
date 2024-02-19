#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* CreateIntFunc(int size);
void PopulateArrayRand(int* _arr,int _size );
void PrintArr(int* arr,int size);
void UserInt(void);
void DestroyArray(int* _arr);
int* CreateZeroIntArray(int _size);

#define RANDOMARR 1
#define ZEROARR 2
#define EXIT 100
#define YES 1
#define NO 2
int* ResizeArray(int* _arr,int _size)
{
	int choise,newsize,type;
	if(_arr==NULL)
	{
		printf("out of memory\n");
		exit(0);
	}
	printf("Do you want to resize the array?\nInput %d if you do and %d if you dont\n",YES,NO);
	scanf("%d",&choise); 
	getchar();
	if(choise==YES)
	{
		printf("Please enter the new number of elements that you need in the array\n");
		scanf("%d", &newsize);
		getchar();
		_arr=(int*)realloc(_arr,newsize*sizeof(int));
		printf("Please enter the type of function you want to resize:\n");
		printf("Input %d for random array and and %d for zero array\n",RANDOMARR,ZEROARR);
		scanf("%d", &type);
		getchar();
		if(type==RANDOMARR)
		{
			PopulateArrayRand(_arr,newsize);
           	PrintArr(_arr,newsize);
		}
		else if(type==ZEROARR)
		{
			_arr=CreateZeroIntArray(newsize);
        	PrintArr(_arr,newsize);
		
		}
		return _arr;
	}
	
		return _arr;
	
}

int* CreateZeroIntArray(int _size)
{
	int *arr;
	if((arr=(int*)calloc(_size, sizeof(int)))==NULL)
	{
		printf("out of memory\n");
		return NULL;
	}
	return arr;

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
		printf("out of memory\n");
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
		printf("out of memory\n");
	}
	printf("The elements of the array are: ");
	for( i=0;i<_size;i++)
	{
		printf("%d ", _arr[i]);
	}
	printf("\n");
}
void DestroyArray(int* _arr)
{
	if(_arr==NULL)
	{
		return;
		printf("The was a mistake\n");
	}
	free(_arr);
}

int SizeArray(void)
{
	int size;
	
	printf("please enter the amount of characters in the array\n");
	scanf("%d",&size);
	getchar();
	
	return size;
}



int main()
{
    int bhira,size,*arr;
   
    do
    {
        printf("Please enter what type of array you choose:\nEnter %d to exit.\n", EXIT);
        printf("1)Create new random array\n");
        printf("2)Create array that containes 0 only\n");
        scanf("%d", &bhira);
        if(bhira==RANDOMARR)
        {
            size=SizeArray();
            arr=CreateIntFunc(size);
            PopulateArrayRand(arr,size);
            PrintArr(arr,size);
            arr=ResizeArray(arr,size);
            DestroyArray(arr);
        }
        else if(bhira==ZEROARR)
        {
        	size=SizeArray();
        	arr=CreateZeroIntArray(size);
        	PrintArr(arr,size);
        	arr=ResizeArray(arr,size);
        	DestroyArray(arr);
        }
    }
    while(bhira!=EXIT);

    return 0;
}
