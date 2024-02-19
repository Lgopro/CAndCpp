#ifndef _DECK_
#define _DECK_
#include "cards.h"
typedef struct Deck Deck;


/*
Description: Function Create a deck structure.
Input: void.
Output: NULL if deck structure not created or the created deck structure.
Complexity: O(1).
*/
Deck* DeckCreate(void);
/*
Description: Function destroy the deck structure.
Input: Pointer to deck structure.
Output: void.
Complexity: O(1).
*/
void DeckDestroy(Deck* _deck);
/*
Description: Function shuffle the deck.
Input: Pointer to deck structure.
Output: The structure of the shuffeled deck.
Complexity: O(n).
*/
Deck* DeckShuffle(Deck* _deck);
/*
Description: Function gets a card from the deck.
Input: Pointer to deck structure and number of cards.
Output: Card structure.
Complexity: O(n).
*/
Cards DeckGetCard(Deck* _deck,int _numcards);


#endif
