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


/*pseudo code*/
/*We do have two functions. Consumer and Producer.
Both functions will work in the same way.
Both will wait for the flag to have the right value and after that they will do their task.
After they finish their task they change the flag and allow the other fucntion to work and block theiself.
 while(0 != counter)
    {
        pthread_spin_lock(&lock);
        if(flag == right value)
        {
            send/recieve.
            change flag
        }
        pthread_spin_unlock(&lock);
        --counter;
        while(flag != change to right value && 0 != counter)
        {

        }
    }
there is synchronization 
there is no condition race
there is busy wait
there is no starvation
there is no deadlock
    
*/
#define SUCCESS (0)
#define FAIL (1)

enum message
{
    READY_TO_BE_SENT = 0,
    READY_TO_BE_RECIEVED
};

int flag = READY_TO_BE_SENT;
int signal;



void *Producer(void *data)
{
    int counter = *(int *)data;
    while(0 < counter)
    {
        if(flag == READY_TO_BE_SENT)
        {
            signal = rand() % 1000000000;
            printf("Sent message %d\n", signal);
            flag = READY_TO_BE_RECIEVED;
        }
        --counter;
        while(flag != READY_TO_BE_SENT && 0 != counter)
        {

        }
    }
    
    pthread_exit(NULL); 
}

void *Consumer(void *data)
{
    int counter = *(int *)data;
    while(0 != counter)
    {
        if(flag == READY_TO_BE_RECIEVED)
        {
            printf("Recieve message %d\n", signal);
            flag = READY_TO_BE_SENT;
        }
        --counter;
        while(flag != READY_TO_BE_RECIEVED && 0 != counter)
        {

        } 
    }   
    pthread_exit(NULL); 
}

int ProducerComsumer(void);

int main()
{
    ProducerComsumer();
    return 0;
}


int ProducerComsumer(void)
{
    int return_value = 0;
    int counter = 5;
    int counter1 = 6;
    pthread_t consumer = 0;
    pthread_t producer = 0;
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    return_value = pthread_create(&producer, NULL, Producer, (void *)&counter);
    if(SUCCESS != return_value)
    {
        return (FAIL);
    }
    return_value = pthread_create(&consumer, NULL, Consumer, (void *)&counter1);
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
