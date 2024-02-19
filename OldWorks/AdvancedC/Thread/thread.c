
#include <stdio.h> 
#include <stdlib.h>            /** malloc */
#include <unistd.h>           /** execvp() */
#include <string.h>           /** strtok */
#include <sys/wait.h>         /** wait(&status) */
#include <sys/types.h>
#include <pthread.h>
#define NUM_OF_THREADS 10


void* PrintFunc(void* tid)
{
	printf("B4 thread num: %d \n" , (int) tid);
	sleep(1);
	printf("The thread num: %d \n" , (int) tid);
	pthread_exit(tid);
	return tid;
}



int main()
{
	int i,status=0,j;
	pthread_t threads[NUM_OF_THREADS];
	
	
	
	for(i=0; i<NUM_OF_THREADS; i++)
	{
		printf("Created thread:%d\n", i);
		
		status= pthread_create(&threads[i], NULL, PrintFunc, (void *)i);
		
		if(status)
		{
			printf("Error\n");
		
		}
		
	}
	for(j=0; j<NUM_OF_THREADS; j++)
	{
		pthread_join(threads[j], NULL);
	}

	return 0;



}
