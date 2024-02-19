#ifndef _CARDS_
#define _CARDS_
#include <stdlib.h>
typedef enum { Hearts , Spades,Diamonds,Clubs, EndSuit}Suit;
typedef enum {  Two=0 , Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, EndRank}Rank;
typedef struct Cards Cards;
struct Cards
{
	Suit m_suit;
	Rank m_rank;


};



#endif
