/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/


#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#include <stdio.h> /*printf*/
#include <unistd.h> /*getppid*/
#include <signal.h> /*sigaction*/
#include <semaphore.h> /*sem_unlink*/
#include <fcntl.h>     /* O_CREAT */
sem_t *ping_semaphore = NULL;
sem_t *pong_semaphore = NULL;
#define SEM_PING "PING2"
#define SEM_PONG "PONG2"
#define MAX_PONGS (4)
#define UNTIL_END (1)
#define FAIL (1)
#define ERROR (-1)



int main()
{      
    int pongs = 0;
    ping_semaphore = sem_open(SEM_PING, O_CREAT, S_IRUSR | S_IWUSR, 0);
    pong_semaphore = sem_open(SEM_PONG, O_CREAT, S_IRUSR | S_IWUSR, 0);
    
    printf("I got here\n");
    sem_post(ping_semaphore);
    
    for (pongs = 0; pongs < MAX_PONGS; ++pongs)
    {
        sem_wait(ping_semaphore);
        printf("Pong!\n");
        sem_post(pong_semaphore);
    }
    sem_destroy(ping_semaphore);
    sem_destroy(pong_semaphore);
    return 0;
}
