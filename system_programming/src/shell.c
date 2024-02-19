
#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <unistd.h> /*fork*/
#include <sys/wait.h> /*system*/
#include <string.h> /*strcmp*/

#include "shell.h"


#define BUFFER_LEN (50)
#define UNTIL_EXIT (1)
#define FAIL (1)
#define SUCCESS (0)
#define SAME (0)
#define UNTIL_DONE (1)


int System(void)
{
    char string[50] = {0};
    int status = 0;

    while(UNTIL_EXIT)
    {
        printf("Leon@Shell $:");
        if(!fgets(string, BUFFER_LEN, stdin)) 
        {
            break;
        }
       
        string[strlen(string) - 1] = '\0';
        if(SAME == strcmp(string, "exit"))
        {
            return SUCCESS;
        }
        status = system(string);
        printf("Status is %d\n", status);
    }
    return FAIL;
}



int Fork(void)
{
    char line[BUFFER_LEN];
    pid_t pid = 0;
    int status = 0;


    while(UNTIL_EXIT) 
    {
        
        printf("Leon@Shell $:");
        if(!fgets(line, BUFFER_LEN, stdin)) 
        {
            break;
        }
        
        line[strlen(line) - 1] = '\0';

        if(SAME == strcmp(line, "exit"))
        {
            return SUCCESS;
        }

        pid = fork();  

        if(pid == 0) 
        {              
            return execl("/bin/sh", "sh", "-c", line, (char *)NULL);
        } 
        else 
        {                    
            wait(&status);
        }
        printf("Status is %d\n", status);
    }
    return (status);
}
