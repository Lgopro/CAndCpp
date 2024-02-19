#include <stdio.h> /*printf*/



int IsSumFound(int *str,size_t length, int sum, int* first, int* last);

int main()
{
	int str[] = {1,5,7,11,15,17,19,22};
	int first = 0;
	int last = 0;
	int result = 0;
	result = IsSumFound(str,8, 24, &first, &last);
	printf("result is: %d first is: %d last is: %d\n", result, first, last);
	return 0;
}

int IsSumFound(int *str,size_t length, int sum, int* first, int* last)
{
	
	int *begin = str;
	int *end = str + length - 1;
	int index_begin = 0;
	int index_end = length - 1;
	while( begin != end)
	{
		if(sum == *begin + *end )
		{
			*first = index_begin;
			*last = index_end;
			return 1;
		}
		if(sum < *begin + *end)
		{
			--end;
			--index_end;
		}
		if(sum > *begin + *end)
		{
			++begin;
			++index_begin;
		}
	}
	return 0;


}
