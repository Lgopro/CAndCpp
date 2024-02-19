/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: finished
date: 02/07/2023
*/
#define _XOPEN_SOURCE 500
#include <stdio.h> /*printf*/
#include <stdlib.h> /*usleep*/
#include <unistd.h> /*usleep*/
#include <pthread.h> /*pthread_create*/




#define _BSD_SOURCE

#define AMOUNT_OF_THREADS (100000)
#define AMOUNT_OF_LEGAL_THREADS (15)
int arr[AMOUNT_OF_THREADS];
size_t global_arr[AMOUNT_OF_LEGAL_THREADS];
size_t sumforex4 = 0;
pthread_mutex_t mutex = {0}; /*changed*/

typedef struct data
{
    size_t number;
    size_t index;
}data_t;

void *ArrChange(void *data)
{
    size_t index = (size_t )data;
    arr[index] = index;
    pthread_exit(NULL);
}

void *CheckSum(void *data)
{
    
    size_t max_num = ((data_t *)data)->number;
    size_t i = ((data_t *)data)->index ;
    size_t index = i * (max_num / AMOUNT_OF_LEGAL_THREADS) + 1;
    
    size_t end = (i + 1) * (max_num / AMOUNT_OF_LEGAL_THREADS) + 1;
    pthread_mutex_init(&mutex, NULL);
    if(max_num <= end)
    {
        end = max_num - 1;
    }
    

    for(index = index; index <= end; ++index)
    {
        if(0 == max_num % index)
        {
            global_arr[i] += index; 
        }
    }
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}

int Check100kThreads(void);
int SumOfDivisors(size_t number);
int SumOfDivisors1Thread(size_t number);
int SumOfDivisors1ThreadEx6(size_t number);

int main()
{
    size_t num = 3100000000;
    /*Check100kThreads();*/
    SumOfDivisors(num);
    printf("1 thread\n");
    SumOfDivisors1Thread(num);
    printf("6 ex thread\n");
    SumOfDivisors1ThreadEx6(num);
    return 0;
}


int Check100kThreads(void)
{
    size_t i = 0;
    size_t j = 0;
    int return_value = 0;
    int return_join = 0;
    pthread_t threads[AMOUNT_OF_THREADS];
    time_t begin;
    time_t end;
    
    begin = time(NULL);
    for (i = 0; i < AMOUNT_OF_THREADS; ++i)
    {
        return_value = pthread_create(&threads[i], NULL, ArrChange, (void *)i); 
        while(0 != return_value)
        {
            for (j = 0; j < i; ++j)
            {  
                return_join = pthread_join(threads[j], NULL);
                if(0 == return_join) 
                {
                    break;
                }

            }
            return_value = pthread_create(&threads[j], NULL, ArrChange, (void *)i);
            if(0 == return_value)
            {
                pthread_detach(threads[j]);
            }
        }
        pthread_detach(threads[i]);
    }
    

    sleep(10);

    end = time(NULL);
    
    for (i = 0; i < AMOUNT_OF_THREADS; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\nAmount of time passed is: %f\n", difftime(end, begin));

    printf("\n");

    return 0;
}


int SumOfDivisors(size_t number)
{
    size_t i = 0;
    int return_value = 0;
    int return_join = 0;
    pthread_t threads[AMOUNT_OF_THREADS];
    size_t thread_amount = AMOUNT_OF_LEGAL_THREADS;
    data_t send_data = {0};
    time_t begin;
    time_t end;
    size_t sum = 0;
    struct timespec var, var2 = {0, 450000000000};
    send_data.number = number;
    
    

    begin = time(NULL);
    pthread_mutex_init(&mutex, NULL);
    while(i < thread_amount)
    {
        
        send_data.index = i;
        
        return_value = pthread_create(&threads[i], NULL, CheckSum, (void *)&send_data); 
        if(0 != return_value)
        {
            printf("pthread_create fail\n");
        }
        ++i;
        nanosleep(&var, &var2);
        usleep(450);
        
    }

    
    for (i = 0; i < thread_amount; ++i)
    {  
        return_join = pthread_join(threads[i], NULL);
        if(0 != return_join)
        {
            printf("pthread_join fail\n");
        }
    }
    
    for (i = 0; i < thread_amount; ++i)
    {  
        sum += global_arr[i];
    }
    pthread_mutex_destroy(&mutex);
    end = time(NULL);
    printf("The sum is %ld\n", sum);
    printf("\nAmount of time passed is: %f\n", difftime(end, begin));

    return 0;
}



int SumOfDivisors1ThreadEx6(size_t number)
{
    size_t i = 0;
    size_t sum = 0;
    time_t begin;
    time_t end;
    begin = time(NULL);

    #pragma omp parallel for
    for(i = 1; i < number; ++i)
    {
        if(0 == number % i)
        {
           sum += i;
        }
    }

    end = time(NULL);

    printf("The sum is %ld\n", sum);
    printf("\nAmount of time passed is: %f\n", difftime(end, begin));
    return 0;
}




int SumOfDivisors1Thread(size_t number)
{
    size_t i = 0;
    size_t sum = 0;
    time_t begin;
    time_t end;
    begin = time(NULL);

    for(i = 1; i < number; ++i)
    {
        if(0 == number % i)
        {
           sum += i;
        }
    }

    end = time(NULL);

    printf("The sum is %ld\n", sum);
    printf("\nAmount of time passed is: %f\n", difftime(end, begin));
    return 0;
}


