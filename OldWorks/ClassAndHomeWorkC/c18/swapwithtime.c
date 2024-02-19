


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SWAP(x,y)\
{\
	int num;\
	num=x;\
	x=y;\
	y=num;\
}

void RandInt(void);
void Swap(int arr[],int amount);
void Swap1(int arr[],int amount);
int main()
{
   
    RandInt();

    return 0;
}




void RandInt(void)
{
    int i,arr[60000],seed,r,num,arr1[60000];
    double time;
    clock_t start,end;
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    srand(seed);


    for(i=0;i<num;i++)
    {
       r=rand()%100000;
       arr[i]=r;
    }
    start=clock();
	
   
       Swap(arr,50000);
   
    end=clock()  ;
    time= (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time difference was %f seconds in function swap\n", time);
    
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    srand(seed);


    for(i=0;i<num;i++)
    {
       r=rand()%100000;
       arr1[i]=r;
    }
    start=clock();
    Swap1(arr1,50000);
    end=clock()  ;
    time= (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time difference was %f seconds in function defineSWAP\n", time);
    
    
    
    return;
}

void Swap(int arr[],int amount)
{
	register int num,i,j;
	for(i=0;i<amount;i++)
	{
		for(j=i+1;j<amount;j++)
		{
			if(arr[i]>=arr[j])
			{
				num=arr[i];
				arr[i]=arr[j];
				arr[j]=num;
			}
		}
	}
	return;
}

void Swap1(int arr[],int amount)
{
	register int i,j;
	for(i=0;i<amount;i++)
	{
		for(j=i+1;j<amount;j++)
		{
			if(arr[i]>=arr[j])
			{
				
				SWAP(arr[i],arr[j]);
			}
		}
	}
	return;
}	
