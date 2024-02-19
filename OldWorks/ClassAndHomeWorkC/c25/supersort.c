#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supersort.h"

void Swap(void* _elem1,void* _elem2, size_t _size)
{
	void* swap = malloc(_size);
	memcpy(swap, _elem1, _size);
	memcpy(_elem1, _elem2, _size);
	memcpy(_elem2, swap, _size);
	free(swap);
}
int Compare(const void* _elem1,const void* _elem2)
{
	return (*((int*)_elem1) > *((int*)_elem2))? 1:0;

}
int sort(void* _elements,size_t _elementsCount,size_t _elementSize,int (*_less)(const void*, const void*))
{
	int i,j,flag;
	for(i = 0;i <_elementsCount; i++)
	{
		flag = 0;
		for(j=0; j<_elementsCount-i;j++)
		{
			if(Compare((char*)_elements + _elementSize*j,(char*)_elements + _elementSize*(j+1)) == 1)
			{
				Swap((char*)_elements + _elementSize*j, (char*)_elements + _elementSize*(j+1), _elementSize);
				flag = 1;
				
			}
		}
		if(flag == 0)
		{
			break;
		}	
	}
	
	return 1;

}



