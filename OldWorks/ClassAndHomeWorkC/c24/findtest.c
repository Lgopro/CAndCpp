
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "search.h"
#define TRUTH 1
#define NOT_TRUTH 0
#define BLOCKSIZE 50
#define INITSIZE 50
#define NUMBER 50000
int searchBin(int _arr[],int _begin, int _end, int _num);
int IsExist(int _arr[], int _size, int _num);
int IsExistBet(int _arr[], int _size, int _num);
int searchJump(int _arr[],int _items, int _num);
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);

int main()
{	
	/*test1();
 	test2();*/
 	test3();
 	test4();
 	test5();
 	test6();
	return 0;
}



void test1(void)
{
	
	
	int i,r;
	int arr[50000],search[50000];
	double time;
	clock_t start,end;
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	arr[i]=r;
    }	
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	search[i]=r;
    }	
    
    
    start=clock();
    for(i=0;i<NUMBER;i++)
    {
    	IsExist(arr, NUMBER, search[i]);
    }
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with normal search is: %f\n", time);
   
}



void test2(void)
{
	
	
	int i,r;
	int arr[50000],search[50000];
	double time;
	clock_t start,end;
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	arr[i]=r;
    }	
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	search[i]=r;
    }	
    
    
    start=clock();
    for(i=0;i<NUMBER;i++)
    {
    	IsExistBet(arr, NUMBER, search[i]);
    }
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with new search is: %f\n", time);
    
}

void test3(void)
{
	
	
	int result;
	int arr[10]={1,3,5,6,7,10,11,12,13};
	double time;
	clock_t start,end;
	
    
    
    
    start=clock();
    
    result=searchBin(arr,0, 8, 6);
    
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with new search is: %f\n", time);
    if(result == TRUTH)
    printf("Good\n");
    else 
    printf("Bad\n");
    
}
void test4(void)
{
	
	
	int result;
	int arr[10]={1,3,5,6,7,10,11,12,13};
	double time;
	clock_t start,end;
	
    start=clock();
    
    result=searchBin(arr,0, 8, 8);
    
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with new search is: %f\n", time);
    if(result == TRUTH)
    printf("Good\n");
    else 
    printf("Bad\n");
    
}
void test5(void)
{
	
	
	int result;
	int arr[10]={1,3,5,6,7,10,11,12,13};
	double time;
	clock_t start,end;
	
    
    
    
    start=clock();
    
    result=searchJump(arr, 9, 6);
    
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with new search is: %f\n", time);
    if(result == TRUTH)
    printf("Good\n");
    else 
    printf("Bad\n");
    
}
void test6(void)
{
	
	
	int result;
	int arr[10]={1,3,5,6,7,10,11,12,13};
	double time;
	clock_t start,end;
	
    start=clock();
    
    result=searchJump(arr, 9, 8);
    
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   	
    printf("The time with new search is: %f\n", time);
    if(result == TRUTH)
    printf("Good\n");
    else 
    printf("Bad\n");
    
}
