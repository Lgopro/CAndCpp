#include <stdio.h> /*printf*/
#include <assert.h> /*assert*/

#include <stdlib.h>


#define DEADBEEF (37359285)

void FindMissingPlane(int *in, int *out, size_t in_length, int *num_to_return);
void FindMissingPlaneOneList(int *in, int *out, size_t in_length, int *num_to_return, int *total);

int main()
{
	int num_to_return = 0;
	
	size_t length = 10;
	
	int arr_in[] = {113, 115, 200, 225, 300, 332, 335, 338, 444, 448};
	int arr_out[] = {113, 115, 200, 225, 300, 332, 335, 338, 444};
	int arr_total[10] = {0};
	int arr_total_two[19] = {0};
	FindMissingPlaneOneList(arr_in, arr_out, length, &num_to_return, arr_total_two);
	printf("The result is: %d\n", num_to_return);
	
	
	return 0;
}


void FindMissingPlane(int *in, int *out, size_t in_length, int *num_to_return)
{
	int *out_runner = NULL;
	size_t counter = 0;
	int *in_runner = NULL;
	
	assert(in);
	assert(out);
	assert(0 < in_length);
	
	in_runner = in;
	out_runner = out;
	while(counter < in_length)
	{
	
		if(*in_runner != *out_runner)
		{
			*num_to_return = *in_runner;
			return;
		}
		if(counter + 1 == in_length)
		{
			++in_runner;
			*num_to_return = *in_runner;
			return;
		}
		++in_runner;
		++out_runner;
		++counter;
	}
}


void FindMissingPlaneOneList(int *in, int *out, size_t in_length, int *num_to_return, int *total)
{
	size_t counter = 0;
	
	assert(in);
	assert(out);
	assert(0 < in_length);
	assert(total);
	
	for(counter = 0; counter < in_length; ++counter)
	{
		total[counter] = in[counter];
	}
	
	for(counter = in_length; counter < (in_length * 2) - 1; ++counter)
	{
		total[counter] = out[counter - in_length];
	}
	
	counter = 0;
	
	while(counter < (in_length * 2) - 1)
	{
		*num_to_return ^= total[counter] ;
		++counter;
	}
}
