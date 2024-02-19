
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "error.h"
#include "cards.h"
#include "ui.h"
#include "deck.h"

#define ZERO 0
#define CARDS_NUM 52
#define MAGIC 2342343

struct Deck
{
	
	Cards* m_cards;
	int m_cardamount;
	int m_magic;


};


Deck* DeckCreate(void)
{
	int i=ZERO;
	Suit suit;
	Rank rank;
	Deck* deck=NULL;
 	if(NULL == (deck=(struct Deck*)malloc(sizeof(struct Deck))))
 	{
   		return NULL;
    }
    if(NULL == (deck->m_cards=(Cards*)calloc(CARDS_NUM,sizeof(Cards))))
	{
		return NULL;
	}
    for(suit=ZERO; suit<EndSuit ;suit++)
    {
    	for(rank=Two; rank<EndRank;rank++)
    	{
    		deck->m_cards[i].m_suit = suit;
    		deck->m_cards[i].m_rank = rank;
    		i++;
    	}
    }
    deck->m_magic=MAGIC;
    deck->m_cardamount = CARDS_NUM;
	return deck;

}

void DeckDestroy(Deck* _deck)
{
	
	if(NULL == _deck)
	{
		return;
	}
	if(_deck && _deck->m_magic == MAGIC)
	{
		free(_deck->m_cards);
		_deck->m_magic = ZERO;
		free(_deck);
	}
}

Cards DeckGetCard(Deck* _deck, int _numcards)
{
	
	if(NULL == _deck)
	{
	
	}
	
	return _deck->m_cards[_numcards];
}


Deck* DeckShuffle(Deck* _deck)
{
	int i,index1,index2;
	Cards temp;
	if(NULL == _deck)
	{
		return NULL;
	}
	srand(time(NULL));
    
	
	for(i=ZERO;i<CARDS_NUM;i++)
	{
		index1=rand()%CARDS_NUM;
		index2=rand()%CARDS_NUM;
		if(index1 != index2)
		{
			temp=_deck->m_cards[index1];
			_deck->m_cards[index1]= _deck->m_cards[index2];
			_deck->m_cards[index2]= temp;
		}
	}
	return _deck;
}

