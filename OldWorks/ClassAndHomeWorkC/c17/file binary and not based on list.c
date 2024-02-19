#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);

Person class[3]={{200,"Shaul",19,&class[0]},{50,"Haim",23,&class[1]},{30,"h",44,NULL}};

int main()
{
	Person newclass[3];
	Person binary[3];
	int i=0;
	FILE *fp;
	char filename[100];
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50,stdin);
		fp = fopen(filename, "w");
	}while(fopen(filename, "w") == NULL);
	while(i<3)
	{
		fprintf(fp, "The id is: %d\n", class[i].m_id);
		fprintf(fp, "The name is: %s\n", class[i]. m_name);
		fprintf(fp, "The age is: %d\n", class[i].m_age);
		i++;
	}
	
	fclose(fp);
	i=0;
	do
	{
		printf("Please enter the file name with .txt\n");
		fgets(filename, 50,stdin);
		fp = fopen(filename, "r");
	}while(fopen(filename, "r") == NULL);
	while(i<3)
	{
		fscanf(fp, "The id is: %d\n", &newclass[i].m_id);
		fscanf(fp, "The name is: %s\n", newclass[i]. m_name);
		fscanf(fp, "The age is: %d\n", &newclass[i].m_age);
		i++;
	}
	i=0;
	fclose(fp);
	while(i<3)
	{
		printf( "The id is: %d\n", newclass[i].m_id);
		printf( "The name is: %s\n", newclass[i]. m_name);
		printf( "The age is: %d\n", newclass[i].m_age);
		i++;
	}
	printf("\n\nThe binary print is:\n\n");
	fp = fopen("leonbin.txt", "w+");
	fwrite(class, sizeof(Person) , 3, fp);
	fclose(fp);
	fp = fopen("leonbin.txt", "r");
	fread(binary, sizeof(Person) , 3, fp);
	i=0;
	while(i<3)
	{
		printf( "The id is: %d\n", binary[i].m_id);
		printf( "The name is: %s\n", binary[i]. m_name);
		printf( "The age is: %d\n", binary[i].m_age);
		i++;
	}
	fclose(fp);
 	return 0;
}


