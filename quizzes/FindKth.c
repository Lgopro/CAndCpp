
#include <stddef.h> /* size_t */
#include <stdio.h>
#include <assert.h>

int cmpfunc( void * a, void * b) 
{
   return ( *(int*)a - *(int*)b );
}

static void GenericSwap(void *var1, void *var2, size_t size_of_element);
void *FindKthElement(char *arr, size_t length, size_t size_of_element, int (*compare)(void *, void *), size_t Kth_num, char *max_value);

int main()
{
	int arr[] = {4, 5, 1, 0, 3, 6, 7, 9, -5};
    int max = 2147483646;
    void *data = NULL;
    data = FindKthElement((char *)arr, 9, 4, cmpfunc, 3, (char *)&max);
	printf("The data is %d\n", *(int *)data);
	
	return 0;
}

void *FindKthElement(char *arr, size_t length, size_t size_of_element, int (*compare)(void *, void *), size_t Kth_num, char *max_value)
{
    size_t i = 0;
    size_t counter = 0;
    char *min = max_value;
    size_t index = 0;

    assert(arr);
	assert(compare);
    assert(max_value);

    for(counter = 0; counter < Kth_num; ++counter)
    {
        for(i = counter; i < length; ++i)
        {
            if(0 < compare(min, arr + i * size_of_element))
            {
                min = (arr + i * size_of_element);
                index = i;
            }
        }
        GenericSwap((arr + counter * size_of_element), (arr + index * size_of_element), size_of_element);
    }
    return (void *)(arr + (Kth_num - 1) * size_of_element);
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