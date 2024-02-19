/*
Rev: Barak Teni Maimon
Dev: Leonid Golovko
status: finished
date:23/03/23
*/

#include <stdio.h> /*puts*/
#include <stdlib.h> /*free*/
#include <string.h> /*strcmp*/
#include <ctype.h> /*tolower*/


void AllRowsPrint(char** envp, char** mine_env);
void ToLower(char row[]);
char *StrDup(char *s);

int main(int argc, char *argv[], char *envp[])
{
    	char **envirment = NULL;
    	if(NULL == argv)
    	{
    		return 1;
    	} 
    	(void)argc;
    	envirment = (char **)malloc(sizeof(char *) * (sizeof(*envp) + 1));
    	if(NULL == envirment)
    	{
    		return 1;
    	}
  	AllRowsPrint(envp, envirment);
  	
    return 0;
}

void AllRowsPrint(char** envp, char** mine_env)
{
	char **begining = NULL;
    	begining = mine_env;
 
	for ( mine_env = envp; *envp != NULL; ++envp)
  	{
  		*mine_env = StrDup(*envp);
    		ToLower(*mine_env);
    		puts(*mine_env);
    		free(*mine_env);	
  	}
  
	free(begining);
}

void ToLower(char *row)
{
	char *begin;
	if(NULL == row)
	{
		return;
	}
	begin = row;
	while ('\0' != *row)
	{
		if(*row >= 'A' && *row <= 'Z')
		{
			*row = tolower(*row);
			
		}
		++row;
	}
	row = begin;
}
char *StrDup(char *s)
{

	char* copy = NULL;
	if(NULL == s)
	{
		return NULL;
	
	}
	copy = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	strcpy(copy, s);
	return copy;

}


 
