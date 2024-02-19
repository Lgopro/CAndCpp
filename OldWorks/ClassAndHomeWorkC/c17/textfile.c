#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
	FILE *fp;
	char filename[50];
	printf("Please enter the file name with .txt\n");
	fgets(filename, 50,stdin);
	fp=fopen(filename, "w");
	fprintf(fp,"Here you can find activities to practise your reading skills\n");
	fprintf(fp,"Reading will help you to improve your understanding of the language and build your vocabulary\n");
	fclose(fp);
	
	return 0;
}
