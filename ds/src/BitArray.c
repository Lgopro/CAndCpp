/*
Rev: Greg Markovski
Dev: Leonid Golovko
status: finished
date:19/04/23
*/
#include <limits.h> /*CHAR_BIT*/
#include <assert.h> /*assert*/
 
#include "BitArray.h"

#define MAX 0xffffffffffffffff
#define SIZE_OF_LINE (sizeof(size_t) * CHAR_BIT)
#define SIZE_OF_ARRAY (sizeof(size_t) * CHAR_BIT)


bitarr_t BitArrSetOn(bitarr_t arr, size_t pos)
{
	assert(SIZE_OF_ARRAY > pos);
	
	return BitArrSet(arr, pos, 1);
}

bitarr_t BitArrSetOff(bitarr_t arr, size_t pos)
{
	assert(SIZE_OF_ARRAY > pos);
	
	return BitArrSet(arr, pos, 0);
}

bitarr_t BitArrSet(bitarr_t arr, size_t pos, int bool_val)
{
	assert(SIZE_OF_ARRAY > pos);
	assert(0 <= bool_val);
	assert(2 > bool_val);
	
	return (arr & ~(1UL << pos)) | ((bitarr_t)bool_val << pos);
}

int BitArrGetVal(bitarr_t arr, size_t pos)
{
	assert(SIZE_OF_ARRAY > pos);
	
	return ((arr & (1UL << pos)) >> pos);

}

bitarr_t BitArrSetAll(bitarr_t arr)
{
	return (~BitArrResetAll(arr));
}

bitarr_t BitArrResetAll(bitarr_t arr)
{
	(void)arr;
	
	return 0UL;

}

size_t BitArrCountOn(bitarr_t arr)
{
	size_t counter = 0;
	
	while(arr)
	{
		arr = arr & (arr-1);
		++counter;
	}
	
	return counter;
}

size_t BitArrCountOff(bitarr_t arr)
{
	return (SIZE_OF_LINE - BitArrCountOn(arr));
}

bitarr_t BitArrFlip(bitarr_t arr, size_t pos)
{
	assert(SIZE_OF_ARRAY > pos);
	
	return arr ^(1UL << pos);
}

static bitarr_t MirWithLoop(bitarr_t x)   
{

	bitarr_t i = 0;
	bitarr_t y = 0;
	bitarr_t j = SIZE_OF_LINE - 1;
	
	for(i = 0; i <= SIZE_OF_LINE -1; ++i)
	{
		if( x & (1UL << i))
		{
			y^=(1UL << j);
		}
		--j;
	}
	return y;
	
}

bitarr_t BitArrMirror(bitarr_t arr)
{
	return MirWithLoop(arr);
}

bitarr_t BitArrRotateLeft(bitarr_t arr, size_t shift)
{
	bitarr_t shifted = 0;
	shift = shift % SIZE_OF_LINE;
	shifted = (arr >> (SIZE_OF_LINE - shift));
	arr = (arr << shift);
	return shifted | arr;
}

bitarr_t BitArrRotateRight(bitarr_t arr, size_t shift)
{
	bitarr_t shifted = 0;
	shift = shift % SIZE_OF_LINE;
	shifted = (arr << (SIZE_OF_LINE - shift));
	arr = (arr >> shift);
	return shifted | arr;
}
static char *CheckNumber(bitarr_t arr, char* array)
{
	int i = 0;
	char *begin = array;
	for(i = SIZE_OF_LINE - 1; i >= 0; --i)
	{
		if( arr & (1UL << i))
		{
			*array = '1';
		}
		else
		{
			*array = '0';
		}
		
		++array;
	}
	*array = '\0';
	array = begin;
	return array;
}

char *BitArrToString(bitarr_t arr, char *dest)
{
	assert(NULL != dest);
	
	return CheckNumber(arr , dest);
}



bitarr_t BitArrCountLUT(bitarr_t arr) 
{
	static int Table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
	int result = 0;
	size_t i = 0;	
	for(i = 0; i < SIZE_OF_LINE / 4; ++i)
	{
		result += Table[arr & 15];
		arr = arr >> 4;
	}
	return result;
}

bitarr_t BitArrMirrorLUT(bitarr_t arr) 
{
	int i = 0;
	bitarr_t move = 1;
	static bitarr_t LUT[6] = 
	{
		0x5555555555555555, /*binary: 0101...*/
		0x3333333333333333, /*binary: 00110011.. */
		0x0f0f0f0f0f0f0f0f, /*binary:  4 zeros,  4 ones ...*/
		0x00ff00ff00ff00ff, /*binary:  8 zeros,  8 ones ...*/
		0x0000ffff0000ffff, /*binary: 16 zeros, 16 ones ...*/
		0x00000000ffffffff, /*binary: 32 zeros, 32 ones ...*/
		
	};
	
	for(i = 0; i < 6; ++i)
	{
		arr = ((arr & LUT[i]) << move) | ((arr & (~LUT[i])) >> move);
		move *= 2;
	}

	return arr;
}


