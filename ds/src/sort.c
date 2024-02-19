/*
Rev: Ido Issacs
Dev: Leonid Golovko
status: finished
date:31/05/23
*/


#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

#define MAX (2147483647)

#define SUCCESS (0)
#define FAIL (1)

#include "sort.h"
static void Swap(int *num1, int *num2);

static int RadixStaticSort(int *arr, int size, int divide);
static int MergeRec (int arr_to_sort[], size_t begin, size_t end);
static int MergePart(int arr_to_sort[], size_t begin, size_t mid, size_t end);
static size_t Partition(void *arr, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
static void GenericSwap(void *var1, void *var2, size_t size_of_element);

void BubbleSort(int *arr, size_t size)
{
	size_t i = 0;
	int flag = 1;
	
	assert(arr);
	assert(0 < size);
	
	while(0 != flag)
	{
		flag = 0;
		for(i = 0; i < size - 1 ; ++i)
		{
			if(*(arr + i) > *(arr + i + 1))
			{
				Swap((arr + i), (arr + i + 1));
				flag = 1;
			}
		}
	}
}



void InsertionSort(int *arr, size_t size)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;
	assert(arr);
	assert(0 < size);

	for(i = 1; (size_t)i < size; ++i)
	{
		temp = *(arr + i);		
		j = i - 1;
		
		while(j >= 0 && *(arr + j) > *(arr + i))
		{
			--j;
		}
			
		j++;
		
		for(k = i; k > j; --k)
		{
			*(arr + k) = *(arr + k - 1);

		}
		
		*(arr + j) = temp;
	}
}

void SelectionSort(int *arr, size_t size)
{
	size_t i = 0;
	size_t j = 1;
	size_t k = 0;
	int minimum = 0;
	
	assert(arr);
	assert(0 < size);

	for(i = 0; i < size; ++i)
	{
		minimum = MAX;
		
		for(j = i; j < size; ++j)
		{
			if(*(arr + j) < minimum)
			{
				minimum = *(arr + j);
				k = j;
			}
		}
		
		Swap((arr + i), (arr + k));
	}
}



int CountingSort(int *arr, size_t size)
{
	int *outputarr = NULL;
	int *countingarr = NULL;

	int i = 0;
	
	assert(arr);
	assert(0 < size);
	
	countingarr = calloc(sizeof(int), 101);
	if(NULL == countingarr)
	{
		return (FAIL);
	}
	
	outputarr = calloc(sizeof(int), size);
	if(NULL == outputarr)
	{
		free(countingarr);
		return (FAIL);
	}
	
	for(i = 0; i < (int)size; ++i)
	{
		++countingarr[arr[i]];
	}
	
	for(i = 1; i <= 100; ++i)
	{
		countingarr[i] += countingarr[i - 1];
	}
	
	
	for(i = size - 1; i >= 0; --i)
	{
		outputarr[countingarr[arr[i]] - 1] = arr[i];
		countingarr[arr[i]]--;
	}
	
	for(i = 0; i < (int)size; ++i)
	{
		arr[i] = outputarr[i];
		
	}
	
	free(outputarr);
	free(countingarr);
	
	return (SUCCESS);
}






static int RadixStaticSort(int *arr, int size, int divide)
{
	
	int *outputarr = NULL;
	int *countingarr = NULL;
	
	int i = 0;
	
	assert(arr);
	assert(0 < size);
	
	outputarr = calloc(sizeof(int), size);
	if(NULL == outputarr)
	{
		return (FAIL);
	}
	
	countingarr = calloc(sizeof(int), 10);
	if(NULL == countingarr)
	{
		free(outputarr);
		return (FAIL);
	}
	
	for(i = 0; i < size; ++i)
	{
		++countingarr[(arr[i] / divide) % 10];
	}
	
	for(i = 1; i < 10; ++i)
	{
		countingarr[i] += countingarr[i - 1];
	}
	
	
	for(i = size - 1; i >= 0; --i)
	{
		outputarr[countingarr[(arr[i] / divide) % 10] - 1] = arr[i];
		--countingarr[(arr[i] / divide) % 10];
	}
	
	
	for(i = 0; i < size; ++i)
	{
		arr[i] = outputarr[i];
	
	}
	
	free(outputarr);
	free(countingarr);
	
	return (SUCCESS);
}

int RadixSort(int *arr, size_t size)
{
	int divide = 1;
	int increase = 10;
	int i = 0;
	int status = 0;
	assert(arr);
	assert(0 < size);
	
	for(i = 0 ;i < 8; ++i)
	{
		status = RadixStaticSort(arr, size, divide);
		if(FAIL == status)
		{
			return (FAIL);
		}
		divide *= increase;	
	}
	return (SUCCESS);
}

int BinarySearch(int *arr, size_t size, int find)
{
	size_t begin_index = 0;
	size_t end_index = 0;
	size_t mid_index = 0;

	assert(arr);
	assert(0 < size);

	end_index = size - 1;

	if(arr[0] > find)
	{
		return -1;
	}
	if(arr[size - 1] < find)
	{
		return -1;
	}

	while(begin_index != end_index)
	{
		mid_index = (end_index + begin_index)/2;
		
		if(arr[mid_index] == find)
		{
			return (int)mid_index;
		}
		else if(arr[mid_index] > find)
		{
			end_index = mid_index;
		}
		else if(arr[mid_index] < find)
		{
			begin_index = mid_index;
		}

	}
	return -1;
}

int BinarySearchRecursive(int *arr, size_t begin, size_t end, int find)
{
	size_t mid_index = (begin + end)/2;
	int result = 0;
	assert(arr);

	if(begin == end)
	{
		return -1;
	}
	else if(arr[mid_index] == find)
	{
		return mid_index;
	}
	else if(arr[mid_index] > find)
	{
		result = BinarySearchRecursive(arr, begin, mid_index, find);
		return result;
	}
	else   
	{
		result = BinarySearchRecursive(arr, mid_index, end, find);
		return result;
	}
}


static void Swap(int *num1, int *num2)
{
	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


int MergeSort(int *arr_to_sort, size_t num_elements)
{
	assert(arr_to_sort);
	assert(0 < num_elements);

	return MergeRec (arr_to_sort, 0, num_elements - 1);
	

}


static int MergeRec (int arr_to_sort[], size_t begin, size_t end)
{
	size_t mid = 0;
	int result = 0;
	if(begin < end)
	{
		mid = (begin + end) / 2;
		result = MergeRec (arr_to_sort,begin, mid);
		if(1 == result)
		{
			return result;
		}
		result = MergeRec (arr_to_sort, mid + 1, end);
		if(1 == result)
		{
			return result;
		}
		result = MergePart(arr_to_sort, begin, mid , end);
	}
	return result;
}

static int MergePart(int arr_to_sort[], size_t begin, size_t mid, size_t end)
{
	size_t counter = 0;
	size_t i = 0;
	size_t j = 0;

	int *arr_begin = NULL;
	int *arr_end = NULL;

	size_t length_begin = mid - begin + 1;
	size_t length_end = end - mid;

	arr_begin = malloc(sizeof(int) * (length_begin));
	if (NULL == arr_begin)
	{
		return (FAIL);
	}

	arr_end = malloc(sizeof(int) * (length_end));
	if (NULL == arr_end)
	{
		free(arr_begin);
		return (FAIL);
	}

	for (i = 0; i < length_begin; ++i)
	{
		arr_begin[i] = arr_to_sort[begin + i];
	}

	for (j = 0; j < length_end; ++j)
	{
		arr_end[j] = arr_to_sort[mid + 1 + j];
	}

	i = 0;
	j = 0;

	while(i < length_begin && j < length_end)
	{
		if (arr_begin[i] <= arr_end[j])
		{
			arr_to_sort[begin + counter] = arr_begin[i];
			++i;
		}
		else
		{
			arr_to_sort[begin + counter] = arr_end[j];
			++j;
		}
		++counter;
	}

	while (i < length_begin) 
	{
        arr_to_sort[begin +counter] = arr_begin[i];
        ++i;
        ++counter;
    }
 
    while (j < length_end) 
	{
        arr_to_sort[begin +counter] = arr_end[j];
        ++j;
        ++counter;
    }

	free(arr_begin);
	free(arr_end);
	return (SUCCESS);
}


void QuicktRec(void *arr, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	char *pivot = 0;
	
	size_t pivot_num = 0;

	assert(NULL != arr);
	assert(NULL != compar);

	pivot = (char *)arr;

	if (1 >= nmemb)
	{
		return;
	}

	pivot_num = Partition(arr, nmemb, size, compar);
	QuicktRec(arr, pivot_num, size, compar);
	QuicktRec(&pivot[(pivot_num + 1) * size], nmemb - pivot_num - 1, size, compar);
}

static size_t Partition(void *arr, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	char *pivot = 0;
	char *begin = NULL;
	char *end = NULL;

	size_t left_nmemb = 1;

	assert(NULL != arr);
	assert(NULL != compar);

	pivot = (char *)arr;
	begin = (char *)arr + size;
	end  = (char *)arr + size * (nmemb - 1);

	
	while (begin != end)
	{
		if (0 < compar(begin, pivot))
		{
			GenericSwap(begin, end, size);
			end -= size;
		}
		else
		{
			begin += size;
			++left_nmemb;
		}
	}
	
	if (0 < compar(begin, pivot))
	{
		begin -= size;
		--left_nmemb;
	}
	GenericSwap(pivot, begin, size);

	return left_nmemb;
}

static void GenericSwap(void *var1, void *var2, size_t size_of_element)
{
	size_t i = 0;
	char temp = 0;
	assert(var1);
	assert(var2);
	assert(0 < size_of_element);
	while(i < size_of_element)
	{
		temp = *(((char *)var1) + i);
		*(((char *)var1) + i) = *(((char *)var2) +i);
		*(((char *)var2) +i) = temp;
		++i;
	}
}
