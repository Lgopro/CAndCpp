
#include <stdio.h>

unsigned int solution(unsigned int number) 
{
    unsigned int max_gap = 0;
    unsigned int current_gap = 0;
    size_t counter = 0;

    for(size_t i = 0; i < 32; ++i)
    {
        if((current_gap > max_gap) && (number & 1 << i) && counter != 0)
        {
            max_gap = current_gap;
        }

        if(number & 1 << i)
        {
            current_gap = 0;
            ++counter;
        }
        else
        {
            ++current_gap;
        }

        
    }

    if(counter <= 1)
    {
        return 0;
    }

    return max_gap;
}