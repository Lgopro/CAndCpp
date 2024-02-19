#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "error.h"
#include "ui.h"
#include "deck.h"
#include "player.h"
#define MAGIC 2342343
#define CARDS_NUM 13
#define GET_TO_REAL_CARD_NUMBER 1
#define ZERO 0
#define TWO 0
#define CLUBS 3
#define GET_TO_NEXT_CARD_NUMBER 1
#define YOU_ARE_NOT_THE_BEGIN_PLAYER -1
#define MAX_NAME_LENGTH 30
#define ALOC_FAILED -1
#define NUMBER_OF_PLAYERS 4
#define HEARTS 0
#define SPADES 1
#define QUEEN 10
#define PLUS_THIRTEEN 13
#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define PLAYER_THREE 2
#define HUMAN_PLAYER 3
#define RIGHT_COUNTER_NUMBER 3
#define FLAG_ON 1
#define LOSER_SCORE 100
#define NO_LOSER_FOUND -1
#define GET_TO_REAL_PLAYER_NUMBER 1
#define NUMBER_OF_TOTAL_SWAPED_CARDS 12
#define TOTAL_OF_SWAP_OPTIONS 4
#define OPTION_ONE 1
#define OPTION_TWO 2
#define OPTION_THREE 3
#define OPTION_FOUR 0
#define STEPS_OPTION_ONE 3
#define STEPS_OPTION_TWO 9
#define STEPS_OPTION_THREE 6
#define STEPS_OPTION_FOUR 0
#define NUMBER_OF_CARDS_TO_SWAP 3
#define INDEX_OF_LAST_SWAPED_CARD 11
#define INDEX_OF_FIRST_SWAPED_CARD 0
#define GET_TO_PREVIUS_INDEX 1
#define CARDS_NUM_FIRST_TRICK 13
#define GET_TO_RIGHT_INDEX 3
#define UNTILL_BREAK 1
#define NOT_RIGHT_CARD_NUMBER 20
#define GET_TO_MINIMUM_CARD_NUMBER 1
static ADTErr GetCardsToMoveThisRound(Player* _arr[],Cards _chosen[]);
static ADTErr MoveChosenCards(Player* _arr[],Cards _chosen[],int _roundnum, int _moves);
static ADTErr SwapCardsAtEachRound(Player* _arr[],Cards _chosen[],int _roundnum);

char * SuitNames[] = {"Hearts", "Spades", "Diamonds", "Clubs"};
char * RankNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King","Ace"};
struct Player
{
	Cards* m_cards;
	int m_nikood;
	char m_name[MAX_NAME_LENGTH];
	int m_magic;
	int m_type;
};


Player* PlayerCreate(void)
{
	
	Player* player=NULL;
 	if(NULL == (player=(struct Player*)calloc(1,sizeof(struct Player))))
 	{
   		return NULL;
    }
    if(NULL == (player->m_cards=(Cards*)calloc(CARDS_NUM,sizeof(Cards))))
	{
		return NULL;
	}
    player->m_magic=MAGIC;
	return player;

}



void PlayerDestroy(Player* _player)
{
	if(NULL == _player)
	{
		return;
	}
	if(_player && _player->m_magic == MAGIC)
	{
		_player->m_magic = ZERO;
		free(_player->m_cards);
		free(_player);
		
	}
}


Player* PlayerGetCardsToHand(Player* _player,Cards* _card,int _numberofcard)
{
	if(NULL == _player || NULL == _card)
	{
		return NULL;
	}
	_player->m_cards[_numberofcard].m_suit = _card->m_suit;
	_player->m_cards[_numberofcard].m_rank = _card->m_rank;
	
	return _player;

}

void PlayerPrintHand(Player* _player,int _numberofcard)
{
	int rank,suit;
	
		rank=_player->m_cards[_numberofcard].m_rank;
		suit=_player->m_cards[_numberofcard].m_suit;
		printf("%d) %s of %s\n",_numberofcard+GET_TO_REAL_CARD_NUMBER, RankNames[rank],SuitNames[suit] );
}

Player* PlayerFullHandSorted(Player* _player,int _numbercards)
{
	int i,j;
	if(NULL == _player)
	{
		return NULL;
	}
	for(i=ZERO;i<_numbercards;i++)
	{
		for(j=i+GET_TO_NEXT_CARD_NUMBER;j<_numbercards;j++)
		{
			if( _player->m_cards[i].m_suit > _player->m_cards[j].m_suit)
			{	
				Swap(&_player->m_cards[i],&_player->m_cards[j]);
			}
			if(_player->m_cards[i].m_suit == _player->m_cards[j].m_suit && _player->m_cards[i].m_rank > _player->m_cards[j].m_rank)
			{
				Swap(&_player->m_cards[i],&_player->m_cards[j]);
			}
		}
	}
	return _player;
}

ADTErr Swap(Cards* _card1,Cards* _card2)
{
	Cards temp;
	if(NULL == _card1 || NULL == _card2)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	temp = *_card1;
	*_card1 = *_card2;
	*_card2 = temp;
	return ERR_OK;
}

int FindBeginPlayer(Player* _player,int _playernumber)
{
	int i;
	for(i=ZERO;i<CARDS_NUM;i++)
	{
		if(_player->m_cards[i].m_suit == CLUBS && _player->m_cards[i].m_rank == TWO)
		{
			return _playernumber;
		}
	}
	return YOU_ARE_NOT_THE_BEGIN_PLAYER;

}
Player* SortCardsAfterTurn(Player* _player, int _cardnumber, int _cardindex)
{
	int i;
	if(NULL == _player)
	{
		return NULL;
	}
	for(i=_cardindex; i<_cardnumber;i++)
	{
		_player->m_cards[i] = _player->m_cards[i+GET_TO_NEXT_CARD_NUMBER];
	}
	return _player;

}

int CountPoints(Cards* _arr[])
{
	int points=ZERO,i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		if(_arr[i]->m_suit == HEARTS)
		{
			points++;
		
		}
		if(_arr[i]->m_suit == SPADES && _arr[i]->m_rank == QUEEN)
		{
			points+=PLUS_THIRTEEN;
		}
		
	}
	
	return points;



}
int Turn(Player* _arr1[],int _cardindex1,int _cardindex2,int _cardindex3,int _cardindex4,int _loser)
{
	int loser;
	Cards* arr;
	 if(NULL == (arr=(struct Cards*)calloc(NUMBER_OF_PLAYERS,sizeof(struct Cards))))
 	{
   		return ALOC_FAILED;
    }
    
		arr[PLAYER_ONE]=_arr1[PLAYER_ONE]->m_cards[_cardindex1];
		arr[PLAYER_TWO]=_arr1[PLAYER_TWO]->m_cards[_cardindex2];
		arr[PLAYER_THREE]=_arr1[PLAYER_THREE]->m_cards[_cardindex3];
		arr[HUMAN_PLAYER]=_arr1[HUMAN_PLAYER]->m_cards[_cardindex4];
	
	loser=PlayersPutCard(_arr1,&arr[PLAYER_ONE],&arr[PLAYER_TWO],&arr[PLAYER_THREE],&arr[HUMAN_PLAYER],_loser);
	free(arr);
	return loser;
}
int PlayerLost(Player* _arr1[],Cards* _arr[],int _lostlastround)
{
	int i,j,flag,counter=ZERO,points;
	points=CountPoints(_arr);
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
			if(_arr[_lostlastround]->m_suit != _arr[i]->m_suit)
			{
				counter++;
			}
			if(_arr[_lostlastround]->m_suit == _arr[i]->m_suit && _arr[_lostlastround]->m_rank > _arr[i]->m_rank)
			{
				counter++;
			}
		if(counter == RIGHT_COUNTER_NUMBER)
		{
			_arr1[_lostlastround]->m_nikood += points;
			return _lostlastround;
		}
	}
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		flag=ZERO;
		counter=ZERO;
		for(j=ZERO;j<NUMBER_OF_PLAYERS;j++)
		{
			if(_arr[i]->m_suit == _arr[_lostlastround]->m_suit)
			{
				if(_arr[i]->m_suit != _arr[j]->m_suit)
				{
					counter++;
				}
				if(_arr[i]->m_suit == _arr[j]->m_suit && _arr[i]->m_rank > _arr[j]->m_rank)
				{
					counter++;
				}
			}
		}
		if(counter == RIGHT_COUNTER_NUMBER)
		{
			flag=FLAG_ON;
		}
		if(flag == FLAG_ON)
		{
			break;
		}
	
	}
	_arr1[i]->m_nikood += points;
	return i;
}

int PlayersPutCard(Player* _arr[],Cards* _player1,Cards* _player2,Cards* _player3,Cards* _player4,int _lostlastround)
{
	Cards* arr[NUMBER_OF_PLAYERS];
	int lost;
	
		arr[PLAYER_ONE] = _player1;
		arr[PLAYER_TWO] = _player2;
		arr[PLAYER_THREE] = _player3;
		arr[HUMAN_PLAYER] = _player4;
		lost = PlayerLost(_arr,arr,_lostlastround);
		return lost;
	
}


int CheckIfPlayerWon(Player* _arr[])
{
	int i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		if(_arr[i]->m_nikood>=LOSER_SCORE)
		{
			return i;
		
		}
	
	
	}
	return NO_LOSER_FOUND;


}

void PrintPlayersResults(Player* _arr[])
{
	int i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		printf("The score of player %d is: %d\n", i+GET_TO_REAL_PLAYER_NUMBER, _arr[i]->m_nikood);
	}
}

ADTErr GetCardsToMove(Player* _arr[],int _roundnum)
{
	Cards* arr;
	int i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		if(NULL == _arr[i])
		{
			return ERR_NOT_INITIALIZED;
		}
	}
	if(NULL == (arr=(struct Cards*)calloc(NUMBER_OF_TOTAL_SWAPED_CARDS,sizeof(struct Cards))))
 	{
   		return ERR_ALLOCATION_FAILED;
    }
    if(_roundnum % TOTAL_OF_SWAP_OPTIONS == OPTION_ONE)
    {
		GetCardsToMoveThisRound(_arr,arr);
		MoveChosenCards(_arr,arr,_roundnum, STEPS_OPTION_ONE);
	}
	if(_roundnum % TOTAL_OF_SWAP_OPTIONS == OPTION_TWO)
    {
		GetCardsToMoveThisRound(_arr,arr);
		MoveChosenCards(_arr,arr,_roundnum, STEPS_OPTION_TWO);
	}
	if(_roundnum % TOTAL_OF_SWAP_OPTIONS == OPTION_THREE)
    {
		GetCardsToMoveThisRound(_arr,arr);
		MoveChosenCards(_arr,arr,_roundnum, STEPS_OPTION_THREE);
	}
	if(_roundnum % TOTAL_OF_SWAP_OPTIONS == OPTION_FOUR)
    {
		MoveChosenCards(_arr,arr,_roundnum, STEPS_OPTION_FOUR);
	}

	free(arr);
	
	
	return ERR_OK;
}
static ADTErr GetCardsToMoveThisRound(Player* _arr[],Cards _chosen[])
{	
	int i,j,k=ZERO;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		for(j=ZERO;j<NUMBER_OF_CARDS_TO_SWAP;j++)
		{
			_chosen[k] = _arr[i]->m_cards[j];
			k++;
		}
	}
	return ERR_OK;
}
static ADTErr MoveChosenCards(Player* _arr[],Cards _chosen[],int _roundnum, int _moves)
{
	Cards temp;
	int i,j;
	for(j=ZERO;j<_moves;j++)
	{
		temp=_chosen[INDEX_OF_LAST_SWAPED_CARD];
		for(i=INDEX_OF_LAST_SWAPED_CARD;i>ZERO;i--)
		{
			_chosen[i]=_chosen[i-GET_TO_PREVIUS_INDEX];
		}
		_chosen[INDEX_OF_FIRST_SWAPED_CARD]=temp;
	}	
	SwapCardsAtEachRound(_arr,_chosen,_roundnum);
	return ERR_OK;
	
}

static ADTErr SwapCardsAtEachRound(Player* _arr[],Cards _chosen[],int _roundnum)
{
	
	int i,j,klaf=ZERO;
	if(_roundnum % TOTAL_OF_SWAP_OPTIONS ==OPTION_ONE || _roundnum % TOTAL_OF_SWAP_OPTIONS ==OPTION_TWO || _roundnum % TOTAL_OF_SWAP_OPTIONS ==OPTION_THREE )
	{
		for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
		{
			klaf=i*GET_TO_RIGHT_INDEX;
			for(j=ZERO;j<HUMAN_PLAYER;j++)
			{
				_arr[i]->m_cards[j]= _chosen[klaf];
				klaf++;
			}
		}
		return ERR_OK;
	}
	
	return ERR_OK;
	
}

int FindWinner(Player* _arr1[])
{
	int i,j,counter;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		counter=ZERO;
		for(j=ZERO;j<NUMBER_OF_PLAYERS;j++)
		{
			if(_arr1[i]->m_nikood <= _arr1[j]->m_nikood)
			{
				counter++;
			}
		}
		if(counter == NUMBER_OF_PLAYERS)
		{
			break;
		}
	}
	return i;
}


void GetPlayersNikoodBegining(Player* _arr1[],int _points[])
{
	int i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		_points[i]=_arr1[i]->m_nikood;
	}


}
void GetPlayersNikoodEnd(Player* _arr1[],int _points[])
{
	int i;
	for(i=ZERO;i<NUMBER_OF_PLAYERS;i++)
	{
		_points[i]=_arr1[i]->m_nikood-_points[i];
		if(i != HUMAN_PLAYER)
		{
			printf("Player %d earned %d points this round!\n", i+GET_TO_REAL_PLAYER_NUMBER, _points[i]);
		}
		else
		{
			printf("You earned %d points this round!\n", _points[i]);
		}
	}
	

}

int LoserStrategy(Player* _arr1[],int _playernumber,int _numofcards)
{
	int i;
	if(_numofcards == CARDS_NUM_FIRST_TRICK)
	{
		for(i=ZERO;i<_numofcards;i++)
		{
			if(_arr1[_playernumber]->m_cards[i].m_suit == CLUBS && _arr1[_playernumber]->m_cards[i].m_rank == TWO)
			{
				return i;
			}
		}
	
	}
	
		return ZERO;
}
int StategyComp(Player* _arr1[],int _cardnumber,int _oponentnum, int _playernumber,int _numofcards)
{
	int j;
		for(j=ZERO;j<_numofcards;j++)
		{
			if(_arr1[_playernumber]->m_cards[j].m_suit == _arr1[_oponentnum]->m_cards[_cardnumber].m_suit)
			{
				return j;
			}
		}
		for(j=ZERO;j<_numofcards;j++)
		{
			if(_arr1[_playernumber]->m_cards[j].m_suit != _arr1[_oponentnum]->m_cards[_cardnumber].m_suit && _arr1[_playernumber]->m_cards[j].m_suit == SPADES && _arr1[_playernumber]->m_cards[j].m_rank == QUEEN)
			{
				return j;
			
			}
		}
		return ZERO;
}

void UserChoise(int _oponentnum, int _numofcards)
{
	if(_numofcards == CARDS_NUM_FIRST_TRICK && _oponentnum == HUMAN_PLAYER)
	{
		printf("you begin the round\n");
		printf("Please make your choise:\n");
		return;
	}
	if(_numofcards != CARDS_NUM_FIRST_TRICK && _oponentnum == HUMAN_PLAYER)
	{
		printf("you lost the last trick\n");
		printf("Please make your choise:\n");
		return;
	}
	if(_numofcards == CARDS_NUM_FIRST_TRICK)
	{
		printf("Player %d begins the round\n", _oponentnum+GET_TO_REAL_PLAYER_NUMBER);
		printf("Please make your choise:\n");
	}
	if(_numofcards != CARDS_NUM_FIRST_TRICK)
	{
		printf("Player %d lost the last trick\n", _oponentnum+GET_TO_REAL_PLAYER_NUMBER);
		printf("Please make your choise:\n");
	}
}
void PrintTrickCards(Player* _arr1[], int _comp1card, int _comp2card, int _comp3card)
{
	int rank,suit;
	printf("\n\n");
	rank=_arr1[PLAYER_ONE]->m_cards[_comp1card].m_rank;
	suit=_arr1[PLAYER_ONE]->m_cards[_comp1card].m_suit;
	printf("player %d card) %s of %s\n",PLAYER_ONE + GET_TO_REAL_CARD_NUMBER, RankNames[rank],SuitNames[suit] );
	rank=_arr1[PLAYER_TWO]->m_cards[_comp2card].m_rank;
	suit=_arr1[PLAYER_TWO]->m_cards[_comp2card].m_suit;
	printf("player %d card) %s of %s\n",PLAYER_TWO + GET_TO_REAL_CARD_NUMBER, RankNames[rank],SuitNames[suit] );
	rank=_arr1[PLAYER_THREE]->m_cards[_comp3card].m_rank;
	suit=_arr1[PLAYER_THREE]->m_cards[_comp3card].m_suit;
	printf("player %d card) %s of %s\n",PLAYER_THREE + GET_TO_REAL_CARD_NUMBER, RankNames[rank],SuitNames[suit] );

}

int UserChoiseIfWin(Player* _arr1[],int _cardnumber,int _oponentnum, int _playernumber,int _numofcards)
{
	int card,flag=ZERO,j;
	
	do
	{
		do
		{
			UserChoise(_oponentnum,_numofcards);
			scanf("%d", &card);
			getchar();
		}while(card<GET_TO_MINIMUM_CARD_NUMBER || card>_numofcards);
		card -= GET_TO_REAL_CARD_NUMBER;
		for(j=ZERO;j<_numofcards;j++)
		{
			if(_arr1[_playernumber]->m_cards[j].m_suit == _arr1[_oponentnum]->m_cards[_cardnumber].m_suit)
			{
				flag=FLAG_ON;
			}
		}
		if(_arr1[_playernumber]->m_cards[card].m_suit == _arr1[_oponentnum]->m_cards[_cardnumber].m_suit && flag == 1 && card<_numofcards)
		{
			break;
		}
		if(flag == ZERO && card < _numofcards && card>=ZERO)
		{
			break;
			
		}
	}while(UNTILL_BREAK);
	return card;

}


int UserChoiseIfLose(Player* _arr1[],int _numcards)
{
	int card,i;
	
	do
	{
		
		UserChoise(HUMAN_PLAYER,_numcards);
		
		scanf("%d", &card);
		getchar();
		card -= GET_TO_REAL_CARD_NUMBER;
		if(_numcards==CARDS_NUM_FIRST_TRICK)
		{
			for(i=ZERO;i<_numcards;i++)
			{
				if(_arr1[HUMAN_PLAYER]->m_cards[i].m_suit == CLUBS && _arr1[HUMAN_PLAYER]->m_cards[i].m_rank == TWO)
				{
					if(card != i)
					{
						card = NOT_RIGHT_CARD_NUMBER;
					}
				}
			}
		}
		
		
	
		
	}while(card<ZERO || card>_numcards);
	return card;

}
