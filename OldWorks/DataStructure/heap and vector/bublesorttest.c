
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"
#include "sort.h"
int main()
{	
	Vector* vec;
	int i,seed,r,num;
	clock_t start,end;
    printf("Please the seed number please\n");
    scanf("%d", &seed);
    printf("Please enter the number of random inputs in the array:\n");
    scanf("%d", &num);
    srand(seed);
    vec=VectorCreate(50000,50);
    for(i=0;i<num;i++)
    {
       	r=rand()%50000;
       	VectorAddEnd(vec , r);
    }	
    start=clock();
    Bublesort(vec);
    end=clock();
    time= (double)(end-start)/CLOCKS_PER_SEC;
	VectorDestroy(vec);
	
	return 0;
	
}



