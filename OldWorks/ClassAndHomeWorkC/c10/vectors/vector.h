#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"



typedef EXIT 0
typedef CREATE_VECTOR 1
typedef struct Vector Vector;

typedef enum
{
    /* General ADT Errors */
    ERR_OK                            =0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
            /* Vector Errors */
    /* Stack  Errors */
    ERR_STACK_BBBBB = 30,
    /* LinkedList  Errors */
    /* Bit Vector*/
} ADTErr;


Vector* VectorCreate (size_t _initialSize, size_t _extensionBblockSize);
Vector* Enter(Vector* _ad);
