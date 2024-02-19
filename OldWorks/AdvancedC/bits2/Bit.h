#ifndef __BIT_H__
#define __BIT_H__


/*
Description: Function insert a new data into the heap and rebiulds it.
Input: The heap structue and the data selected.
Output: returnes ERR_NOT_INITIALIZED if heap dont exist, ERR_NOT_ADDED is the item not added and ERR_OK if the item is added.
Complexity: O(n).
*/
void FlipAllBits(int  _x,int _from,int _to);
void PrintBit(int  _x);
void FlipOneBit(int  _x,int _flip);
int Rotate(int  _x, int _n);
void FlipOneBitTable(int  _x,int _flip);
void FlipTwoBitTable(int  _x,int _flip,int _flip2);
int Add(int _x, int _y) ;
int MultiplyByTreeInHalf(int  _x);
void FlipTwoBits(int  _x, int _flip, int _flip2);
int PowerOfTwo(int  number);
int PowerOfTwoTable(int  number);
int getSingle(int arr[], int n);





#endif 
