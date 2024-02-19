/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#define _XOPEN_SOURCE 500
#include <errno.h> /*siginfo_t*/
#define __USE_POSIX /*signaction*/
#define __USE_POSIX199309 /*siginfo_t*/
#include <signal.h> /*sigaction*/
#include <stdio.h> /*printf*/
#include <unistd.h> /*getpid*/
#include <pthread.h> /*pthread_create*/
#include "watchdog.h"


#define MAX_PINGS (4)
#define UNTIL_END (1)
#define FAIL (1)
#define SUCCESS (0)
#define ERROR (-1)
int Task1(void *data)
{
    /*Send signal*/
    return 1;
}
int Task2(void *data)
{
    /*Send signal*/
    return 1;
}
void *UserSchedulerInit(void *data)
{
    scheduler_t *user_scheduler = NULL;
    pid_t child_pid = getppid();
    (void)data;
    while(NULL == user_scheduler)
    {
        user_scheduler = SchedulerCreate();
    }
    SchedulerAddTask(user_scheduler, Task1, (void *)&child_pid, 1, 1,  NULL, NULL);
    SchedulerAddTask(user_scheduler, Task2, (void *)&child_pid, 1, 1,  NULL, NULL);
    return (NULL);
}




static void catcher(int pid)
{
    (void)pid;
}

static void ParentProcess(int pid)
{
    int pings = 0;
    for (pings = 0; pings < MAX_PINGS; ++pings)
    {
        printf("Ping %d!\n", pings);
        sleep(1);
        kill(pid, SIGUSR1);
        pause();
    }
    kill(pid, SIGTERM);
}


int WDStart(char **path)
{
    struct sigaction child = {0};
    struct sigaction parent = {0};
    int pid = 0 ;
    int return_value = 0;
    pthread_t watchdog_thread;

    sigemptyset(&child.sa_mask);
    child.sa_flags = 0;
    child.sa_handler = catcher;
    
    sigemptyset(&parent.sa_mask);
    parent.sa_flags = 0;
    parent.sa_handler = catcher;

    if (ERROR == sigaction(SIGUSR1, &child, NULL))
    {
        return (FAIL);
    }
    if (ERROR == sigaction(SIGUSR2, &parent, NULL))
    {
        return (FAIL);
    }

    pid = fork();
    if (0 > pid)
    {
        return (FAILED_TO_CREATE_CHILD_PROCESS);
    }
    else if (0 == pid)
    {
        exec(path);
    }
    else
    {
        ParentProcess(pid);
        return_value = pthread_create(&watchdog_thread, NULL, UserSchedulerInit, NULL);
        if(0 == return_value)
        {
            pthread_join(watchdog_thread, NULL);
        }
    }

    return (SUCCESS);

}





void WDStop(size_t timeout)
{





}