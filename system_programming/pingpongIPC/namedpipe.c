/*
Rev: Oleg Vragov
Dev: Leonid Golovko
status: finished
date: 27.08.2023
*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L
#include <errno.h> /*siginfo_t*/
#include <signal.h> /*sigaction*/
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <unistd.h> /*getpid*/
#include <fcntl.h>     /* O_CREAT */

#include <sys/types.h> /*mk_fifo*/
#include <sys/stat.h> /*mk_fifo*/
#include "namedpipe.h"
#define MAX_PINGS (4)

#define FAIL (1)
#define SUCCESS (0)
#define RIGHT_AMOUNT (2)

char * ping = "/tmp/myfifo";
char * pong = "/tmp/myfifo1";
int fd;
int fd1;

void Ping()
{
    int i = 0;
    char arr1[10]; 
    char arr2[10] = "Ping";
    /* FIFO file path */
    /* Creating the named file(FIFO) */
    /* mkfifo(<pathname>, <permission>) */
    mkfifo(ping, 0666);
    mkfifo(pong, 0666);
    
    for(i = 0; i < 5; ++i)
    { 
    
        fd = open(ping, O_WRONLY);
        write(fd, arr2, strlen(arr2)+1);
        close(fd);

        /* Open FIFO for Read only */
        fd = open(pong, O_RDONLY);

        /* Read from FIFO */
        read(fd, arr1, sizeof(arr1));

        /* Print the read message */
        printf("User2: %s\n", arr1);
        close(fd);
    }
}

void Pong()
{
    
    int i = 0;
    char str1[10], str2[10] = "Pong";
    

    /* Creating the named file(FIFO) */
    /* mkfifo(<pathname>,<permission>) */
    mkfifo(ping, 0666);
    mkfifo(pong, 0666);

    
    for(i = 0; i < 5; ++i)
    { 
        /* First open in read only and read */
        fd1 = open(ping,O_RDONLY);
        read(fd1, str1, 10);

        /* Print the read string and close */
        printf("User1: %s\n", str1);
        close(fd1);

        /* Now open in write mode and write */
        /* string taken from user. */
        fd1 = open(pong,O_WRONLY);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
}





int main(int argc, char *argv[])
{
    if(RIGHT_AMOUNT != argc)
    {
        return FAIL;
    }
    
    
    if(0 == strcmp(argv[1], "ping"))
    {
        Ping();
    }
    else if(0 == strcmp(argv[1], "pong"))
    {
        Pong();
    }
    
    return SUCCESS;

}