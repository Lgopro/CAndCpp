
/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 27.08.2023
*/
#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#include <errno.h> /*siginfo_t*/
#include <signal.h> /*sigaction*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <unistd.h> /*getpid*/
#include <fcntl.h>     /* O_CREAT */
#include <semaphore.h> /*sem_open*/

#include "semaphore.h"

#define MAX_PINGS (4)

#define FAIL (1)
#define SUCCESS (0)
#define RIGHT_AMOUNT (2)
sem_t *ping_semaphore = NULL;
sem_t *pong_semaphore = NULL;
#define SEM_PING "PING2"
#define SEM_PONG "PONG2"


void Ping()
{
    int pings = 0;
    for (pings = 0; pings < MAX_PINGS; ++pings)
    {
        printf("Ping!\n");
        sem_post(ping_semaphore);
        sem_wait(pong_semaphore);
    }
}

void Pong()
{
    int pongs = 0;
    for (pongs = 0; pongs < MAX_PINGS; ++pongs)
    {
        sem_wait(ping_semaphore);
        printf("Pong!\n");
        sem_post(pong_semaphore);
    }
}





int main(int argc, char *argv[])
{
    if(RIGHT_AMOUNT != argc)
    {
        return FAIL;
    }
    ping_semaphore = sem_open(SEM_PING, O_CREAT, S_IRUSR | S_IWUSR, 0);
    pong_semaphore = sem_open(SEM_PONG, O_CREAT, S_IRUSR | S_IWUSR, 0);
    if(0 == strcmp(argv[1], "ping"))
    {
        Ping();
    }
    else if(0 == strcmp(argv[1], "pong"))
    {
        Pong();
    }
    sem_destroy(ping_semaphore);
    sem_destroy(pong_semaphore);
    return SUCCESS;

}