
#include <stdio.h> /*printf()*/
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <unistd.h>
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/wait.h>
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <errno.h>          /* errno, ECHILD            */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait().. */
#include <fcntl.h>          /* O_CREAT, O_EXEC          */
#include <string.h> /*strtok*/
#include <sys/stat.h> /*S_IRUSR | S_IWUSR*/

#define MAX (30)
#define MIN_AMOUNT_OF_WORDS (2)
#define UNTIL_END (1)
#define EQUAL (0)
#define SUCCESS (0)
#define FAIL (1)
#define UNDO_SUC (2)

static int FindNumber(char *input_value, int *number);

int main (int argc, char *argv[])
{
    int value = 0; 
    int value_for_user = 0;
    int number = 0;
    int number_status = 0;
    int status = 0;  
    int counter = 0;  
    int undo_value = 0;     
    sem_t *sem;                
    char input_value[MAX];
    if(MIN_AMOUNT_OF_WORDS > argc)
    {
        printf("Please enter name of the semaphore as the second word\n");
        return (FAIL);
    }

    printf ("Please enter the value of the semaphores\n");
    scanf("%d", &value);

    sem = sem_open(argv[1], O_CREAT, S_IRUSR | S_IWUSR, value); 
    if(SEM_FAILED == sem)
    {
        printf("Failed to create semaphore\n");
        return (FAIL);
    }     

    printf ("semaphore is initialized.\n\n");
    printf("The name is %s\n", argv[1]);
    printf("The value is %d\n\n", value);
    getchar();

    sem_getvalue(sem, &undo_value);
    value_for_user = undo_value;

    while(UNTIL_END)
    {
        counter = 0;

        printf("Please enter your option of manipulation\n");
        printf("D number to decrement the value by D\n");
        printf("I number to increment the value by I\n");
        printf("V to view the value\n");
        printf("X to exit\n");
        printf("Please enter your option: ");
        fgets(input_value, MAX, stdin);

        input_value[strlen(input_value) - 1] = '\0';

        if(EQUAL == strcmp(input_value, "X"))
        {
            if(undo_value != value_for_user)
            {
                if(undo_value < value_for_user)
                {
                    while(undo_value != value_for_user)
                    {
                        sem_wait(sem);
                        --value_for_user;
                        printf("undo_value %d\n", undo_value);
                        printf("value_for_user %d\n", value_for_user);
                    }
                }
                else
                {
                    while(undo_value != value_for_user)
                    {
                        sem_post(sem);
                        ++value_for_user;
                        printf("undo_value %d\n", undo_value);
                        printf("value_for_user %d\n", value_for_user);
                    }
                }
            }
            sem_close(sem);
            return (SUCCESS);
        }
        if(EQUAL == strcmp(input_value, "V"))
        {
            status = sem_getvalue(sem, &value_for_user);
            if(SUCCESS == status)
            {
                printf("The value is %d\n", value_for_user);
            }
            else
            {
                printf("Failed to get value\n");
                return (FAIL);
            }
        }
        if(input_value[0] == 'D')
        {
            number_status = FindNumber(input_value, &number);
            
            if(UNDO_SUC == number_status)
            {
                sem_getvalue(sem, &undo_value);
            }
            if(SUCCESS == number_status || UNDO_SUC == number_status)
            {
                
                while(number != counter && 0 != value_for_user)
                {
                    ++counter;
                    sem_wait(sem);
                    sem_getvalue(sem, &value_for_user);
                }
            }
            

        }
        if(input_value[0] == 'I')
        {
            number_status = FindNumber(input_value, &number);
            
            if(UNDO_SUC == number_status)
            {
                sem_getvalue(sem, &undo_value);
            }
            if(SUCCESS == number_status || UNDO_SUC == number_status)
            {
                while(number != counter)
                {
                    ++counter;
                    sem_post(sem);
                }
            }   
        }
    }

    sem_close(sem);
    return (SUCCESS);
    
}


static int FindNumber(char *input_value, int *number)
{
    char *token = NULL;
   
    const char check[2] = " ";
    strtok(input_value, check);
    token = strtok(NULL, check);
    if(NULL == token)
    {
        return (FAIL);
    }
    *number = atoi(token);
    token = strtok(NULL, check);
    if(NULL == token)
    {
        return (SUCCESS);
    }
    if(0 == strcmp(token, "[undo]"))
    {
        return (UNDO_SUC);
    }
    return  (SUCCESS);
}

