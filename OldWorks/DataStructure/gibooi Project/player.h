#ifndef _PLAYER_
#define _PLAYER_
#include "cards.h"

typedef struct Player Player;
/*
Description: Function print the player hand each round.
Input: Pointer to player array structure and number of cards.
Output: Void.
Complexity: O(n).
*/
void PlayerPrintHand(Player* _player,int _numberofcard);
/*
Description: Function Create a player structure.
Input: void.
Output: NULL if player structure not created or the created player structure.
Complexity: O(1).
*/
Player* PlayerCreate(void);
/*
Description: Function destroy the player structure.
Input: Pointer to player structure.
Output: void.
Complexity: O(1).
*/
void PlayerDestroy(Player* _player);
/*
Description: Function get the cards for the players.
Input: Pointer to player structure.
Output: The new player structure.
Complexity: O(n).
*/
Player* PlayerGetCardsToHand(Player* _player,Cards* _card,int _numberofcard);
/*
Description: Function make the player to put 1 card to the game.
Input: Pointer to player structure.
Output: The new player structure.
Complexity: O(n).
*/
Player* PlayerPutCards(Player* _player);
/*
Description: Function get the points of the player in the end of the round.
Input: Pointer to player structure and a pointer to the updated points
Output: ERR_OK if the points updated and ERR_NOT_INITIALIZED if the player structure does not exist.
Complexity: O(1).
*/

ADTErr PlayerUpdateNikood(Player* _player, int* nikood);
/*
Description: Function swaps between 2 cards.
Input: The 2 cards needed to swap.
Output: ERR_OK if the cards swaped and ERR_NOT_INITIALIZED if one of the cards are NULL.
Complexity: 
*/
ADTErr Swap(Cards* _card1,Cards* _card2);
/*
Description: Function sort the hand of the players.
Input: The player structure and the number of cards
Output: The player structure with the sorted hand.
Complexity: O(n).
*/
Player* PlayerFullHandSorted(Player* _player,int _numbercards);
/*
Description: Function finds the player that begin the round.
Input: The player structure and the player number
Output: return the number of the begining player.
Complexity: O(n).
*/
int FindBeginPlayer(Player* _player,int _playernumber);
/*
Description: Function compare find the losing player in the trick.
Input: The 4 player structures.
Output: The number of the losing player.
Complexity: O(1).
*/
int ChooseLoserInMiniRound(Player* _player1,Player* _player2,Player* _player3,Player* _player4);
/*
Description: function sort the cards in the end of the turn to each player
Input: Pointer to player structure, the total card number and the card index you want to remove.
Output: New player structure after finishing the procces.
Complexity: O(n)
*/
Player* SortCardsAfterTurn(Player* _player, int _cardnumber, int _cardindex);
/*
Description: function count the points of the cards that all the players put this round.
Input: Pointer to card structure array that the players put.
Output: Number of poits that the loser of the round will get.
Complexity: O(n)
*/
int CountPoints(Cards* _arr[]);
/*
Description: function determine the lost player.
Input: Pointer to players array, pointer to cards array and the number of the player that lost last round.
Output: Number of the player lost.
Complexity: O(n)
*/
int PlayerLost(Player* _arr1[],Cards* _arr[],int _lostlastround);
/*
Description: Function put The puted cards in a card array to continue the determination of the loser of the round.
Input: Pointer to players array, pointer to cards the cards of the 4 players and the number of the lost player.
Output: Number of the player lost.
Complexity: O(n)
*/
int PlayersPutCard(Player* _arr[],Cards* _player1,Cards* _player2,Cards* _player3,Cards* _player4,int _lostlastround);
/*
Description: Function get the card indexes of the 4 players to determine the loser of the round.
Input: Pointer to players array, index of the cards of the 4 players and the number of the lost player.
Output: Number of the player lost.
Complexity: O(n)
*/
int Turn(Player* _arr1[],int _cardindex1,int _cardindex2,int _cardindex3,int _cardindex4,int _loser);
/*
Description: Function check if any player got to 100 points.
Input: Pointer to players array.
Output: return -1 if no one got 100 points and the number of player the did got to 100 points.
Complexity: O(n)
*/
int CheckIfPlayerWon(Player* _arr[]);
/*
Description: Function print the player points.
Input: Pointer to players array.
Output: void.
Complexity: O(n)
*/
void PrintPlayersResults(Player* _arr[]);
/*
Description: Function get the swap between players depending on the round.
Input: Pointer to players array and round number.
Output: ERR_NOT_INITIALIZED if the player array structure is NULL or ERR_OK if the swap happened.
Complexity: O(n)
*/
ADTErr GetCardsToMove(Player* _arr[],int _roundnum);
/*
Description: Function find the winner of the game.
Input: Pointer to players array structure.
Output: number of the player that won.
Complexity: O(n)
*/
int FindWinner(Player* _arr1[]);
/*
Description: Function get the player points at the begining of the round.
Input: Pointer to players array structure and poits array.
Output: void.
Complexity: O(n)
*/
void GetPlayersNikoodBegining(Player* _arr1[],int _points[]);
/*
Description: Function print the poits the players got after the round.
Input: Pointer to players array structure and poits array.
Output: void.
Complexity: O(n)
*/
void GetPlayersNikoodEnd(Player* _arr1[],int _points[]);
/*
Description: Function print the poits the players got after the round.
Input: Pointer to players array structure and poits array.
Output: void.
Complexity: O(n)
*/
int LoserStrategy(Player* _arr1[],int _playernumber,int _numofcards);
/*
Description: Function make the computer pick the right card.
Input: Pointer to players array structure, the number of the card and the number of his card, player number and number of cards.
Output: The number of card that the computer player returnes.
Complexity: O(n)
*/
int StategyComp(Player* _arr1[],int _cardnumber,int _oponentnum, int _playernumber,int _numofcards);
/*
Description: Function check the user choise if he lost the lst trick or if he begins the round.
Input: Pointer to players array structure and number of cards.
Output: The number of card that the user returnes.
Complexity: O(n)
*/
int UserChoiseIfLose(Player* _arr1[],int _numcards);
/*
Description: Function check the user choise if he dident lost the lst trick.
Input: Pointer to players array structure,the oponent number nd card that is the loser of last trick and current player number and number of cards.
Output: The number of card that the user returnes.
Complexity: O(n)
*/
int UserChoiseIfWin(Player* _arr1[],int _cardnumber,int _oponentnum, int _playernumber,int _numofcards);
/*
Description: Function print the oponent the lost the last trick before player choise.
Input: Oponent number and number of cards.
Output: Void.
Complexity: O(1)
*/
void UserChoise(int _oponentnum, int _numofcards);
/*
Description: Function print the crds that all players put in the trick.
Input: Pointer to players array structure and the three puted cards of the comuter.
Output: Void.
Complexity: O(1)
*/
void PrintTrickCards(Player* _arr1[], int _comp1card, int _comp2card, int _comp3card);

#endif
