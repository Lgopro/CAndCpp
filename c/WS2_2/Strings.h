#ifndef __STRINGS_H__
#define __STRINGS_H__





/*Explanation: Copies string src to dest. The value of dest is returned*/
char *StrCpy(char *dest, const char *src); /*finish*/

/*Explanation: Copy n characters from src to dest.The value of dest is returned*/
char *StrNCpy(char *dest, const char *src, size_t n); /*finish*/

/*Explanation: Compares n characters of s1 and s2. Return 0 if they are equal, number < 0 if s1 < s2 and number > 0 if s1 > s2*/
int StrNCmp(const char *s1, const char *s2, size_t n); /*finish*/

/*Explanation: Copy the src to the end of dest. Overwrites '\0'.*/
char *StrCat(char *dest, const char *src); /*finish*/

/*Explanation: Copy the src to the end of dest. Overwrites '\0'.*/
char *StrNCat(char *dest, const char *src, size_t n); /*finish*/

/*Explanation: Compare two strings with no regard to upper and lower case.*/
int StrCaseCmp(const char *s1, const char *s2); /*finish*/

/*Explanation: Return the address of c in s.*/
char *StrChr(const char *s, int c); /*finish*/
/*Explanation: Return the string entered copied to other string.*/
char *StrDup(const char *s); /*finish*/
/*Explanation: Return the location of needle in haystack.*/
char *StrStr(const char *haystack, const char *needle); /*finish*/
/*Explanation: Check if the string can be red from both sides in the same way.*/
int Palindrom(const char *array);/*finish*/
/*Explanation: Return the number of chars of s that are part of the chars of accept.*/
size_t StrSpn(const char *s, const char *accept); /*finish*/
/*Explanation: printf BOOM if number % == 0 or contain 7.*/
char *Boom(int first,int last);





#endif /* __STRINGS_H__ */
