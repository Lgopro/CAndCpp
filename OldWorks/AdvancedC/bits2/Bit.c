#include <stdio.h>
#include <stdlib.h>
#include "Bit.h"
static void FillTable(int  _x ,int _table[]);
static void PrintTable(int _table[]);



void FlipAllBits(int  _x,int _from,int _to)
{
     int table[31]={0};
     int i;
     FillTable(_x ,table);
     PrintTable(table);
     for(i=_from;i<=_to;i++)
     {
         if(table[i]==1)
         {
            table[i]=0;
         }
         else
         {
            table[i]=1;
         }

     }
     PrintTable(table);
     fflush(stdin);

}


int Add(int _x, int _y) 
{ 
    if(_y == 0)
    { 
        return _x; 
    }
    return Add( _x ^ _y, (_x & _y) << 1); 
    
} 

void FlipTwoBitTable(int  _x, int _flip, int _flip2)
{
     int table[31]={0};
     int i;
     FillTable(_x ,table);
     PrintTable(table);
     for(i=0;i<=31;i++)
     {
      	if(i+1 == _flip || i+1 == _flip2)
      	{	
        	if(table[i]==1)
        	{
          		table[i]=0;
        	}
        	else
        	{
            	table[i]=1;
        	}
        }

     }
     PrintTable(table);

}

void FlipOneBit(int  _x,int _flip)
{
    int mask=1;
    _flip -= 1;
    _flip %= 32;
    PrintBit(_x);
    _x = ((mask << _flip) ^ _x);
    PrintBit(_x);
  
}
int MultiplyByTreeInHalf(int  _x)
{
    return Add(3*_x,_x >> 1);

}
void FlipTwoBits(int  _x, int _flip, int _flip2)
{
    int mask=1;
    _flip -= 1;
    _flip %= 32;
    _flip2 -= 1;
    _flip2 %= 32;
    PrintBit(_x);
    _x = ((mask << _flip) ^ _x);
     _x = ((mask << _flip2) ^ _x);
    PrintBit(_x);
}

void FlipOneBitTable(int  _x,int _flip)
{
     int table[31]={0};
     int i;
     FillTable(_x ,table);
     PrintTable(table);
     for(i=0;i<=31;i++)
     {
      	if(i+1 == _flip)
      	{	
        	if(table[i]==1)
        	{
          		table[i]=0;
        	}
        	else
        	{
            	table[i]=1;
        	}
        }

     }
     PrintTable(table);

}

void PrintBit(int  _x)
{
	int i=0;
	for(i=31;i>=0;--i)
	{
		if( _x&(1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}


int Rotate(int  _x, int _n)
{
	int i,bit;
	_n%=32;
	PrintBit(_x);
	for(i=0;i<_n;i++)
	{
		bit=0;
		if( _x &(1<<31))
		{
				bit=1;
		}
		_x = _x <<1;
		if(bit == 1)
		{
			_x |= (1<<0);
		}
	}
	PrintBit(_x);
	return 1;
}
static int countBits(int  number)
{
    int i;
    int  mask = 1;
    int count=0;
    for(i=0;i<32; i++)
    {
        if((mask << i) & number)
        {
            ++count;
        }

    }
    return count;

}

int PowerOfTwo(int  number)
{
    int status;
    status = countBits(number);
    return (status == 1);
}
int PowerOfTwoTable(int  number)
{
    int i,counter=0;
    int table[31]={0};
    FillTable(number,table);
    for(i=0;i<31;i++)
    {
        if(table[i] == 1)
        {
            counter++;
        }
    }
    return (counter == 1);
}

static void FillTable(int  _x ,int _table[])
{

	int i=0;
	for(i=31;i>=0;i--)
	{
		if( _x&(1<<i))
		{
			_table[i] = 1;
		}
		else
        {
            _table[i] = 0;
        }
	}
	return;
}

static void PrintTable(int _table[])
{
    int i;
    for (i=31; i>=0 ;--i)
    {
        printf("%d",_table[i]);
    }
    printf("\n");
    return;
}
int getSingle(int arr[], int n) 
{ 
    int ones = 0, twos = 0 ,i ; 
  
    int common_bit_mask; 
  
     
    for(i=0; i< n; i++ ) 
    { 
        twos  = twos | (ones & arr[i]); 
        ones  = ones ^ arr[i]; 
        common_bit_mask = ~(ones & twos); 
        ones &= common_bit_mask; 
        twos &= common_bit_mask; 
    } 
    return ones; 
} 
  