#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define EXIT 0
#define CREATE_VECTOR 1
#define DESTROY_VECTOR 2
#define ADD_ITEM_TO_END_OF_VECTOR 3
#define REMOVE_LAST_ITEM 4
#define GET_ITEM_TO_POINTER 5
#define GET_ITEM_IN_VECTOR_TO_INDEX 6
#define GET_POINTER_ARRAY_TO_POINTER_ARRAY 7


typedef struct Vector Vector;



typedef enum
{
    
    ERR_OK,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
           
    ERR_STACK_BBBBB = 30
    
  
}ADTErr ;
/*
Description: Function gets the last index in the vector.
Input: The sctructure of the vector.
Output: The amount of items in the vector.
*/
size_t LastIndex(struct Vector* _vector);
/*
Description: Function get the initual size and the block size of the vector and then goes to the function VectorCreate.
Input: The sctructure of the vector.
Output: The sctructure of the vector that created or NULL if not created.
*/
struct Vector* Enter(struct Vector* _vector);
/*
Description: Function creates a vector.
Input: Pointer to the vector structure
Output: Returnes the created structure if succesfully created and returns NULL if not.
*/
struct Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize);
/*
Description: Function prints the vector(not used yet).
Input: Pointer to the vector structure.
Output: void.
*/
void VectorPrint(struct Vector* _vector);
/*
Description: Print the menu.
Input: void.
Output: Returnes the selected option from the menu.
*/
int Printmenu(void);
/*
Description: Function destroyes the vector.
Input: Pointer to the vector structure.
Output: void.
*/
void VectorDestroy(struct Vector* _vector);
/*
Description: Function adds the selected item(number) to the end of the vector.
Input: Pointer to the vector structure and the item it addes.
Output: NEED TO WORK ON THIS.
*/
ADTErr VectorAddEnd(struct Vector *_vector,  int  _item);
/*
Description: Function generate the item.
Input: pointer to vector.
Output: The number of the item.
*/
int GetItem(struct Vector* _vector);
/*
Description: Function deletes the end of the index of the vector.
Input: Pointer to vector and pointer to integer from the deleted number;
Output: NEED TO WORK ON THIS.
*/
ADTErr VectorDeleteEnd(struct Vector* _vector, int* _item);
/*
Description: Function inputs the vector with the selceted index  to the item.
Input: Pointer to vector, index inside vector and pointer to the number that will get the value of vector in some index.
Output: NEED TO WORK ON THIS.
*/
ADTErr VectorGet(struct Vector* _vector, size_t _index, int* _item);
/*
Description: Function gets the needed index.
Input: Pointer to vector.
Output: The number of the index.
*/
int GetIndex(struct Vector* _vector);
/*
Description: Function gets the item to the vector in the selceted index if the index is valid.
Input: Pointer to vector, the index and the item.
Output: NEED TO WORK ON THIS.
*/
ADTErr VectorSet(struct Vector* _vector, size_t _index, int  _item);
/*
Description: Function get the pointer of the vector to other selected pointer.
Input: Pointer to vector and pointer to the new integer array of the items.
Output: NEED TO WORK ON THIS.
*/
ADTErr VectorItemsNum(struct Vector* _vector, int* _numOfItems);
/*
Description: Function change size of the vector.
Input: Pointer to vector.
Output: The adress of new structure of vector.
*/
struct Vector* ChangeSize(struct Vector* _vector);

