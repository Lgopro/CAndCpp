#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT 0
#define CREATE_TREE 1
#define DESTROY_TREE 2
#define INPUT_NEW_NODE 3
#define FIND_DATA_IN_TREE 4
#define PRINT_TREE 5
#define NOT_GENERATED 0
#define EQUALITY_FOUND 1
#define EQUALITY_NOT_FOUND 2
#define PRE_ORDER_ 1
#define IN_ORDER_ 2
#define POST_ORDER_ 3
#define NOT_INITIALIZED 4


void NodePrint(Node* _root);
Tree* TreeCreate(void);
ADTErr TreeInsert(Tree* _tree, char _name[]);
ADTErr InsertNode(Node* _root, Node* _insert);
void Destroy(Node* _root);
void TreeDestroy(struct Tree* _tree);
typedef struct Tree;
typedef struct Node;
typedef enum
{
    
    ERR_OK,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
           
    ERR_STACK_BBBBB = 30
}ADTErr ;
typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
} TreeTraverse;


struct Node
{
    char    m_word[50];
    int 	m_count=0;
    Node*   m_left;
    Node*   m_right;
    Node*   m_father;
};

struct Tree
{
    Node* m_root;
    int m_magic;
};

int main()
{
	
	
	char filename[100],wordfile[100];
	int counter[1000]={0};
	FILE *fp;
	struct Tree* Tree;
	
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50, stdin);
		fp = fopen(filename , "r");
	}while(fopen(filename, "r") == NULL);
	Tree=TreeCreate();
	do
	{
		
		fscanf(fp, "%s", wordfile);
		TreeInsert(Tree, wordfile);
		
	}while(!feof(fp));
	NodePrint(Tree->m_root);
	TreeDestroy(Tree);
	
	fclose(fp);
	return 0;
}
void NodePrint(Node* _root)
{
 
    	NodePrint(_root->m_left,IN_ORDER);
    	printf("%s      %d", _root->m_word,_root->m_count);
		NodePrint(_root->m_right,IN_ORDER);
    	return;
    
}

Tree* TreeCreate(void)
{
	struct Tree* Tree=NULL;
 	if(NULL == (Tree=(struct Tree*)malloc(sizeof(struct Tree))))
 	{
   		return NULL;
    }
    Tree->m_magic=MAGICNUM;
    
	return Tree;
}



ADTErr TreeInsert(Tree* _tree, char _name[])
{
	Node* newnode;
	ADTErr error;
	if(NULL == _tree)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(NULL == (newnode=(struct Node*)malloc(sizeof(struct Node))))
 	{
   		return ERR_ALLOCATION_FAILED;
    }
    strcpy(newnode->m_word,_name);
    
	if(_tree->m_root == NULL)
	{
		_tree->m_root = newnode;
		return ERR_OK;
	}
	else
	{
		error=InsertNode(_tree->m_root,newnode);
		return error;
	}
}



ADTErr InsertNode(Node* _root, Node* _insert)
{
	ADTErr error;
	if(_root->m_right == NULL && strcmp(_root->m_word,_insert->m_word)>0)
	{
		_insert->m_count++;
		_insert=_root->m_right;
		
		return ERR_OK;
	}
	if(_root->m_left == NULL && strcmp(_root->m_word,_insert->m_word)<0)
	{
		_insert->m_count++;
		_insert=_root->m_left;
		return ERR_OK;
	}
	if(strcmp(_root->m_word,_insert->m_word) == 0)
	{
		_insert->m_count++;
		return ERR_OK;
	}
	if(strcmp(_root->m_word,_insert->m_word)>0)
	{
		error=InsertNode(_root->m_right,_insert);
	}
	if(strcmp(_root->m_word,_insert->m_word)<0)
	{
		error=InsertNode(_root->m_left,_insert);
	}
	return error;
}
void Destroy(Node* _root)
{
	if(_root!=NULL)
	{
		Destroy(_root->m_left);
		Destroy(_root->m_right);
		free(_root);
	}
	return;
}
void TreeDestroy(struct Tree* _tree)
{
	if(NULL == _tree)
	{
		return;
	}
	
	Destroy(_tree->m_root);
	free(_tree);
	return;
}

