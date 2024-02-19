#ifndef __LISTSTRUCTS_H__
#define __LISTSTRUCTS_H__


typedef struct Node Node;

struct Node
{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};


struct List
{
	int m_magic;
	Node m_head;
	Node m_tail;
	
};



#endif
