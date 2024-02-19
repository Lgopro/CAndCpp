#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <pthread.h> /*pthread_create*/
#include <semaphore.h> /*semaphore*/

#define SUCCESS (0)
#define FAIL (1)

sem_t sem;

void DoPing()
{
    while(1)
    {
        
        printf("PING\n");
        sem_post(&sem);
        usleep(5);
    }
}

void DoPong()
{
    while(1)
    {
        sem_wait(&sem);
        printf("PONG\n");
        
    }
}

void *Ping(void *data)
{
    
    (void)data;
    DoPing();
    return (NULL); 
}

void *Pong(void *data)
{
    (void)data;
    DoPong();
    return (NULL); 
}

int PingPong(void);

int main()
{
    PingPong();
    return 0;
}


int PingPong(void)
{
    
    int return_value = 0;
    pthread_t consumer = 0;
    pthread_t producer = 0;
    return_value = sem_init(&sem, 0, 0);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    return_value = pthread_create(&producer, NULL, Ping, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    return_value = pthread_create(&consumer, NULL, Pong, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }

    return_value = pthread_join(consumer, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    return_value = pthread_join(producer, NULL);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    
    return (SUCCESS);
}