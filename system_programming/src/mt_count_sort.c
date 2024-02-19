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
#include <pthread.h> /*pthread_create*/
#include <time.h> /*clock_t*/

#include "mt_count_sort.h"

#define SUCCESS (0)
#define FAIL (1)
#define ERROR (-1)


size_t amount_of_data_in_one_thread = 0;
pthread_mutex_t mutex;
size_t global_lut[256] = {0};

void *LUT(void * data)
{
    size_t counter = 0;
    size_t i = 0;
    size_t LUT[256] = {0};
    char *array = (char *)data;

    
    while(counter < amount_of_data_in_one_thread)
    {
        ++LUT[(int)*array];
        ++counter;
        ++array;
    }
    pthread_mutex_lock(&mutex);
    for(i = 0; i < 256 ;++i)
    {
        global_lut[i] += LUT[i];
    }
    pthread_mutex_unlock(&mutex);

    return (NULL);
}


int MTCountSort(unsigned char *arr, size_t size, size_t number_of_threads)
{
    int return_value = 0;
    size_t i = 0;
    unsigned char *array = arr;
    double total = 0;
    size_t counter = 0;
    size_t remainder = 0;
    struct timespec start, stop;
    pthread_t producer[number_of_threads];

    pthread_mutex_init(&mutex, NULL);

    amount_of_data_in_one_thread = size / number_of_threads;
    #ifndef NDEBUG
    printf("amount of data per thread %ld\n", amount_of_data_in_one_thread);
    #endif
    if(ERROR == clock_gettime( CLOCK_REALTIME, &start)) 
    {
        return 1;
    }
    if(0 != size % number_of_threads)
    {
        remainder = size % number_of_threads;
    }
    for(i = 0; i < number_of_threads; ++i)
    {
        return_value = pthread_create(&producer[i], NULL, LUT, &array[(size / number_of_threads) * i]);
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

    while(counter < remainder)
    {
        ++global_lut[(int)array[number_of_threads * amount_of_data_in_one_thread + counter]];
        ++counter;
    }

    counter = 0;

    for(i = 0; i < 256; ++i)
    {

        while(0 != global_lut[i])
        {
            arr[counter] = global_lut[i];
            --global_lut[i];
            ++counter;
        }
    }
    if(ERROR == clock_gettime( CLOCK_REALTIME, &stop)) 
    {
        return 1;
    }
    total = ( stop.tv_nsec - start.tv_nsec );
    printf( "The time is %lf nano sec\n", total);
    pthread_mutex_destroy(&mutex);
   
    return (SUCCESS);
}