/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#include <errno.h> /*siginfo_t*/
#define __USE_POSIX /*signaction*/
#define __USE_POSIX199309 /*siginfo_t*/
#include <signal.h> /*sigaction*/
#include <stdio.h> /*printf*/
#include <unistd.h> /*getpid*/

#define MAX_PINGS (4)
#define UNTIL_END (1)
#define FAIL (1)
#define SUCCESS (0)
#define ERROR (-1)



void sigHandler( int signo, siginfo_t *siginfop, void *context);


static void catcher(int pid)
{
    (void)pid;
}

static void ChildProcess(void)
{

    while (UNTIL_END)
    {
        pause();
        printf("Pong!\n");
        sleep(1);
        kill(getppid(), SIGUSR2);
    }
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

int PingPongEx1()
{
    struct sigaction child = {0};
    struct sigaction parent = {0};
    int pid = 0 ;

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
        return (FAIL);
    }
    else if (0 == pid)
    {
        ChildProcess();
    }
    else
    {
        ParentProcess(pid);
    }

    return (SUCCESS);
}



int PingPongEx2()
{
    struct sigaction parent = {0};
    int pid = 0 ;
    char *argv[] = {"./pong", NULL};
    
    sigemptyset(&parent.sa_mask);
    parent.sa_flags = 0;
    parent.sa_handler = catcher;

    if (ERROR == sigaction(SIGUSR2, &parent, NULL))
    {
        return (FAIL);
    }

    pid = fork();
    printf("%d\n", pid);

    if (0 > pid)
    {
        return (FAIL);
    }
    if (0 == pid)
    {
		execvp(argv[0], argv);
    }
    else
    {
        
        ParentProcess(pid);
    }

    return (SUCCESS);
}


int PingPongEx3()
{
    struct sigaction parent;
    int pings = 0;
    
    printf("%d\n", getpid()); /*pid of the current process*/

    sigemptyset(&parent.sa_mask);
    parent.sa_flags = SA_SIGINFO;
    parent.sa_sigaction = sigHandler; /*function that will take care of incoming signals*/

    if (ERROR == sigaction(SIGUSR1, &parent, NULL))
    {
        return (FAIL);
    }
    
    for(pings = 0; pings < MAX_PINGS; ++pings)
    {
        pause();
    }
    return (SUCCESS);
}

void sigHandler(int signo, siginfo_t *siginfop, void *context)
{
   union sigval sv = {0};
   (void)signo;
   (void)context;
   sleep(1);
   printf("Ping\n");

   if( siginfop != NULL )
   {
       sigqueue(siginfop->si_pid, SIGUSR2, sv); /*sigqueue sends the signal to the */
   }
}

int main()
{
    int option = 0;
    int flag = 1;
    while(flag)
    {
        printf("Please enter an option for the exercise\n");
        scanf("%d", &option);
        getchar();
        switch(option)
        {
            case(1):
            {
                PingPongEx1();
                break;
            }
            case(2):
            {
                PingPongEx2();
                break;
            }
            case(3):
            {
                PingPongEx3();
                sleep(2);
                break;
            }
            default:
            {
                flag = 0;
                break;
            }
        }
    }
    return 0;

}