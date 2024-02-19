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

size_t Bursa(int str1[], int *buy_index, int *sell_index, int length)
{
	/*int *begining = str1;
	int *end = str1 + 1;
	int counter = 1;
	int min = *begining;
	int max = *end;
	int profit = 0;
	++begining;
	++end;
	*buy_index = counter;
	*sell_index= counter + 1;
	while(counter != length - 2)
	{
		if(min > *begining && *buy_index < *sell_index)
		{
			min = *begining;
			*buy_index = counter;
		
		}
		if(max < *end && *buy_index < *sell_index)
		{
			max = *end;
			*sell_index = counter + 1;
		
		}
		if(*sell_index - *buy_index > profit)
		{
			profit = max - min;
		}
		++counter;
		++begining;
		++end;*/
	int min = MAX;
	int max = 0;
	int i = 0;
	while(i < length)
	{
		if(str1[i] < min && i > *sell_index)
		{
			min = str1[i];
			*buy_index = i;
		}
		if(str1[i] > max)
		{
			max = str1[i];
			*sell_index = i;
		}
		++i;
	}
	
	
	
	return (max - min);
}
