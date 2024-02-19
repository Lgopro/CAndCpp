#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "queue.h"


int Printmenu(void);

int main()
{
 	
	struct Queue* Queue=NULL;
    int num,item,empty;
    ADTErr err;
	do
	{
		num=Printmenu();
    switch(num)
    {
    	case CREATE_QUEUE:
    		if(NULL != Queue)
        	{
         		printf("The vector already created. you can destroy vector to create a new one.\n\n"); 
        	}
        	else
        	{
           		Queue=Enter(Queue);
           		
        	}
   		break;
    	case DESTROY_QUEUE:
    		if(Queue==NULL)
        	{
         		printf("\nPlease add an vector first.\n\n"); 
        	}
        	else
        	{
        		QueueDestroy(Queue);
        		Queue=NULL;
    		}
    	break;
    	case ADD_ITEM_TO_QUEUE:
    		item=GetItem(Queue);
    		err=QueueInsert (Queue,item);
    		PError(err);
    	break;
    	
    	case REMOVE_ITEM_FROM_QUEUE:
    		err=QueueRemove (Queue, &item);
    		PError(err);
    	break;
    	
    	case CHECK_QUEUE_IS_EMPTY:
    		empty=QueueIsEmpty(Queue);
    		if(empty==0)
    		{
    			printf("The Queue is empty\n");
    		}
    		if(empty==1)
    		{
    			printf("The Queue is not empty\n");
    		}
    		if(empty==2)
    		{
    			printf("Please create the Queue first\n");
    		}
    	break;
    	
    	case PRINT_QUEUE:
    		QueuePrint(Queue);
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
       printf("1)Create queue\n");
       printf("2)destroy queue\n");
       printf("3)Add item to queue\n");
       printf("4)Delete item from queue\n");
       printf("5)Check if queue is empty \n");
       printf("6)Print queue\n");
       printf("Please enter %d to exit\n", EXIT);
       scanf("%d", &num);
       getchar();
   }
   while(num<0 || num>6);
    return num;
}
