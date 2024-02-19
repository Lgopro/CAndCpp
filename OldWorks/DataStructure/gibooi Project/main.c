#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#include "error.h"
#include "ui.h"
#include "cards.h"
#include "deck.h"
#include "player.h"
#include "round.h"
#include "game.h"
#define EXIT 2


int main()
{
	int choise;
	Game* game;
	
	do
	{
		choise=PrintMenu();
		if(choise == 1)
		{
			game = GameCreate();
			GameStart(game);
			GameDestroy(game);
		}
	}while(choise != EXIT);
	return 0;


}

