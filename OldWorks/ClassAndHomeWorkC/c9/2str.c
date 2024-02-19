#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	char filename1[100],str1[100],filename2[100],str2[100];
	int countlines=0,countlines1=0,i;
	FILE* fp;
	FILE* t;
	do
	{
		printf("Please enter the first file name with .txt\n");
		fgets(filename1, 50,stdin);
		fp=fopen(filename1, "r");
		
	}while(fopen(filename1, "r")==NULL);
	
	do
	{
		printf("Please enter the second file name with .txt\n");
		fgets(filename2, 50,stdin);
		t=fopen(filename2, "r");
	}while(fopen(filename2, "r")==NULL);
	
	do
	{
		fgets(str1,100,fp);
		++countlines;
	
	}while(!feof(fp));
	--countlines;
	do
	{
		fgets(str2,100,t);
		++countlines1;
	
	}while(!feof(t));
	--countlines1;
	fclose(t);
	fclose(fp);
	fp=fopen(filename1, "r");
	t=fopen(filename2, "r");
	if(countlines>=countlines1)
	{
		for(i=0;i<countlines1;i++)
		{
			fgets(str1,100,fp);
			fgets(str2,100,t);
			if(strcmp(str1,str2)!=0)
			{
				printf("%s\n", str1);
				printf("%s\n", str2);
			}
		}
		for(i=countlines1;i<countlines;i++)
		{
			fgets(str1,100,fp);
			printf("%s\n", str1);
		}
		
	}
	else
	{
		for(i=0;i<countlines;i++)
		{
			fgets(str1,100,fp);
			fgets(str2,100,t);
			if(strcmp(str1,str2)!=0)
			{
				printf("%s\n", str1);
				printf("%s\n", str2);
			}
		}
		for(i=countlines;i<countlines1;i++)
		{
			fgets(str2,100,t);
			printf("%s\n", str2);
		}
	
	}
	fclose(fp);
	fclose(t);
	return 0;
}
