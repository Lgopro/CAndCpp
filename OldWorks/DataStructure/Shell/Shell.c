#include <stdio.h> 
#include <stdlib.h>            /** malloc */
#include <unistd.h>           /** execvp() */
#include <string.h>           /** strtok */
#include <sys/wait.h>         /** wait(&status) */

#define LENGTH	120
#define TRUE 1
int main()	
{
		char userInput[LENGTH];
		char* command[10];
		char* token;
		pid_t child;
		int i = 0;
		int status;
	while (TRUE) 
	{
		printf("Please enter your command:");
		scanf("%s", userInput);
		getchar();
		token = strtok(userInput, " ");
		command[i++] = token;
		if (0 == strncmp(token, "exit", 4))
		{
			exit(1);
		}
		while (token != NULL)
		{
			token = strtok(NULL, " ");
			command[i++] = token;
		}
		command[i] = NULL;	
		if ((child = fork()) != 0) 
		{
			waitpid(child, &status, 0);           /* Parent Code */
		}
		else 
		{
			if (-1 == (execvp(command[0],command)))              /* Child code */
			{
				printf("Wrong Command\n");
				exit(1);
			}
		}
			
	}
	return 0;
}



