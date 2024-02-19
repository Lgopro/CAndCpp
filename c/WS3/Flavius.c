/*
Rev: Ido Peled
Dev: Leonid Golovko
status: finished
date:23/03/23
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*free*/
#define POINTALIVE 1

size_t Flavius(size_t num_of_soldiers);
void InitializeSoldiers(int *soldiers, size_t num_of_soldiers);
size_t Kill(int *soldiers, size_t num_of_soldiers);

int main()
{
	if(3 == Flavius(3) && 1 == Flavius(4) && 9 == Flavius(12) && 17 == Flavius(40)&& 41 == Flavius(52)&& 73 == Flavius(100) )
	{
	
		printf("Test Flavius pass\n");
	
	}
	return 0;
}

size_t Flavius(size_t num_of_soldiers)
{
	int *soldiers;
	
	size_t alive = 0;
	soldiers = (int *)malloc(sizeof(int) * num_of_soldiers + 2);
	InitializeSoldiers(soldiers, num_of_soldiers);
	alive = Kill(soldiers, num_of_soldiers);
	free(soldiers);
	return alive;
}	


void InitializeSoldiers(int *soldiers, size_t num_of_soldiers)
{
	size_t i = 0;
	while( num_of_soldiers - 1 != i)
	{
		soldiers[i] = i + 1;
		++i;
	}
	soldiers[i] = '\0';
}

size_t Kill(int *soldiers, size_t num_of_soldiers)
{
	size_t i = 0, next_kill = 0;
	while(num_of_soldiers != 1)
	{
		next_kill = soldiers[soldiers[i]];
		soldiers[i] = next_kill;
		--num_of_soldiers;
		i = next_kill;	
	}
	return next_kill + POINTALIVE; 



}
