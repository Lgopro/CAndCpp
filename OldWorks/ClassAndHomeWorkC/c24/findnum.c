#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "search.h"
#define TRUTH 1
#define NOT_TRUTH 0
int IsExist(int _arr[], int _size, int _num);
int IsExistBet(int _arr[], int _size, int _num);
int searchBin(int _arr[],int _begin, int _end, int _num);
int searchJump(int _arr[],int _items, int _num);
int IsExist(int _arr[], int _size, int _num)
{
	int i;
	for(i=0; i<_size; i++)
	{
		if(_arr[i] == _num)
		{
			return TRUTH;
		}
	
	
	}
	return NOT_TRUTH;
}



int IsExistBet(int _arr[], int _size, int _num)
{

	int i=0,temp;
	if(_arr[_size-1] == _num)
	{
		return TRUTH;
	}
	else 
	{
		temp = _arr[_size-1] ;
		_arr[_size-1] =_num;
	
	}
	while(_arr[i] != _num)
	{
		i++;
	}
	_arr[_size-1]=temp;
	if(i == _size-1)
	{
		return NOT_TRUTH;
	}
	else
	{
		return TRUTH;
	
	}

}


int searchBin(int _arr[],int _begin, int _end, int _num)
{
	int mid,result;
	if(_begin<_end)
	{
		mid= (_begin + _end)/2;
		if(_arr[mid] > _num)
		{
			result=searchBin( _arr,_begin, mid,  _num);
			return result;
		}
		if(_arr[mid] < _num)
		{
			result=searchBin( _arr,mid+1, _end, _num);
			return result;
		}
		if(_arr[mid] == _num)
		{
			return TRUTH;
		}
	}
	
	return NOT_TRUTH;
}

int searchJump(int _arr[],int _items, int _num)
{
	int index,i;
	while( sqrt(_items)!=0)
	{
		index=sqrt(_items);
		if(_arr[index] == _num)
		{
			return TRUTH;
		}
		if(_arr[index] < _num)
		{
			break;
		}
	}
	for(i=index;i <_items;i++)
	{
		if(_arr[i] == _num)
		{
			
			return TRUTH;
		}
		if(_arr[i] > _num)
		{
			break;
		}
	}
	return NOT_TRUTH;
}

