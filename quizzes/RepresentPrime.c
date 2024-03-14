#include <stdio.h>



void RepresentPrime(unsigned int number)
{
    unsigned int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
                             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    unsigned int result[100] = {0};
    size_t counter = 0;

    while(number != 1)
    {   
        for(size_t i = 0; i < 25; ++i)
        {
            if(number % prime[i] == 0)
            {
                number /= prime[i];
                result[counter] = prime[i];
                ++counter;
                break;
            }
            if(number < prime[i])
            {
                printf("Cannot display\n");
                return;
            }
        }
    }
    for(size_t i = 0; i < counter; ++i)
    {
        if(i == 0)
        {
            printf("%d", result[i]);
        }
        else
        {
            printf("*%d", result[i]);
        }
    }
    printf("\n");
}   


int main()
{
    RepresentPrime(55);
    return 0;

}