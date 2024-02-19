#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "player.h"
#include "round.h"
#include "game.h"
int PrintMenu(void)
{
	int choise;
	do
	{
		printf("Welcome to War! You duel 3 more oponents in the game of hearts!\n");         
    	printf("The winner of the game is determined by whoever ends with the lowest points\n");
    	printf("The loser of game is the player with the highest points\n");
		printf("Please enter the option you prefer!\n");
		printf("1) Start game\n");
		printf("2) Exit game\n");
		printf("Please enter your choise\n");
		scanf("%d", &choise);
	}while(choise<0 || choise>2);
	return choise;


}




