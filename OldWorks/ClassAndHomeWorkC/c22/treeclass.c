
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
static int CheckSimilar(Node* _root1, Node* _root2);
int AreSimilar(Tree* _tree1, Tree* _tree2);
/*int CheckNodeLevel(node* _root)

	int levelright,levelleft;
	if(_root == NULL)
	_levelleft=CheckNodeLevel(_root->m_left,_level+1,);
	_levelright=CheckNodeLevel(_root->m_right,_level+1,);
	if(levelright > levelleft)
	{
		return levelright + 1;
	}
	if(levelright < levelleft)
	{
		return levelleft + 1;
	}
	return levelright + 1;
}

int CheckTreeLevel(Tree* _tree)
{
	
	if(_tree->m_root == NULL)
	{
		return -1;
	}
	
	level=CheckNodeLevel( _tree->m_root);
	


}*/


int AreSimilar(Tree* _tree1, Tree* _tree2)
{

	if(NULL == _tree1 || NULL == _tree1)
	{
		return 0;
	}
	CheckSimilar(_tree1->m_root,_tree2->m_root);

}
static int CheckSimilar(Node* _root1, Node* _root2)
{
	int result;
	if(NULL == _root1 && NULL == _root2)
	{
		return SAME;
	}
	if((NULL =! _root1 && NULL == _root2) || (NULL == _root1 && NULL =! _root2))
	{
		return NOT_SAME;
	}
	if(_root1->m_data == _root2->m_data)
	{
		return SAME;
	}
	else
	{
		return NOT_SAME;
	}
	result = CheckSimilar(_root1->m_left,_root2->m_left) & 1;
	result = CheckSimilar(_root1->m_right,_root2->m_right) & 1;
	return result;
}


