
#include <stdio.h>
#include "strlen.h"


#define LINE_LENGTH 50


size_t  StrlenItr(const char* _str)
{
	const char* iterator = _str;
	while(*iterator)
	{
		++iterator;
	}
	
	return (size_t)(iterator - _str);

}


char* StrcpyItr(char*  _destination, const char* _source)
{
	while((*(_destination++) = (*_source++))){}
	return _destination;
}

size_t  StrlenRec(const char* _str)
{
	size_t result;
	if(*_str == '\0')
	{
		return 0;
	}
	result=StrlenRec(_str + 1)+1;
	return result;

}


int StrcmpItr(const char* _str1,   const char* _str2)
{
	while(*_str1 != '\0')
	{
		if(*_str1 - *_str2 == 0)
		{
			++_str1;
			++_str2;
		}
		if(*_str1 - *_str2 > 0)
		{
			return (int)(*_str1 - *_str2);
		}
		if(*_str1 - *_str2 < 0)
		{
			return (int)(*_str1 - *_str2);
		}
	}
	
	return 0;


}


int StrcmpRec(const char* _str1,   const char* _str2)
{
	int result;
	if(*_str1 == '\0')
	{
		return 0;
	}
	if(*_str1 - *_str2 == 0)
	{
		result = StrcmpRec(_str1 + 1, _str2 +1);
		return result;
	}
	if(*_str1 - *_str2 > 0)
	{
		return (int)(*_str1 - *_str2);
	}
	
	return (int)(*_str1 - *_str2);
}

char* StrcpyRec(char*  _destination, const char* _source)
{
	
	if(*_source == '\0')
	{
		*_destination = '\0';
		return _destination;
	}
	*_destination = *_source;
	
	StrcpyRec(_destination+1, _source+1);
	return _destination;
}


char* StrncpyItr(char* _destination, const char* _source, size_t _num)
{
	
	while(* _source != '\0')
	{
		*_destination = *_source;
		
		if(_num == 0)
		{
			*_destination = '\0';
			break;
		}
		_num--;
		_destination++;
		_source++;
	}
	return _destination;
}
char* StrncpyRec(char* _destination, const char* _source, size_t _num)
{
	
	if(_num == 0 || *_source == '\0')
	{
		*_destination = '\0';
		return _destination;
	}
	*_destination = *_source;
	StrncpyRec(_destination+1, _source+1, _num-1);
	return _destination;
}


char* MyStrcat(char* _destination, const char* _source)
{

	while(*_destination != '\0')
	{
		_destination++;
	}
	while(*_source != '\0')
	{
		*_destination = *_source;
		_destination++;
		_source++;
	}
	return _destination;
}


char* MyStrstr(const char* _str, const char* _substr)
{
	size_t length;
	char* pointer;
	while( *_str != '\0')
	{
		length=StrlenItr(_substr);
		if( *_str == *_substr)
		{
			while( length != 0)
			{
				if(	*_substr == '\0')
				{
					length=StrlenItr(_substr);
					while(length != 0)
					{
						_str--;
						length--;
					}
					pointer = _str;
					return pointer;
				}
				if( *_str != *_substr)
				{
					break;
				}
				_str++;
				_substr++;
			}	
		}
		_str++;
	}
	return NULL;
}
