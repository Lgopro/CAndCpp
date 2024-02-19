#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "ui.h"
#include "cards.h"
#include "deck.h"
#include "player.h"
#include "round.h"
#define CARD_AMOUNT 13
#define ZERO 0
#define PLAYER_AMOUNT 4
#define MAGIC 2342343
#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define PLAYER_THREE 2
#define HUMAN_PLAYER 3
#define ROUNDS_LEFT 12
#define CARDS_NUM 52
#define GET_TO_REAL_CARD_NUMBER 1
#define WRONG -1

/*
Description: Function fill the hands of the players with cards
Input: The round structure.
Output: void.
Complexity: O(n)
*/
static void FillHands(Round* _round);
/*
Description: Function sort the hands of all players.
Input: The round structure.
Output: void
Complexity: O(n)
*/
static void SortFullHand(Round* _round);
/*
Description: Function print the hand of the player.
Input: The round structure and the amount of cards
Output: void.
Complexity: O(n)
*/
static void PrintallHands(Round* _round,int _cardamount);
/*
Description: The function finds the player with the two of clubs to start the game.
Input: The round structure.
Output: void.
Complexity: O(n)
*/
static int FindStartingPlayer(Round* _round);
/*
Description: Function sort the hand after each turn.
Input: the round structure.
Output: void.
Complexity: O(n)
*/
static int HandAfterOneTurn(Round* _round,int _cardamount,int _loser);

struct Round
{
	Deck* m_deck;
	Player* m_player[PLAYER_AMOUNT];
	int m_points[PLAYER_AMOUNT];
	int m_roundnum;
	int m_magic;

};




Round* RoundCreate(Player* _player[])
{
	int i;
	Round* round=NULL;
 	if(NULL == (round=(struct Round*)calloc(1,sizeof(struct Round))))
 	{
   		return NULL;
    }
    
    round->m_magic=MAGIC;
    round->m_deck = DeckCreate();
    for(i=ZERO;i<PLAYER_AMOUNT;i++)
    {
    	round->m_player[i]=_player[i];
    }
	return round;

}



void RoundDestroy(Round* _round)
{
	if(NULL == _round)
	{
		return;
	}
	if(_round && _round->m_magic == MAGIC)
	{
		_round->m_magic = ZERO;
		DeckDestroy(_round->m_deck);
		
		free(_round);
	}
}

ADTErr RoundStart(Round* _round,int _roundnumber)
{
	int i,loser;
	if(NULL == _round)
	{
		return ERR_NOT_INITIALIZED;
	}
	GetPlayersNikoodBegining(_round->m_player,_round->m_points);
	_round->m_deck = DeckCreate();
	_round->m_deck=DeckShuffle(_round->m_deck);
	FillHands(_round);
	SortFullHand(_round);
	loser=FindStartingPlayer(_round);
	GetCardsToMove(_round->m_player,_roundnumber);
	SortFullHand(_round);
	PrintallHands(_round,CARD_AMOUNT);
	loser=HandAfterOneTurn(_round,CARD_AMOUNT,loser);
	for(i=ROUNDS_LEFT;i>ZERO;i--)
	{
		PrintallHands(_round,i);
		loser=HandAfterOneTurn(_round,i,loser);
		
	}
	GetPlayersNikoodEnd(_round->m_player,_round->m_points);
	return ERR_OK;

}


static void FillHands(Round* _round)
{
	int i,j,numberofcards=CARDS_NUM;
	Cards card;
	for(i=ZERO;i<PLAYER_AMOUNT;i++)
	{
		for(j=ZERO;j<CARD_AMOUNT;j++)
		{
			numberofcards--;
			card=DeckGetCard(_round->m_deck,numberofcards);
			PlayerGetCardsToHand(_round->m_player[i], &card, j);
			
		}
	}
}

static void SortFullHand(Round* _round)
{
	int i;
	for(i=ZERO;i<PLAYER_AMOUNT;i++)
	{
		PlayerFullHandSorted(_round->m_player[i],CARD_AMOUNT);
	}
}

static void PrintallHands(Round* _round,int _cardamount)
{
	int j;
	
	printf("\nYour hand is:\n");
	for(j=ZERO;j<_cardamount;j++)
	{
		PlayerPrintHand(_round->m_player[HUMAN_PLAYER],j);
	}
	
}

static int FindStartingPlayer(Round* _round)
{
	int i,playernumber;
	for(i=ZERO;i<PLAYER_AMOUNT;i++)
	{
		playernumber = FindBeginPlayer(_round->m_player[i],i+GET_TO_REAL_CARD_NUMBER);
		if(playernumber == WRONG)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return i;
}
	


static int HandAfterOneTurn(Round* _round,int _cardamount,int _loser)
{
	int i,loser,arr[PLAYER_AMOUNT],player=HUMAN_PLAYER;
	
	if(_loser == player)
	{
		 arr[player]=UserChoiseIfLose(_round->m_player,_cardamount);
	}
	for(i=ZERO;i<HUMAN_PLAYER;i++)
	{
		if(i == _loser)
		{
			arr[_loser]=LoserStrategy(_round->m_player,_loser,_cardamount);
		}
	}
	
	for(i=ZERO;i<HUMAN_PLAYER;i++)
	{
		if(i != _loser)
		{
			arr[i]=StategyComp(_round->m_player,arr[_loser],_loser, i,_cardamount);
		}
	}
	PrintTrickCards(_round->m_player, arr[PLAYER_ONE], arr[PLAYER_TWO],arr[PLAYER_THREE]);
	if(_loser != player)
	{
		
		arr[player]=UserChoiseIfWin(_round->m_player,arr[_loser] , _loser, player,_cardamount);
	
	}
	loser=Turn(_round->m_player,arr[PLAYER_ONE],arr[PLAYER_TWO],arr[PLAYER_THREE],arr[HUMAN_PLAYER],_loser);
	for(i=ZERO;i<PLAYER_AMOUNT;i++)
	{
		SortCardsAfterTurn(_round->m_player[i],_cardamount,arr[i]);
	}

	return loser;

}


