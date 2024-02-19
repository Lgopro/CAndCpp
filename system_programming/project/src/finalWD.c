/*
Rev: Etai Shimoni.
Dev: Leonid Golovko
status: finished
date: 24/07/2023
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
#include <stdatomic.h> /*atomic_int*/
#include <string.h> /*strcat*/
#include "watchdog.h"
#include "scheduler.h"
#include "task.h"
#include "dlist.h"

#define UNTIL_END (1)
#define FAIL (1)
#define SUCCESS (0)
#define ERROR (-1)
#define CHARTOINT (48)
#define REPEAT (0)
#define DO_NOT_REPEAT (1)
#define USER "/user"
#define WD "/watchdog"
#define SEM_NAME "My_SEM"
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
static int user_pid_global = 0;
static sem_t *global_sem = NULL;
static pthread_t watchdog_thread;
static char user_path[100];
static char watchdog_path[100];
static char **argv;

static volatile atomic_int process_counter = 0;

static int CreateSingnalHandlers(void);
static int Revive();
static void *UserSchedulerInit();

/********************TASKS*********************/
int Task1(void *data)
{
    (void)data;
    if(flag_to_close == 1)
    {
        return (DO_NOT_REPEAT);
    }
    #ifndef NDEBUG
    printf("Signal to %d from %d!\n" , pid, getpid());
    #endif
    kill(pid , SIGUSR1);
    
    return (REPEAT);
}

int Task2(void *data)
{
    (void)data;
    if(flag_to_close == 1)
    {
        return (DO_NOT_REPEAT);
    }
    #ifndef NDEBUG
    printf("The counter of %d is %d\n", getpid(), process_counter);
    #endif
    if(0 == process_counter)
    {
        Revive();
    }
    atomic_exchange(&process_counter, 0);
    counter_of_user = 0;
    return (REPEAT);
}
int Task3(void *data)
{
    (void)data;
    if(flag_to_close == 1)
    {
        #ifndef NDEBUG
        printf("Ping to close %d from %d!\n" , pid, getpid());
        #endif
        kill(pid , SIGUSR2);
        SchedulerStop(user_scheduler);
        sleep(1);
        
        return (DO_NOT_REPEAT);
    }
    return (REPEAT);
}




void *RunScheudler(void *data)
{
    (void)data;
    SchedulerRun(user_scheduler);
    SchedulerDestroy(user_scheduler);
    return (NULL);
}

/********************SIG_HANDLERS*********************/

static void IncreaseCounter(int data)
{
    (void)data;
    atomic_fetch_add(&process_counter, 1);
}


static void StopRunning(int data)
{
    (void)data;
    #ifndef NDEBUG
    printf("User stopped running\n");
    printf("My pid is %d\n", pid);
    #endif
    flag_to_close = 1;
}

/********************MAIN FUNCTIONS*********************/

int WDStart(char **path)
{
    int number = 0;
    int return_value = 0;
    char user[] = USER;
    char watchdog[] = WD;

    assert(path);

    global_sem = sem_open(SEM_NAME, O_CREAT, S_IRUSR | S_IWUSR, 0);
    CreateSingnalHandlers();
    argv = path;
    getcwd(user_path, sizeof(user_path));
    getcwd(watchdog_path, sizeof(watchdog_path));
    strcat(user_path, user);
    strcat(watchdog_path, watchdog);

    if(NULL == getenv("WATCH_DOG_PID"))
    {
        pid = fork();
        if (0 > pid)
        {
            return (FAILED_TO_CREATE_CHILD_PROCESS);
        }
        else if (0 == pid)
        {
            if (-1 == execv(watchdog_path, (char **)path))
            {
                return (FAIL);
            }

        }
        else
        {
            user_scheduler = UserSchedulerInit();
            user_pid_global = pid;
            sem_wait(global_sem);
            return_value = pthread_create(&watchdog_thread, NULL, RunScheudler, &pid);
            if(0 != return_value)
            {
                return (FAIL);
            } 
        }

    }
    else if(getppid() == atoi(getenv("WATCH_DOG_PID")))
    {
        user_scheduler = UserSchedulerInit();
        pid = getppid();
        sem_post(global_sem);
        return_value = pthread_create(&watchdog_thread, NULL, RunScheudler, &pid);
        if(0 != return_value)
        {
            return (FAIL);
        } 
    }
    else if(getpid() == atoi(getenv("WATCH_DOG_PID")))
    {
        pid = getppid();
        user_scheduler = UserSchedulerInit();
        sem_post(global_sem);
        sem_getvalue(global_sem, &number);
        SchedulerRun(user_scheduler);
        SchedulerDestroy(user_scheduler);
    }
    return (SUCCESS);
}


void WDStop(size_t timeout)
{
    time_t timer = time(NULL);
    
    kill(pid , SIGUSR2);
    while(((size_t)timeout >= (size_t)time(NULL) - (size_t)timer) && flag_to_close != 1)
    {
        
    }
    if(flag_to_close == 0)
    {
        kill(pid , SIGABRT);
    }
    #ifndef NDEBUG
    printf("************STOPPING*************\n");
    #endif
    pthread_join(watchdog_thread, NULL);
    sem_unlink(SEM_NAME);
}

/********************STATIC FUNCTIONS*********************/

static int CreateSingnalHandlers(void)
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

static int Revive()
{
    #ifndef NDEBUG
    printf("Got to revive\n");
    #endif
    /*Parent Died*/
    if(NULL != (getenv("WATCH_DOG_PID")) && getpid() == atoi((getenv("WATCH_DOG_PID"))))
    {
        #ifndef NDEBUG
        printf("User Died\n");
        #endif
        pid = fork();
        if (0 > pid)
        {
            return (FAILED_TO_CREATE_CHILD_PROCESS);
        }
        else if (0 == pid)
        {
            pid = getpid();
            if (-1 == execv(user_path, (char **)argv))
            {
                return (FAIL);
            }

        }
        else
        {
            sem_wait(global_sem);
        }
    }
    /*Child died*/
    else
    {
        #ifndef NDEBUG
        printf("Watchdog Died\n");
        #endif
        pid = fork();
        if (0 > pid)
        {
            return (FAILED_TO_CREATE_CHILD_PROCESS);
        }
        else if (0 == pid)
        {
            
            if (-1 == execv(watchdog_path, (char **)argv))
            {
                return (FAIL);
            }
        }
        else
        {
            sem_wait(global_sem); 
        }
    }
    return (FAIL);
}

static void *UserSchedulerInit()
{
    
    ilrd_uid_t tasks[AMOUNT_OF_TASKS] = {0};
  
    user_scheduler = SchedulerCreate();
    if (NULL == user_scheduler)
    {
        return (NULL);
    }
    tasks[SEND_SIGNAL] = SchedulerAddTask(user_scheduler, Task1, NULL, 0, 1,  NULL, NULL);
    if (UIDIsSame(tasks[SEND_SIGNAL], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    tasks[INCREASE_COUNTER] = SchedulerAddTask(user_scheduler, Task2, NULL, 5, 5,  NULL, NULL);
    if (UIDIsSame(tasks[INCREASE_COUNTER], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    tasks[STOP_SCHEDULER] = SchedulerAddTask(user_scheduler, Task3, NULL, 1, 1,  NULL, NULL);
    if (UIDIsSame(tasks[STOP_SCHEDULER], UIDBadUID))
    {
        SchedulerDestroy(user_scheduler);
        return (NULL);
    }
    
    return (user_scheduler);
}
