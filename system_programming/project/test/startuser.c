/*
Rev: Liran Tzuman.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
*/
#define _POSIX_C_SOURCE 200112L
#include <stdlib.h> /*getenv*/
#include <pthread.h> /*pthread_create*/
#include <semaphore.h> /*sem_unlink*/
#include "watchdog.h"

#define SEM_NAME "User_Watch"


void Run(char **path);

int main(int argc, char **argv)
{
    
    (void)argc;
    Run(argv);
    return 0;
}



void Run(char **path)
{
    time_t timer = time(NULL);
    size_t timeout = 40;
    WDStart(path);
    
    while(((size_t)timeout >= (size_t)time(NULL) - (size_t)timer))
    {
    }
    
    WDStop(1);
}
