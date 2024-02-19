/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date:11/06/2023
*/
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "Stack.h"

typedef enum STATUS
{
    SUCCESS,
    MATH_ERR,
    SYNTAX_ERR,
    MEMORY_ALLOC_ERR
}calculator_status_t;


/*
Description: Calculate the expression and return the status and the result.
Receive: Valid pointers to expression and result.
Return: Status.
Time complexity: O(n).
Space complexity: O(1).
*/
calculator_status_t Calculator(const char *expression, double *result);

#endif /* __CALCULATOR_H__ */
