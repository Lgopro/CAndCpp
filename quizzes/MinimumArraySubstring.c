
#include <stdio.h> /*printf*/
#include <string.h> /*strcmp*/
#include <stdlib.h> /*malloc*/
#include <assert.h>

#include "Stack.h"
#define FAIL (1)
#define SUCCESS (0)
#define FOUND (0)
#define MAX (1000000)
int SubString(char *big_str, char *sm_str, char * result);

int main()
{	
    char *big_str = NULL;
    char *sm_str = NULL;
    char *result = NULL;
    big_str = (char *)malloc(25);
    sm_str = (char *)malloc(5);
    result = (char *)malloc(26);
    
    strcpy(big_str, "hello bro please woke");
    strcpy(sm_str, "eo");

    SubString(big_str, sm_str, result);
    if(result == NULL)
    {
        printf("Im NULL\n");
    }
    else
    {
        printf("%s\n", result);
    }
    

    free(big_str);
    free(sm_str);
    free(result);

	return 0;
}

size_t FindMin(size_t *help_arr_counter, size_t size)
{
    size_t i = 0;
    size_t min = MAX;
    for(i = 0;i < size; ++i)
    {
        if(min > help_arr_counter[i])
        {
            min = help_arr_counter[i];
        }
    }
    return min;
}

size_t FindMax(size_t *help_arr_counter, size_t size)
{
    size_t i = 0;
    size_t max = 0;
    for(i = 0;i < size; ++i)
    {
        if(max <= help_arr_counter[i])
        {
            max = help_arr_counter[i];
        }
    }
    return max;
}

int SubString(char *big_str, char *sm_str, char * result)
{
    size_t i = 0;
    size_t j = 0;
    size_t counter = 0;
    size_t min = 0;
    size_t max = 0;
    size_t return_min = 0;
    size_t return_max = 0;
    size_t *help_arr_counter = NULL;
    size_t begin = 0;
    size_t k = 0;
    size_t big_str_size = 0;
    size_t sm_str_size = 0;
 
    assert(big_str);
    assert(sm_str);
    assert(result);
   
    return_max = strlen(big_str);
    big_str_size = strlen(big_str);
    sm_str_size = strlen(sm_str);

    help_arr_counter = (size_t *)calloc(sm_str_size, sizeof(size_t));
    if(NULL == help_arr_counter)
    {
        strcpy(result, "Did not find");
        return (FAIL);
    }

    for(i = 0; i < sm_str_size; ++i)
    {
        begin = 0;
        for(k = 0; k < i; ++k)
        {
            if(sm_str[i] == sm_str[k])
            {
                begin = help_arr_counter[i] + 1;
            }
        }
        
        for(j = begin; j < big_str_size; ++j)
        {
            if(sm_str[i] == big_str[j])
            {
                help_arr_counter[i] = j;
                ++counter;
                break;
            }
        }
    }
   
    if(counter != sm_str_size)
    {
        free(help_arr_counter);
        strcpy(result, "Did not find");
        return (FAIL);
    }

    while(FOUND != counter)
    {
        counter = 0;
        min = FindMin(help_arr_counter, sm_str_size);
        max = FindMax(help_arr_counter, sm_str_size);
        
        if(return_max - return_min > max - min)
        {
            return_max = max;
            return_min = min;
        }
        for(i = 0;i < sm_str_size; ++i)
        {
            if(min == help_arr_counter[i])
            {
                for(j = help_arr_counter[i] + 1; j < big_str_size; ++j)
                {
                    if(sm_str[i] == big_str[j])
                    {
                        ++counter;
                        help_arr_counter[i] = j;    
                        break;   
                    }
                }  
                break;
            }
        }
    }

    free(help_arr_counter);
    strncpy(result, big_str + return_min, return_max - return_min + 1);
    result[return_max - return_min + 1] = '\0';
    return (SUCCESS);
}