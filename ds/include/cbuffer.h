/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date: 03/05/2023
*/
#ifndef __C_BUFFER_H__
#define __C_BUFFER_H__

#include <sys/types.h> /* ssize_t */

typedef struct CBuff cbuff_t;



/*==================================================================
Description: Create a circular buffer.
Args: Capacity that is not 0.
Return value: Pointer to circular buffer
Time complexity; O(1)
Space complexity; O(1)
*/
cbuff_t *CBuffCreate(size_t capacity);

/*==================================================================
Description: Destroy a circular buffer.
Args: Valid pointer of a circular buffer.
Return value: Void.
Time complexity; O(1)
Space complexity; O(1)
*/
void CBuffDestroy(cbuff_t *c_c_buffer);

/*==================================================================
Description: Read from circular buffer to destination count amount of bytes.
Args: Valid c_buffer, dest pointers and a count bigger then 0.
Return value: If at least one byte was written return the number of bytes. If it fails return -1.
Time complexity; O(n)
Space complexity; O(1)
*/
ssize_t CBuffRead(cbuff_t *c_buffer, void *dest, size_t count);

/*==================================================================
Description:Write to circular buffer from src count amount of bytes.
Args: Valid c_buffer, src pointers and a count bigger then 0.
Return value: If at least one byte was read return the number of bytes. If it fails return -1.
Time complexity; O(n
Space complexity; O(1)
*/
ssize_t CBuffWrite(cbuff_t *c_buffer, const void *src, size_t count);

/*==================================================================
Description: Return the amout of bytes free to write.
Args: Valid const pointer to circular buffer.
Return value: Amount of free space in bytes
Time complexity; O(1)
Space complexity; O(1)
*/
size_t CBuffFreeSpace(const cbuff_t *c_buffer);

/*==================================================================
Description: Find circular buffer capacity.
Args: Valid const pointer to circular buffer.
Return value: Capacity in bytes.
Time complexity; O(1)
Space complexity; O(1)
*/
size_t CBuffCapacity(const cbuff_t *c_buffer);

/*==================================================================
Description: Return status on if the circular buffer is empty.
Args: Valid const pointer to circular buffer.
Return value: 1 if buffer empty and 0 if not.
Time complexity; O(1)
Space complexity; O(1)
*/
int CBuffIsEmpty(const cbuff_t *c_buffer);


#endif /*__C_BUFFER_H__*/
