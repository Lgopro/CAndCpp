/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: Approved
date: 26/06/2023
*/


#include <assert.h> /*assert*/
#include <time.h> /*clock*/

#define NUMBER_OF_BITS 8
#define AMOUNT_OF_ACTIONS 8
#define AMOUNT_OF_SQUERES (BOARD_HEIGHT * BOARD_HEIGHT)
#define MOVE_IS_LEGAL 0
#define MOVE_IS_NOT_LEGAL 1
#define BOARD_HEIGHT 8
#define NO_ELEMENT_FOUND 0
#define THERE_IS_AN_ELEMENT 1
#define WRONG_VALUE 100

#include "knighttour.h"

static void InitiateLoot(unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);
static size_t XandYToIndex(size_t x_value, size_t y_value);
static void IndexToXandY(size_t index, size_t *x_value, size_t *y_value);

static int CheckIfIndexisLegal(unsigned char column, unsigned char row);

static status_t KnightsTourBruteForce(unsigned char column, unsigned char row,
                                      unsigned int timeout_in_sec, unsigned char *path,
                                      unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);

static status_t FindKnightMoves(unsigned char column, unsigned char row, unsigned int timeout_in_sec,unsigned char *path,
                                bitarr_t *board , size_t jump_amount, time_t timeout, 
                                unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);

static int CheckIfMoveisLegal(bitarr_t *board, unsigned char column, unsigned char row);

static status_t KnightsTourWarnsdorfAlgorithm(unsigned char column, unsigned char row, 
                                              unsigned int timeout_in_sec, unsigned char *path,
                                              unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);

static status_t FindKnightMovesWarnsdorfAlgorithm(unsigned char column, unsigned char row, unsigned int timeout_in_sec,unsigned char *path,
                                bitarr_t *board , size_t jump_amount, time_t timeout, 
                                unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);


static size_t FindMinIndex(char amount_of_moves[AMOUNT_OF_ACTIONS]);

static size_t CheckAmountofMovespossible(unsigned char column, unsigned char row, 
                                         size_t *board, unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);
static void InitiateLoot(unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS]);

typedef bitarr_t board_t;

status_t KnightsTour(unsigned char column, unsigned char row, unsigned int timeout_in_sec, 
								  is_heuristic_t status, unsigned char *path)
{
    
    unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS] = {0};

    assert(path);

    InitiateLoot(LUT);

    if(FALSE == status)
    {
        return KnightsTourBruteForce(column, row, timeout_in_sec, path, LUT);
    }
   
    return KnightsTourWarnsdorfAlgorithm(column, row, timeout_in_sec, path, LUT);
}

static status_t KnightsTourBruteForce(unsigned char column, unsigned char row,
                                      unsigned int timeout_in_sec, unsigned char *path
                                      , unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    bitarr_t board = 0;
    time_t start_time;

    time(&start_time);

    if(MOVE_IS_LEGAL == CheckIfMoveisLegal(&board, column, row))
    {
        board = BitArrSetOn(board, column + row * BOARD_HEIGHT);
        *(path) = column + row * BOARD_HEIGHT;
    }
    else
    {
        return (KNIGHT_TOUR_NOT_FOUND);
    }
    return FindKnightMoves(column, row, timeout_in_sec, path , &board, 1, start_time, LUT);

}

static status_t FindKnightMoves(unsigned char column, unsigned char row, unsigned int timeout_in_sec,unsigned char *path,
                                bitarr_t *board , size_t jump_amount, time_t timeout, 
                                unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    size_t i = 0;
    size_t next_x_value = 0;
    size_t next_y_value = 0;
    size_t new_index = 0;
    status_t status = KNIGHT_TOUR_SUCCESS;

    if(difftime(time(NULL), timeout) >= timeout_in_sec)
    {
        return (KNIGHT_TOUR_TIME_OUT);
    }

    if(AMOUNT_OF_SQUERES == jump_amount)
    {
        return (KNIGHT_TOUR_SUCCESS);
    }

    for(i = 0; i < AMOUNT_OF_ACTIONS; ++i)
    {
        new_index = LUT[XandYToIndex(column, row)][i];
        IndexToXandY(new_index, &next_x_value, &next_y_value);

        if(MOVE_IS_LEGAL == CheckIfMoveisLegal(board, next_x_value, next_y_value))
        {
            *board = BitArrSetOn(*board, next_x_value + next_y_value * BOARD_HEIGHT);
            *(path + jump_amount) = next_x_value + next_y_value * BOARD_HEIGHT;

            status = FindKnightMoves(next_x_value, next_y_value, timeout_in_sec, path , board, 
                                     jump_amount + 1, timeout, LUT);

            if(KNIGHT_TOUR_NOT_FOUND == status)
            {
                *board = BitArrSetOff(*board, next_x_value + next_y_value * BOARD_HEIGHT);
            }
            else
            {
                return (status);
            }
        }
        
    }

    return (KNIGHT_TOUR_NOT_FOUND);
}

static int CheckIfMoveisLegal(bitarr_t *board, unsigned char column, unsigned char row)
{
    if(((BOARD_HEIGHT - 1 >= column) && (BOARD_HEIGHT - 1 >= row)) && 1 != BitArrGetVal(*board, (column + row * BOARD_HEIGHT)))
    {
        return (MOVE_IS_LEGAL);
    }
    return (MOVE_IS_NOT_LEGAL);
}



static status_t KnightsTourWarnsdorfAlgorithm(unsigned char column, unsigned char row, 
                                              unsigned int timeout_in_sec, unsigned char *path, 
                                              unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    bitarr_t board = 0;
    time_t start_time;

    time(&start_time);


    if(MOVE_IS_LEGAL == CheckIfMoveisLegal(&board, column, row))
    {
        board = BitArrSetOn(board, column + row * BOARD_HEIGHT);
        *(path) = column + row * BOARD_HEIGHT;
    }
    else
    {
        return (KNIGHT_TOUR_NOT_FOUND);
    }

    return FindKnightMovesWarnsdorfAlgorithm(column, row, timeout_in_sec, path , &board, 1, start_time, LUT);

}




static status_t FindKnightMovesWarnsdorfAlgorithm(unsigned char column, unsigned char row, unsigned int timeout_in_sec,unsigned char *path,
                                bitarr_t *board , size_t jump_amount, time_t timeout, 
                                unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    size_t i = 0;
    size_t next_x_value = 0;
    size_t next_y_value = 0;
    size_t find_min_index = 0;
    size_t flag = 0;
    size_t new_index = 0;

    char amount_of_moves[AMOUNT_OF_ACTIONS] = {AMOUNT_OF_ACTIONS};

    if(difftime(time(NULL), timeout) >= timeout_in_sec)
    {
        return (KNIGHT_TOUR_TIME_OUT);
    }

    if(AMOUNT_OF_SQUERES == jump_amount)
    {
        return (KNIGHT_TOUR_SUCCESS);
    }

    for(i = 0; i < AMOUNT_OF_ACTIONS; ++i)
    {
        new_index = LUT[XandYToIndex(column, row)][i];
        IndexToXandY(new_index, &next_x_value, &next_y_value);

        if(MOVE_IS_LEGAL == CheckIfMoveisLegal(board, next_x_value, next_y_value))
        {
            flag = THERE_IS_AN_ELEMENT;
            amount_of_moves[i] = CheckAmountofMovespossible(next_x_value, next_y_value, board, LUT);
        }
        else
        {
            amount_of_moves[i] = BOARD_HEIGHT + 1;
        }
    }

    if(NO_ELEMENT_FOUND == flag)
    {
        return (KNIGHT_TOUR_NOT_FOUND);
    }

    find_min_index = FindMinIndex(amount_of_moves);

    new_index = LUT[XandYToIndex(column, row)][find_min_index];
    IndexToXandY(new_index, &next_x_value, &next_y_value);

    *board = BitArrSetOn(*board, next_x_value + next_y_value * BOARD_HEIGHT);
    *(path + jump_amount) = next_x_value + next_y_value * BOARD_HEIGHT;

    if(KNIGHT_TOUR_SUCCESS == FindKnightMovesWarnsdorfAlgorithm(next_x_value, next_y_value, timeout_in_sec, path , board,
                                                                jump_amount + 1, timeout, LUT))
    {
        return (KNIGHT_TOUR_SUCCESS);
    }

    return (KNIGHT_TOUR_NOT_FOUND);
}



static size_t FindMinIndex(char amount_of_moves[AMOUNT_OF_ACTIONS])
{
    size_t min = 9;
    size_t i = 0;
    size_t index = 0;
    for(i = 0; i < AMOUNT_OF_ACTIONS; ++i)
    {
        if(min > (size_t)amount_of_moves[i])
        {
            min = (size_t)amount_of_moves[i];
            index = i;
        }
    }
    return (index);
}

static size_t CheckAmountofMovespossible(unsigned char column, unsigned char row, 
                                         size_t *board, unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    size_t counter = 0;
    size_t next_x_value = 0;
    size_t next_y_value = 0;
    size_t i = 0;
    size_t new_index = 0;

    for(i = 0; i < AMOUNT_OF_ACTIONS; ++i)
    {
        
        new_index = LUT[XandYToIndex(column, row)][i];
        IndexToXandY(new_index, &next_x_value, &next_y_value);
        if(MOVE_IS_LEGAL == CheckIfMoveisLegal(board, next_x_value, next_y_value))
        {
            ++counter;
        }
    }
    return (counter);

}

static int CheckIfIndexisLegal(unsigned char column, unsigned char row)
{
    if(((BOARD_HEIGHT - 1 >= column) && (BOARD_HEIGHT - 1 >= row)))
    {
        return (MOVE_IS_LEGAL);
    }
    return (MOVE_IS_NOT_LEGAL);
}

static void IndexToXandY(size_t index, size_t *x_value, size_t *y_value)
{
    *y_value = index / BOARD_HEIGHT;
    *x_value = index % BOARD_HEIGHT;
}

static size_t XandYToIndex(size_t x_value, size_t y_value)
{
    return(x_value + y_value * BOARD_HEIGHT);
}

static void InitiateLoot(unsigned char LUT[AMOUNT_OF_SQUERES][AMOUNT_OF_ACTIONS])
{
    size_t i = 0;

    size_t x_value = 0;
    size_t y_value = 0;

    for (i = 0; i < AMOUNT_OF_SQUERES; ++i)
    {
        IndexToXandY(i, &x_value, &y_value);

        
        if (CheckIfIndexisLegal(x_value + 2, y_value + 1))
        {
            LUT[i][0] = WRONG_VALUE;
        }
        else
        {
            LUT[i][0] = x_value + 2 + BOARD_HEIGHT * (y_value + 1);
        }
        
        if (CheckIfIndexisLegal(x_value + 1, y_value + 2))
        {
            LUT[i][1] = WRONG_VALUE;
        }
        else
        {
            LUT[i][1] = x_value + 1 + BOARD_HEIGHT * (y_value + 2);
        }
        
        if (CheckIfIndexisLegal(x_value - 1, y_value + 2))
        {
            LUT[i][2] = WRONG_VALUE;
        }
        else
        {
            LUT[i][2] = x_value - 1 + BOARD_HEIGHT * (y_value + 2);
        }
        
        if (CheckIfIndexisLegal(x_value - 2, y_value + 1))
        {
            LUT[i][3] = WRONG_VALUE;
        }
        else
        {
            LUT[i][3] = x_value - 2 + BOARD_HEIGHT * (y_value + 1);
        }
       
        if (CheckIfIndexisLegal(x_value - 2, y_value - 1))
        {
            LUT[i][4] = WRONG_VALUE;
        }
        else
        {
            LUT[i][4] = x_value - 2 + BOARD_HEIGHT * (y_value - 1);
        }
      
        if (CheckIfIndexisLegal(x_value - 1, y_value - 2))
        {
            LUT[i][5] = WRONG_VALUE;
        }
        else
        {
            LUT[i][5] = x_value - 1 + BOARD_HEIGHT * (y_value - 2);
        }
       
        if (CheckIfIndexisLegal(x_value + 1, y_value - 2))
        {
            LUT[i][6] = WRONG_VALUE;
        }
        else
        {
            LUT[i][6] = x_value + 1 + BOARD_HEIGHT * (y_value - 2);
        }
        
        if (CheckIfIndexisLegal(x_value + 2, y_value - 1))
        {
            LUT[i][7] = WRONG_VALUE;
        }
        else
        {
            LUT[i][7] = x_value + 2 + BOARD_HEIGHT * (y_value - 1);
        }
    }

}

