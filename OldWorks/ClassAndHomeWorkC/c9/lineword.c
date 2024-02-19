#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
	FILE *fp;
	int wordscount=0,countlines=0,i,j,length;
	char filename[100],str[100];
	
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
	printf("The amount of lines in this txt file is: %d\n",countlines);
	fclose(fp);
	fp=fopen(filename, "r");
	for(i=0;i<countlines;i++)
	{
		fgets(str,100,fp);
		length=strlen(str);
		for(j=0;j<length;j++)
		{
			if(str[j]==' ')
			{
				wordscount++;
			}
		}
		wordscount++;

	}
	printf("The amount of words in the text is:%d\n", wordscount);
	fclose(fp);
	
	
	
	return 0;
}
