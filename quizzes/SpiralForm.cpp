#include <iostream>
#include <cassert>

enum Direction
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2, 
    UP = 3, 
    AMOUNT = 4
};

void PrintInSpiral(int ** arr, int max_x, int max_y)
{
    assert(arr);
    int min_x = 0;
    int min_y = 0;
    int current_x = 0;
    int current_y = 0;
    int direction = RIGHT;
    int counter = max_x * max_y;
    

    while(counter != 0)
    {
        std::cout<< arr[current_y][current_x] << " ";
        if(current_x + 1 == max_x && direction == RIGHT)
        {
            direction = (direction + 1) % AMOUNT;
            ++min_y;
        }
        else if(current_y + 1 == max_y && direction == DOWN)
        {
            direction = (direction + 1) % AMOUNT;
            --max_x;
        }
        else if(current_x == min_x && direction == LEFT)
        {
            direction = (direction + 1) % AMOUNT;
            ++min_x;
        }
        else if(current_y == min_y && direction == UP)
        {
            direction = (direction + 1) % AMOUNT;
            --max_y;
        }

        if(direction == RIGHT)
        {
            ++current_x;
        }
        else if(direction == DOWN)
        {
            ++current_y;
        }
        else if(direction == LEFT)
        {
            --current_x;
        }
        else
        {
            --current_y;
        }
        --counter;
    }

}


int main()
{
    int number = 0;
    int **arr = (int **)malloc(sizeof(int *) * 4);
    for(int i = 0; i < 4; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int) * 5);
    }
    for(int y = 0; y < 4; ++y)
    {
        for(int x = 0; x < 4; ++x)
        {
            ++number;
            arr[y][x] = number;
        }
    }
    PrintInSpiral(arr, 4, 4);



    return 0;
}