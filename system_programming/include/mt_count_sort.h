/*
Rev: Etai Shimoni.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/

#ifndef _COUNT_THREAD_H_
#define _COUNT_THREAD_H_

#include <stddef.h> /* size_t */

/*Name: MTCountSort
Description: Sort Array.
Arguments:
	- arr: Array to sort.
	- size: Size of the array.
    - number_of_threads: number of threads.
Return: Status.
Time complexity: O(n)
Space complexity: O(1)*/
int MTCountSort(unsigned char *arr, size_t size, size_t number_of_threads);



#endif /* _COUNT_THREAD_H_ */