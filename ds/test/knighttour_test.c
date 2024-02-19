/*
Rev: Yonathan Zarkovian
Dev: Leonid Golovko
status: Approved
date: 26/06/2023
*/
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/

#include "knighttour.h"


void FindKnightMovesTest();
void KnightsTourWarnsdorfAlgorithmTest();
void FindKnightMovesTimeTest();
void KnightsTourWarnsdorfAlgorithmTimeTest();

int main()
{	
	FindKnightMovesTest();
	KnightsTourWarnsdorfAlgorithmTest();
	FindKnightMovesTimeTest();
	KnightsTourWarnsdorfAlgorithmTimeTest();
	return 0;
}

void FindKnightMovesTest()
{
    unsigned char path[64] = {0};
	size_t i = 0;
    status_t status = KNIGHT_TOUR_TIME_OUT;
    status = KnightsTour(0, 0, 300, FALSE, path);
	for(i = 0; i < 64; ++i)
	{
		printf("%d ", *(path + i));
	}
    if(KNIGHT_TOUR_SUCCESS == status)
	{
		printf("\nFindKnightMovesTest pass\n");
	}
	
	else
	{
		printf("\nFindKnightMovesTest fail\n");
	}

}

void KnightsTourWarnsdorfAlgorithmTest()
{
	unsigned char path[64] = {0};
	size_t i = 0;
    status_t status = KNIGHT_TOUR_TIME_OUT;
    status = KnightsTour(0, 0, 300, TRUE, path);
	for(i = 0; i < 64; ++i)
	{
		printf("%d ", *(path + i));
	}
    if(KNIGHT_TOUR_SUCCESS == status)
	{
		printf("\nKightsTourWarnsdorfAlgorithmTest pass\n");
	}
	
	else
	{
		printf("\nKnightsTourWarnsdorfAlgorithmTest fail\n");
	}
}

void FindKnightMovesTimeTest()
{
    unsigned char path[64] = {0};
    status_t status = KNIGHT_TOUR_TIME_OUT;
    status = KnightsTour(0, 0, 5, FALSE, path);
    if(KNIGHT_TOUR_TIME_OUT == status)
	{
		printf("\nFindKnightMovesTimeTest pass\n");
	}
	
	else
	{
		printf("\nFindKnightMovesTimeTest fail\n");
	}

}

void KnightsTourWarnsdorfAlgorithmTimeTest()
{
	unsigned char path[64] = {0};
    status_t status = KNIGHT_TOUR_TIME_OUT;
    status = KnightsTour(0, 0, 0, TRUE, path);
    if(KNIGHT_TOUR_TIME_OUT == status)
	{
		printf("\nKnightsTourWarnsdorfAlgorithmTimeTest pass\n");
	}
	
	else
	{
		printf("\nKnightsTourWarnsdorfAlgorithmTimeTest fail\n");
	}
}