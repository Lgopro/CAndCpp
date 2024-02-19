/*
Rev: Daniel Haimov
Dev: Leonid Golovko
status: finished
date:21/03/23
*/
#include <stdio.h>  /*sprintf*/
#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <ctype.h>  /*toupper*/

char *StrCpy(char *dest, const char *src);
char *StrNCpy(char *dest, const char *src, size_t n);
int StrNCmp(const char *s1, const char *s2, size_t n);
char *StrCat(char *dest, const char *src);
char *StrNCat(char *dest, const char *src, size_t n);
char *StrChr(const char *s, int c);
int StrCaseCmp(const char *s1, const char *s2);
size_t StrLen(const char *s);
char *StrDup(const char *s);
size_t StrSpn(const char *s, const char *accept);
int Palindrom(const char *array);
char *Boom(int first,int last);

int main()
{

	
	return 0;
}
/********************************************************/
size_t StrLen(const char *s)
{
	int i = 0;
	assert(NULL != s);
	while('\0' != s[i])
	{
		i++;
	}
	return i;
	



}

/********************************************************/
int Palindrom(const char *array)
{
	size_t size = StrLen(array), i = 0, j = size - 1;
	while(i <= j)
	{
		if( array[i] != array[j])
		{
			return 1;
			
		}
		++i;
		--j;
	
	}
	return 0;

}
/********************************************************/

size_t StrSpn(const char *s, const char *accept)
{	
	size_t counter = 0;
	assert(NULL != s);
	assert(NULL != accept);
	while('\0' != *s)
	{
		if(NULL != StrChr(accept, *s))
		{
			++counter;
			++s;
		
		}
		else
		{
			break;
		}
		
	}
	return counter;
	
	

}
/********************************************************/
char *StrStr(const char *haystack, const char *needle)
{
	int i = 0;
	size_t size_needle = 0, size_haystack = 0;
	
	assert(NULL != haystack);
	assert(NULL != needle);
	size_needle = StrLen(needle);
	size_haystack = StrLen(haystack);
	for(i = 0; (size_t)i < size_haystack - size_needle; ++i)
	{
		if(0 == StrNCmp(needle, haystack, size_needle))
		{
		
			return (char *)haystack;
		
		}
		++haystack;
	}
	return NULL;
}
/********************************************************/

char *StrDup(const char *s)
{

	char* copy;
	assert(NULL != s);
	copy = (char*)malloc(sizeof(char) * StrLen(s));
	StrCpy(copy, s);
	return copy;

}




/********************************************************/
int StrCaseCmp(const char *s1, const char *s2)
{

		int result = 0 , i = 0;
	
	assert(NULL != s1);
	assert(NULL != s2);
	
	while('\0' != s1[i] && '\0' != s2[i])
	{
		result = toupper(s1[i]) - toupper(s2[i]);
		if(0 != result)
		{
			return result;
			
		}
		i++;
		
	}
	if('\0' == s1[i] && '\0' != s2[i])
	{
		return -1;
	}
	if('\0' != s1[i] && '\0' == s2[i])
	{
		return 1;
	}
	return result;



}


/********************************************************/
char *StrChr(const char *s, int c)
{
	int i = 0;
	
	
	assert(NULL != s);
	while('\0' != s[i])
	{
		if(s[i] == (char)c)
		{
			
			return (char *)(s + i);
		
		}
		++i;
	}
	return NULL;


}

/********************************************************/
char *StrNCat(char *dest, const char *src, size_t n)
{

	int i = 0 , j = 0;
	assert(NULL != dest);
	assert(NULL != src);
	while('\0' != dest[i])
	{
		++i;
	}
	while('\0' != src[j] && (size_t)j < n)
	{
		dest[i + j] = src[j];
		++j;
	}
	
	return dest;




}

/********************************************************/
char *StrCat(char *dest, const char *src)
{
	
	int i = 0 , j = 0;
	assert(NULL != dest);
	assert(NULL != src);
	while('\0' != dest[i])
	{
		++i;
	}
	while('\0' != src[j])
	{
		dest[i + j] = src[j];
		++j;
	}
	return dest;
}

/********************************************************/
int StrNCmp(const char *s1, const char *s2, size_t n) 
{

	int result = 0;
	size_t i = 0;
	assert(NULL != s1);
	assert(NULL != s2);
	while('\0' != s1[i] && i < n && '\0' != s2[i])
	{
		result = s1[i] - s2[i];
		if(0 != result)
		{
			return result;
			
		}
		i++;
		if(i == n)
		{
			return 0;
		}
		
	}
	if('\0' == s1[i] && '\0' != s2[i])
	{
		return -1;
	}
	if('\0' != s1[i] && '\0' == s2[i])
	{
		return 1;
	}
	return 0;
	
}


/********************************************************/
char *StrCpy(char *dest, const char *src)
{
	int i = 0;
	assert(NULL != dest);
	assert(NULL != src);
	for(i = 0; src[i] != '\0'; ++i)
	{
		
		dest[i] = src[i];
	
	}
	dest[i] = '\0';
	return dest;

}
/********************************************************/
char *StrNCpy(char *dest, const char *src, size_t n)
{
	int i = 0;
	assert(NULL != dest);
	assert(NULL != src);
	
	for(i = 0; ((size_t)i < n) && ('\0' != src[i]); ++i)
	{
	
		dest[i] = src[i];
		
	}
	return dest;
	

}
/*******************************************************/
char *Boom(int first,int last)
{

	int i = 0, find = 0, digit = 0;
	char* arr;
	arr = (char *)malloc(sizeof(char) * 100000); 
	for(i = first; i <= last; ++i)
	{
		if(0 == i % 7)
		{
			sprintf(arr + StrLen(arr),"BOOM ");
			continue;
		}
		find = i;
		while(0 != find)
		{
			digit = find % 10;
			find /= 10;
			if(7 == digit || -7 == digit)
			{
				sprintf(arr + StrLen(arr),"BOOM ");
				find = -1;
				break;
			}
		}
		if(-1 == find)
		{
			continue;
		}
		else
		{
			sprintf(arr + StrLen(arr),"%d " ,i);
		}
	}
	

	return arr;

}
