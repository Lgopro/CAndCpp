#ifndef __BITWISE_H__
#define __BITWISE_H__


int PowOfTwoWithFor(unsigned int x);
/*Explanation: Founds if x is a pow of 2 with for or while*/
int PowOfTwoWithIf(unsigned int x);
/*Explanation: Print char in bits*/
void PrintBit(unsigned char x);
/*Explanation: fFunds if x is a pow of 2 with no for or while*/
int PowOfTwoWithFor(unsigned int x);
/*Explanation: Founds if x is a pow of 2 with for or while*/
int PowOfTwoWithIf(unsigned int x);
/*Explanation: Prints 32 bits of float*/
void PrintFloat(float number);
/*Explanation: finds if there is 3 bits that are on*/
void Count3(unsigned int *arr, size_t size);
/*Explanation: counts amount of bits set with loop*/
int BitCounterWithLoop(int x);
/*Explanation: Byte miror*/
int MirWithLoop(unsigned char x);
/*Explanation: Checks if 2 and 6 bit are on. if theey are return true*/
int SixAndTwo(int number);
/*Explanation: Checks if at least one of 2 or 6 bit are on. if theey are return true**/
int SixOrTwo(int number);
/*Explanation: Swaps 3 and 5 bit.*/
int SwapBit(unsigned char number, unsigned int location1, unsigned int location2);
/*Explanation: Returns number smaller than the one entered that is divided by 16.*/
unsigned int DivideBy16(unsigned int number);
/*Explanation: Byte miror with no loop*/
int MirWithNoLoop(unsigned char x);
/*Explanation: Returns x*(2^y) */
long Pow2(unsigned int x, unsigned int y);
/*Explanation: Copies string src to dest. The value of dest is returned*/
void Swap(int *number1, int *number2);
/*Explanation: returns number + 1*/
int Plus1(int number);
int BitCounterWithNoLoop(int x);



#endif /* __BITWISE_H__ */
