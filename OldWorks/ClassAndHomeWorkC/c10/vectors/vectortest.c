#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"



int main()
{
 	float hour;
	struct Vector* Vector=NULL;
    int* items =NULL; 
    int num;
	do
	{
		num=Printmenu();
    switch(num)
    case CREATE_VECTOR:
    	Vector=VectorCreate(_initialSize,_extensionBblockSize);

    break;
    
    }while(num!=EXIT); 
    return 0;
}
int Printmenu(void)
{
   int num;
   do
   {
       printf("Please enter one of the folloing options\n");
       printf("1)Create vector\n");
       printf("2)destroy vector\n");
       printf("3)Add item to the end of the vector\n");
       printf("4)Remove apointment from AD\n");
       printf("5)Find apointment in AD\n");
       printf("6)Destroy AD\n");
       printf("7)Print AD\n");
       printf("8)printf AD to file\n");
       printf("9)Load AD from file\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>9);
    return num;
}
