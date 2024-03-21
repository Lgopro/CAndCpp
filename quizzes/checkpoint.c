
#define FAIL -1

struct customer 
{
	unsigned int arrival_time;
	unsigned int prepare_time;
}


double average_wait_time(struct customer* customers, int len)
{
    unsigned int aver_prepare_time = 0;
    unsigned int more_wait = 0;

    assert(customers);

    for(int i = 0; i < len; ++i)
    {
        aver_prepare_time += customers[i].prepare_time;
    }

    for(int current = 0; current < len - 1; ++current)
    {
        for(int next = current + 1; next < len; ++next)
        {
            if(customers[current].arrival_time + customers[current].prepare_time + more_wait
               < customers[next].arrival_time)
            {
                break;
            }
            else
            {
                more_wait += customers[current].arrival_time + customers[current].prepare_time
                - customers[next].arrival_time;
            }
        }
    }
    return (((double)aver_prepare_time + (double)more_wait) / (double)len);
}



double average_wait_time(struct customer* customers, int len)
{
    unsigned int aver_prepare_time = 0;
    unsigned int more_wait = 0;

    int current = 0;
    int next = 1;

    assert(customers);

    for(int i = 0; i < len; ++i)
    {
        aver_prepare_time += customers[i].prepare_time;
    }

    unsigned int *custumer_arr_and_prepare = (unsigned int *)malloc(sizeof(unsigned int) * len);
    if(custumer_arr_and_prepare == NULL)
    {
        return FAIL;
    }

    for(int i = 0; i < len; ++i)
    {
        custumer_arr_and_prepare[i] = customers[i].arrival_time + customers[i].prepare_time ;
    }

    while(next != len)
    {
        if(customers[next].arrival_time < custumer_arr_and_prepare[current])
        {
            more_wait += custumer_arr_and_prepare[current] - customers[next].arrival_time;
            ++next;
        }
        else
        {
            ++current;
        }
    }
    free(custumer_arr_and_prepare);

    return (((double)aver_prepare_time + (double)more_wait) / (double)len);
}


nt

MysteryFunction(char *s)
{
    int number_of_repeat = 0;
    int max = 0;
    int LUT[256] = {[0 ... 255] = -1};
    int i;
    int len = strlen(s);

    for (i = 0; i < len; i++) 
    {
        if (LUT[s[i]] >= number_of_repeat) 
        {
            if (i - number_of_repeat > max) 
            {
				max = i - number_of_repeat;
			}

            number_of_repeat = LUT[s[i]] + 1;
        }
        LUT[s[i]] = i;
    }
    if(i - number_of_repeat > max) 
    {
		max = i - number_of_repeat;
	}
    return max;
}


1, 2, 6, 8, 10, 12
12, 1, 2, 6, 8, 10



int FindIndexRotatedArray(int *arr, size_t size, int number)
{
    int result = 1;
    assert(arr);

    for(size_t i = 0; i < size; ++i)
    {
        result *= arr[i] ^ number;
    }

    return result;
}


#define NOT_FOUND -1

int FindIndexRotatedArray(int *arr, size_t size, int number)
{
    size_t min = 0;
    size_t max = 0;
    size_t mid = 0;

    assert(arr);

    
    while(mid != min || mid != max)
    {
        if(number < arr[mid])
        {
            max = mid;
            mid = (min + max) / 2;
        }
        else if(number > arr[mid])
        {
            min = mid;
            mid = (min + max) / 2;
        }
        else
        {
            return mid;
        }
    }

    return NOT_FOUND;
}