#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void test1(void);

int main()
{
 	
    test1();   	

	
	
    return 0;
}


void test1(void)
{
    struct Vector* Vector=NULL;
    Vector=VectorCreate(3,5);
    if(Vector==NULL)
    {
        printf("Fail\n");
    }
    else
    {
        
        printf("Pass\n");

    }

}



