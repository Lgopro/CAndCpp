/*
Rev: Maria Ponomariov
Dev: Leonid Golovko
status: finished
date:24/03/23
*/

#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/

#define EXIT 27
#define CONTINUE 0
#define STOP 1
#define KEYT 'T'
#define KEYA 'A'
#define ASCIISIZE 256

static void IfElse(int run);
static void SwitchCase(int run);
static void LUT(int enter);
static size_t DontPrint();
static size_t PrintT();
static size_t PrintA();
static size_t Exit();
typedef size_t (*Print[ASCIISIZE])();

int main()
{	
	IfElse(0);
	SwitchCase(0);
	LUT(1);
	
	return 0;
}


static void IfElse(int run)
{
	char enter = '\0';
	system("stty -icanon -echo");
	if(1 == run)
	{
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
	}
	system("stty -icanon -echo");
}

static void SwitchCase(int run)
{
	char enter = 0;
	system("stty -icanon -echo");
	if(1 == run)
	{
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
	}
	system("stty -icanon -echo");
}


static void LUT(int run)
{
	size_t i = 0, flag = 0;
	char enter = 0;
	Print p;
	system("stty -icanon -echo");
	if(1 == run)
	{
		while(ASCIISIZE != i)
		{
			if(EXIT == i)
			{
				p[i] = &Exit;
			}
			else if(KEYA == i)
			{
				p[i] = &PrintA;
			}
			else if(KEYT == i)
			{
				p[i] = &PrintT;
			}
			else
			{
				p[i] = &DontPrint;
			}
			++i;	
		}
		do
		{		
			printf("Please enter a char: ");
			scanf(" %c", &enter);
			printf("\n");
			flag = (*p[(int)enter])();		
		}
		while(STOP != flag );
	}
	system("stty -icanon -echo");
}

static size_t DontPrint()
{
	return CONTINUE;
}	
static size_t PrintT()
{
	printf("T-pressed\n");
	return CONTINUE;
}
static size_t PrintA()
{
	printf("A-pressed\n");
	return CONTINUE;

}
static size_t Exit()
{
	return STOP;

}
