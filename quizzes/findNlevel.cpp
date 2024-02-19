
#include <iostream>

void Count(size_t level, size_t *num_of_ways, size_t level_to_find);

int main()
{
    size_t num_of_ways = 0;

    Count(0, &num_of_ways, 4);

    std::cout << "Number of ways is: " << num_of_ways << std::endl;

    return 0;
}


void Count(size_t level, size_t *num_of_ways, size_t level_to_find)
{
    if(level == level_to_find)
    {
        ++(*num_of_ways);
        return;
    }
    if(level > level_to_find)
    {
        return;
    }

    Count(level + 1, num_of_ways, level_to_find);
    Count(level + 2, num_of_ways, level_to_find);
}