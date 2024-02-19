#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fp;
int main()
{
	int i;
   fp=fopen("Myfirstfile1.txt","w");
   for(i=0;i<10;i++)
   {
   fprintf(fp,"line # %d\n", i+1);
   
   }
      fclose(fp);
      return 0;
   
}


