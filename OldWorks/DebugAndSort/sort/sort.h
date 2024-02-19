#ifndef _SORT_
#define _SORT_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ADTErr CountingSort(Vector* _vec, int _maxValue);
ADTErr MergeSort (Vector* _vec);
ADTErr RadixSort(Vector* _vec, int _nDigits);
ADTErr SelectionSort (Vector* _vec);
/*
Description: Function gets the pivot member in a way that all the smaller numbers are from the left and the bigger numbers are from the right side.
Input: Vector structure, begin and end index of the vector.
Output: The index of the pivot.
Complexity: o().
*/
int Partiotion(Vector* _vec,int _begin,int _end);
/*
Description: Function sort the array from left and right sides.
Input: Vector structure.
Output: void.
Complexity: o(n^2).
*/
ADTErr Shakesort(Vector* _vec);
/*
Description: Function sort the array from the right side.
Input: Vector structure.
Output: void.
Complexity: o().
*/
ADTErr Bublesort(Vector* _vec);
/*
Description: Function sort the selected vector by the partition function.
Input: Vector structure, begin and end of the selected area to sort.
Output: void.
Complexity: o().
*/
void QuickRec(Vector* _vec, size_t _begin, size_t _end);
/*
Description: Function sort the vector with buble sort each selected member of the not sorted area to the sorted area.
Input: Vector structure.
Output: ERR_NOT_INITIALIZED if vector do not exist and ERR_OK if the sort completed.
Complexity: o(n^2).
*/
ADTErr InsertionSort (Vector* _vec);

ADTErr ShellSort (Vector* _vec);
#endif
