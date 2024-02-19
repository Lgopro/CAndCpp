#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Description: Prints last n lines of file selected or all lines if the lines number selected is to big.
Input: Void.
Output: 0.
Complexity: o(n).
*/
int main()
{
	FILE *fp;
	int numlines,countlines=0,i;
	char filename[100],str[100];
	printf("Please enter the number of last lines you want to print:\n");
	scanf("%d", &numlines);
	getchar();
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50,stdin);
		fp=fopen(filename, "r");
	}while(fopen(filename, "r")==NULL);
	
	do
	{
		fgets(str,100,fp);
		++countlines;
	
	}while(!feof(fp));
	countlines--;
	fclose(fp);
	fp=fopen(filename, "r");
	if(numlines>=countlines)
	{
		for(i=0;i<countlines;i++)
		{
			fgets(str,100,fp);
			printf("%s", str);
		
		}
		fclose(fp);
	}
	else
	{
		for(i=0;i<countlines;i++)
		{
			if(i<countlines-numlines)
			{
				fgets(str,100,fp);
			}
			else
			{
				fgets(str,100,fp);
				printf("%s", str);
			
			}
			
		}
		fclose(fp);
	}
	
	
	return 0;
}
