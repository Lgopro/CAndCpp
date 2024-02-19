
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
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
static void MirrorNode(Node* _root);
int AreSimilar(Tree* _tree1, Tree* _tree2);
static int CheckSimilar(Node* _root1, Node* _root2);
int CheckFullTree( Node* _root);
int CheckNodeLevel(Node* _root);
/*
Description: Function gets data input from user.
Input: Pointer to the original tree.
Output: 0 if tree not initialized or the data number added by the user.
Complexity: o(1).
*/
int GetData(Tree* _tree);
/*
Description: Function prits the tree in the selected way.
Input: Pointer to the root of the tree and the way to print.
Output: Void.
Complexity: o(n).
*/
void NodePrint(Node* _root, TreeTraverse _traverseMode);
/*
Description: Function gets input from user on the pyte he want to print in.
Input: Pointer to the original tree.
Output: Void.
Complexity: o(1).
*/
void Print(Tree* _tree);
/*
Description: Function the find if the inserted data is in the tree structure.
Input: The structure of the root of the tree and the created new node to look for the needed data.
Output: NOT_GENERATED if the tree structure dident created, EQUALITY_FOUND if the data found in the structure and EQUALITY_NOT_FOUND if not.
Complexity: o(n).
*/
int FindtNode(Node* _root, Node* _insert);
/*
Description: Function insert the node to the tree.
Input: The structure of the root of the tree and the created new node to insert.
Output: ERR_NOT_INITIALIZED if the tree structure dident created, ERR_OK if the data included in the structure and ERR_GENERAL if the dasa already found in the tree.
Complexity: o(n).
*/
ADTErr InsertNode(Node* _root, Node* _insert);
/*
Description: Function destroyes all the nodes in the tree recursivly.
Input: The structure of the root of the tree.
Output: Void.
Complexity: o(n).
*/
void Destroy(Node* _root);




void NodePrint(Node* _root, TreeTraverse _traverseMode)
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
	if(_root!=NULL)
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
		return ERR_OK;
	}
	if(_root->m_left == NULL && _root->m_data > _insert->m_data)
	{
		_root->m_left=_insert;
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
	struct Tree* Tree=NULL;
 	if(NULL == (Tree=(struct Tree*)malloc(sizeof(struct Tree))))
 	{
   		return NULL;
    }
    Tree->m_magic=MAGICNUM;
    Tree->m_root = NULL;
	return Tree;
}

void TreeDestroy(struct Tree* _tree)
{
	if(NULL == _tree)
	{
		return;
	}
	
	Destroy(_tree->m_root);
	if(_tree && _tree->m_magic == MAGICNUM)
	{
		free(_tree);
		_tree->m_magic = 0;
	}
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
	if(NULL == (newnode=(struct Node*)malloc(sizeof(struct Node))))
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
	if(NULL == (newnode=(struct Node*)malloc(sizeof(struct Node))))
 	{
   		return NOT_GENERATED;
    }
    newnode->m_data = _data;
	if(_tree->m_root == NULL)
	{
		return EQUALITY_NOT_FOUND;
	}
	else if(_tree->m_root->m_data ==  newnode->m_data)
    {
    	return EQUALITY_FOUND;
    }
	else
	{
		datafound=FindtNode(_tree->m_root,newnode);
		return datafound;
	}
}




void TreePrint(Tree* _tree, TreeTraverse _traverseMode)
{
	
	if(NULL == _tree)
	{
		return;
	}
    if( _traverseMode == PRE_ORDER)
    {
    NodePrint(_tree->m_root, PRE_ORDER);
    
    }
    if( _traverseMode == IN_ORDER)
    {
    NodePrint(_tree->m_root,IN_ORDER);
    
    }
    if( _traverseMode == POST_ORDER)
    {
    
    NodePrint(_tree->m_root, POST_ORDER);
    }
  	return;

}



int CheckNodeLevel(Node* _root)
{
	int levelright,levelleft;
	if(_root == NULL)
	{
		return -1;
	}
	
	levelleft = CheckNodeLevel(_root->m_left) + 1;
	levelright = CheckNodeLevel(_root->m_right) + 1;
	if(levelright > levelleft)
	{
		return levelright ;
	}
	return levelleft ;
}

int CheckTreeLevel(Tree* _tree)
{
	int level;
	if(_tree->m_root == NULL)
	{
		return -1;
	}
	level = CheckNodeLevel( _tree->m_root);
	return level;
}

int IsFullTree(Tree* _tree)
{
	if(_tree->m_root == NULL)
	{
		return 0;
	}
	return CheckFullTree( _tree->m_root);
}

int CheckFullTree( Node* _root)
{
	int fullleft,fullright;
	if((_root -> m_right != NULL && _root -> m_left == NULL) || (_root -> m_right == NULL && _root -> m_left != NULL))
	{
		return 0;
	}
	
	if(_root -> m_right == NULL && _root -> m_left == NULL)
	{
		return 1;
	}
	fullleft = CheckNodeLevel(_root->m_left) & 1;
	fullright = CheckNodeLevel(_root->m_right) & 1;
	
	return fullleft & fullright;


}

int AreSimilar(Tree* _tree1, Tree* _tree2)
{
	int status;
	if(NULL == _tree1 || NULL == _tree1)
	{
		return 0;
	}
	status=CheckSimilar(_tree1->m_root,_tree2->m_root);
	return status;

}
static int CheckSimilar(Node* _root1, Node* _root2)
{
	int result;
	
	if(NULL == _root1 && NULL == _root2)
	{
		return SAME;
	}
	if((NULL != _root1 && NULL == _root2) || (NULL == _root1 && NULL != _root2))
	{
		return NOT_SAME;
	}
	if(_root1->m_data == _root2->m_data)
	{
		result = CheckSimilar(_root1->m_left,_root2->m_left) & 1;
		result = CheckSimilar(_root1->m_right,_root2->m_right) & 1;
		return result;
	}
	else
	{
		return NOT_SAME;
	}
	return result;
}


Tree* MirrorTree(Tree* _tree)
{
	if(NULL == _tree)
	{
		return NULL;
	}
	MirrorNode(_tree->m_root);
	return _tree;
}


static void MirrorNode(Node* _root)
{
	struct Node* node;
	if(_root == NULL)
	{
		return;
	}
	else
	{
		MirrorNode(_root->m_left);
		MirrorNode(_root->m_right);
		node = _root->m_right;
		_root->m_right = _root->m_left;
		_root->m_left = node;
	}
	
}


