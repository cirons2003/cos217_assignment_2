#ifndef STR_H
#define STR_H

#include <stddef.h>

/*
** Accepts a string, returns the number of characters
** in the string (excluding the null character)
*/
size_t Str_getLength(const char *s);

/*
** Copies the string pointed to by s2 to the 
** string pointed to by s1. 
** Does not change the string pointed to by s2
*/
char *Str_copy(char * s1, const char * s2);

/*
** Appends the characters in the string pointed 
** to by s2, to the end of the string pointed to
** by s1. Does not change the string pointed to by s2.
*/
char *Str_concat(char * s1, const char * s2);

/*
** Returns 1 if s1 is greater than s2
** Returns 0 if s1 is equal to s2
** Returns -1 if s1 is less than s2
**
** A string s1 is less than string s2, if the
** first n>=0 characters are the same, and the 
** n+1th character of s1 is lexicographically less
** than s2. 
** If all characters are equal, but s1 and s2 are 
** of different lengths, the shorter string is deemed
** less than the longer string.
*/
int Str_compare(const char * s1, const char *s2);

/*
** Returns a pointer to the first occurence of the string pointed to by 
** s2 within the string pointed to by s1. If no such occurence 
** is found, returns the NULL pointer. 
*/
char *Str_search(const char *s1, const char *s2);

#endif