#include <stdio.h> /*printf*/
#include <stdlib.h> /*system*/
#include <ctype.h>
#define NDEBUG
#include <assert.h>

#include <string.h>
#include <math.h>
void FindTwoMissingNumsInArray(int *str, int *str_result, size_t amount_of_numbers);
void FindTwoMissingNumsInArrayMath(int *str, int *str_result, size_t amount_of_numbers);



int main()
{
    int array[10] = {0};
    int result_array[2] = {0};
    int i = 0;
    for(i = 1; i <= 8; ++i)
    {
        array[i - 1] = i;
    }
    FindTwoMissingNumsInArray(array, result_array, 10);
    for(i = 0; i < 2; ++i)
    {
        printf("The numbers are %d\n", result_array[i]);
    }

    FindTwoMissingNumsInArrayMath(array, result_array, 10);
    for(i = 0; i < 2; ++i)
    {
        printf("The numbers are %d\n", result_array[i]);
    }
    return 0;
}


void FindTwoMissingNumsInArray(int *str, int *str_result, size_t amount_of_numbers)
{
    size_t counter = 0;
    size_t num_find = 1;
    size_t result_counter = 0;
    int result = amount_of_numbers * 8;

    assert(str);

    while(num_find <= amount_of_numbers)
    {
        counter = 0;
        result = amount_of_numbers * 2;
        while(counter <= amount_of_numbers - 2)
        {
            result *= *(str + counter)^num_find;
            
            ++counter;
        }
        if(0 != result)
        {
            str_result[result_counter] = num_find;
            ++result_counter;
        }
        ++num_find;
    }
}

void FindTwoMissingNumsInArrayMath(int *str, int *str_result, size_t amount_of_numbers)
{
    size_t sum_of_all_integers = 0;
    size_t sum_of_arr_integers = 0;
    size_t kefel_of_all_integers = 1;
    size_t kefel_of_arr_integers = 1;

    size_t sum_of_result_numbers = 0;
    size_t kefel_of_result_numbers = 0;

    size_t a = 0;
    size_t b = 0;
    size_t c = 0;
    size_t i = 0;

    assert(str);
    assert(str_result);
    
    for(i = 1; i <= amount_of_numbers; ++i)
    {
        sum_of_all_integers += i;
        kefel_of_all_integers *= i;
    }

    
    printf("sum_of_all_integers %ld\n", sum_of_all_integers);
    printf("kefel_of_all_integers %ld\n", kefel_of_all_integers);
    

    for(i = 0; i < amount_of_numbers - 2; ++i)
    {
        sum_of_arr_integers += str[i];
        kefel_of_arr_integers *= str[i];
    }
    
    printf("sum_of_arr_integers %ld\n", sum_of_arr_integers);
    printf("kefel_of_arr_integers %ld\n", kefel_of_arr_integers);
    

    sum_of_result_numbers = sum_of_all_integers - sum_of_arr_integers;
    kefel_of_result_numbers = kefel_of_all_integers / kefel_of_arr_integers;

    
    printf("sum_of_result_numbers %ld\n", sum_of_result_numbers);
    printf("kefel_of_result_numbers %ld\n", kefel_of_result_numbers);
    

    a = 1;
    b = -sum_of_result_numbers;
    c = kefel_of_result_numbers;

    str_result[0] = (int)(-b + sqrt(b * b - 4 * a * c))/2;
    str_result[1] = (int)(-b - sqrt(b * b - 4 * a * c))/2;

   
    printf("str_result[0] %d\n", str_result[0]);
    printf("str_result[1] %d\n", str_result[1]);
    
}

