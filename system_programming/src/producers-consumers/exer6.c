/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 12/07/2023
*/
#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <pthread.h> /*pthread_create*/
#include <semaphore.h> /*semaphore*/
#include "queue.h"

/*pseudo code*/
/*We have one producer and N cosumers. The producer make one input and increases the semaphore by the amount of threads.
The producer will wait until the consumer finished its job with the condition wait.
When the threads make the consumer operation they release the operation function to continue functioning
with pthread_cond_broadcast.

there is synchronization 
there is no condition race
there is no busy wait
there is no starvation
there is no deadlock
*/
#define SUCCESS (0)
#define FAIL (1)
#define ARR_SIZE (5)
#define AMOUNT_OFF_VAR (5)
enum message
{
    READY_TO_BE_SENT = 0,
    READY_TO_BE_RECIEVED
};

size_t arr[ARR_SIZE] = {0};
size_t counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t sem_mutex;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int consumer_count = 0;
size_t index = 0;
int global_flag = 0;

void *Producer(void *data)
{
    int i = 0;
    int j = 0;
    (void)data;

    
    for(i = 0; i < AMOUNT_OFF_VAR; ++i)
    {
        pthread_mutex_lock(&mutex);
        printf("Sent Message %d\n", i);
        index = i;
        for(j = 0; j < AMOUNT_OFF_VAR; ++j)
        {
            sem_post(&sem_mutex);
        } 
        global_flag = 1;  
        pthread_cond_wait(&cond, &mutex); 

        pthread_mutex_unlock(&mutex);
    }
    
    return (NULL);
}

void *Consumer(void *data)
{
    int i = 0;
    (void)data;
    for(i = 0; i < AMOUNT_OFF_VAR; ++i)
    {

        sem_wait(&sem_mutex);
        
        printf("Got Message %ld\n", index);
        ++consumer_count;
        
        if(AMOUNT_OFF_VAR == consumer_count)
        {
            global_flag = 0;
            consumer_count = 0;
            sem_init(&sem_mutex, 0, 0);
            pthread_cond_broadcast(&cond);
        }
        else
        {
            pthread_cond_wait(&cond, &mutex); 
        }
        pthread_mutex_unlock(&mutex); 
    }
    return (NULL);
}

int ProducerComsumerex6(void);
void InitArr(void);

int main()
{
    InitArr();
    ProducerComsumerex6();
    return 0;
}
void InitArr(void)
{
    int i = 0;
    for(i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = i;
    }
}

int ProducerComsumerex6(void)
{
    int return_value = 0;
    size_t i = 0;
    size_t j = 0;
    pthread_t producer;
    pthread_t consumer[AMOUNT_OFF_VAR];
    
    
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_mutex, 0, 0);
    pthread_cond_init(&cond, NULL);

    return_value = pthread_create(&producer, NULL, Producer, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }   


    for(i = 0; i < AMOUNT_OFF_VAR ; ++i)
    {

        return_value = pthread_create(&consumer[i], NULL, Consumer, NULL);
        while(SUCCESS != return_value)
        {
            j = 0;
            for (j = 0; j < i; ++j)
            {  
                return_value = pthread_join(consumer[j], NULL);
                if(SUCCESS != return_value)
                {
                    break;
                }
            }
            return_value = pthread_create(&consumer[j], NULL, Consumer, NULL);
        } 
    } 
    

    return_value = pthread_join(producer, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }

    for(i = 0; i < AMOUNT_OFF_VAR ; ++i)
    {
        return_value = pthread_join(consumer[i], NULL);
        if(SUCCESS != return_value)
        {
            return (FAIL);
        }
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_mutex);
    pthread_cond_destroy(&cond);
    return (SUCCESS);
}
