/*
Rev: 
Dev: 
status: 
date: 
*/
#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#include <errno.h> /*siginfo_t*/
#include <signal.h> /*sigaction*/
#include <stdio.h> /*printf*/
#include <unistd.h> /*getpid*/
#include <pthread.h> /*pthread_create*/
#include <time.h> /*time_t*/
#include <semaphore.h> /*sem_open*/
#include <fcntl.h>     /* O_CREAT */
#include <stdlib.h> /*getenv*/
#include <assert.h> /*assert*/
#include "watchdog.h"
#include "scheduler.h"
#include "task.h"
#include "dlist.h"

#define UNTIL_END (1)
#define FAIL (1)
#define SUCCESS (0)
#define ERROR (-1)
#define CHARTOINT (48)
#define SEM_NAME "User_Watch"
#define MODE (0644)
enum
{
    SEND_SIGNAL,
    INCREASE_COUNTER,
    STOP_SCHEDULER,
    AMOUNT_OF_TASKS
};

static int flag_to_close = 0;
static int counter_of_user = 0;
static scheduler_t *user_scheduler = NULL;
static int pid = 0;
static sem_t *global_sem = NULL;
static pthread_t watchdog_thread;

void ItoABaseTen(int number, char *str, int base);
int CreateSingnalHandlers(void);

int Task1(void *data)
{
    (void)data;
    sem_wait(global_sem);
    if(flag_to_close == 1)
    {
        printf("USER FLAG TO CLOSE CHANGED TO 1 TASK 1\n");
        return 1;
    }
    printf("User to %d from %d!\n" , pid, getpid());
    kill(pid , SIGUSR1);
    
    return 0;
}

int Task2(void *data)
{
    (void)data;
    if(flag_to_close == 1)
    {
        printf("USER FLAG TO CLOSE CHANGED TO 1 TASK 2\n");
        return 1;
    }
    printf("The user counter is %d\n", counter_of_user);
    if(counter_of_user == 0)
    {
        /*revive*/
    }
    sem_wait(global_sem);
    return 0;
}
int Task3(void *data)
{
    (void)data;
    if(flag_to_close == 1)
    {
        printf("USER FLAG TO CLOSE CHANGED TO 1 TASK 3\n");
        printf("Ping to %d from %d!\n" , pid, getpid());
        kill(pid , SIGUSR2);
        sleep(1);
        
        return 1;
    }
    return 0;
}

void *UserSchedulerInit(int *pid)
{
    
    ilrd_uid_t tasks[AMOUNT_OF_TASKS] = {0};
  
    user_scheduler = SchedulerCreate();
    if (NULL == user_scheduler)
    {
        return (NULL);
    }
    tasks[SEND_SIGNAL] = SchedulerAddTask(user_scheduler, Task1, pid, 0, 1,  NULL, NULL);
    if (UIDIsSame(tasks[SEND_SIGNAL], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    tasks[INCREASE_COUNTER] = SchedulerAddTask(user_scheduler, Task2, user_scheduler, 5, 5,  NULL, NULL);
    if (UIDIsSame(tasks[INCREASE_COUNTER], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    tasks[STOP_SCHEDULER] = SchedulerAddTask(user_scheduler, Task3, pid, 1, 1,  NULL, NULL);
    if (UIDIsSame(tasks[STOP_SCHEDULER], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    
    return (user_scheduler);
}


void *RunScheudler(void *data)
{
    (void)data;
    SchedulerRun(user_scheduler);
    SchedulerDestroy(user_scheduler);
    return (NULL);
}

static void IncreaseCounter(int pid)
{
    printf("User Got Signal\n");
    ++counter_of_user;
    sem_post(global_sem);
    (void)pid;
}


static void StopRunning(int pid)
{
    printf("User stopped running\n");
    SchedulerStop(user_scheduler);
    flag_to_close = 1;
    (void)pid;
}



int WDStart(char **path)
{
    int return_value = 0;
    char pidstring[50] = {0};
    
    int number = 0;
    global_sem = sem_open(SEM_NAME, O_CREAT, S_IWUSR | S_IWOTH, 0);
    (void)path;
    CreateSingnalHandlers();
    sem_unlink(SEM_NAME);
    if(0 != atoi(getenv("WD_PID")))
    {
        pid = atoi(getenv("WD_PID"));
        user_scheduler = UserSchedulerInit(&pid);
        SchedulerRun(user_scheduler);
    }
    else
    {
        pid = fork();
        if (0 > pid)
        {
            return (FAILED_TO_CREATE_CHILD_PROCESS);
        }
        else if (0 == pid)
        {
            printf("Child here\n");
            execl("watchdog.out","watchdog_test.c", NULL);
            
        }
        else
        {

            ItoABaseTen(pid, pidstring, 10);
            setenv("WD_PID", pidstring , 1);
            user_scheduler = UserSchedulerInit(&pid);
            /*sleep(1);
            sem_getvalue(global_sem, &number);
            printf("Sem counter %d\n", number);
            printf("Got here\n");
            
            printf("Got here\n");*/
            sem_wait(global_sem);
            return_value = pthread_create(&watchdog_thread, NULL, RunScheudler, &pid);
            if(0 != return_value)
            {
                return (FAIL);
            }
            
        }

    }
    return (SUCCESS);
}


void WDStop(size_t timeout)
{
    time_t timer = time(NULL);
    while((size_t)timeout >= (size_t)time(NULL) - (size_t)timer)
    {

    }
    flag_to_close = 1;
    kill(pid , SIGUSR2);
    printf("************Im here*************\n");
    pthread_join(watchdog_thread, NULL);
    sem_close(global_sem);
    
}


int CreateSingnalHandlers(void)
{
    struct sigaction signal_one = {0};
    struct sigaction signal_two = {0};

    sigemptyset(&signal_two.sa_mask);
    signal_two.sa_flags = 0;
    signal_two.sa_handler = StopRunning;

    sigemptyset(&signal_one.sa_mask);
    signal_one.sa_flags = 0;
    signal_one.sa_handler = IncreaseCounter;
    

    if (ERROR == sigaction(SIGUSR1, &signal_one, NULL))
    {
        return (FAIL);
    }

    if (ERROR == sigaction(SIGUSR2, &signal_two, NULL))
    {
        return (FAIL);
    }

    return (SUCCESS);
}



void ItoABaseTen(int number, char *str, int base)
{
	size_t i = 0;
	size_t sign = 0;
	size_t counter = 0;
	
	assert(NULL != str);
	assert( 1 < base && base < 37);
	
	(void)base;
	if(0 > number)
	{
		*str = '-';
		sign = 1;
		++counter;
		number *= -1;
	}
	if(0 == number)
	{
		*str = '0';
		*(str + 1) = '\0';
	}
	while(0 != number)
	{
		i = counter;
		*(str + sign) = (char)(number % 10 + CHARTOINT);
		++counter;
		if(0 != number && 0 == number / 10)
		{
			break;
		}
		else if(0 != number)
		{
			while(sign - 1!= i)
			{
				str[i + 1] = str[i];
				--i;
			}
			
		}
		else
		{
			break;
		
		}
		number /= 10;
	}
	*(str + counter) = '\0';
}