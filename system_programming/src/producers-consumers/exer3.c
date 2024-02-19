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
#include "dlist.h"

/*pseudo code*/
/*In this part the only thing that is needed to add from exer2.c is semaphore to the part of the
costumer and producer. It will be initialized to 0 and when we have a something produced it will be increased
and when something will be consumed it will decrease. 

there is synchronization 
there is no condition race
there is busy wait
there is no starvation
there is no deadlock
*/
#define SUCCESS (0)
#define FAIL (1)
#define ARR_SIZE (200)

size_t arr[ARR_SIZE] = {0};
size_t counter = 0;
pthread_mutex_t mutex;
sem_t sem_mutex = {0};

void *Producer(void *data)
{
    
    dlist_t *list = (dlist_t *)data;
    pthread_mutex_lock(&mutex);
    DListPushBack(list, (void *)&arr[counter]);
    printf("The data entered is %ld\n", arr[counter]);
    ++counter;
    
    pthread_mutex_unlock(&mutex);
    sem_post(&sem_mutex);
    return (NULL);
}

void *Consumer(void *data)
{
    
    dlist_t *list = (dlist_t *)data;
    size_t info = 0;
    
    sem_wait(&sem_mutex);
    
    info = *(size_t *)DListPopFront(list);
    printf("The data recieved is %ld\n", info);
    
    
    return (NULL);
}

int ProducerComsumerex3(void);
void InitArr(void);

int main()
{
    InitArr();
    ProducerComsumerex3();
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

int ProducerComsumerex3(void)
{
    int return_value = 0;
    size_t i = 0;
    size_t j = 0;
    pthread_t consumer[ARR_SIZE];
    pthread_t producer[ARR_SIZE];
    dlist_t *list = DListCreate();
    sem_init(&sem_mutex, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    for(i = 0; i < ARR_SIZE; ++i)
    {
        return_value = pthread_create(&producer[i], NULL, Producer, (void *)list);
        while(SUCCESS != return_value)
        {
            j = 0;
            for (j = 0; j < i; ++j)
            {  
                return_value = pthread_join(producer[j], NULL);
                if(SUCCESS == return_value) 
                {
                    break;
                }

            }
            return_value = pthread_create(&producer[j], NULL, Producer, (void *)list);
        }
        usleep(5);
        return_value = pthread_create(&consumer[i], NULL, Consumer, (void *)list);
        while(SUCCESS != return_value)
        {
            j = 0;
            for (j = 0; j < i; ++j)
            {  
                return_value = pthread_join(consumer[j], NULL);
                if(SUCCESS == return_value) 
                {
                    break;
                }

            }
            return_value = pthread_create(&consumer[j], NULL, Consumer, (void *)list);
        } 
    }
   
    for(i = 0; i < ARR_SIZE; ++i)
    {
        return_value = pthread_join(consumer[i], NULL);
        if(SUCCESS != return_value)
        {
            return (FAIL);
        }
    }
    for(i = 0; i < ARR_SIZE; ++i)
    {
        return_value = pthread_join(producer[i], NULL);
        if(SUCCESS != return_value)
        {
            return (FAIL);
        }
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_mutex);
    DListDestroy(list);
    return (SUCCESS);
}
