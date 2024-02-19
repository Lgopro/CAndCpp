#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"



int main()
{
 	
	struct Vector* Vector=NULL;
    int num,item,itemdel,index,getitemfvec,numofitems[1000];
	do
	{
		num=Printmenu();
    switch(num)
    {
    	case CREATE_VECTOR:
    		if(NULL != Vector)
        	{
         		printf("The vector already created. you can destroy vector to create a new one.\n\n"); 
        	}
        	else
        	{
           		Vector=Enter(Vector);
           		
        	}
   		break;
    	case DESTROY_VECTOR:
    		if(Vector==NULL)
        	{
         		printf("\nPlease add an vector first.\n\n"); 
        	}
        	else
        	{
        		VectorDestroy(Vector);
        		Vector=NULL;
    		}
    	break;
    	case ADD_ITEM_TO_END_OF_VECTOR:
    		Vector=ChangeSize(Vector);
    		item=GetItem(Vector);
    		VectorAddEnd(Vector, item);
    	break;
    	case REMOVE_LAST_ITEM:
    		VectorDeleteEnd(Vector,&itemdel);
    	break;
    	
    	case GET_ITEM_TO_POINTER:
    		index=GetIndex(Vector);
    		VectorGet(Vector, index, &getitemfvec);
    	break;
    	case GET_ITEM_IN_VECTOR_TO_INDEX:
    		index=GetIndex(Vector);
    		item=GetItem(Vector);
    		VectorSet(Vector,index,item);
    	break;
    	case GET_POINTER_ARRAY_TO_POINTER_ARRAY:
    		VectorItemsNum(Vector, numofitems);
    	
    	break;
    }
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
       printf("4)Delete last item from vector\n");
       printf("5)Get part of a vector array to a variable \n");
       printf("6)Get selected number to the vector index selected\n");
       printf("7)Get a pointer from vector to array\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>7);
    return num;
}
