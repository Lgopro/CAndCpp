


#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include "avl.h" 

#define MAXIMUM(x, y) ((x > y) ? x : y)


#define FAIL 1
#define SUCCESS 0
#define ZERO 0

static void AVLNodeDestroy(avl_node_t *node);
static avl_node_t * InsertNode(avl_tree_t *tree, avl_node_t *tree_node, avl_node_t *input_node);
static void InputValues(avl_node_t *node, avl_node_t *left, avl_node_t *right, void *data, size_t node_level);
static size_t NodeCount(avl_node_t *node);
static avl_node_t *FindNode(avl_tree_t *tree, avl_node_t *node, const void *data);
static int NodeForEach(avl_tree_t *tree, avl_node_t* root, int traverse_type, int (*call_back)(void *, void *), void *param);
static avl_node_t * RemoveNode(avl_tree_t *tree, avl_node_t *node, const void *data);
static avl_node_t *MinNode(avl_node_t * node);
static size_t FindHeight(avl_node_t *node);
static avl_node_t *RotateLeft(avl_node_t * node);
static avl_node_t *RotateRight(avl_node_t * node);
static int BalanceLevel(avl_node_t * node);
static avl_node_t *Balance(avl_node_t * node, int (*compare_func)(const void *, const void *), void *data);
static avl_node_t *BalanceRemove(avl_node_t * node);






/******************************************************/

avl_tree_t *AVLCreate(int (*compare_func)(const void *,const void *))
{
	avl_tree_t *tree = NULL;
	
	assert(compare_func);
	
	tree = (avl_tree_t *)malloc(sizeof(avl_tree_t));
	if(NULL == tree)
	{
		return NULL;
	}

	tree->root = NULL;
	tree->compare_func = compare_func;
	return (tree);
}



/******************************************************/

void AVLDestroy(avl_tree_t *tree)
{
	assert(tree);
	if(!AVLIsEmpty((const avl_tree_t *)tree))
	{
		AVLNodeDestroy(tree->root);
	}
	free(tree);
}


/******************************************************/

void AVLRemove(avl_tree_t *tree, void *data)
{
	assert(tree);
	assert(data);
	tree->root = RemoveNode(tree, tree->root, (const void *)data);	
	FindHeight(tree->root);
}


/******************************************************/

int AVLIsEmpty(const avl_tree_t *tree)
{
	assert(tree);
	return (NULL == tree->root);
}	


/******************************************************/

void *AVLFind(avl_tree_t *tree, const void *data)
{
	avl_node_t *node = NULL;
	assert(tree);
	assert(data);

	node = FindNode(tree, tree->root, data);
	if(NULL == node)
	{
		return NULL;
	}
	return (node->data);
}


/******************************************************/


size_t AVLCount(const avl_tree_t *tree)
{
	assert(tree);
	if(AVLIsEmpty(tree))
	{
		return (ZERO);
	}
	return (NodeCount(tree->root) + 1);
}

/******************************************************/

size_t AVLHeight(const avl_tree_t *tree)
{
	assert(tree);
	if(AVLIsEmpty(tree))
	{
		return (ZERO);
	}
	return tree->root->node_level; 
}



/******************************************************/

int AVLInsert(avl_tree_t *tree, void *data)
{
	
	avl_node_t *node_to_insert = NULL;
	avl_node_t *node_from_tree = NULL;
	
	assert(tree);
	assert(data);
	
	node_to_insert = (avl_node_t *)malloc(sizeof(avl_node_t));
	
	if(NULL == node_to_insert)
	{
		return (FAIL);
	}
	
	InputValues(node_to_insert, NULL, NULL, data, 0);

	if(AVLIsEmpty((const avl_tree_t *)tree))
	{
		tree->root = node_to_insert;
		return (SUCCESS);
	}
	node_from_tree = tree->root;
	tree->root = InsertNode(tree, node_from_tree, node_to_insert);
	tree->root->node_level = FindHeight(tree->root);
	if(NULL == tree->root)
	{
		return (FAIL);
	}
	return (SUCCESS);
}


/******************************************************/




int AVLForEach(avl_tree_t *tree, int traverse_type, int (*call_back)(void *, void *), void *param)
{
	assert(tree);
	assert(call_back);
	return (NodeForEach(tree, tree->root, traverse_type, call_back, param));
}



/********************static functions********************/

static avl_node_t *BalanceRemove(avl_node_t * node)
{
	int balance_level = 0;
	if (NULL == node)
	{
		return (node);
	}	

    node->node_level = FindHeight(node);
    balance_level = BalanceLevel(node);

	if (balance_level > 1 && BalanceLevel(node->children[LEFT]) >= 0)
	{
		return (RotateRight(node));
	}
        
    if (balance_level > 1 && BalanceLevel(node->children[RIGHT])< 0)
    {
        node->children[LEFT] =  RotateLeft(node->children[LEFT]);
        return (RotateRight(node));
    }

    if (balance_level < -1 && BalanceLevel(node->children[RIGHT]) <= 0)
	{
		return (RotateLeft(node));
	}
        
    if (balance_level < -1 && BalanceLevel(node->children[RIGHT]) > 0)
    {
        node->children[RIGHT] = RotateRight(node->children[RIGHT]);
        return (RotateLeft(node));
    }
	return (node);
}


static avl_node_t *Balance(avl_node_t * node, int (*compare_func)(const void *, const void *), void *data)
{
	int balance_level = 0;
	if (NULL == node)
	{
		return (node);
	}	
    node->node_level = FindHeight(node);
    balance_level = BalanceLevel(node);

    if (balance_level > 1 && 0 < compare_func(node->children[LEFT]->data, data))
	{
		return RotateRight(node);
	}
	if (balance_level > 1 && 0 > compare_func(node->children[LEFT]->data, data))
    {
        node->children[LEFT] = RotateLeft(node->children[LEFT]);
		return RotateRight(node);
    }
	if (balance_level < -1 && 0 > compare_func(node->children[RIGHT]->data, data) )
	{
		return RotateLeft(node);
	}
    if (balance_level < -1 && 0 < compare_func(node->children[RIGHT]->data, data))
    {
        node->children[RIGHT] = RotateRight(node->children[RIGHT]);
		return RotateLeft(node);	
    }

	return (node);
}

static avl_node_t *RotateLeft(avl_node_t * node)
{
	avl_node_t *root = node->children[RIGHT];
    node->children[RIGHT] = root->children[LEFT];
    root->children[LEFT] = node;
    
	FindHeight(root);

	return (root);
}

static avl_node_t *RotateRight(avl_node_t * node)
{

	avl_node_t *root = node->children[LEFT]; 
    node->children[LEFT] = root->children[RIGHT];
    root->children[RIGHT] = node;

    FindHeight(root);
	
    return (root);
}

static int BalanceLevel(avl_node_t * node)
{
	if(NULL == node)
	{
		return (ZERO);
	}
	
	return ((int)FindHeight(node->children[LEFT]) - (int)FindHeight(node->children[RIGHT]));
	
}


static int NodeForEach(avl_tree_t *tree, avl_node_t* root, int traverse_type, int (*call_back)(void *, void *), void *param)
{
	int status = 0;

	if(NULL == root)
	{
		return (0);
	}
	if(PRE_ORDER == traverse_type)
    {
		status = call_back(root->data, param);
		if(0 != status)
		{
			return (status);
		}
    	status = NodeForEach(tree, root->children[LEFT], PRE_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
		status = NodeForEach(tree, root->children[RIGHT],PRE_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
		
    }
    if(IN_ORDER == traverse_type)
    {
    	status = NodeForEach(tree, root->children[LEFT], IN_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
		status = call_back(root->data, param);
		if(0 != status)
		{
			return (status);
		}
		status = NodeForEach(tree, root->children[RIGHT],IN_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
    }
    if(POST_ORDER == traverse_type)
    {
    	status = NodeForEach(tree, root->children[LEFT], POST_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
		status = NodeForEach(tree, root->children[RIGHT],POST_ORDER, call_back, param);
		if(0 != status)
		{
			return (status);
		}
		status = call_back(root->data, param);
		if(0 != status)
		{
			return (status);
		}
    }
	return (status);
}


static avl_node_t *MinNode(avl_node_t * node)
{
	if(NULL != node->children[LEFT] && node)
	{
		MinNode(node->children[LEFT]);
	}
	return (node);
}

static void InputValues(avl_node_t *node, avl_node_t *left, avl_node_t *right, void *data, size_t node_level)
{
	node->children[LEFT] = left;
	node->children[RIGHT] = right;
	node->data = data;
	node->node_level = node_level;
}


static size_t NodeCount(avl_node_t *node)
{
	size_t counter = 0;
	
	if(NULL == node)
	{
		return (0);
	}
	if((node->children[LEFT]))
	{
		++counter;
	}
	if((node->children[RIGHT]))
	{
		++counter;
	}
	counter += NodeCount(node->children[LEFT]) + NodeCount(node->children[RIGHT]);
	return (counter);
}

static avl_node_t *FindNode(avl_tree_t *tree, avl_node_t *node, const void *data)
{
	avl_node_t *node_to_find = NULL;
	if(0 < tree->compare_func(node->data, data) && NULL == node->children[LEFT])
	{
		return NULL;
	}
	else if(0 > tree->compare_func(node->data, data) && NULL == node->children[RIGHT])
	{
		return NULL;
	}
	else if(0 < tree->compare_func(node->data, data))
	{
		node_to_find = FindNode(tree, node->children[LEFT], data);
		return node_to_find;
	}
	else if(0 > tree->compare_func(node->data, data))
	{
		node_to_find = FindNode(tree, node->children[RIGHT], data);
		return node_to_find;
	}
	return (node);
}


static size_t FindHeight(avl_node_t *node)
{
	size_t height_left = 0;
	size_t height_right = 0;
	if(NULL == node)
	{
		return (0);
	}
	
	height_left = FindHeight(node->children[LEFT]);
	node->node_level = height_left;
	height_right = FindHeight(node->children[RIGHT]);
	node->node_level = height_right;
	
	return (MAXIMUM(height_left, height_right) + 1);
}


static avl_node_t * InsertNode(avl_tree_t *tree, avl_node_t *tree_node, avl_node_t *input_node) 
{
	
	if(0 < tree->compare_func(tree_node->data, input_node->data) && NULL == tree_node->children[LEFT])
	{
		tree_node->children[LEFT] = input_node;
		tree_node = Balance(tree_node, tree->compare_func, input_node->data);
		return (tree_node);
	}
	else if(0 > tree->compare_func(tree_node->data, input_node->data) && NULL == tree_node->children[RIGHT])
	{
		tree_node->children[RIGHT] = input_node;
		tree_node = Balance(tree_node, tree->compare_func, input_node->data);
		return (tree_node);
	}
	else if(0 < tree->compare_func(tree_node->data, input_node->data))
	{
		tree_node->children[LEFT] = InsertNode(tree, tree_node->children[LEFT], input_node);
		tree_node = Balance(tree_node, tree->compare_func, input_node->data);
		return (tree_node);
	}
	else if(0 > tree->compare_func(tree_node->data, input_node->data))
	{
		tree_node->children[RIGHT] = InsertNode(tree, tree_node->children[RIGHT], input_node);
		tree_node = Balance(tree_node, tree->compare_func, input_node->data);
		return (tree_node);
	}
	free(input_node);

	return NULL;
}


static void AVLNodeDestroy(avl_node_t *node)
{
	if(NULL == node)
	{
		return;
	}
	
	AVLNodeDestroy(node->children[LEFT]);
	AVLNodeDestroy(node->children[RIGHT]);
	free(node);
	
}

static avl_node_t *RemoveNode(avl_tree_t *tree, avl_node_t *node, const void *data)
{
	avl_node_t *temp = NULL;
	if(NULL == node)
	{
		return (node);
	}
	if(0 < tree->compare_func(node->data, data))
	{
		node->children[LEFT] = RemoveNode(tree, node->children[LEFT], data);
	}
	else if(0 > tree->compare_func(node->data, data))
	{
		node->children[RIGHT] = RemoveNode(tree, node->children[RIGHT], data);
	}
	else
	{
		if((NULL == node->children[LEFT]) && (NULL == node->children[RIGHT]))
        {
			free(node);
			return NULL;
		}	
		else if (NULL == node->children[LEFT])
		{
			temp = node->children[RIGHT];
			free(node);
			return (temp);
		}
		else if(NULL == node->children[RIGHT])
		{
			temp = node->children[LEFT];
			free(node);
			return (temp);
		}
		temp = MinNode(node->children[RIGHT]);
        node->data = temp->data;
        node->children[RIGHT] = RemoveNode(tree, node->children[RIGHT], node->data);
	}
	node = BalanceRemove(node);
	return (node);
}
