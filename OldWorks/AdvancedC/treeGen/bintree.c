

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"
#define MAGICNUM 8577438


typedef struct Node Node;

struct Node
{
    void*   m_data;
    Node*   m_left;
    Node*   m_right;
    Node*   m_parent;
};

struct BSTree
{
	int m_magic;
    Node m_root;
   	LessComparator m_less;
};
static BSTreeItr GoLeft(BSTreeItr _it);
static BSTreeItr InsertData(Node* _root, Node* _insert, BSTree* _tree);
static void Destroy(Node* _root, void (*_destroyer)(void*));
static BSTreeItr FindBegin(Node* _root);
static BSTreeItr GoRight(BSTreeItr _it);

BSTree* BSTree_Create(LessComparator _less)
{
	BSTree* Tree=NULL;
	if( NULL == _less)
	{
		return NULL;
	
	}
	
 	if(NULL == (Tree=(struct BSTree*)malloc(sizeof(struct BSTree))))
 	{
   		return NULL;
    }
    Tree->m_magic=MAGICNUM;
    Tree->m_root.m_right = &Tree->m_root;
    Tree->m_root.m_left = NULL;
    Tree->m_less = _less;
	return Tree;
}

static void Destroy(Node* _root, void (*_destroyer)(void*))
{
	if(_root->m_left != NULL)
	{
		Destroy(_root->m_left, _destroyer);
	}
	if(_root->m_right != NULL)
	{
		Destroy(_root->m_right, _destroyer);
	}
	if( _destroyer != NULL)
	{
		_destroyer(_root->m_data);
	}
	free(_root);
	return;
}

void  BSTree_Destroy(BSTree** _tree, void (*_destroyer)(void*))
{
	if( NULL == _tree || NULL == *_tree)
	{
		return;
	}
	if((*_tree) && (*_tree)->m_magic == MAGICNUM)
	{
		if((*_tree)->m_root.m_left == NULL)
		{
			 (*_tree)->m_magic = 0;
			(*_tree) = NULL;
			free((*_tree));
		}
		else
		{
			(*_tree)->m_magic = 0;
			Destroy((*_tree)->m_root.m_left, _destroyer);
			free((*_tree));
			(*_tree) = NULL;
		}
	}
}
static BSTreeItr FindBegin(Node* _root)
{
	
	if(NULL == _root)
	{
		return NULL;
	}
	if(_root->m_left == NULL)
	{
		return (BSTreeItr)_root;
	}
	return FindBegin(_root->m_left);
	
}

BSTreeItr BSTreeItr_Begin(const BSTree* _tree)
{

	if(NULL == _tree)
	{
		return NULL;
	}
	return FindBegin(_tree->m_root.m_left);
}
	

BSTreeItr BSTreeItr_End(const BSTree* _tree)
{
	if(NULL == _tree)
	{
		return NULL;
	}
	return (BSTreeItr)&_tree->m_root;
}


BSTreeItr BSTree_Insert(BSTree* _tree, void* _item)
{
	Node* newnode;
	BSTreeItr status;
	if(NULL == _tree )
	{
		return NULL;
	}
	if(NULL == _item )
	{
		return BSTreeItr_End(_tree);
	}
	if(NULL == (newnode=(struct Node*)calloc(1,sizeof(struct Node))))
 	{
   		return NULL;
    }
    newnode->m_data = _item;
    if(_tree->m_root.m_left == NULL)
    {
    	_tree->m_root.m_left = newnode;
    	return (BSTreeItr)newnode;
    }
    status=InsertData(_tree->m_root.m_left, newnode, _tree);
    return status;
}

static BSTreeItr InsertData(Node* _root, Node* _insert, BSTree* _tree)
{
	BSTreeItr status;
	if(_root->m_right == NULL && _tree->m_less(_root->m_data ,_insert->m_data))
	{
		_root->m_right=_insert;
		_insert->m_parent=_root;
		return (BSTreeItr)_insert;
	}
	if(_root->m_left == NULL && _tree->m_less(_insert->m_data, _root->m_data))
	{
		_root->m_left=_insert;
		_insert->m_parent=_root;
		return (BSTreeItr)_insert;
	}
	if(_root->m_data == _insert->m_data)
	{
		return (BSTreeItr)&_tree->m_root;
	}
	if(_tree->m_less(_root->m_data , _insert->m_data))
	{
		status = InsertData(_root->m_right,_insert, _tree);
		return status;
	}
	if(_tree->m_less( _insert->m_data , _root->m_data))
	{
		status = InsertData(_root->m_left,_insert, _tree);

	}
	return status;
}


int BSTreeItr_Equals(BSTreeItr _a, BSTreeItr _b)
{
	return (_a == _b);

}


BSTreeItr BSTreeItr_Next(BSTreeItr _it)
{	
	Node* node= (Node*)_it;
	if(node->m_right != NULL)
	{
		node = (Node*)GoLeft((BSTreeItr)node->m_right);
	}
	else
	{
		while (node->m_parent->m_left != node)
		{
			node = node->m_parent;
		}
		node = node->m_parent;
	}
	return (BSTreeItr)node;
}

static BSTreeItr GoLeft(BSTreeItr _it)
{
	Node* node= (Node*)_it;
	while(node->m_left != NULL)
	{
		node = node->m_left;
	}
	return (BSTreeItr)node;
}



BSTreeItr BSTreeItr_Prev(BSTreeItr _it)
{	
	Node* node= (Node*)_it;
	if(node->m_left != NULL)
	{
		node = (Node*)GoRight((BSTreeItr)node->m_left);
	}
	else
	{
		node = node->m_parent;
		while( node->m_parent->m_right != node)
		{
			node = node->m_parent;
			if( node->m_right == node)
			{
				return _it;
			}
		}
	}
	return (BSTreeItr)node->m_parent;
}

static BSTreeItr GoRight(BSTreeItr _it)
{
	Node* node= (Node*)_it;
	while(node->m_right != NULL)
	{
		node = node->m_right;
	}
	return (BSTreeItr)node;
}
void Swap(Node* node, Node* nodeprev)
{
	void* swap;
	swap = node->m_data;
	node->m_data = nodeprev->m_data;
	nodeprev->m_data = swap;

}

void* BSTreeItr_Remove(BSTreeItr _it)
{
	Node* nodeprev;
	Node* node = (Node*)_it;
	void* data;
	if( node->m_left != NULL && node->m_right != NULL)
	{
		nodeprev = (Node*)BSTreeItr_Prev(_it);
		data = node->m_data;
		Swap(node, nodeprev);
		
	}
	if( (node->m_left != NULL && node->m_right == NULL) || (node->m_left == NULL && node->m_right != NULL))
	{
		if( node->m_left != NULL)
		{
			data = node->m_data;
			nodeprev = (Node*)BSTreeItr_Prev(_it);
			node->m_parent->m_left = nodeprev->m_left;
			node->m_left->m_parent = nodeprev->m_parent;
			node = NULL;
			free(node);
		}
		else
		{
			data = node->m_data;
			nodeprev = (Node*)BSTreeItr_Prev(_it);
			node->m_parent->m_right = nodeprev->m_right;
			node->m_right->m_parent = nodeprev->m_parent;
			node = NULL;
			free(node);
		}	
	}
	else
	{
		if(node->m_parent->m_data > node->m_data)
		{
			data = node->m_data;
			free(node);
			node->m_parent->m_left = NULL;
			
		}
		else
		{
			data = node->m_data;
			free(node);
			node->m_parent->m_right = NULL;
			
		}
		
	}
	return data;
}

BSTreeItr BSTree_FindFirst(BSTreeItr _begin, BSTreeItr _end, PredicateFunction _predicate, void* _context)
{
	void* data;
	if(NULL == _begin || NULL == _end || _predicate == NULL || _context == NULL)
	{
		return _end;
	}
	
	while(_begin != _end)
	{
		data = BSTreeItr_Get(_begin);
		if(_predicate(data ,_context))
		{
			return _begin;
		}
		_begin = BSTreeItr_Next(_begin);
	}
	return _end;
}

void* BSTreeItr_Get(BSTreeItr _it)
{
	void* data;
	Node* node = (Node*)_it;
	data = node->m_data;
	return data;
}

BSTreeItr BSTree_ForEach(const BSTree* _tree, TreeTraversalMode _mode, ActionFunction _action, void* _context)
{
	BSTreeItr _begin,_end;
	_begin = BSTreeItr_Begin(_tree);
	_end = BSTreeItr_End(_tree);
	if(NULL == _tree || NULL == _context)
	{
		return _end;
	}
	while(_begin != _end)
	{
		if(_action(BSTreeItr_Get(_begin), _context))
		{
			return _begin;
		}
		_begin = BSTreeItr_Next(_begin);
	}
	return _end;
}
