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

#include "dlist.h"

/*pseudo code*/
/*In this part the function there is only one thread that make a process in the Produser funtions and
a lot of threads do the Consumer process at once. After the Consumer function finishes the process there is a chance 
that not all nodes are cleared. Because of that we need more threads to make sure that all the nodes are free'd we put the mutex lock 
on the costumer as well. 


there is synchronization 
there is no condition race
there is no busy wait
there is no starvation
there is no deadlock

*/


#define SUCCESS (0)
#define FAIL (1)
#define ARR_SIZE (50)
#define EMPTY (1)

size_t arr[ARR_SIZE] = {0};
size_t counter = 0;
pthread_mutex_t mutex;


void *Producer(void *data)
{
    
    dlist_t *list = (dlist_t *)data;
    pthread_mutex_lock(&mutex);
    DListPushBack(list, (void *)&arr[counter]);
    printf("The data entered is %ld\n", arr[counter]);
    ++counter;
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

void *Consumer(void *data)
{
    
    dlist_t *list = (dlist_t *)data;
    size_t info = 0;
    pthread_mutex_lock(&mutex);
    while(EMPTY != DListIsEmpty(list))
    {
        
        info = *(size_t *)DListPopFront(list);
        printf("The data recieved is %ld\n", info);
        
    }
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int ProducerComsumerex2(void);
void InitArr(void);

int main()
{
    InitArr();
    ProducerComsumerex2();
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

int ProducerComsumerex2(void)
{
    int return_value = 0;
    size_t i = 0;
    size_t j = 0;
    pthread_t consumer[ARR_SIZE];
    pthread_t producer[ARR_SIZE];
    dlist_t *list = DListCreate();

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
        usleep(50);
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
        return_value = pthread_join(producer[i], NULL);
        if(SUCCESS != return_value)
        {
            return (FAIL);
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
    

    pthread_mutex_destroy(&mutex);
    DListDestroy(list);
    return (SUCCESS);
}
