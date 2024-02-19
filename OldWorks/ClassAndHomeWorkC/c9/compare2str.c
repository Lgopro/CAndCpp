#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	char filename1[100],str1[100],filename2[100],str2[100];
	int countlines=0,countlines1=0;
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
	do
	{
		fgets(str2,100,t);
		++countlines1;
	
	}while(!feof(t));
	if(countlines>=countlines1)
	{
		do
		{
			fgets(str1,100,fp);
			fgets(str2,100,t);
			if(strcmp(str1,str2)!=0)
			{
				printf("%s\n", str1);
				printf("%s\n", str2);
			}
		}while(!feof(fp)) ;
	}
	else
	{
		do
		{
			fgets(str1,100,fp);
			fgets(str2,100,t);
			if(strcmp(str1,str2)!=0)
			{
				printf("%s\n", str1);
				printf("%s\n", str2);
			}
		}while(!feof(t)) ;
	
	}
	fclose(fp);
	fclose(t);
	return 0;
}
