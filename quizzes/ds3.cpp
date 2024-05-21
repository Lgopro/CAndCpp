

#include <iostream>
#include <cassert>

const int ERROR = -1;
const int TRUE = 1;
const int FALSE = 0;


void circularNmove(int *arr, size_t size, size_t move)
{
    assert(arr);

    move %= size;
    if(move == 0)
    {
        return;
    }

    size_t counter = 0;
    size_t current_loc = 0;
    size_t next_loc = move;
    int temp1 = arr[next_loc];
    int temp2 = arr[current_loc];

    while(counter != size)
    {
        temp1 = arr[next_loc];
        arr[next_loc] = temp2;

        current_loc = (current_loc + move) % size;
        next_loc = (next_loc + move) % size;
        temp2 = temp1;
        ++counter;
    }
}

void RemoveIsland(int **arr, int y, int x, int max_y, int max_x)
{
    if(y == max_y || y < 0)
    {
        return;
    }

    if(x == max_x || x < 0)
    {
        return;
    }

    arr[y][x] = 0;

    if(y == 0)
    {
        if(arr[y + 1][x] == 0 &&
    arr[y - 1][x] == 0 &&
    arr[y][x + 1] == 0 &&
    arr[y][x -1] == 0 &&
    arr[y][x] == 0 &&
    arr[y][x] == 0 &&
    arr[y][x] == 0 && 
    arr[y][x] == 0)
    }

    if(arr[y + 1][x] == 0 &&
    arr[y - 1][x] == 0 &&
    arr[y][x + 1] == 0 &&
    arr[y][x -1] == 0 &&
    arr[y][x] == 0 &&
    arr[y][x] == 0 &&
    arr[y][x] == 0 && 
    arr[y][x] == 0)
    {
        return;
    }

    RemoveIsland(arr, y - 1, x, max_y, max_x);
    RemoveIsland(arr, y + 1, x, max_y, max_x);
    RemoveIsland(arr, y, x - 1, max_y, max_x);
    RemoveIsland(arr, y, x + 1, max_y, max_x);
    RemoveIsland(arr, y - 1, x - 1, max_y, max_x);
    RemoveIsland(arr, y - 1, x + 1, max_y, max_x);
    RemoveIsland(arr, y + 1, x - 1, max_y, max_x);
    RemoveIsland(arr, y + 1, x + 1, max_y, max_x);

    
}

int CountIslands(int **arr, size_t y, size_t x)
{
    int counter = 0;

    if(arr == NULL)
    {
        return ERROR;
    }

    for(size_t i = 0 ; i < y; ++i)
    {
        for(size_t j = 0; j < x; ++j)
        {
            if(arr[i][j] == 1)
            {
                ++counter;
                RemoveIsland(arr, i, j, y, x);
            }
        }
    }

    return counter;
}

void Exer5()
{
    int **arr = (int **)malloc(sizeof(int *) * 8);
    for(size_t i = 0; i < 8; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int) * 8);
    }

    for(size_t i = 0; i < 8; ++i)
    {
        for(size_t j = 0; j < 8; ++j)
        {
            arr[i][j] = 0;
        }
    }

    arr[1][1] = 1;
    arr[1][2] = 1;

    arr[5][5] = 1;
    arr[4][5] = 1;

    arr[7][7] = 1;
    arr[7][6] = 1;

    CountIslands(arr, 8, 8);
}

void Exer4()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    circularNmove(arr, sizeof(arr)/sizeof(int), 3);

    for(size_t i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    Exer4();


    return 0;
}