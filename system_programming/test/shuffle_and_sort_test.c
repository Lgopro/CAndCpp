/*
Rev: Etai Shimoni.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/

#define _POSIX_C_SOURCE 200112L
#include <stdio.h> /*printf*/
#include <string.h> /*fseek*/
#include <stdlib.h> /*malloc*/
#include <time.h> /*clock_t*/

#include "shuffle_and_sort.h"
#define FAIL (1)
#define SUCCESS (0)
#define AMOUNT_Of_DICT (3)
#define ERROR (-1)
int cmpfunc(const void * a, const void * b) 
{
    return (rand() - rand());
    (void)a;
    (void)b;
}

static void Dictionary(size_t amount)
{
    FILE* filePointer;
    size_t length = 0;
    unsigned char *buffer = NULL;  
    struct timespec start, stop;
    size_t i = 0;
    double total = 0;
    size_t number_of_words = 0;
    unsigned char **dictionary = NULL;
    unsigned char **begin = NULL;
    filePointer = fopen("/usr/share/dict/american-english", "r");
    if (filePointer)
    {
        fseek (filePointer, 0, SEEK_END);
        length = ftell (filePointer);
        fseek (filePointer, 0, SEEK_SET);
        buffer = (unsigned char *)malloc(length * 3);
        if(NULL == buffer)
        {
            return;
        }
        
        
        for(i = 0; i < AMOUNT_Of_DICT ;++i)
        {
            fread (buffer + length * i, 1, length, filePointer);
            fseek(filePointer, 0, SEEK_SET);
        }
        
    
        fclose(filePointer);
    }
    
    while(i < length * AMOUNT_Of_DICT)
    {
        if('\n' == buffer[i])
        {
            buffer[i] = '\0';
            ++number_of_words;
        }
        if(i == 0)
        {
            ++number_of_words; /*number_of_words*/
        }
        ++i;
    }
    buffer[length * AMOUNT_Of_DICT - 1] = '\0';
    i = 0;
    dictionary = (unsigned char **)malloc(sizeof(unsigned char *) * (number_of_words + 1));
    if(NULL == dictionary)
    {
        return;
    }
    begin = dictionary;
    
    *dictionary = &buffer[0];
    ++dictionary;
    ++i; 

    while(i < length * AMOUNT_Of_DICT - 1)
    {
        if('\0' == buffer[i])
        {
            *dictionary = &buffer[i + 1];
            ++dictionary;
        }
        ++i;
    }

    dictionary = begin;
    
    /*shuffle*/
    qsort(dictionary, number_of_words, sizeof(unsigned char *), cmpfunc);

    dictionary = begin;
    if(ERROR == clock_gettime( CLOCK_REALTIME, &start)) 
    {
        return;
    }
    Sort(dictionary, number_of_words , amount);
    Merge(dictionary, number_of_words - 1 , amount);
    if(ERROR == clock_gettime( CLOCK_REALTIME, &stop)) 
    {
        return;
    }
    total = ( stop.tv_nsec - start.tv_nsec );
    printf( "The time is %lf nano sec with %ld threads\n", total, amount);
    free(buffer);
    free(dictionary);

}


int main()
{
    int i = 0;
    for(i = 1;i < 30; ++i)
    {
        Dictionary(i);
    }
    
    
    return 0;
}