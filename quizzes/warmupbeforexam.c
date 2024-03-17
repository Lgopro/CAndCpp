#include <stdio.h>
#include <assert.h>

#define MAX 100000

void Swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp; 
}

void BubleSort(int *arr, size_t size)
{
    size_t counter = 0;

    assert(arr);

    for(size_t i = 0; i < size; ++i)
    {
        counter = 0;

        for(size_t j = i + 1; j < size; ++j)
        {
            if(arr[i] > arr[j])
            {
                ++counter;
                Swap(&arr[i], &arr[j]);
            }
        }
        if(counter == 0)
        {
            return;
        }
    }
}

void SelectionSort(int *arr, size_t size)
{
    int min = MAX;
    int location = -1;

    assert(arr);

    for(size_t i = 0; i < size - 1; ++i)
    {
        location = -1;
        min = arr[i];
        for(size_t j = i + 1; j < size; ++j)
        {
            if(min > arr[j])
            {
                min = arr[j];
                location = j;
            }
        }
        if(location != -1)
        {
            Swap(&arr[i], &arr[location]);
        }
    }
}

int main()
{

    int arr[] = {1, 3, 2, -2, 6, 0, -5};

    /* BubleSort(arr, 7); */
    SelectionSort(arr, 7);
    for(size_t i = 0; i < 7; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}