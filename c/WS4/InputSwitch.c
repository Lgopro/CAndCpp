#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/

#define EXIT 27
#define CONTINUE 0
#define STOP 1
#define KEYT 'T'
#define KEYA 'A'


static void SwitchCase();



int main()
{	
	
	SwitchCase();

	
	return 0;
}



static void SwitchCase()
{
	char enter = 0;
	system("stty -icanon -echo");
	
		do
		{	
			printf("Please enter a char: ");
			scanf(" %c", &enter);
			printf("\n");
			switch(enter)
			{
				case KEYA:
				{
					printf("A-pressed\n");
					break;
				}
				case KEYT:
				{
					printf("T-pressed\n");
					break;
				}
				default:
				{
					break;
				}
			}
			
		}
		while(EXIT != enter);
	
	system("stty icanon echo");
}

