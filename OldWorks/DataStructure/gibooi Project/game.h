#ifndef _GAME_
#define _GAME_


typedef struct Game Game;

/*
Description: Function Create a game structure.
Input: void.
Output: NULL if game not created or the created game structure.
Complexity: O(1).
*/
Game* GameCreate(void);
/*
Description: Function Start the game and runs it.
Input: Pointer to game structure.
Output: NULL if game not created or the  game structure after the end of the game.
Complexity: O(1).
*/
Game* GameStart(Game* _game);
/*
Description: Function destroy the game structure.
Input: Pointer to game structure.
Output: void.
Complexity: O(1).
*/
void GameDestroy(Game* _game);
/*
Description: Function prints the results and determine the winner and the loser.
Input: Pointer to game structure.
Output: void.
Complexity: O(n).
*/
void PrintEndGame(Game* _game);
#endif

