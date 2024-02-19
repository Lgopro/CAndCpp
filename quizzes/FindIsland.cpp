
#include <iostream>

const int RIGHT = 1;
const int LEFT = -1;

void RemoveIsland(int location[][4], int current_length, int current_height, int max_length, int max_height )
{
    if(current_height < 0 || current_height == max_height || current_length < 0 || current_length == max_length)
    {
        return;
    }
    if(0 == location[current_length][current_height])
    {
        return;
    }
    if(1 == location[current_length][current_height])
    {
        location[current_length][current_height] = 0;
        RemoveIsland(location, current_length + RIGHT, current_height, max_length, max_height);
        RemoveIsland(location, current_length + LEFT, current_height, max_length, max_height);
        RemoveIsland(location, current_length, current_height + RIGHT, max_length, max_height);
        RemoveIsland(location, current_length, current_height + LEFT, max_length, max_height);
        RemoveIsland(location, current_length + RIGHT, current_height + RIGHT, max_length, max_height);
        RemoveIsland(location, current_length + RIGHT, current_height + LEFT, max_length, max_height);
        RemoveIsland(location, current_length + LEFT, current_height + RIGHT, max_length, max_height);
        RemoveIsland(location, current_length + LEFT, current_height + LEFT, max_length, max_height);
    }
}


size_t FindIslands(int arr[][4], int length, int height)
{
    size_t island_counter = 0;
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            if(1 == arr[i][j])
            {
                ++island_counter;
                RemoveIsland(arr, i ,j ,length ,height);
            }
        }
    }
    return island_counter;
}


int main()
{
    int arr[][4] = {0};

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[3][3] = 1;
    arr[3][2] = 1;
    

    size_t result = FindIslands(arr, 4, 4);
    std::cout << "The island counter is " << result << std::endl;

    return 0;
}