#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ui.h"
#include "error.h"
#include "player.h"
#include "round.h"
#include "game.h"



#define ROUND_NUMBER_ONE 1
#define GET_TO_REAL_PLAYER_NUMBER 1
#define NOT_GOOD -1
#define ZERO 0
#define MAGIC 2342343
#define PLAYER_AMOUNT 4
struct Game
{
	Player* *m_player;
	int m_round;
	Round *round;
	int m_magic;
};



Game* GameCreate(void)
{
	int i=ZERO,j;
	
	Game* game=NULL;
 	if(NULL == (game=(struct Game*)calloc(1,sizeof(struct Game))))
 	{
   		return NULL;
    }
    if(NULL == (game->m_player=(struct Player**)calloc(PLAYER_AMOUNT,sizeof(struct Player*))))
 	{
   		return NULL;
    }
    for(i=ZERO; i<PLAYER_AMOUNT; i++)
    {
    	game->m_player[i] = PlayerCreate();
    	if(game->m_player[i] == NULL)
    	{
    		for(j=ZERO;j<=i;j++)
    		{
    			PlayerDestroy(game->m_player[j]);
    		}
    	
    	}
    }
    game->m_magic=MAGIC;
	return game;

}



void GameDestroy(Game* _game)
{
	int i;
	if(NULL == _game)
	{
		return;
	}
	if(_game && _game->m_magic == MAGIC)
	{
		for(i=ZERO; i<PLAYER_AMOUNT ; i++)
		{
			PlayerDestroy( _game->m_player[i] );
		}
		_game->m_magic = ZERO;
		RoundDestroy(_game->round);
		free(_game);
	}
}


Game* GameStart(Game* _game)
{
	int i=ROUND_NUMBER_ONE,result=NOT_GOOD,won;
	if(NULL == _game)
	{
		return NULL;
	}
	_game->round = RoundCreate(_game->m_player);
	while( result == NOT_GOOD)
	{
		RoundStart(_game->round, i);
		i++;
		PrintPlayersResults(_game->m_player);
		result=CheckIfPlayerWon(_game->m_player);
	}
	won=FindWinner(_game->m_player);
	printf("Player %d won!!\n", won+GET_TO_REAL_PLAYER_NUMBER);
	printf("Player %d lost!!\n", result+GET_TO_REAL_PLAYER_NUMBER);
	
	return _game;
}
/*static void FindWinnerAndLoser(int _arr[],int* _winner,int* _loser)
{
	int i,j,counter=0;
	for(i=0;i<4;i++)
	{
		if(_arr[i] >= 100)
		*_winner=i+1;
		
	}
	for(i=0;i<4;i++)
	{
		counter=0;
		for(j=0;j<4;j++)
		{
			if(_arr[i] < _arr[j])
			{
				counter++;
			}
		
		}
		if(counter == 3)
		{
			*_loser=i+1;
		
		}
	}
}*/

