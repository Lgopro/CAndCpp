#include <stdio.h>
#define BEGINNING 0
#define END 13
void HelloWorld();

int main()
{
	HelloWorld();
	return 0;

}



void HelloWorld()
{
	int Hello[] = {0x22,0x48, 0x65, 0x6C, 0x6C,0x6F, 0X20, 0x57, 0x6F, 0x72, 0x6C, 0x64, 0x22}, i;
	
	
	for(i = BEGINNING; i < END ; i++)
	{
		printf("%c", Hello[i]);
		
		
	}
	printf("\n");
	return;

}
