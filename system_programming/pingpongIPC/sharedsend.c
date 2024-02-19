/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 27.08.2023
*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include "shareddata.h"

  
void Send()
{
    /* ftok to generate unique key */
    key_t key = ftok("shmfile",65);
  
    /* shmget returns an identifier in shmid */
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    /* shmat to attach to shared memory */
    char *str = (char*) shmat(shmid,(void*)0,0);
  
    printf("Write Data : \n");
    fgets(str, 20, stdin);
  
    printf("Data written in memory: %s\n",str);
      
    /* detach from shared memory  */
    shmdt(str);
}

int main()
{
    
    Send();
    return 0;
}