/*
Rev: Greg Markovski
Dev: Leonid Golovko
status: finished
date:19/04/23
*/

#ifndef BITARRAY_H
#define BITARRAY_H

#include <stddef.h> /*size_t*/


typedef size_t bitarr_t;
/*
Description: Set on bit in the selected position.
Receive: The arr and the position in it. The position values should be between 0 and 63.
Return: The new value of the arr. 
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrSetOn(bitarr_t arr, size_t pos);
/*
Description: Set off bit in the selected position.
Receive: The arr and the position in it. The position values should be between 0 and 63.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrSetOff(bitarr_t arr, size_t pos);
/*
Description: Set on bit in the selected position to the bool value.
Receive: The arr and the position in it. The position values should be between 0 and 63. bool_val should be 0 or 1.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrSet(bitarr_t arr, size_t pos, int bool_val);
/*
Description: Get a bit value in the selected position.
Receive: The arr and the position in it. The position values should be between 0 and 63.
Return: The value of the position selected.
Time complexity: O(1)
Space complexity: O(1)
*/
int BitArrGetVal(bitarr_t arr, size_t pos);
/*
Description: Set all bits to one.
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrSetAll(bitarr_t arr);
/*
Description: Set all bits to one.
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrResetAll(bitarr_t arr);
/*
Description: Count the amount of bits on in the arr.
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t BitArrCountOn(bitarr_t arr);
/*
Description: Count the amount of bits off in the arr.
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t BitArrCountOff(bitarr_t arr);
/*
Description: Flip a bit value in the selected position.
Receive: The arr and the position to change. The position values should be between 0 and 63.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrFlip(bitarr_t arr, size_t pos);
/*
Description: Get the mirror image of the arr.
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrMirror(bitarr_t arr);
/*
Description: Rotate the arr left by the shift value.
Receive: The arr and the shift value.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrRotateLeft(bitarr_t arr, size_t shift);
/*
Description: Rotate the arr right by the shift value.
Receive: The arr and the shift value.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrRotateRight(bitarr_t arr, size_t shift);
/*
Description: Rotate the arr right by the shift value.
Receive: The arr and the shift value. dest cannot be NULL.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
char *BitArrToString(bitarr_t arr, char *dest);
/*
Description: Count the arr with the use of LUT
Receive: The arr.
Return: The new value of the arr.
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrCountLUT(bitarr_t arr);
/*
Description: Fuction the make a mirror of the recived value.
Receive: The arr.
Return: The mirror of arr
Time complexity: O(1)
Space complexity: O(1)
*/
bitarr_t BitArrMirrorLUT(bitarr_t arr);

#endif /*BITARRAY_H*/
