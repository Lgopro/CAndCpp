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
#include <assert.h> /*assert*/
/*pseudo code*/
/*In this exercise a thread safe queue was wrote with two mutexes and semaphores.
They will take care of the read and write indexes and make sure that only one thread can call
the read and write functions at a time. 
All the thread safe operations happen in the queue.

there is synchronization 
there is no condition race
there is busy wait
there is no starvation
there is no deadlock
*/
#define SUCCESS (0)
#define FAIL (1)
#define ARR_SIZE (30)

typedef struct Queue
{
    
    size_t  capacity;
    size_t  read_index;      
    size_t  write_index;  
    size_t 	amount_of_items;
	size_t size_of_element;
	pthread_mutex_t mutex1;
	sem_t add;
	pthread_mutex_t mutex2;
	sem_t delete;
	size_t *arr;
}queue_t;

size_t arr[ARR_SIZE] = {0};
size_t counter = 0;
pthread_mutex_t mutex;
sem_t sem_mutex;
queue_t* queue = NULL;



queue_t *QueueCreate(size_t amount_of_elements ,size_t size_of_element);
void QueueDestroy(queue_t* queue);
int QueueIsEmpty(queue_t* queue);
size_t QueueSize(queue_t* queue);
int EnQueue(queue_t* queue, void *element);
void *DeQueue(queue_t* queue);

void *Producer(void *data)
{
    
    size_t info = *(size_t *)data;
    
    EnQueue(queue, (void *)&info);
    printf("The data entered %ld\n", info);
    
    return (NULL);
}

void *Consumer(void *data)
{
    
    (void)data;

    printf("The data recieved is %ld\n", *(size_t *)DeQueue(queue));
    
    return (NULL);
}

int ProducerComsumerex5(void);
void InitArr(void);

int main()
{
    InitArr();
    ProducerComsumerex5();
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

int ProducerComsumerex5(void)
{
    int return_value = 0;
    size_t i = 0;
    size_t j = 0;
    pthread_t consumer[ARR_SIZE];
    pthread_t producer[ARR_SIZE];
    queue_t *queue = QueueCreate(ARR_SIZE, sizeof(size_t));

    for(i = 0; i < ARR_SIZE; ++i)
    {
        return_value = pthread_create(&producer[i], NULL, Producer, (void *)&arr[i]);
        usleep(10);
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
            return_value = pthread_create(&producer[j], NULL, Producer, (void *)&arr[i]);
        }
        
    
        return_value = pthread_create(&consumer[i], NULL, Consumer, (void *)&arr[i]);
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
            return_value = pthread_create(&consumer[j], NULL, Consumer, (void *)&arr[i]);
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

    QueueDestroy(queue);
    return (SUCCESS);
}




queue_t *QueueCreate(size_t amount_of_elements ,size_t size_of_element)
{
	queue = (queue_t *)malloc(sizeof(queue_t));
 	if(NULL == queue)
   	{
   		return NULL;
   	}
   
	queue->amount_of_items = 0;
	queue->capacity = amount_of_elements;
	queue->read_index = 0;
	queue->write_index = 0;
	queue->size_of_element = size_of_element;
    queue->arr = (size_t *)malloc(sizeof(size_t) * (amount_of_elements));
	if(NULL == queue->arr)
	{
		free(queue);
		return NULL;	
	}
   	if(-1 == pthread_mutex_init(&queue->mutex1, NULL))
    {
        printf("mutex error\n");
        return NULL;

    }
	if(-1 == pthread_mutex_init(&queue->mutex2, NULL))
    {
        printf("mutex error\n");
        return NULL;
    }
	if(-1 == sem_init(&queue->add, 0, 0))
    {
        printf("sem_init error\n");
        return NULL;
    }
	if(-1 == sem_init(&queue->delete, 0, ARR_SIZE))
    {
        printf("sem_init error\n");
        return NULL;
    }

   return queue;
}


void QueueDestroy(queue_t* queue)
{

	if(NULL == queue)
	{
        return ;
	}
	pthread_mutex_destroy(&queue->mutex1);
	pthread_mutex_destroy(&queue->mutex2);
    sem_destroy(&queue->add);
    sem_destroy(&queue->delete);
    free(queue->arr);
	free(queue);		
}


int QueueIsEmpty(queue_t* queue)
{	
	assert(queue);
	if(0 == queue->amount_of_items)
	{
		return 1;
	}
	return 0;
}

size_t QueueSize(queue_t* queue)
{
	assert(queue);
	return queue->amount_of_items;
}

int EnQueue(queue_t* queue, void *element)
{
	assert(NULL != queue);
	assert(NULL != element);
    pthread_mutex_lock(&queue->mutex1);
	sem_wait(&queue->delete);
	
	
	
	queue->arr[queue->read_index] = *(size_t *)element;
	queue->read_index = (queue->read_index + 1) % queue->capacity;

	sem_post(&queue->add);
	pthread_mutex_unlock(&queue->mutex1); 
	return 0;
}

void *DeQueue(queue_t* queue)
{
	void *value = NULL;
	assert(NULL != queue);
	pthread_mutex_lock(&queue->mutex2);
    sem_wait(&queue->add);
	
	
	value = (void *)&queue->arr[queue->write_index];
	queue->write_index = (queue->write_index + 1) % queue->capacity;
	
	sem_post(&queue->delete);
	pthread_mutex_unlock(&queue->mutex2); 
	return value;
}
