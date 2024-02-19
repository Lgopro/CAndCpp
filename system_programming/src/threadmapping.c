
/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <pthread.h> /*pthread_create*/




#define _BSD_SOURCE

#define AMOUNT_OF_THREADS (3)
int arr[AMOUNT_OF_THREADS];
size_t sumforex4 = 0;
const size_t global_const = 0;
pthread_mutex_t mutex;

__thread int counter = 5;

void *ArrChange(void *data)
{
    
    size_t index = (size_t )data;
    static int var = 0;
    int *arr = NULL;
    pthread_mutex_lock(&mutex);
    arr = (int *)malloc(sizeof(int) * 5);
    
    printf("Thread N %ld ", index);
    printf("Heap adr %p ", (void *)arr);
    printf("Stack adr %p ", (void *)&index);
    printf("static int adr %p ", (void *)&var);
    printf("global_const adr %p ", (void *)&global_const);
    printf("LTS %p ", (void *)&counter);
    printf("Thread N %ld\n\n", index);
    
    
    pthread_mutex_unlock(&mutex);
    ++var;
    return NULL;
}

int Check100kThreads(void);


int main()
{
    Check100kThreads();
    return 0;
}

int Check100kThreads(void)
{
    size_t i = 0;
    pthread_t threads[AMOUNT_OF_THREADS];
    time_t begin;
    time_t end;
    
    begin = time(NULL);
    for (i = 0; i < AMOUNT_OF_THREADS; ++i)
    {
        pthread_create(&threads[i], NULL, ArrChange, (void *)i); 
        usleep(450);
    }
    sleep(1);
    for (i = 0; i < AMOUNT_OF_THREADS; ++i)
    { 
        pthread_join(threads[i], NULL);
    }


    end = time(NULL);
    
    printf("\nAmount of time passed is: %f\n", difftime(end, begin));

    printf("\n");

    return 0;
}