#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/

#define EXIT 27
#define CONTINUE 0
#define STOP 1
#define KEYT 'T'
#define KEYA 'A'
#define ASCIISIZE 256

static void LUT();
static size_t DontPrint();
static size_t PrintT();
static size_t PrintA();
static size_t Exit();
typedef size_t (*Print[ASCIISIZE])();

int main()
{	
	
	LUT();
	
	return 0;
}





static void LUT()
{
	size_t i = 0, flag = 0;
	char enter = 0;
	Print p;
	system("stty -icanon -echo");
	
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
	
	system("stty icanon echo");
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
