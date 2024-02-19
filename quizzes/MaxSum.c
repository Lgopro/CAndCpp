#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/

#define MAX 2147483647

size_t Bursa(int *str1, int *buy_index, int *sell_index, int length);

int main()
{
	int bursa[] = {8,6,2,7,1,10,22,15,16};
	int buy = 0, sell = 0, result = 0;
	result = Bursa(bursa, &buy, &sell, 9);
	printf("Profit is %d and the buy index is %d and the sell index is %d\n", result, buy, sell);
	
	return 0;
}

int MaxSum(int *arr, size_t sum, int *begin, int *end)
{
	
}
