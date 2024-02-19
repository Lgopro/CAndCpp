#ifndef T_CONTAINER_H
#define T_CONTAINER_H

#include <algorithm>
#include <typeinfo>
#include <vector>
#include <list>
#include <iostream>
#include "TException_t.h"
using namespace std;

template <class T>
class Containes
{
public:
	Containes(T _index){m_val = _index;}
	bool operator()(T *_element) { return *_element == m_val;}

private:
	T m_val;
};

template <class T, class Container>
class tContainer_t
{
public:
	typedef typename Container::const_iterator citer_t;
	typedef typename Container::iterator iter_t;

	tContainer_t() {}
	~tContainer_t() {}

	bool IsEmpty() const { return m_cont.empty();}
	size_t NumOfElements() const { return m_cont.size();}
	void Insert(T *_element) { m_cont.push_back(_element);}
	T* GetFirst() const { return m_cont.empty() ? NULL : *m_cont.begin();}
	T* GetLast() const { return m_cont.empty() ? NULL : *m_cont.rbegin();}
	T* FindElement(const T &_element) const;
	T* RemoveElement(const T &_element);
	void RemoveAllElements() { m_cont.clear();}
	void RemoveAndDeleteElement(const T &_element);
	void RemoveAndDeleteAllElements();
	T* operator[](size_t _index) const;

private:
	Container m_cont;
	tContainer_t(const tContainer_t &) {}
	tContainer_t &operator=(const tContainer_t &) {}
};



template <class T, class Container>
T* tContainer_t<T, Container>::FindElement(const T &_element) const
{
	citer_t it = find_if(m_cont.begin(), m_cont.end(), Containes<T>(_element));
	if (it == m_cont.end())
	{
		return NULL;
	}
	else
	{
		return *it;
	}
}

template <class T, class Container>
T* tContainer_t<T, Container>::RemoveElement(const T &_element)
{
	iter_t it = find_if(m_cont.begin(), m_cont.end(), Containes<T>(_element));
	if (it == m_cont.end())
	{
		return NULL;
	}
	else
	{
		T *rem = *it;
		m_cont.erase(it);
		return rem;
	}
}
template <class T, class Container>
void tContainer_t<T, Container>::RemoveAndDeleteElement(const T& _element)
{
	iter_t it = find_if(m_cont.begin(), m_cont.end(), Containes<T>(_element));
	if (it == m_cont.end())
	{
		cout << "Element not found" << endl;
	}
	else
	{
		T *del = *it;
		m_cont.erase(it);
		delete del;
	}
}

template <class T, class Container>
void tContainer_t<T, Container>::RemoveAndDeleteAllElements()
{
	for (iter_t it = m_cont.begin(); it != m_cont.end(); it++)
	{
		iter_t temp = it;
		T *del = *it;
		m_cont.erase(temp);
		delete del;
	}
}

template <class T, class Container>
T* tContainer_t<T, Container>::operator[](size_t _index) const //add T*&
{
	if (_index > m_cont.size())
	{
		return NULL;//throw exception 
	}

	if (typeid(m_cont) == typeid(vector<T *>))
	{
		return (*(vector<T*>*)&m_cont)[_index];
	}
	else
	{
		size_t i;
		citer_t it = m_cont.begin();
		for (i = 0; i < _index; it++, i++)
		{
		}
			return *it;
	}
}


#endif 
