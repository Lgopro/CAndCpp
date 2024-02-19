/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*atoi*/
#include <unistd.h> /*getppid*/
#define __USE_POSIX /*signaction*/
#define __USE_POSIX199309 /*siginfo_t*/
#include <signal.h> /*sigaction*/


#define MAX_PINGS (4)
#define UNTIL_END (1)
#define FAIL (1)
#define SUCCESS (0)
#define ERROR (-1)

void sigHandler(int signo, siginfo_t *siginfop, void *context)
{
    union sigval sv = {0};
    (void)signo;
    (void)context;

    sleep(1);
    printf("Pong\n");

    if(siginfop != NULL)
    {
       sigqueue(siginfop->si_pid, SIGUSR1, sv);
    }
}
      
int main(int argc, const char *argv[])
{
    int ping_pid = atoi(argv[1]);
    int pings = 0;
    union sigval sv = {0};
    struct sigaction sa;
    sa.sa_sigaction = sigHandler;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
   
    (void)argc;
    if(ERROR == sigaction(SIGUSR2, &sa, NULL)) 
    {
        printf("sigaction error\n");
    }
   
    if(ERROR == sigqueue(ping_pid, SIGUSR1, sv)) 
    {
        printf("sigqueue error\n");
    }
    
   
    for(pings = 0; pings < MAX_PINGS; ++pings)
    {
        pause();
    }

    return 0;
}