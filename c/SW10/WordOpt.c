/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:11/04/23
*/



#include <stdio.h> /*printf*/
#include <string.h> /*strcpy*/
#include <stdlib.h> /*strcpy*/
#include <assert.h> /*assert*/ 
#include "WordOpt.h"

static size_t Add8MemMove(void **add_to, void ** what_to_add, size_t n);
static size_t AddOneMemSet(void **add_to, unsigned char what_to_add, size_t n);
static size_t Add8MemSet(void **add_to, long what_to_add, size_t n);
static void AddOneMemCpy(void **add_to, void **what_to_add, size_t *n);
static void Add8MemCpy(void **add_to, void ** what_to_add, size_t *n);

#define CHUNK (8)

static size_t AddOneMemSet(void **add_to, unsigned char what_to_add, size_t n)
{

	*(unsigned char *)(*add_to) = what_to_add;
	*add_to = (char *)(*add_to) + 1;
	--n;
	return n;
}

static size_t Add8MemSet(void **add_to, long what_to_add, size_t n)
{

	*(long *)(*add_to) = what_to_add;
	n -= sizeof(long);
	*add_to = (char *)(*add_to) + sizeof(long);
	return n;
}
static long CreateWord(long word, unsigned char c)
{
	long unsigned int i = 0;
	for(i = 0; i < sizeof(long); ++i)
	{
		word = word << sizeof(long);
		word += (unsigned char)c;	
	}
	return word;
}


void *Memset(void *s, int c, size_t n)
{
	void * start = s;
	long word = 0;
	
	assert(NULL != s);
	word = CreateWord(word, (unsigned char)c);
	while(n > 0)
	{
		if(CHUNK > n || 0 != *(long *)&s % CHUNK)
		{
			n = AddOneMemSet(&start, (unsigned char)c, n);
		}
		else if(CHUNK <= n)
		{
			n = Add8MemSet(&start, word, n);
		}
	}
	return s;
}

static void AddOneMemCpy(void **add_to, void **what_to_add, size_t *n)
{
	*(char *)(*add_to) = *(char *)(*what_to_add);
	*add_to = (char *)(*add_to) + 1;
	*what_to_add = (char *)(*what_to_add) + 1;
	--(*n);
	
}

static void Add8MemCpy(void **add_to, void ** what_to_add, size_t *n)
{
	*(long *)(*add_to) = *(long *)(*what_to_add);
	*add_to = (char *)(*add_to) + sizeof(long);
	*what_to_add = (char *)(*what_to_add) + sizeof(long);
	(*n) -= sizeof(long);
}

void *Memcpy(void *dest, const void *src, size_t n)
{
	void *start = dest;
	void *copy = (void *)src;

	assert(dest);
	assert(src);
	assert(0 != n);
	
	while(n > 0)
	{
		if(CHUNK > n || 0 != *(long *)&start % CHUNK)
		{
			AddOneMemCpy(&start, &copy, &n);
		}
		else if(CHUNK <= n)
		{
			Add8MemCpy(&start, &copy, &n);
		}
	}
	return dest;
}

static size_t Add8MemMove(void **add_to, void ** what_to_add, size_t n)
{
	n -= sizeof(long) ;
	*add_to = ((char *)(*add_to) + n);
	*what_to_add = ((char *)(*what_to_add) + n);
	*((long *)(*add_to)) = *((long *)(*what_to_add));
	return n;
}

void *Memmove(void *dest, const void *src, size_t n)
{
	assert(NULL != dest && NULL != src && 0 != n);
	if(0 > *(long *)&dest - *(long *)&src || (long)n < *(long *)&dest - *(long *)&src)
	{
		return Memcpy(dest, src, n);
	}
	
	if(0 < *(long *)&dest - *(long *)&src) 
	{
		while(n > 0)
		{
			if(0 != ((*(long *)&dest) + n) % 8 || 0 != ((*(long *)&src) + n) % 8 || n <= 8)
			{
				*((char *)dest + n) = *((char *)src + n);
				--n;
			}
			else if(0 == *(long *)&dest % 8 && 0 == *(long *)&src % 8)
			{
				n = Add8MemMove(&dest, (void **)&src, n);		
			}
			else
			{
				*((char *)dest + n) = *((char *)src + n);
				--n;
			}
		}
	}
	
	return dest;	
}






