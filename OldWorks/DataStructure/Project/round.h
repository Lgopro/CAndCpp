#ifndef _ROUND_
#define _ROUND_

#include "cards.h"
#include "player.h"
typedef struct Round Round;
/*
Description: Function start the round
Input: Pointer to round structure and round number.
Output: ERR_NOT_INITIALIZED if round not initialized and ERR_OK if round is running.
Complexity: O(1).
*/
ADTErr RoundStart(Round* _round,int _roundnumber);
/*
Description: Function Create a round structure
Input: Pointer to player array structure
Output: NULL if round not initialized or the created round structure.
Complexity: O(1).
*/
Round* RoundCreate(Player** _player);
/*
Description: Function destroy the round structure.
Input: Pointer to round structure.
Output: void.
Complexity: O(1).
*/
void RoundDestroy(Round* _round);
/*
Description: Function play 1 round of the game.
Input: Pointer to round structure and pointer to the 4 playing players
Output: ERR_OK if round played properly, ERR_NOT_INITIALIZED if one of the players structures or the round structure is not created.
Complexity: O(1).
*/
ADTErr RoundPlay(Round* _round,Player* _player1, Player* _player2,Player* _player3,Player* _player4);

/*
Description: Function compare the cards of the 4 players and return the number of the winner.
Input: Pointer to round structure and pointer to the 4 cards of the playing players.
Output: The number of the player won.
Complexity: O(1).
*/
int CompareCards(Round* _round,Cards* _player1, Cards* _player2, Cards* _player3, Cards* _player4, int _playersturn);
/*
Description: Function count the points of the 4 players.
Input: Pointer to round structure and pointer to the 4 playing players.
Output: ERR_OK if points counted properly, ERR_NOT_INITIALIZED if one of the players structures or the round structure is not created.
Complexity: O(1).
*/
ADTErr CountPionts(Round* _round,Player* _player1, Player* _player2,Player* _player3,Player* _player4);
/*
Description: Function get full hand of cards to the player.
Input: Pointer to round structure and pointer to the player structure.
Output: ERR_OK if the player got all card, ERR_NOT_INITIALIZED if one of the player structure or the round structure is not created.
Complexity: O(n).
*/
ADTErr PlayerGetCards(Round* _round,Player* _player1);
#endif
