/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 27.08.2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "pipe.h"


#define READ (0)
#define WRITE (1)
int Pipe() 
{
    int fd1[2]; 
    int fd2[2];
    int i = 0;
    int j = 0;
    char ping_message[] = "Ping!";
    char pong_message[] = "Pong!";
    char rec_message_pong[10];
    char rec_message_ping[10];
    pid_t pid;

    if (pipe(fd1) == -1) 
    {
        perror("Pipe creation failed");
        return 1;
    }

    if (pipe(fd2) == -1) 
    {
        perror("Pipe creation failed");
        return 1;
    }

    pid = fork(); 

    if (pid < 0) 
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) 
    {
        for(i = 0; i < 5; ++i)
        { 
            read(fd1[READ], rec_message_ping, sizeof(ping_message)); 
            printf("Child received: %s\n", rec_message_ping);
            write(fd2[WRITE], pong_message, strlen(pong_message) + 1); 
        }
    } 
    else 
    {
        for(j = 0; j < 5; ++j)
        {
            write(fd1[WRITE], ping_message, strlen(ping_message) + 1);
            read(fd2[READ], rec_message_pong, sizeof(pong_message)); 
            printf("Parent received: %s\n", rec_message_pong);
            
        }
    }

    return 0;
}

int main()
{
    Pipe();
    return 0;
}