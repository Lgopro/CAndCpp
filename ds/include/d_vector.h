/*
Rev: Anna Bar
Dev: Leonid Golovko
status: finished
date: 25/04/2023
*/
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h> /* size_t */

typedef struct DVector dvector_t;

/***********************************************************************/
/*
Description: Create a vector.
Arguments: Element size and capacity.
Return: Pointer to vector.
Time complexity: O(1)
Space complexity: O(1)
*/
dvector_t *DVectorCreate(size_t element_size, size_t capacity);

/***********************************************************************/
/*
Description: Destroy vector.
Arguments: Valid pointer to Vector.
Return: void.
Time complexity: O(1)
Space complexity: O(1)
*/
void DVectorDestroy(dvector_t *vector);

/***********************************************************************/
/*
Description: Push the element to the back of the vector.
Arguments: valid vector pointer, const void pointer to element.
Return: 0 in case of successful push; -1 in case of failure.
Time complexity: O(1)
Space complexity: O(1)
*/
int DVectorPushBack(dvector_t *vector,const void *element);

/***********************************************************************/
/*
Description: Remove last element from vector. Shrinks memory by 2 if 
			capacity is at/under 25%.
Arguments: Valid pointer to vector.
Return: 0 in case of successful pop; -1 in case of failure.
Time complexity: O(1)
Space complexity: O(1)
*/
int DVectorPopBack(dvector_t *vector);

/***********************************************************************/
/*
Description: Get element from index.
Arguments: valid pointer to a vector and index of element. The index should be with in the size of the vector.
Return: Void pointer to the index value.
Time complexity: O(1)
Space complexity: O(1)
*/
void *DVectorGetAccessToElement(const dvector_t *vector, size_t index);

/***********************************************************************/
/*
Description: Gives the user Vector size.
Arguments: Constant valid pointer to a vector.
Return: Size of the vector.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t DVectorSize(const dvector_t *vector);

/***********************************************************************/
/*
Description: Gives the user vector Capacity.
Arguments: Constant valid pointer to a vector.
Return: Vector Capacity.
Time complexity: O(1)
Space complexity: O(1)
*/
size_t DVectorCapacity(const dvector_t *vector);

/***********************************************************************/
/*
Description: Increase the vector capacity to the new capacity selected by the user.
Arguments: Valid pointer to a vector and the size of the new capacity.
Return: Status.
Time complexity: O(n)
Space complexity: O(n)
*/
int DVectorReserve(dvector_t *vector, size_t new_capacity);

/***********************************************************************/
/*
Description: Shrink vector capacity to 125% of his size.
Arguments: Valid pointer to a vector.   
Return: Status.
Time complexity: O(1)
Space complexity: O(1)
*/
int DVectorShrink(dvector_t *vector);




#endif /*__VECTOR_H__*/
