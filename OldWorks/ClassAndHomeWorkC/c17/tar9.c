#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
Description: Function find the amount of times each word is wrote in the file.
Input: void.
Output: amount of times a word is in the file.
Complexity: o(n).
*/
void Count(void);




int main()
{
	Count();
	return 0;
}

void Count(void)
{
	char wordfile[100],wordprint[1000][100],filename[100],ch;
	int counters[1000]={0};
	int words=0,i,bonus;
	FILE *fp;
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50, stdin);
		fp = fopen(filename , "r");
	}while(fopen(filename, "r") == NULL);
	while(!feof(fp))
	{
		bonus=0;
		fscanf(fp, "%s", wordfile);
		for(i=0 ;i<=words ;i++)
		{
			if(strcmp(wordfile,wordprint[i])==0)
			{
				counters[i]++;
				bonus=1;	
			}
		}
		if(bonus == 0)
		{
			strcpy(wordprint[words],wordfile);
			counters[words]++;
			words++;
		}
		ch=fgetc(fp);
		ch=fgetc(fp);
		if(ch == EOF)
		{
			break;
		}
		fseek(fp,-2,SEEK_CUR);
	}
	for(i=0;i<words;i++)
	{
		printf("%5s        %9d\n" , wordprint[i], counters[i]);
		
	}
	fclose(fp);
	return;
}


