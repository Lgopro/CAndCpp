/* #include <stdio.h>

#define ROWS 5
#define COLS 5
#define WRONG_PLACE 1
#define ITS_ONE 2
#define ITS_ZERO 0
int FindIsland(int map[][COLS], int row, int col) 
{
    int valid1 = 0;
    int valid2 = 0;
    int valid3 = 0;
    int valid4 = 0;
    int valid5 = 0;
    int valid6 = 0;
    int valid7 = 0;
    int valid8 = 0;
    valid1 = CheckIfValid(map, row - 1, col); 
    valid2 = CheckIfValid(map, row - 1, col - 1); 
    valid3 = CheckIfValid(map, row, col - 1);
    valid4 = CheckIfValid(map, row -1, col + 1); 

    valid5 = CheckIfValid(map, row , col + 1); 
    valid6 = CheckIfValid(map, row + 1 , col + 1); 
    valid7 = CheckIfValid(map, row + 1,  col);
    valid8 = CheckIfValid(map, row + 1 , col - 1); 
    if(1 == valid5 && 1 == valid6 && 1 == valid7 && 1 == valid8)
    {
        if(1 ==  map[row][col])
        {
            return 0;
        }
    }
    else if(2 == valid1 || 2 == valid2 || 2 == valid3 || 2 == valid4)
    {
        return 1;
    }
    if((0 == row) && (2 == valid5 || 2 == valid6 || 2 == valid7 || 2 == valid8))
    {
        return 1;
    }
    return 0;
    
}
int CheckIfValid(int map[][COLS], int row, int col) 
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) 
    {
        return (WRONG_PLACE);
    }
    if(1 ==  map[row][col])
    {
        return (ITS_ONE);
    }
    return (ITS_ZERO);
}
int countIslands(int map[][COLS]) {
    int island = 0;
    int status = 0;
    int i = 0;
    int j = 0;
    for (i = ROWS - 1; -1 != i; i--) 
    {
        for (j = COLS - 1; -1 != j; j--) 
        {
            if (map[i][j] == 1) 
            { 
                status = FindIsland(map, i, j); 
                if(0 == status)
                {
                    ++island;
                }
            }
        }
    }

    return island;
}

int main() {
    int map[ROWS][COLS] = 
    {
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1}
    };

    int numOfIslands = countIslands(map);
    printf("Number of islands: %d\n", numOfIslands);

    return 0;
}
 */


#include <stdio.h>

#define ROWS 5
#define COLS 5

void FindIsland(int map[][COLS], int row, int col) 
{
    if (0 > row || row >= ROWS || 0 > col || col >= COLS || 0 == map[row][col] ) 
    {
        return;
    }

    map[row][col] = 0; 
    
    FindIsland(map, row - 1, col - 1); 
    FindIsland(map, row - 1, col);     
    FindIsland(map, row - 1, col + 1); 
    FindIsland(map, row, col - 1);     
    FindIsland(map, row, col + 1);     
    FindIsland(map, row + 1, col - 1); 
    FindIsland(map, row + 1, col);     
    FindIsland(map, row + 1, col + 1); 
}

int CountIslands(int map[][COLS]) 
{
    int island = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < ROWS; ++i) 
    {
        for (j = 0; j < COLS; ++j) 
        {
            if (1 == map[i][j] ) 
            { 
                ++island;
                FindIsland(map, i, j); 
            }
        }
    }

    return (island);
}

int main() {
    int map[ROWS][COLS] = {
        {1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 0, 1, 1}
    };

    int numOfIslands = CountIslands(map);
    printf("Number of islands: %d\n", numOfIslands);

    return 0;
}