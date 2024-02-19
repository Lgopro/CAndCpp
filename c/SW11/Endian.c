#include <stdio.h> /*printf*/

#include "ItoaAtoi.h"


#define ISLITTLEINDIAN (*(unsigned short *)"\0\xff" > 0x0100)


void EndianTypeCheck();
void EndianMacroCheck();

int main()
{	
	EndianTypeCheck();
	EndianMacroCheck();
	
	return 0;
}


void EndianMacroCheck()
{
	if(ISLITTLEINDIAN)
	{
		printf ("Architecture is little endian. \n");
		printf ("Macro check pass. \n");
	}
	else
  	{
    	printf ("Architecture is big endian.\n");
    	printf ("Macro check fail. \n");
  	}

}



void EndianTypeCheck()
{
  unsigned int endian = 0x76543210;
  char *check = (char*) &endian;
 
  printf ("*check is: 0x%x\n", *check);
  if (*check == 0x10)
  {
    printf ("Architecture is little endian. \n");
    printf ("Type check pass. \n");
  }
  else
  {
     printf ("Architecture is big endian.\n");
     printf ("Type check fail. \n");
  }
}
