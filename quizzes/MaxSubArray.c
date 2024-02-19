#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/

#define MAX 2147483647

int MaxSum(int *arr, size_t sum, int *begin, int *end);

int main()
{
	
	int arr[] = {-2, 1, -3, 4, -1, 2, 3, -5, 4};
	int begin = 0;
	int end = 0;
	int sum = 0;
	sum = MaxSum(arr, 9, &begin, &end);
	printf("The begining index is %d, the end index is %d and the max sum is %d\n", begin, end, sum);
	return 0;
}

int MaxSum(int *arr, size_t size, int *begin, int *end)
{
	size_t i = 0;
	int sum = 0;
	int first = 0;
	int last = 0;
	int sum_max = 0;
	int flag = 1;
	while(i < size)
	{
		if(0 < sum + arr[i] && 1 == flag)
		{
			first = i;
			last = i;
			flag = 0;
			sum += arr[i];
		}
		else if(0 < sum + arr[i] && sum_max < sum + arr[i] && 0 == flag)
		{
			last = i;
			sum += arr[i];
			sum_max = sum;
			*end = last;
			*begin = first;
		}
		else if(0 > sum + arr[i])
		{
			first = i + 1;
			last = i + 1;
			flag = 1;
			sum = 0;
		}
		else if(0 < sum + arr[i] && 0 == flag)
		{
			sum += arr[i];
		}
		++i;
	}
	return sum_max;
}
