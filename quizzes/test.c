


#include <stdio.h>




void PrintBit(unsigned char x)
{
	int i=0;

	for(i=7;i>=0;--i)
	{
		if( x & (1<<i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		
		}
	}
	printf("\n");
}


unsigned char MirWithLoop(unsigned char x)    /*done*/
{

	int i = 0;
	int y = 0;
	int j = 7;
	
	for(i = 0; i <= 7; ++i)
	{
		if( x & (1 << i))
		{
			y^=(1 << j);
		}
		--j;
	}

	
	return y;
	
}



int main()
{
    unsigned char result = MirWithLoop(3);
    PrintBit(result);
    return 0;
}