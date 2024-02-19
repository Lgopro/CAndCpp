

#ifndef __WORD_H__
#define __WORD_H__


/*
Description: fill memory with a constant byte.
Receive: void pointer, byte to add as an int, amount of times to add.
Return: return a pointer to the memory area s.
*/
void *Memset(void *s, int c, size_t n);
/*
Description: copy memory area.
Receive: pointer to a void source and destination and amount of bytes to copy.
Return: return a pointer to dest.
*/
void *Memcpy(void *dest, const void *src, size_t n);
/*
Description: copy memory area. Can handle memory area overlap
Receive: pointer to a void source and destination and amount of bytes to copy.
Return: return a pointer to dest.
*/
void *Memmove(void *dest, const void *src, size_t n);

#endif /*__WORD_H__*/

