#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "stack.h"



int main()
{
 	
	struct Stack* Stack=NULL;
    int num,item,itemdel,empty,lastitem;
    
	do
	{
		num=Printmenu();
    switch(num)
    {
    	case CREATE_STACK:
    		if(NULL != Stack)
        	{
         		printf("The stack already created. you can destroy stack to create a new one.\n\n"); 
        	}
        	else
        	{
           		Stack=EnterVariables(Stack);
           		
        	}
   		break;
    	case DESTROY_STACK:
    		if(NULL == Stack)
        	{
         		printf("\nPlease add a stack first.\n\n"); 
        	}
        	else
        	{
        		StackDestroy(Stack);
        		Stack=NULL;
    		}
    	break;
    	case ADD_ITEM_TO_END_OF_STACK:
    		if(NULL == Stack)
        	{
         		printf("The stack already created. you can destroy stack to create a new one.\n\n"); 
        	}
        	else
        	{
        	item=GetItemToStack(Stack);
    		StackPush(Stack, item);
    		}
    	break;
    	case REMOVE_LAST_ITEM_FROM_STACK:
    		if(NULL == Stack)
        	{
         		printf("The stack already created. you can destroy stack to create a new one.\n\n"); 
        	}
        	else
        	{
        		StackPop(Stack,&itemdel);
        	
        	}
    		
    	break;
    	
    	case GET_ITEM_TO_POINTER:
    		if(NULL == Stack)
        	{
         		printf("The stack already created. you can destroy stack to create a new one.\n\n"); 
        	}
    		StackTop (Stack, &lastitem);
    		
    	break;
    	case CHECK_IF_STACK_IS_EMPTY:
    		if(NULL == Stack)
        	{
         		printf("The stack already created. you can destroy stack to create a new one.\n\n"); 
        	}
    		empty=StackIsEmpty (Stack);
    		if(empty==1)
    		{
    			printf("The stack is empty!\n");
    		}
    		else
    		{
    			printf("The stack is not empty!\n"); 
    		}
    	break;
    	case PRINT_ALL_STACK:
    		StackPrint (Stack);
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

