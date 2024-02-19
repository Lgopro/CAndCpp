#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int PrintMenu(void);
int GetData(Tree* _tree);
void Print(Tree* _tree);

int main()
{

	struct Tree* Tree;
	int choise,data;
	
	do
	{
		choise=PrintMenu();
		switch(choise)
		{	
		case CREATE_TREE:
			if(NULL != Tree)
			{
				printf("The tree already created!\n");
			}
			else
			{
				Tree=TreeCreate();
			
			}
		break;
		case DESTROY_TREE:
			if(NULL == Tree)
			{
				printf("There is nothing to destroy. Please try again\n");
			}
			else
			{
				TreeDestroy(Tree);
				printf("The tree destroyed succesfully\n");
			}
		break;
		case INPUT_NEW_NODE:
			if(NULL == Tree)
			{
				printf("Please create the tree first\n");
			}
			else
			{
				 data=GetData(Tree);
				 TreeInsert(Tree,data);
			}
		break;
		
		case FIND_DATA_IN_TREE:
			if(NULL == Tree)
			{
				printf("Please create the tree first\n");
			}
			else
			{
				data=GetData(Tree);
				TreeIsDataFound(Tree, data);
			}
		break;
		case PRINT_TREE:
			if(NULL == Tree)
			{
				printf("Please create the tree first\n");
			}
			else
			{
				Print(Tree);
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
    	printf("1)Create Tree\n");
    	printf("2)Destroy Tree\n");
    	printf("3)Push new data to tree\n");
    	printf("4)Check if the selected data is in the tree\n");
    	printf("5)Print the tree in the selected way\n");
    	printf("Please enter %d to exit\n", EXIT);
    	scanf("%d", &num);
    	getchar();
	}while(num<0 || num>5);
	return num;

}
