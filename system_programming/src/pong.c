/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#include <stdio.h> /*printf*/
#include <unistd.h> /*getppid*/
#define __USE_POSIX /*signaction*/
#define __USE_POSIX199309 /*siginfo_t*/
#include <signal.h> /*sigaction*/

#define UNTIL_END (1)
#define FAIL (1)
#define ERROR (-1)

static void catcher(int pid)
{
    (void)pid;
}

int main()
{      
    struct sigaction child;

    sigemptyset(&child.sa_mask);
    child.sa_flags = 0;
    child.sa_handler = catcher;

    if (ERROR == sigaction(SIGUSR1, &child, NULL))
    {
        return (FAIL);
    }
   
    while (UNTIL_END)
    {
        pause();
        printf("Pong!\n");
        sleep(1);
        kill(getppid(), SIGUSR2);
    }
    return 0;
}