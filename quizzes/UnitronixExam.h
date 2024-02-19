/*
Rev: Unitronix
Dev: Leonid Golovko
status: In Progress
date: 07/02/2024
*/

#ifndef __UNITRONIX_EXAM_H__
#define __UNITRONIX_EXAM_H__


/*
Description: Copy some amount of d.
Receive: Valid pointer to srcStrcut and dstBuffer and the length of the amount of data to copy 
with the begin location that we will copy in src and dest.
Return: Amount of bytes copied on success and error status on fail.
Time complexity: O(n)
Space complexity: O(1)
*/
int StructToBuffer(unsigned char *srcStrcut, unsigned char *dstBuffer, int dstBufferSize, int srcBufferSize, int dataLength, int StartLocationDest, int StartLocationScr, int *padding);
/*
Description: Sort array or integers with BubbleSort.
Receive: Valid pointer to srcBuffer and dsStrcut and the length of the amount of data to copy 
with the begin location that we will copy in src and dest.
Return: Status.
Time complexity: O(n)
Space complexity: O(1)
*/
int BufferToStruct(unsigned char * srcBuffer, int dataLength, unsigned char *dsStrcut, int dstBufferSize, int srcBufferSize, int StartLocationDest, int StartLocationScr, int *padding);


enum Status
{
    SUCCESS = 0,
    ERROR_ALLOCATION_SRC = -1,
    ERROR_ALLOCATION_DEST = -2,
    ERROR_SIZE_SRC = -3,
    ERROR_SIZE_DEST = -4
};

#endif /*__UNITRONIX_EXAM_H__*/