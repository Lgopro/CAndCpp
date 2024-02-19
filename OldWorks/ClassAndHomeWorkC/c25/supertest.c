
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mu_test.h"
#include "supersort.h"






UNIT(Sorttest)
	int i;
	int arr[10]={9,8,5,7,2,4,8,5,2,1};
	sort(arr , 10, sizeof(int), Compare);
	for(i=0;i<10;i++)
	{
		printf("%d ", arr[i]); 
	}
	fflush(stdin);
	for(i=0;i<9;i++)
	{
		ASSERT_THAT(arr[i]<=arr[i+1]);
	}
	
	
END_UNIT


TEST_SUITE(Supertest)
	TEST(Sorttest)
	
END_SUITE
