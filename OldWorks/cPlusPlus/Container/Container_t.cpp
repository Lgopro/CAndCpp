#include "Container_t.h"
using namespace std;

template <class T, class Container>
T* Container_t<T, Container>::FindElementIf(const T& _element) const
{
	citer_t find = find_if(m_container.begin(), m_container.end(), Find<T>(_element));
	if(find == m_container.end())
	{
		return NULL;
	}
	else
	{
		return *find;
	}
}

template <class T, class Container>
T* Container_t<T, Container>::RemoveElement(const T& _element)
{
	iter_t remove = find_if(m_container.begin(), m_container.end(), Find<T>(_element));
	if(remove == m_container.end())
	{
		return NULL;
	}
	else
	{
		iter_t temp = remove;
		m_container.erase(temp);
		return *remove;
	}	
}

template <class T, class Container>
void	Container_t<T, Container>::RemoveAllElements()
{
	m_container.for_each(m_container.begin(), m_container.end(), Container::erase);
}

template <class T, class Container>
void Container_t<T, Container>::RemoveAndDeleteElement(const T& _element)
{
	iter_t findAndRemove = find_if(m_container.begin(), m_container.end(), Find<T>(_element));
	if(findAndRemove == m_container.end())
	{
		throw TException_t<T>(_element, __FILE__, __LINE__, "not found");
	}
	else
	{
		m_container.erase(findAndRemove);
		delete *findAndRemove;
	}		
}

template <class T, class Container>
void Container_t<T, Container>::RemoveAndDeleteAllElements()
{
	for(iter_t remove = m_container.begin() ; remove != m_container.end() ; remove++)
	{
		iter_t temp = remove;
		m_container.erase(temp);
		delete *temp;		
	}
}

