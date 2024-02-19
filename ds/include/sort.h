
/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date:31/05/23
*/

#ifndef _SORT_H
#define _SORT_H

void QuicktRec(void *arr, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int MergeSort(int *arr_to_sort, size_t num_elements);
int BinarySearch(int *arr, size_t size, int find);
int BinarySearchRecursive(int *arr, size_t begin, size_t end, int find);

/*
Description: Sort array or integers with BubbleSort.
Receive: Valid pointer to arr and size of arr.
Return: Void.
Time complexity: O(n^2)
Space complexity: O(1)
*/
void BubbleSort(int *arr, size_t size);
/*
Description: Sort array or integers with InsertionSort.
Receive: Valid pointer to arr and size of arr.
Return: Void.
Time complexity: O(n^2)
Space complexity: O(1)
*/
void InsertionSort(int *arr, size_t size);
/*
Description: Sort array or integers with SelectionSort.
Receive: Valid pointer to arr and size of arr.
Return: Void.
Time complexity: O(n^2)
Space complexity: O(1)
*/
void SelectionSort(int *arr, size_t size);
/*
Description: Sort array or integers with CountingSort.
Receive: Valid pointer to arr and size of arr.
Return: Void.
Time complexity: O(n)
Space complexity: O(1)
*/
int CountingSort(int *arr, size_t size);
/*
Description: Sort array or integers with RadixSort.
Receive: Valid pointer to arr and size of arr.
Return: Void.
Time complexity: O(n)
Space complexity: O(1)
*/
int RadixSort(int *arr, size_t size);

#endif /*_SORT_H*/
