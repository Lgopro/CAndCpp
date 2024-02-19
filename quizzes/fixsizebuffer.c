
#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <pthread.h> /*pthread_create*/
#include <semaphore.h> /*semaphore*/
#include "queue.h"

/*pseudo code*/
/*Use only one mutex and 2 semaphores that allow only 1 thread to access the structure.
There are full and empty semaphore. Full initialize to max amount of items. 
It mean we have an max amount of items to write.
Empty initialize to 0. It mean we have nothing to read. When we want to write we increment the empty semaphore.
When we want to read we decrement the full semaphore.

there is synchronization 
there is no condition race
there is busy wait
there is no starvation
there is no deadlock
*/
#define SUCCESS (0)
#define FAIL (1)
#define ARR_SIZE (50)

size_t arr[ARR_SIZE] = {0};
size_t counter = 0;
pthread_mutex_t mutex;
sem_t empty = {0};
sem_t full = {0};

void *Producer(void *data)
{
    
    queue_t *queue = (queue_t *)data;
    
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    QEnqueue(queue, (void *)&arr[counter]);
    printf("The data entered is %ld\n", arr[counter]);
    ++counter;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
   
    return (NULL);
}

void *Consumer(void *data)
{
    
    queue_t *queue = (queue_t *)data;
    size_t info = 0;
    
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    info = *(size_t *)QPeek(queue);
    QDequeue(queue);
    printf("The data recieved is %ld\n", info);
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    
    return (NULL);
}

int ProducerComsumerex4(void);
void InitArr(void);

int main()
{
    InitArr();
    ProducerComsumerex4();
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

int ProducerComsumerex4(void)
{
    int return_value = 0;
    size_t i = 0;
    size_t j = 0;
    pthread_t consumer[ARR_SIZE];
    pthread_t producer[ARR_SIZE];
    queue_t *queue = QCreate();

    if(-1 == sem_init(&empty, 0, 0))
    {
        printf("sem_init error\n");
        return (FAIL);
    }

     if(-1 == sem_init(&full, 0, ARR_SIZE))
    {
        printf("sem_init error\n");
        return (FAIL);
    }

    pthread_mutex_init(&mutex, NULL);

    for(i = 0; i < ARR_SIZE; ++i)
    {
        return_value = pthread_create(&producer[i], NULL, Producer, (void *)queue);
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
            return_value = pthread_create(&producer[j], NULL, Producer, (void *)queue);
        }
        return_value = pthread_create(&consumer[i], NULL, Consumer, (void *)queue);
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
            return_value = pthread_create(&consumer[j], NULL, Consumer, (void *)queue);
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
    sem_destroy(&empty);
    sem_destroy(&full);
    QDestroy(queue);
    return (SUCCESS);
}