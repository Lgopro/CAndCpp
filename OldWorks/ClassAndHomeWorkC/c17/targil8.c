#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Description: Function finds the amount of each letter in the opened file.
Input: void.
Output: 0.
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
	int  i=0,counter[52]={0};
	char ch,letters[52],filename[100];
	FILE *fp;
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50, stdin);
		fp = fopen(filename , "r");
	}while(fopen(filename, "r") == NULL);
	for(i=0;i<26;i++)
	{
		letters[i]=(char)(65+i);
	}
	for(i=26;i<52;i++)
	{
		letters[i]=(char)(71+i);
	}
	do
	{
		ch=fgetc(fp);
		for(i=0;i<52;i++)
		{
			if(letters[i]== ch)
			{
				counter[i]++;
			}
		}
	}while(!feof(fp));
	for(i=0;i<52;i++)
	{
		if(counter[i]!=0)
		{
			printf("       %c         %d\n" , letters[i], counter[i]);
		}
	}
	fclose(fp);
	return;
}
