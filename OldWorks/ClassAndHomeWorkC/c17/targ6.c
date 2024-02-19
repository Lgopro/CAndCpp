
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/*
Description: Function opens selected file and reads name of new file and a word.Then it openes the new file and found the amount of times the word is in the new file.
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
	int counterword=0;
	FILE *fp;
	FILE *fp1;
	char filename[100],word[100],wordfile[100];
	
	fp = fopen("SOMEFILE.txt", "r");
	
	fscanf(fp, "%s", filename);
	fscanf(fp, "%s", word);
	fclose(fp);
	fp1 = fopen(filename, "r");
	do
	{
		
		fscanf(fp1, "%s", wordfile);
		if(strcmp(word, wordfile) == 0)
		{
			counterword++;
		}
		
		
	}while(!feof(fp1));
	fclose(fp1);
	printf("The word %s counted %d times\n", word,counterword);
	return;



}
