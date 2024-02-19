#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/

#define EXIT 27
#define CONTINUE 0
#define STOP 1
#define KEYT 'T'
#define KEYA 'A'

static void IfElse();

int main()
{	
	IfElse();
	
	return 0;
}


static void IfElse()
{
	char enter = '\0';
	system("stty -icanon -echo");
	
		do
		{
			printf("Please enter a char: ");
			scanf(" %c", &enter);
			printf("\n");
			if(KEYA == enter)
			{
				printf("A-pressed\n");
			}
			if(KEYT == enter)
			{
				printf("T-pressed\n");
			}
			
		}
		while(EXIT != enter);
	
	system("stty icanon echo");
}




