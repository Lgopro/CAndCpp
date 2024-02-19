#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Description: Function flips the node in oposite order.
Input: Node structure.
Output: The node structure after the change.
Complexity: o(n).
*/
Node* Flip(Node* _node);

int main()
{


	return 0;
	
}


Node* Flip(Node* _node)
{
	Node* node;
	
	if(_node == NULL || _node->m_next == NULL)
	{
		return _node
	
	}
	node=Flip(_node->m_next);
	
	_node->m_next->m_next=_node;
	_node->m_next = NULL;
	
	return node;






}
