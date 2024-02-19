
/*
Rev: Liran Tzuman.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/
#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <string.h> /*strcmp*/
#include <pthread.h> /*pthread_create*/
#include <time.h> /*clock_t*/

#include "shuffle_and_sort.h"

#define SUCCESS (0)
#define FAIL (1)
#define ERROR (-1)

size_t amount_of_data_in_one_thread = 0;

unsigned char ** array = NULL;
size_t size_of_array = 0;
size_t threads_num = 0;
size_t remainder = 0;


int cmpfuncionsort(const void * a, const void * b) 
{
    char **arr1 = (char **)a;
    char **arr2 = (char **)b;
    return(strcmp(*arr1, *arr2));
}

void *SortArray(void *data)
{
    size_t length = amount_of_data_in_one_thread;
    if(threads_num - 1 == (size_t)data)
    {
        length = amount_of_data_in_one_thread + remainder;
    }
    qsort(array + (size_t)data * amount_of_data_in_one_thread, length, sizeof(unsigned char *), cmpfuncionsort);
    return (NULL);
}

int Sort(unsigned char **arr, size_t size, size_t number_of_threads)
{
    int return_value = 0;
    size_t i = 0;
    array = arr;
    
    
    pthread_t producer[number_of_threads];
    size_of_array = size;
    threads_num = number_of_threads;
    amount_of_data_in_one_thread = size / number_of_threads;
    
   
    remainder = size % number_of_threads;
    
    for(i = 0; i < number_of_threads; ++i)
    {
        return_value = pthread_create(&producer[i], NULL, SortArray, (void *)i);
        if(SUCCESS != return_value)
        {
            return (FAIL);
        }
    }
    
    for(i = 0; i < number_of_threads; ++i)
    {
        return_value = pthread_join(producer[i], NULL);
        if(SUCCESS != return_value)
        {
            return (FAIL);
        }
    }
    
    return (SUCCESS);
}

int Merge(unsigned char **arr, size_t size, size_t number_of_threads)
{
    int status = 0;
    unsigned char **array_begin = arr;
    while(1 != number_of_threads)
    {
        number_of_threads /= 2;
        status = Sort(array_begin, size, number_of_threads);
        if(FAIL == status)
        {
            return (status);
        }
        array_begin = arr;
    }
    return (SUCCESS);
}