#ifndef _ROUND_
#define _ROUND_


/*
Description: Function the length of the string.
Input: pointer to char array.
Output: size of the array.
Complexity: O(n)
*/
size_t  StrlenItr(const char* _str);
/*
Description: Function the length of the string recursivly
Input: pointer to char array.
Output: size of the array.
Complexity: O(n)
*/
size_t  StrlenRec(const char* _str);
/*
Description: Compares two strings.
Input: pointer to two char arrays.
Output: 0 if the are the same, bigger then 0 if str1 bigger and smaller then 0 if str1 is smaller.
Complexity: O(n)
*/
int     StrcmpItr(const char* _str1,   const char* _str2);
/*
Description: Compares two strings recursivly.
Input: pointer to two char arrays.
Output: 0 if the are the same, bigger then 0 if str1 bigger and smaller then 0 if str1 is smaller.
Complexity: O(n)
*/
int     StrcmpRec(const char* _str1,   const char* _str2);
/*
Description: Function copy the source string to the destination.
Input: pointer to two char arrays.
Output: pointer to the destination char
Complexity: O(n)
*/
char*   StrcpyItr(char*  _destination, const char* _source);
/*
Description: Function copy the source string to the destination recursivly.
Input: pointer to two char arrays.
Output: pointer to the destination char
Complexity: O(n)
*/
char*   StrcpyRec(char*  _destination, const char* _source);
/*
Description: Function copy the selected number of the source string to the destination.
Input: pointer to two char arrays and number of chars to copy.
Output: pointer to the destination char
Complexity: O(n)
*/
char*   StrncpyItr(char* _destination, const char* _source, size_t _num);
/*
Description: Function copy the selected number of the source string to the destination recursivly.
Input: pointer to two char arrays and number of chars to copy.
Output: pointer to the destination char
Complexity: O(n)
*/
char*   StrncpyRec(char* _destination, const char* _source, size_t _num);
/*
Description: Function copy the source string to the end of the destination string.
Input: pointer to two char arrays
Output: void.
Complexity: O(n)
*/
char*   MyStrcat(char*   _destination, const char* _source);
/*
Description: Function find the substring in the main string.
Input: Two char pointers .
Output: NULL if substing not found or pointer to the found 
Complexity: O(n)
*/
char*   MyStrstr(const char* _str,     const char* _substr);

#endif
