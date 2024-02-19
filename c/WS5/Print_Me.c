#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/

#define AMOUNT 10


void Print(int num);
typedef void (*print_t)(int);

typedef struct print_me_t
{
	int num;
	print_t pt;

} print_me;

int main()
{	
	size_t i = 0;
	int number = 0;
	print_me arr[AMOUNT];
	while(AMOUNT != i)
	{
		number = rand() % 100;
		arr[i].num = number;
		arr[i].pt = Print;
		arr[i].pt(arr[i].num);
		++i;
	}
	
	
	return 0;
}





void Print(int num)
{
	printf("The number is: %d\n", num);
}
