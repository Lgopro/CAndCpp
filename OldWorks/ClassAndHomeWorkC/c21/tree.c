
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct Node Node;
#define MAGICNUM 8577438
struct Node
{
    int     m_data;
    Node*   m_left;
    Node*   m_right;
    Node*   m_father;
};

struct Tree
{
    Node*   m_root;
    int m_magic;
};

/*
Description: Function gets data input from user.
Input: Pointer to the original tree.
Output: 0 if tree not initialized or the data number added by the user.
Complexity: o(1).
*/
static int GetData(Tree* _tree);
/*
Description: Function prits the tree in the selected way.
Input: Pointer to the root of the tree and the way to print.
Output: Void.
Complexity: o(n).
*/
static void NodePrint(Node* _root, TreeTraverse _traverseMode);
/*
Description: Function gets input from user on the pyte he want to print in.
Input: Pointer to the original tree.
Output: Void.
Complexity: o(1).
*/
static void Print(Tree* _tree);
/*
Description: Function the find if the inserted data is in the tree structure.
Input: The structure of the root of the tree and the created new node to look for the needed data.
Output: NOT_GENERATED if the tree structure dident created, EQUALITY_FOUND if the data found in the structure and EQUALITY_NOT_FOUND if not.
Complexity: o(n).
*/
static int FindtNode(Node* _root, Node* _insert);
/*
Description: Function insert the node to the tree.
Input: The structure of the root of the tree and the created new node to insert.
Output: ERR_NOT_INITIALIZED if the tree structure dident created, ERR_OK if the data included in the structure and ERR_GENERAL if the dasa already found in the tree.
Complexity: o(n).
*/
static ADTErr InsertNode(Node* _root, Node* _insert);
/*
Description: Function destroyes all the nodes in the tree recursivly.
Input: The structure of the root of the tree.
Output: Void.
Complexity: o(n).
*/
static void Destroy(Node* _root);


static void PrePrint(Node* _root)
{
	if(_root != NULL)
	{
		printf("The number is: %d\n", _root->m_data);
    	PrePrint(_root->m_left);
		PrePrint(_root->m_right);
    }
}
static void InPrint(Node* _root)
{
	if(_root != NULL)
	{
		InPrint(_root->m_left);
    	printf("The number is: %d\n", _root->m_data);
		InPrint(_root->m_right);
    }
}
static void PostPrint(Node* _root)
{
	if(_root != NULL)
	{
		PostPrint(_root->m_left);
		PostPrint(_root->m_right);
    	printf("The number is: %d\n", _root->m_data);
    }
}
static void NodePrint(Node* _root, TreeTraverse _traverseMode)
{
	if(_root->m_left == NULL)
	{
		printf("The number is: %d\n", _root->m_data);
		return;
	}
	if(_root->m_right == NULL)
	{
		printf("The number is: %d\n", _root->m_data);
		return;
	}
	if( _traverseMode == PRE_ORDER)
    {
    	printf("The number is: %d\n", _root->m_data);
    	NodePrint(_root->m_left,PRE_ORDER);
		NodePrint(_root->m_right,PRE_ORDER);
    	return;
    }
    if( _traverseMode == IN_ORDER)
    {
    	NodePrint(_root->m_left,IN_ORDER);
    	printf("The number is: %d\n", _root->m_data);
		NodePrint(_root->m_right,IN_ORDER);
    	return;
    }
    if( _traverseMode == POST_ORDER)
    {
    
    	NodePrint(_root->m_left,POST_ORDER);
		NodePrint(_root->m_right,POST_ORDER);
    	printf("The number is: %d\n", _root->m_data);
    	return;
    }

}


int GetData(Tree* _tree)
{
	int data;
	if(_tree==NULL)
	{
        return 0;
	}
	
	printf("Please enter the data number:\n");
	scanf("%d", &data);
	getchar();
	return data;
}
void Print(Tree* _tree)
{
	int choise;
	printf("Please enter the type of printing:\n");
	printf("1)Pre order\n");
	printf("2)In order:\n");
	printf("3)Post order:\n");
	scanf("%d\n",&choise);
	if(choise == PRE_ORDER_)
	{
		TreePrint(_tree, PRE_ORDER);
	}
	if(choise == IN_ORDER_)
	{
		TreePrint(_tree, IN_ORDER);
	}
	if(choise == POST_ORDER_)
	{
		TreePrint(_tree, POST_ORDER);
	}
}
void Destroy(Node* _root)
{
	if(_root != NULL)
	{
		Destroy(_root->m_left);
		Destroy(_root->m_right);
		free(_root);
	}
	return;
}
int FindtNode(Node* _root, Node* _insert)
{
	int result;
	if(_root == NULL)
	{
		return EQUALITY_NOT_FOUND;
	}
	if(_root->m_data == _insert->m_data)
	{
		return EQUALITY_FOUND;
	}
	if(_root->m_data < _insert->m_data)
	{
		result=FindtNode(_root->m_right,_insert);
	}
	if(_root->m_data > _insert->m_data)
	{
		result=FindtNode(_root->m_left,_insert);
	}
	
	return result;
	
	
	if(_root->m_right == NULL && _root->m_data < _insert->m_data)
	{
		return EQUALITY_NOT_FOUND;
	}
	if(_root->m_left == NULL && _root->m_data > _insert->m_data)
	{
		return EQUALITY_NOT_FOUND;
	}
	if(_root->m_data == _insert->m_data)
	{
		return EQUALITY_FOUND;
	}
	if(_root->m_data < _insert->m_data)
	{
		result=FindtNode(_root->m_right,_insert);
	}
	if(_root->m_data > _insert->m_data)
	{
		result=FindtNode(_root->m_left,_insert);
	}
	return result;
	
}
ADTErr InsertNode(Node* _root, Node* _insert)
{
	ADTErr error;
	if(_root->m_right == NULL && _root->m_data < _insert->m_data)
	{
		_root->m_right=_insert;
		_insert->m_father=_root;
		return ERR_OK;
	}
	if(_root->m_left == NULL && _root->m_data > _insert->m_data)
	{
		_root->m_left=_insert;
		_insert->m_father=_root;
		return ERR_OK;
	}
	if(_root->m_data == _insert->m_data)
	{
		return ERR_GENERAL;
	}
	if(_root->m_data < _insert->m_data)
	{
		error=InsertNode(_root->m_right,_insert);
	}
	if(_root->m_data > _insert->m_data)
	{
		error=InsertNode(_root->m_left,_insert);
	}
	return error;
}






Tree* TreeCreate(void)
{
	Tree* tree=NULL;
 	if(NULL == (tree=(struct tree*)malloc(sizeof(struct tree))))
 	{
   		return NULL;
    }
    tree->m_magic=MAGICNUM;
    tree->m_root = NULL;
	return tree;
}

void TreeDestroy(struct Tree* _tree)
{
	if(NULL == _tree || _tree->m_magic != MAGICNUM)
	{
		return;
	}
	
	Destroy(_tree->m_root);
	_tree->m_magic = 0;
	free(_tree);
	return;
}


ADTErr TreeInsert(Tree* _tree, int _data)
{
	Node* newnode;
	ADTErr error;
	if(NULL == _tree)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(NULL == (newnode=(struct Node*)calloc(1,sizeof(struct Node))))
 	{
   		return ERR_ALLOCATION_FAILED;
    }
    newnode->m_data = _data;
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


int TreeIsDataFound(Tree* _tree, int _data)
{
	Node* newnode;
	int datafound;
	if(NULL == _tree)
	{
		return NOT_INITIALIZED;
	}
	return FindtNode(_tree->m_root, _data);
	
}




void TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	
	if(NULL == _tree)
	{
		return;
	}
    if( _traverseMode == PRE_ORDER)
    {
    	PrePrint(_tree->m_root);
    
    }
    if( _traverseMode == IN_ORDER)
    {
    	InPrint(_tree->m_root);
    
    }
    if( _traverseMode == POST_ORDER)
    {
    
    	PostPrint(_tree->m_root);
    }
  	return;

}





