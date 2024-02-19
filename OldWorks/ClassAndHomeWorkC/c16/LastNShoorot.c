#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	int numlines,countlines=0,madad;
	char filename[100],str[100],ch;
	printf("Please enter the number of last lines you want to print:\n");
	scanf("%d", &numlines);
	getchar();
	
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50,stdin);
		fp=fopen(filename, "r");
	}while(fopen(filename, "r")==NULL);
	fseek(fp,0,SEEK_END);
	while(countlines<=numlines)
	{
		
		madad=fseek(fp,-2,SEEK_CUR);
		if(madad == -1)
		{
			break;
		}
		ch=fgetc(fp);
		if(ch == '\n')
		{
			countlines++;
		}
	}
	fgetc(fp);
	do
	{
		fgets(str,100,fp);
		printf("%s", str);
	
	}while(!feof(fp));
	
	
	return 0;
}
