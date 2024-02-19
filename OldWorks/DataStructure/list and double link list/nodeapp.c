#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int PrintMenu(void);

int main()
{

	struct List* List;
	int choise,data,datadeleted,empty;
	ADTErr error;
	size_t result;
	do
	{
		choise=PrintMenu();
		switch(choise)
		{	
		case CREATE_LIST:
			
			
				List=ListCreate();
			
		break;
		case DESTROY_LIST:
			if(NULL == List)
			{
				printf("There is nothing to destroy. Please try again\n");
			}
			else
			{
				ListDestroy(List);
				printf("The list destroyed succesfully\n");
			}
		break;
		case PUSH_A_NEW_NODE_TO_HEAD:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				data=GetData(List);
				error=ListPushHead(List,data);
				PError(error);
			}
		break;
		
		case PUSH_A_NEW_NODE_TO_TAIL:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				data=GetData(List);
				error=ListPushTail(List,data);
				PError(error);
			}
		break;
		case POP_A_NEW_NODE_FROM_HEAD:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				error=ListPopHead(List,&datadeleted);
				PError(error);	
			}
		break;
		case POP_A_NEW_NODE_FROM_TAIL:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				error=ListPopHead(List,&datadeleted);
				PError(error);	
			}
		break;
		case COUNT_AMOUNT_OF_NODES:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				result=ListCountItems(List);
				printf("The amount of nodes: %lu\n",result);
			}
			
		break;
		case CHECK_IF_LIST_IS_EMPTY:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				empty=ListIsEmtpy(List);
				if(empty==1)
				{
					printf("The list is empty\n");
				}
				if(empty==2)
				{
					printf("The list is not empty\n");
				}
				
			}
		break;
		case PRINT_LIST:
			if(NULL == List)
			{
				printf("Please create the list first\n");
			}
			else
			{
				empty=ListIsEmtpy(List);
				if(empty==1)
				{
					printf("The list is empty\n");
				}
				ListPrintf(List);
			}
		break;
		}
	}while(choise!=EXIT);


	return 0;


}

int PrintMenu(void)
{
	int num;
	do
	{
    	printf("Please enter one of the folloing options\n");
    	printf("1)Create List\n");
    	printf("2)Destroy List\n");
    	printf("3)Push a new node to head\n");
    	printf("4)Push a new node to tail\n");
    	printf("5)Pop a new node from head\n");
    	printf("6)Pop a new node from tail\n");
    	printf("7)Count the amount of nodes in the list\n");
    	printf("8)Check if the list is empty\n");
    	printf("9)Print list\n");
    	printf("Please enter %d to exit\n", EXIT);
    	scanf("%d", &num);
    	getchar();
	}while(num<0 || num>9);
	return num;

}

