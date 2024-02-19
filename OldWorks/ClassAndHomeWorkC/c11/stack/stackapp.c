#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"



int main()
{
 	
	struct Stack* Stack=NULL;
    int num/*,item,itemdel,index,getitemfvec,numofitems[1000]*/;
	do
	{
		num=Printmenu();
    switch(num)
    {
    	case CREATE_STACK:
    		if(NULL != Stack)
        	{
         		printf("The vector already created. you can destroy vector to create a new one.\n\n"); 
        	}
        	else
        	{
           		Stack=EnterVariables(Stack);
           		
        	}
   		break;
    	case DESTROY_STACK:
    		/*if(Vector==NULL)
        	{
         		printf("\nPlease add an vector first.\n\n"); 
        	}
        	else
        	{
        		VectorDestroy(Vector);
        		Vector=NULL;
    		}
    	break;*/
    	case ADD_ITEM_TO_END_OF_STACK:
    		/*Vector=ChangeSize(Vector);
    		item=GetItem(Vector);
    		VectorAddEnd(Vector, item);*/
    	break;
    	case REMOVE_LAST_ITEM_FROM_STACK:
    		/*VectorDeleteEnd(Vector,&itemdel);*/
    	break;
    	
    	case GET_ITEM_TO_POINTER:
    		/*index=GetIndex(Vector);
    		VectorGet(Vector, index, &getitemfvec);*/
    	break;
    	case CHECK_IF_STACK_IS_EMPTY:
    		/*index=GetIndex(Vector);
    		item=GetItem(Vector);
    		VectorSet(Vector,index,item);*/
    	break;
    	case PRINT_ALL_STACK:
    		/*VectorItemsNum(Vector, numofitems);*/
    	
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
       printf("1)Create stack\n");
       printf("2)destroy stack\n");
       printf("3)Add item to the end of the stack\n");
       printf("4)Delete last item from stack\n");
       printf("5)Get the top number to an pointer \n");
       printf("6)Check if stuck is Empty\n");
       printf("7)Print all stack\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>7);
    return num;
}
