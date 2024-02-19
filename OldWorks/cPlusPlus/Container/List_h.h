#ifndef _LIST_T_H
#define _LIST_T_H


#include <iostream>
#include "TException_t.h"
#include "Container_t.h"

using namespace std;


template <class LST>
class list_t: public container_t<LST>
{
public:

    size_t Count() const {return this->GetNumOfElem();};
    bool IsEmpty() const {return this->GetNumOfElem() == 0;};

    list_t()
    {
		m_head.m_prev = NULL;
		m_tail.m_next = NULL;
		m_head.m_next = &m_tail;
		m_tail.m_prev = &m_head;
		this->SetNumOfElem(0);
    };
    
    virtual ~list_t()
    {
        Node* remove;
		remove = m_head.m_next;
		while(remove != &m_tail)
		{
			remove = remove->m_next;
			delete(remove->m_prev);

		}
		this->SetNumOfElem(0);
    };

	list_t(const list_t &_copy)
    {
		Node* curr = _copy.m_head.m_next;
		for(size_t i =0; i< Count(); ++i)
		{
			Insert(curr->m_data);
			curr = curr->m_next;
		}
		
    }
    list_t &operator=(const list_t & _copy)
    {
		RemoveAll();
		if(this != &_copy)
		{
			Node* curr = _copy.m_head.m_next;
			for(size_t i =0; i< Count(); ++i)
			{
				Insert(curr->m_data);
				curr = curr->m_next;
			}
		}
		return *this;
    }
    virtual bool Append(size_t _index, const LST* _item)
    {
		Node* find;
		size_t counter = 0;
        if(_index > Count() || _item == NULL)
		{
			return false;
		}
		find = m_head.m_next;
		while(find != &m_tail)
		{
			counter++;
			if( counter == _index)
			{
				new Node(*find, _item );
				this->IncreaseSizeOf();
				break;
			}
			find = find->m_next;
		}
		return true;
    };

    virtual bool Prepend(size_t _index, const LST* _item)
    {
        Node* find;
		size_t counter = 0;
        if(_index > Count() || _item == NULL)
		{
			return false;
		}
		find = m_head.m_next;
		while(find != &m_tail)
		{
			counter++;
			if( counter == _index - 1)
			{
				new Node(*find, _item );
				this->IncreaseSizeOf();
				return true;
			}
			find = find->m_next;
		}
		return false;
    };
    
    virtual bool Contains(const LST& _item)
    {
		Node* find = m_head.m_next;
		while(find != &m_tail )
		{
			if(_item == *find->m_data)
			{
				return true;
			}
			find = find->m_next;
		}
		return false;
    };
    
    virtual LST* Find(const LST& _value) const
    {
        Node* find = m_head.m_next;
		while(find != &m_tail )
		{
			if(_value == *find->m_data)
			{
				return find->m_data;
			}
			find = find->m_next;
		}
		return NULL;
    };

	/* Node* FindNode(const LST& _data)
		{
			Node* find = m_head.m_next;
			while(find != &m_tail )
			{
				if(_data == *find->m_data)
				{
					return find;
				}
			}
			return NULL;
		} */
    virtual int Index(const LST& _item) const
    {
		Node* find;
		size_t counter = 0;
		find = m_head.m_next;
		while(find != &m_tail)
		{
			counter++;
			find = find->m_next;
		}
		return counter;

    }; 
 
    virtual bool Insert(const LST* _item)
    {
		if(_item == NULL)
		{
			return false;
		}
    	new Node(*m_tail.m_prev, _item );
		this->IncreaseSizeOf();
		return true;
    }

    virtual LST* Remove(const LST&_value)
    {
		Node* temp;
        Node* find = m_head.m_next;
		while(find != &m_tail )
		{
			if(_value == *find->m_data)
			{
				return find->m_data;
			}
			find = find->m_next;
		}
		if(find == &m_tail)
		{
			return NULL;
		}
		temp = find;
		
		find->m_prev->m_next = find->m_next;
		find->m_next->m_prev = find->m_prev;
		delete(find);
		this->DecreaseSizeOf();
		return temp->m_data;
    }

    virtual bool RemoveAndDelete(const LST& _value)
    {
        Node* find = m_head.m_next;
		while(find != &m_tail )
		{
			if(_value == *find->m_data)
			{
				return find->m_data;
			}
			find = find->m_next;
		}
		if(find == &m_tail)
		{
			return false;
		}
		find->m_data = NULL;
		find->m_prev->m_next = find->m_next;
		find->m_next->m_prev = find->m_prev;
		delete(find);
		this->DecreaseSizeOf();
		return true;
	}
    
    virtual void RemoveAll()
    {
		size_t i;
		for(i=0; i<Count();++i)
		{
			Node* find = m_head.m_next;
			find->m_prev->m_next = find->m_next;
			find->m_next->m_prev = find->m_prev;
			delete find;
		}
		this->SetNumOfElem(0);
    }

    virtual void RemoveAndDeleteAll()
    {
        size_t i;
		for(i=0; i<Count();++i)
		{
			Node* find = m_head.m_next;
			find->m_data = NULL;
			find->m_prev->m_next = find->m_next;
			find->m_next->m_prev = find->m_prev;
			delete find;
		}
		this->SetNumOfElem(0);
    } 

	
private:
    
    class Node
	{
		public:
		Node()
		{
			m_data = NULL;
			m_next = NULL;
			m_prev = NULL;
		}

		~Node()
		{
		}

		Node(Node &_prev, const LST* _data )
		{
			m_data = (LST*)_data;
			m_prev = &_prev;
			m_next = _prev.m_next;
			_prev.m_next = this;
			m_next->m_prev = this;
		}

		void RemoveNode(Node* _delete)
		{
			_delete->m_next->m_prev = _delete->m_prev;
			_delete->m_prev->m_next = _delete->m_next;
			
		};
		LST* m_data;
		Node* m_next;
		Node* m_prev;
	};

	Node m_head;
	Node m_tail;
};



#endif 
