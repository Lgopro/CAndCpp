
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "sort.h"
void MergeRec (Vector* _vec, size_t _begin, size_t _end, int _arr[]);
void Shakesort(Vector* _vec);
static void Swap(Vector* _vec, size_t _item1,size_t _item2,int index1,int index2);
static void Shell(Vector* _vec,int items);
static void MergePart(Vector* _vec, size_t _begin, size_t _mid, size_t _end, int _arr[]);
static int FindMin(int _num1,int _num2,int _index1, int _index2);
static void Swap(Vector* _vec, size_t _item1,size_t _item2,int index1,int index2)
{
	VectorSet(_vec, index1 , _item2);
	VectorSet(_vec, index2 , _item1);
}

void Bublesort(Vector* _vec)
{
    int i,j,flag,numberofitems,item1,item2;
    VectorItemsNum(_vec, &numberofitems);
    for(i=0;i<numberofitems;i++)
    {
    	flag=0;
        for(j=0;j<numberofitems-1-i;j++)
        {
        	VectorGet(_vec, j,&item1);
        	VectorGet(_vec, j+1,&item2);
            if(item1 > item2)
            {
              Swap(_vec, item1, item2, j, j+1);
               flag=1;
            }
        }
        if(flag == 0)
        {
        	break;
        }
    }

    return;
}


void Shakesort(Vector* _vec)
{
    int i,j,flag,numberofitems,item1,item2;
    VectorItemsNum(_vec, &numberofitems);
    for(i=0;i<numberofitems;i++)
    {
    	flag=0;
    	
        for(j=i;j<numberofitems-1-i;j++)
        {
        	VectorGet(_vec, j,&item1);
        	VectorGet(_vec, j+1,&item2);
            if(item1 > item2)
            {
              Swap(_vec, item1, item2, j, j+1);
               flag=1;
            }
        }
        
        
        for(j=numberofitems-1-i;j>i;j--)
        {
        	VectorGet(_vec, j,&item1);
        	VectorGet(_vec, j-1,&item2);
            if(item1 < item2)
            {
              Swap(_vec, item1, item2, j, j-1);
               flag=1;
            }
        }
        
        if(flag == 0)
        {
        	break;
        }
    }

    return;
}
/*int Partiotion(Vector* _vec)
{
	int numberofelem, too_big_index, too_small_index,databig,datasmall,pivot;
	
	VectorItemsNum(_vec, &numberofelem);
	too_small_index = 1;
	too_big_index = numberofelem-1;
	VectorGet(_vec, 0, &pivot);
	do
	{
		VectorGet(_vec, too_small_index, &datasmall);
		VectorGet(_vec, too_big_index , &databig);
		while(datasmall <= pivot && too_small_index <= too_big_index) 
		{
    		++too_small_index;
    		VectorGet(_vec, too_small_index, &datasmall);
    		if(databig < datasmall)
    		{
    			break;
    		}
    	}
		while(databig > pivot && too_small_index <= too_big_index) 
		{ 
    		--too_big_index;
    		VectorGet(_vec, too_big_index , &databig);
    		if(databig < datasmall)
    		{
    			break;
    		}
    	}
    
		if(databig < datasmall && too_small_index<too_big_index)
		{
			Swap(_vec, databig,datasmall,too_big_index , too_small_index);
		}
	}while( too_big_index > too_small_index);
	
	Swap(_vec, databig,pivot,too_big_index,0);
	return too_big_index;
}*/


int Partiotion(Vector* _vec,int _begin,int _end)
{
	int  too_big_index, too_small_index,databig,datasmall,pivot;
	
	
	
	too_small_index = _begin+1;
	too_big_index = _end;
	VectorGet(_vec, _begin, &pivot);
	do
	{
		VectorGet(_vec, too_small_index, &datasmall);
		VectorGet(_vec, too_big_index , &databig);
		
		while(datasmall <= pivot && too_small_index < _end)
		{
    		++too_small_index;
    		VectorGet(_vec, too_small_index, &datasmall);
    		
    	}
		while(databig > pivot) 
		{ 
    		--too_big_index;
    		VectorGet(_vec, too_big_index , &databig);
  
    	}
    
		if(databig < datasmall && too_small_index<too_big_index)
		{
			Swap(_vec, databig,datasmall,too_big_index , too_small_index);
		}
	}while( too_big_index > too_small_index);
	
	Swap(_vec, databig,pivot,too_big_index,_begin);
	return too_big_index;
}


void QuickRec(Vector* _vec, size_t _begin, size_t _end)
{

	int pivot;
	

	if(_begin >= _end )
	{
		return;
	}
	pivot = Partiotion(_vec,_begin,_end);
	if(pivot>0)
	{	
		QuickRec(_vec, _begin, pivot-1);
	}
	QuickRec(_vec, pivot+1, _end);
		
	
	
	
}
void QuickIter(Vector* _vec, size_t _begin, size_t _end,int StackArr[])
{
   
	
	int topstack=-1,pivot; 
  	
    StackArr[++topstack] = _begin; 
    StackArr[++topstack] = _end; 
    while (topstack >= 0) 
    { 
        _end = StackArr[topstack--]; 
        _begin = StackArr[topstack--]; 
        pivot = Partiotion(_vec,_begin,_end); 
  
        if (pivot - 1 > _begin) 
        {
            StackArr[++topstack] = _begin; 
            StackArr[++topstack] = pivot - 1; 
        } 
        if (pivot + 1 < _end) 
        { 
            StackArr[++topstack] = pivot + 1; 
            StackArr[++topstack] = _end; 
        } 
    } 
} 




ADTErr InsertionSort (Vector* _vec)
{
	int i,j,numberofitems,item1,item2;
	if(NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numberofitems);
    for(i=0;i<numberofitems-1;i++)
    {
         for(j=i+1;j>0;j--)
        {
        	VectorGet(_vec, j,&item1);
        	VectorGet(_vec, j-1,&item2);
        	if(item1 >= item2)
        	{
        		break;
        	}
            if(item1 < item2)
            {
              Swap(_vec, item1, item2, j, j-1);
               
            }
        }
       
    }
    return ERR_OK;
}

ADTErr ShellSort (Vector* _vec)
{
	int numberofitems;
	VectorItemsNum(_vec, &numberofitems);
	
	while(numberofitems > 0)
	{
		Shell(_vec, numberofitems);
		numberofitems/=2;
	}
	return ERR_OK;

}

static void Shell(Vector* _vec,int items)
{
	int numberofitems,i,j,item1,item2;
	VectorItemsNum(_vec, &numberofitems);
	for(i=items;i<numberofitems;i++)
	{
		for(j=i-1;j>=0;j=j-items)
		{
		
			if(j + items < numberofitems)
			{
				VectorGet(_vec, j,&item1);
        		VectorGet(_vec, j+items,&item2);
			
				if(item1 > item2)
				{
			 		Swap(_vec, item1, item2, j, j+items);
			
					}
				if(item1 <= item2)
				{
					break;
			
			
				}
			}
		}	
	}
}


ADTErr SelectionSort (Vector* _vec)
{
	int i,j,numberofitems,item1,index,nummin,indexmin,itemi;
    VectorItemsNum(_vec, &numberofitems);
    for(i=0;i<numberofitems-1;i++)
    {
    	VectorGet(_vec, i,&itemi);
    	indexmin=i;
    	nummin=itemi;
        for(j=i;j<numberofitems;j++)
        {
        	VectorGet(_vec, j,&item1);
            index=FindMin(item1,nummin,j,indexmin);
            if(index == j)
            {
            	nummin=item1;
            	indexmin=j;
            }
        }
    	if( indexmin == i)
   	 	{
    		continue;
    	}
    	else
    	{
    		Swap(_vec, itemi, nummin, i, indexmin);
		}
	}
    return ERR_OK;
}

int FindMin(int _num1,int _num2,int _index1, int _index2)
{
	if(_num1 < _num2)
	{
		return _index1;
	}
	return _index2;
}


ADTErr CountingSort(Vector* _vec, int _maxValue)
{
	int numberofitems,i,itemi;
	int* arr;
	int* arrfinal;
	VectorItemsNum(_vec, &numberofitems);
	if(NULL == (arr=(int*)calloc(_maxValue,sizeof(int))))
	{
		return ERR_ALLOCATION_FAILED;
	}
	if(NULL == (arrfinal=(int*)calloc(numberofitems,sizeof(int))))
	{
		return ERR_ALLOCATION_FAILED;
	}
	for(i=0;i<numberofitems;i++)
	{
		VectorGet(_vec, i,&itemi);
		arr[itemi]++;
	}
	for(i=1;i<numberofitems;i++)
	{
		arr[i]= arr[i]+arr[i-1];
	}
	for(i=numberofitems-1;i>=0;i--)
	{
		VectorGet(_vec, i,&itemi);
		arrfinal[arr[itemi]]=itemi;
		arr[itemi]--;
	
	}
	for(i=0;i<numberofitems;i++)
	{
		VectorSet(_vec, i, arrfinal[i]);
	}
	free(arr);
	free(arrfinal);
	return ERR_OK;
}
/*ADTErr ShellSort (Vector* _vec)
{
	int i,j,numberofitems,item1,item2,items;
	if(NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numberofitems);
	items=numberofitems;
	for(i=0;i<numberofitems;i=i+items/2)
	{
		if(i+items < numberofitems)
		{
			VectorGet(_vec, i,&item1);
        	VectorGet(_vec, i+items,&item2);
		}
		if(item1 > item2)
		{
			 Swap(_vec, item1, item2, i, i+items);
			
		}
		if(items == 1)
		{
			break;
		}
		else
		{
			items/=2;
		}
	}
    for(i=0;i<numberofitems-1;i++)
    {
         for(j=i+1;j>0;j--)
        {
        	VectorGet(_vec, j,&item1);
        	VectorGet(_vec, j-1,&item2);
        	if(item1 >= item2)
        	{
        		break;
        	}
            if(item1 < item2)
            {
              Swap(_vec, item1, item2, j, j-1);
            }
        }
       
    }
    return ERR_OK;
}*/
ADTErr MergeSort (Vector* _vec)
{
	int numberofitems;
	int* arrfinal;
	if(NULL == _vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec, &numberofitems);
	if(NULL == (arrfinal=(int*)calloc(numberofitems,sizeof(int))))
	{
		return ERR_ALLOCATION_FAILED;
	}
	MergeRec (_vec, 0, (size_t) numberofitems-1,arrfinal);
	free(arrfinal);
	return ERR_OK;
}


void MergeRec (Vector* _vec, size_t _begin, size_t _end, int _arr[])
{
	size_t mid;
	if(_begin<_end)
	{
		mid = (_begin+_end)/2;
		MergeRec (_vec, _begin, mid,_arr);
		MergeRec (_vec, mid+1, _end,_arr);
		MergePart(_vec, _begin, mid, _end ,_arr);
	}
	return;
}
static void MergePart(Vector* _vec, size_t _begin, size_t _mid, size_t _end, int _arr[])
{
	int i,j,item1;
	for(i=_begin;i<=_mid;i++)
    for(i=_begin;i<_end;i++)
    {
    	VectorGet(_vec, i,&_arr[i]);
        for(j=i+1;j<=_end;j++)
        {
        	VectorGet(_vec, j,&_arr[j]);
            if(_arr[i] > _arr[j])
            {
            	item1=_arr[i];
            	_arr[i]=_arr[j];
            	_arr[j]=item1;
            	VectorSet(_vec, (size_t)i, _arr[i]);
            	VectorSet(_vec, (size_t)j, _arr[j]);
            }
        }
    }
	for(i=_begin; i<=_end;i++)
	{
		VectorSet(_vec, (size_t)i, _arr[i]);
	
	}
    return;
}
/*
ADTErr RadixSort (Vector* _vec, int _nDigits)
{
	



}
*/
