/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date:31/05/23
*/



#include <stdio.h> /*printf*/
#include <stdlib.h> /*rand*/
#include <time.h> /*clock_t*/


#include "sort.h"

#define NUM 1000


int cmpfunc(const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

void BublesortTest();
void InsertionSortTest();
void SelectionSortTest();
void CountingSortTest();
void RedixSortTest();
void BinarySearchRecursiveTest();
void BinarySearchTest();
void MergeSortTest();
void QuickRecTest();


int main()
{
	BublesortTest();
	InsertionSortTest();
	SelectionSortTest();
	CountingSortTest();
	RedixSortTest();
	BinarySearchRecursiveTest();
	BinarySearchTest();
	MergeSortTest();
	QuickRecTest();

	return 0;


}




void BublesortTest()
{
	
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[5000];
	clock_t start,end;

	srand(5);
    for(i = 0; i < 5000; i++)
    {
       	r = rand() % 100000;
       	arr[i] = r; 
    }	
    
    start = clock();
    BubbleSort(arr, 5000);
    end = clock();
    
    time = (double)(end-start)/CLOCKS_PER_SEC;
    
    min = arr[0];
    max = arr[4999];
    
    for(i = 0; i < 5000;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
    printf("The time with Bublesort is: %f\n", time);
   	if(0 == flag)
	{
		printf("Bublesort pass\n");
	}
	else
	{
		printf("Bublesort fail\n");
	}
	
	start = clock();
	qsort(arr, sizeof(int), 5000, cmpfunc);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with qsort is: %f\n", time);
}



void InsertionSortTest()
{
	
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[5000];
	clock_t start,end;

	srand(5);
    for(i = 0; i < 5000; i++)
    {
       	r = rand() % 100000;
       	arr[i] = r; 
    }	
    start=clock();
    InsertionSort(arr, 5000);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with InsertionSort is: %f\n", time);
    min = arr[0];
    max = arr[4999];
    
    for(i = 0; i < 5000;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("InsertionSort pass\n");
	}
	else
	{
		printf("InsertionSort fail\n");
	}
	start = clock();
	qsort(arr, sizeof(int), 5000, cmpfunc);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with qsort is: %f\n", time);
}

void SelectionSortTest()
{
	
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[5000];
	clock_t start,end;

	srand(5);
    for(i = 0; i < 5000; i++)
    {
       	r = rand() % 100000;
       	arr[i] = r; 
    }	
    start=clock();
    SelectionSort(arr, 5000);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with SelectionSort is: %f\n", time);
	min = arr[0];
    max = arr[4999];
    
    for(i = 0; i < 5000;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("SelectionSort pass\n");
	}
	else
	{
		printf("SelectionSort fail\n");
	}
	start = clock();
	qsort(arr, sizeof(int), 5000, cmpfunc);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with qsort is: %f\n", time);
}



void CountingSortTest()
{
	
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[5000];
	clock_t start,end;

	srand(5);
    for(i = 0; i < 5000; i++)
    {
       	r = rand() % 99;
       	arr[i] = r + 1; 
    }	
    start=clock();
    CountingSort(arr, 5000);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with SelectionSort is: %f\n", time);
	min = arr[0];
    max = arr[4999];
    
    for(i = 0; i < 5000;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("CountingSortTest pass\n");
	}
	else
	{
		printf("CountingSortTest fail\n");
	}
}

void RedixSortTest()
{
	
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[NUM];
	clock_t start,end;

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	
    start=clock();
    RadixSort(arr, NUM);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with RedixSortTest is: %f\n", time);
	min = arr[0];
    max = arr[NUM - 1];
    
    for(i = 0; i < NUM;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("RedixSortTest pass\n");
	}
	else
	{
		printf("RedixSortTest fail\n");
	}
}

void BinarySearchRecursiveTest()
{

	int i = 0;
	int r = 0;
	int result = 0;
	double time;
	int arr[NUM];
	clock_t start,end;

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	

    start=clock();
    InsertionSort(arr, NUM);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with RedixSortTest is: %f\n", time);

	result = BinarySearchRecursive(arr, 0, NUM - 1, arr[NUM -5]);

   	if(NUM -5 == result)
	{
		printf("BinarySearchRecursive pass\n");
	}
	else
	{
		printf("\n\n%d\n\n", BinarySearchRecursive(arr, 0, NUM - 1, arr[NUM -5]));
		printf("BinarySearchRecursive fail\n");
	}



}

void BinarySearchTest()
{

	int i = 0;
	int r = 0;
	int result = 0;
	double time;
	int arr[NUM];
	clock_t start,end;

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	

    start=clock();
    InsertionSort(arr, NUM);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with RedixSortTest is: %f\n", time);

	result = BinarySearch(arr, NUM, arr[NUM -5]);

   	if(NUM -5 == result)
	{
		printf("BinarySearchTest pass\n");
	}
	else
	{
		printf("\n\n%d\n\n", BinarySearch(arr, NUM, arr[NUM -5]));
		printf("\nBinarySearchTest fail\n");
	}


}


void MergeSortTest()
{
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[NUM];
	clock_t start,end;

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	

    start=clock();
    MergeSort(arr, NUM);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with MergeSortTest is: %f\n", time);
	min = arr[0];
    max = arr[NUM - 1];
    
    for(i = 0; i < NUM;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("MergeSortTest pass\n");
	}
	else
	{
		printf("MergeSortTest fail\n");
	}
	/*for(i = 0; i < NUM;++i)
    {
    	printf("%d ", arr[i]);
    }*/
}


void QuickRecTest()
{
	int i = 0;
	int r = 0;
	int min = 0;
	int max = 0;
	int flag = 0;
	double time;
	int arr[NUM];
	clock_t start,end;

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	
	
    start=clock();
    QuicktRec(arr, (size_t)NUM, sizeof(int), cmpfunc);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with QuickRecTest is: %f\n", time);
	min = arr[0];
    max = arr[NUM - 1];
    
    for(i = 0; i < NUM;++i)
    {
    	if(min > arr[i] || max < arr[i])
    	{
    		flag = 1;
    		break;
    	}
    }
   	if(0 == flag)
	{
		printf("QuickRecTest pass\n");
	}
	else
	{
		printf("QuickRecTest fail\n");
	}
	/*for(i = 0; i < NUM;++i)
    {
    	printf("%d ", arr[i]);
    }*/

	srand(5);
    for(i = 0; i < NUM; i++)
    {
       	r = rand() % 9999998;
       	arr[i] = r + 1; 
    }	
	start=clock();
    qsort(arr, (size_t)NUM, sizeof(int), cmpfunc);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with qsort is: %f\n", time);
}