#ifndef _UI_
#define _UI_
#include "error.h"
#include "player.h"
#include "round.h"
#include "game.h"
/*
Description: Function print the menu.
Input: void.
Output: player number of choise.
Complexity: O(1).
*/
int PrintMenu(void);
/*
Description: Function print round score.
Input: Pointer to player array structure
Output: void.
Complexity: O(n).
*/
void PrintRoundScore(Player* _player[],int _score1,int _score2,int _score3,int _score4);
/*
Description: Function print the game score.
Input: Pointer to game structure.
Output: NULL if round not initialized or the created round structure.
Complexity: O(1).
*/
void PrintGameScore(Game* _game);
/*
Description: Function print the hand of the player.
Input: Pointer to player structure
Output: NULL if round not initialized or the created round structure.
Complexity: O(n).
*/
void PrintHand(Player* _player);



#endif
