#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Person* ListInsertHead(struct Person* _head ,struct Person* _p)
{
	if(NULL == _p)
	{
		return _head;
	}

	_p->m_next=_head;
	return _p;
}

struct Person* ListRemoveHead(struct Person* _head,struct Person** _item)
{
	if( NULL == _head ||  _item == NULL )
	{
		if(_item!=NULL)
		{	
			*_item=NULL;
		}
		return _head;
	}
	*_item = _head;
	return _head->m_next;
}

struct Person* ListInsertByKeyRec(struct Person* _head, int _key,struct Person* _p)
{
	if(NULL == _p)
	{
		return _head;
	}
	if(NULL == _head)
	{
		_p->m_next=_head;
		return _p;
	}
	if(_head->m_id==_key)
	{
		return _head;
	}
	if(_head->m_id<_key)
	{
		_p->m_next=_head;
		return _head;
	}
	_head->m_next=ListInsertByKeyRec(_head->m_next,_key,_p);
	return _head;

}

struct Person* ListInsertByKey(struct Person* _head, int _key,struct Person* _p)
{
	Person* move1=_head;
	Person* move2=_head;
	if(NULL == _p)
	{
		return _head;
	}
	if(NULL == _head)
	{
		_p->m_next=NULL;
		return _p;
	}
	while(move1!=NULL)
	{
		if(move1->m_id<_key)
		{
			move2->m_next=_p;
			_p->m_next=move1;
			return _head;
		
		}
		if(move1->m_id==_key)
		{
			return _head;
		}
		move2=move1;
		move1=move1->m_next;
	}
	move2->m_next=_p;
	_p->m_next=NULL;
	return _head;
	
}


void PrintList(struct Person* _head)
{
	Person* move1=_head;
	if(NULL == _head)
	{
		printf("There is nothing to print\n");
		return;
	}
	while(move1!=NULL)
	{
		printf("The id is: %d\n", move1->m_id);
		printf("The id is: %s\n", move1-> m_name);
		printf("The id is: %d\n", move1->m_age);
		move1=move1->m_next;
	}
}

Person* ListRemoveByKey(Person* _head, int _key, Person* *_p)
{

	Person* move1=_head;
	Person* move2=_head;
	if(NULL == _p)
	{
		return _head;
	}
	if(NULL == _head)
	{
		return _head;
	}
	while(move1!=NULL)
	{
		if(move1->m_id==_key)
		{
			move2->m_next=move1->m_next;
			*_p=move1;
			return _head;
		}
		move2=move1;
		move1=move1->m_next;
	}
	
	return NULL;
}

struct Person* ListRemoveByKeyRec(struct Person* _head, int _key,struct Person**_p)
{
	if(NULL == _p)
	{
		return _head;
	}
	if(NULL == _head)
	{
		*_p=NULL;
		return NULL;
	}
	if(_head->m_id==_key)
	{	
		_p=&_head;
		_head=_head->m_next;
		return _head;
	}
	_head->m_next=ListInsertByKeyRec(_head->m_next,_key,*_p);
	return _head;
}

Person* LastPerson(struct Person* _head)
{
	if(_head==NULL || _head->m_next==NULL)
	{
		return _head;
	}
	return LastPerson(_head->m_next);
	
}

















