/*
Rev: Eylon Enache
Dev: Leonid Golovko
status: finished
date:04/06/2023
*/

#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/

#include "bst.h" 

#define MAX (2147483647)

#define EMPTY (1)
#define ERROR (-1)
#define FOUND (-1)

struct BSTNode
{
    bst_node_t *parent;
    bst_node_t *children[NUM_OF_CHILDREN];
    void *value;
};

struct BST
{
    bst_node_t root_stub;
    int (*compare_func)(const void *a, const void *b);
};


static void InputValues(bst_node_t *node, bst_node_t *parent, bst_node_t *left, bst_node_t *right, void *data);
static bst_iter_t MostLeftNode(bst_node_t * node);
static bst_iter_t MostRightNode(bst_node_t * node);
static int FindRightParent(bst_iter_t current_iter);
static int RightDirection(bst_t *tree, void *node_to_insert_value, void *node_from_tree_value);
static bst_node_t *IterToNode(bst_iter_t iter);
static bst_iter_t NodeToIter(bst_node_t * node);




bst_t *BSTCreate(int (*compare_func)(const void *a, const void *b))
{

	bst_t *tree = (bst_t *)malloc(sizeof(bst_t) + sizeof(bst_node_t));
	if(NULL == tree)
	{
		return NULL;
	}
	
	InputValues(&tree->root_stub, NULL, NULL, NULL, &(tree->root_stub));
	
	tree->compare_func = compare_func;
	
	return tree;
	
}

void BSTDestroy(bst_t *tree) 
{
	bst_iter_t node = NULL;
	
	assert(tree);
	
	while(EMPTY != BSTIsEmpty((const bst_t *)tree))
	{
		node = tree->root_stub.children[LEFT];
		BSTRemove(node);
	}
	free(tree);
}


bst_iter_t BSTInsert(bst_t *tree, void *data)
{
	bst_node_t *node_to_insert = NULL;
	bst_node_t *node_from_tree = NULL;
	int right_direction = 0;
	int flag = 0;
	assert(tree);
	
	node_to_insert = (bst_node_t *)malloc(sizeof(bst_node_t));
	if(NULL == node_to_insert)
	{
		return BSTEnd((const bst_t *)tree);
	}
	
	InputValues(node_to_insert, NULL, NULL, NULL, data);
	
	node_from_tree = tree->root_stub.children[LEFT];
	
	if(BSTIsEmpty((const bst_t *)tree))
	{
		tree->root_stub.children[LEFT] = node_to_insert;
		node_to_insert->parent = &tree->root_stub; 
		return NodeToIter(node_to_insert);
	}
	while(FOUND != flag)
	{
		right_direction = RightDirection(tree, node_to_insert->value, node_from_tree->value);
		if(right_direction == NUM_OF_CHILDREN)
		{
			free(node_to_insert);
		 	return BSTEnd((const bst_t *)tree);
		}
		if(NULL == node_from_tree->children[right_direction])
		{
			node_from_tree->children[right_direction] = node_to_insert;
			node_to_insert->parent = node_from_tree;
			flag = FOUND; 
			continue;
		}
		node_from_tree = node_from_tree->children[right_direction];
	}
	return NodeToIter(node_to_insert);
}

bst_iter_t BSTBegin(const bst_t *tree)
{
	bst_node_t* node = NULL;
	
	assert(tree);
	
	if(BSTIsEmpty(tree))
	{
		return (bst_iter_t)&(tree->root_stub);
	}
	
	node = tree->root_stub.children[LEFT];
	
	return MostLeftNode(node);
}


bst_iter_t BSTEnd(const bst_t *tree)
{
	assert(tree);
	
	return (bst_iter_t)&(tree->root_stub);
}

void *BSTGetData(bst_iter_t where)
{
	assert(where);
	
	return where->value;
}

int BSTIsEmpty(const bst_t *tree)
{
	assert(tree);
	
	return (NULL == tree->root_stub.children[LEFT]);
}

int BSTIsSameIter(const bst_iter_t iter1, const bst_iter_t iter2)
{		
	return (iter1 == iter2);
}


bst_iter_t BSTFind(bst_t *tree, const void *param)
{

	int right_direction = 0;
	bst_node_t *node_from_tree = NULL;
	int flag = 0;
	
	assert(tree);
	assert(param);
	
	node_from_tree = tree->root_stub.children[LEFT];
	
	while(FOUND != flag)
	{
		right_direction = RightDirection(tree, (void *)param, node_from_tree->value);
		if(right_direction == NUM_OF_CHILDREN)
		{
		 	return node_from_tree;
		}
		if(NULL == node_from_tree->children[right_direction])
		{
			flag = FOUND; 
			continue;
		}
		node_from_tree = node_from_tree->children[right_direction];
	}
	return BSTEnd((const bst_t *)tree);
}

int BSTForEach(bst_iter_t from, bst_iter_t to, int (*call_back)(void *, void *), void *param)
{

	bst_iter_t node = NULL;
	int status = 0;
	assert(from);
	assert(to);
	assert(call_back);
	
	node = from;

	while(1 != BSTIsSameIter(node, to))
	{
		status = call_back(node->value, param);
		if(1 == status)
		{
			return status;
		}
		node = BSTNext(node);
	}
	
	return status;
}


size_t BSTSize(const bst_t *tree)
{
	bst_iter_t count = NULL;
	bst_iter_t end = NULL;
	
	size_t counter = 0;
	assert(tree);
	
	if(BSTIsEmpty(tree))
	{
		return counter;
	}
	
	count = BSTBegin((const bst_t *)tree);
	end = BSTEnd((const bst_t *)tree);
	
	while(1 != BSTIsSameIter(count, end))
	{
		count = BSTNext(count);
		++counter;
	}
	return counter;
}



bst_iter_t BSTNext(bst_iter_t current)
{
	bst_node_t * runner = NULL;
	
	assert(current);
	
	runner = IterToNode(current);

	if(NULL == runner->children[RIGHT] && NULL != runner->parent)
	{
		while(1 == BSTIsSameIter(NodeToIter(runner), NodeToIter(runner->parent->children[RIGHT])))
		{
			if(NULL == runner->parent)
			{
				return NodeToIter(runner->value);
			}
			runner = runner->parent;
		}
		return NodeToIter(runner->parent);
	}
		
	if(NULL != runner->children[RIGHT] && NULL != runner->parent)
	{
		runner = runner->children[RIGHT];
		
		return MostLeftNode(runner);
	}
	return NULL;
}

bst_iter_t BSTPrev(bst_iter_t current)
{

	bst_node_t * runner = NULL;
	
	assert(current);
	
	runner = IterToNode(current);
		
	if(NULL == runner->children[LEFT])
	{
		while(1 == BSTIsSameIter(NodeToIter(runner), NodeToIter(runner->parent->children[LEFT])))
		{
			if(NULL == runner->parent)
			{
				return NodeToIter(runner->value);
			}
			runner = runner->parent;
		}
		return NodeToIter(runner->parent);
	}
		
	if(NULL != runner->children[LEFT] && NULL != runner->parent)
	{
		runner = runner->children[LEFT];
		
		return MostRightNode(runner);
	}
	return NULL;
}


void BSTRemove(bst_iter_t current)
{
	bst_node_t *current_iter = NULL;
	bst_node_t *prev_iter = NULL;
	int right_parent = 0;
	
	assert(current);
	current_iter = IterToNode(current);

	if(NULL == current_iter->children[RIGHT] && NULL == current_iter->children[LEFT] )
	{
		right_parent = FindRightParent(NodeToIter(current_iter));
		
		current_iter->parent->children[right_parent] = NULL;
		free(current_iter);
		return;
	}
	else if(NULL != current_iter->children[RIGHT] && NULL == current_iter->children[LEFT])
	{
		
		right_parent = FindRightParent(NodeToIter(current_iter));
		
		current_iter->parent->children[right_parent] = current_iter->children[RIGHT];
		current_iter->children[RIGHT]->parent = current_iter->parent;
		free(current_iter);
		return;
	}
	else
	{
		prev_iter = IterToNode(BSTPrev(NodeToIter(current_iter)));
		current_iter->value = prev_iter->value;
		
		if(NULL == prev_iter->children[RIGHT] && NULL == prev_iter->children[LEFT] )
		{
			right_parent = FindRightParent(NodeToIter(prev_iter));
			
			prev_iter->parent->children[right_parent] = NULL;
			free(prev_iter);
			return;
		}
		else
		{
			prev_iter->parent->children[RIGHT] = prev_iter->children[LEFT];
			prev_iter->children[LEFT]->parent = prev_iter->parent;
			free(prev_iter);
			return;
		}	
	}
}


/***********************************STATIC FUNC*********************************/


static void InputValues(bst_node_t *node, bst_node_t *parent, bst_node_t *left, bst_node_t *right, void *data)
{
	node->parent = parent;
	node->children[LEFT] = left;
	node->children[RIGHT] = right;
	node->value = data;
}

static bst_iter_t MostLeftNode(bst_node_t * node)
{
	while(NULL != node->children[LEFT])
	{
		node = node->children[LEFT];
	}
	return NodeToIter(node);
}

static bst_iter_t MostRightNode(bst_node_t * node)
{
	while(NULL != node->children[RIGHT])
	{
		node = node->children[RIGHT];
	}
	return NodeToIter(node);
}


static int FindRightParent(bst_iter_t current_iter)
{
	
	if(1 == BSTIsSameIter(current_iter->parent->children[LEFT], current_iter))
	{
		return LEFT;
	}
	
	return RIGHT;
}

static int RightDirection(bst_t *tree, void *node_to_insert_value, void *node_from_tree_value)
{
	if(0 == tree->compare_func(node_to_insert_value, node_from_tree_value))
	{
		return NUM_OF_CHILDREN;
	}
	else if(0 > tree->compare_func(node_to_insert_value, node_from_tree_value))
	{	
		return LEFT;
	}
	else if(0 < tree->compare_func(node_to_insert_value, node_from_tree_value))
	{	
		return RIGHT;
	}
	return ERROR;
}


static bst_node_t *IterToNode(bst_iter_t iter)
{
	return (bst_node_t *)iter;
}

static bst_iter_t NodeToIter(bst_node_t * node)
{
	return (bst_iter_t)node;
}
