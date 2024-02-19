
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"
#include "sort.h"
#define BLOCKSIZE 50
#define INITSIZE 50
#define NUMBER 100
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);
void test13(void);
void test14(void);
void test15(void);
void test16(void);
void test17(void);
void test18(void);
void test19(void);
void test20(void);
void test21(void);
void test22(void);
void test23(void);
void test24(void);
void test25(void);
void test26(void);
void test27(void);
void test28(void);


int main()
{	
	test1();
 	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
 	/*test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
 	test18();
	test19();
	test20();
	test21();
	test22();
	test23();
	test24();
	test25();
	test26();
	test27();
	test28();*/
	
	/*Vector* vec;
	int i,seed,r,num;
	clock_t start,end;
	double time;
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    while( num != 0)
    {
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    srand(seed);
    vec=VectorCreate(50000,50);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%50;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    Bublesort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time for buble sort is %f\n",time);
    start=clock();
    Shakesort(vec);
    end=clock();
    
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time for shakesort sort is %f\n",time);
    start=clock();
    VectorPrint(vec);
    Partiotion(vec);
    VectorPrint(vec);
	end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    
    }
	VectorDestroy(vec);*/
	
	return 0;
	
}
void test1(void)
{
	
	Vector* vec;
	int i,r;
	double time;
	clock_t start,end;
	
	vec=VectorCreate(NUMBER,50);
	 srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    Bublesort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with Bublesort is: %f\n", time);
   
    VectorDestroy(vec);
}

void test2(void)
{
	
	Vector* vec;
	int i,r;
	double time;
	clock_t start,end;
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    Shakesort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with Shakesort is: %f\n", time);
 
	VectorDestroy(vec);
}
void test3(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    InsertionSort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with insertionsort is: %f\n",time);
	VectorDestroy(vec);
}
void test4(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    QuickRec(vec, 0, NUMBER-1);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("The time with quick is: %f\n",time);
	VectorDestroy(vec);
}
void test5(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    ShellSort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("The time with shell is: %f\n",time);
	VectorDestroy(vec);
}
void test6(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
   
    start=clock();
    SelectionSort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("The time with Selectionsort is: %f\n",time);
	VectorDestroy(vec);
}
void test7(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
   
    start=clock();
    CountingSort(vec, NUMBER);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    VectorPrint(vec);
    printf("The time with countingsort is: %f\n",time);
    
    VectorDestroy(vec);
}
void test8(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	vec=VectorCreate(NUMBER,50);
	srand(4);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
    VectorPrint(vec);
    start=clock();
    MergeSort(vec);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    VectorPrint(vec);
    printf("The time with Mergesort is: %f\n",time);
    VectorDestroy(vec);
}
void test9(void)
{
	
	Vector* vec;
	int i,r;
	clock_t start,end;
	double time;
	vec=VectorCreate(NUMBER,50);
	srand(5);
    for(i=0;i<NUMBER;i++)
    {
       	r=rand()%NUMBER;
       	VectorAddEnd(vec , r);
    }	
  
    start=clock();
    RadixSort(vec,1);
    end=clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
   
    printf("The time with RadixSort is: %f\n",time);
    VectorDestroy(vec);
}
/*
void test6(void)
{
	
	Vector* vec;
	printf("Test 6\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Partiotion(vec, 0, 7);
	VectorPrint(vec);
	printf("Test 6\n");
	printf("\n");
	VectorDestroy(vec);
}
void test7(void)
{
	
	Vector* vec;
	printf("Test 7\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorPrint(vec);
	Partiotion(vec, 0, 1);
	VectorPrint(vec);
	printf("Test 7\n");
	printf("\n");
	VectorDestroy(vec);
}
void test8(void)
{
	
	Vector* vec;
	printf("Test 8\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	InsertionSort (vec);
	VectorPrint(vec);
	printf("Test 8\n");
	printf("\n");
	VectorDestroy(vec);
}

void test9(void)
{
	
	Vector* vec;
	printf("Test 9\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  6);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	InsertionSort (vec);
	VectorPrint(vec);
	printf("Test 9\n");
	printf("\n");
	VectorDestroy(vec);
}
void test10(void)
{
	
	Vector* vec;
	printf("Test 10\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  23);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  77);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	InsertionSort (vec);
	VectorPrint(vec);
	printf("Test 10\n");
	printf("\n");
	VectorDestroy(vec);
}
void test11(void)
{
	
	Vector* vec;
	printf("Test 11\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  33);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  27);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  5);
	VectorPrint(vec);
	InsertionSort (vec);
	VectorPrint(vec);
	printf("Test 11\n");
	printf("\n");
	VectorDestroy(vec);
}
void test12(void)
{
	
	Vector* vec;
	printf("Test 12\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  40);
	VectorAddEnd(vec,  20);
	VectorPrint(vec);
	QuickRec(vec, 0, 2);
	VectorPrint(vec);
	printf("Test 12\n");
	printf("\n");
	VectorDestroy(vec);
}

void test13(void)
{
	
	Vector* vec;
	printf("Test 13\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  15);
	VectorAddEnd(vec,  20);
	VectorAddEnd(vec,  5);
	VectorPrint(vec);
	QuickRec(vec, 0, 3);
	VectorPrint(vec);
	printf("Test 13\n");
	printf("\n");
	VectorDestroy(vec);
}
void test14(void)
{
	
	Vector* vec;
	printf("Test 14\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  20);
	VectorAddEnd(vec,  20);
	VectorPrint(vec);
	QuickRec(vec, 0, 2);
	VectorPrint(vec);
	printf("Test 14\n");
	printf("\n");
	VectorDestroy(vec);
}
void test15(void)
{
	
	Vector* vec;
	printf("Test 15\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorPrint(vec);
	QuickRec(vec, 0, 3);
	VectorPrint(vec);
	printf("Test 15\n");
	printf("\n");
	VectorDestroy(vec);
}

void test16(void)
{
	
	Vector* vec;
	printf("Test 16\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  15);
	VectorAddEnd(vec,  20);
	VectorAddEnd(vec,  30);
	VectorAddEnd(vec,  40);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  25);
	VectorAddEnd(vec,  1);
	VectorPrint(vec);
	QuickRec(vec, 0, 7);
	VectorPrint(vec);
	printf("Test 16\n");
	printf("\n");
	VectorDestroy(vec);
}

void test17(void)
{
	
	Vector* vec;
	printf("Test 17\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  240);
	VectorAddEnd(vec,  11);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  6);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	QuickRec(vec, 0, 14);
	VectorPrint(vec);
	printf("Test 17\n");
	printf("\n");
	VectorDestroy(vec);
}
void test18(void)
{
	
	Vector* vec;
	printf("Test 18\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorPrint(vec);
	QuickRec(vec, 0, 1);
	VectorPrint(vec);
	printf("Test 18\n");
	printf("\n");
	VectorDestroy(vec);
}
void test19(void)
{
	
	Vector* vec;
	printf("Test 19\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 19\n");
	printf("\n");
	VectorDestroy(vec);
}


void test20(void)
{
	
	Vector* vec;
	printf("Test 20\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 20\n");
	printf("\n");
	VectorDestroy(vec);
}

void test21(void)
{
	
	Vector* vec;
	printf("Test 21\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  6);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 21\n");
	printf("\n");
	VectorDestroy(vec);
}
void test22(void)
{
	
	Vector* vec;
	printf("Test 22\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  23);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  77);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 22\n");
	printf("\n");
	VectorDestroy(vec);
}
void test23(void)
{
	
	Vector* vec;
	printf("Test 23\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  33);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  27);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  5);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 23\n");
	printf("\n");
	VectorDestroy(vec);
}
void test24(void)
{
	
	Vector* vec;
	printf("Test 24\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Bublesort (vec);
	VectorPrint(vec);
	printf("Test 24\n");
	printf("\n");
	VectorDestroy(vec);
}


void test25(void)
{
	
	Vector* vec;
	printf("Test 25\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  4);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  2);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Shakesort (vec);
	VectorPrint(vec);
	printf("Test 25\n");
	printf("\n");
	VectorDestroy(vec);
}

void test26(void)
{
	
	Vector* vec;
	printf("Test 26\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  6);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  5);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Shakesort (vec);
	VectorPrint(vec);
	printf("Test 26\n");
	printf("\n");
	VectorDestroy(vec);
}
void test27(void)
{
	
	Vector* vec;
	printf("Test 27\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  23);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  77);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorPrint(vec);
	Shakesort (vec);
	VectorPrint(vec);
	printf("Test 27\n");
	printf("\n");
	VectorDestroy(vec);
}
void test28(void)
{
	
	Vector* vec;
	printf("Test 28\n");
	vec=VectorCreate(INITSIZE, BLOCKSIZE);
	VectorAddEnd(vec,  33);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  3);
	VectorAddEnd(vec,  27);
	VectorAddEnd(vec,  7);
	VectorAddEnd(vec,  1);
	VectorAddEnd(vec,  5);
	VectorPrint(vec);
	Shakesort (vec);
	VectorPrint(vec);
	printf("Test 28\n");
	printf("\n");
	VectorDestroy(vec);
}*/

