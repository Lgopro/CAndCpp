/*
Rev: Etai Shimoni
Dev: Leonid Golovko
status: finished
date:16/04/23
*/

#ifndef __ITOAATOI_H__
#define __ITOAATOI_H__


/*
Description: Convert string to int.
Receive: char pointer.
Return: return integer and 0 on an error.
*/
int AtoIBaseTen(const char *nptr);
/*
Description: Convert int to string.
Receive: char string, base and value.
Return: return integer and exit by assert on an error.
*/
char *ItoA(int value, char *str, int base);
/*
Description: Convert int to string on base 10.
Receive: char string, base and value.
Return: return integer and exit by assert on an error.
*/
char *ItoABaseTen(int number, char *str, int base);
/*
Description: Convert string to int.
Receive: char string, base and value.
Return: return integer and 0 on an error.
*/
int AtoI(int value, char *str, int base);
#endif /*__ITOAATOI_H__*/

