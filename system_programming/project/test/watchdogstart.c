

#define _POSIX_C_SOURCE 200112L
#include <stdlib.h> /*getenv*/
#include <pthread.h> /*pthread_create*/
#include <semaphore.h> /*sem_unlink*/
#include <assert.h> /*assert*/
#include <stdio.h> /*printf*/
#include <sys/types.h> /*getpid*/
#include <unistd.h> /*getpid*/
#include "watchdog.h"
#define CHARTOINT (48)
#define SEM_NAME "User_Watch"


static void ItoABaseTen(int number, char *str, int base);



int main(int argc, char **argv)
{

    char pid[10] = {0};
   
	(void)argc;
    ItoABaseTen(getpid(), pid, 10);

    printf("Got to WD MAIN MENU\n");
    printf("PID IS %d\n", getpid());

    setenv("WATCH_DOG_PID", pid, 1);
    WDStart(argv);
   
    return 0;
}

static void ItoABaseTen(int number, char *str, int base)
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