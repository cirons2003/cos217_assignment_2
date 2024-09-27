#include "str.h"
#include <string.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *s) {
    size_t len = 0;
    assert(s != NULL);
    while (s[len] != '\0') {
        len++;
    }
    return len; 
}

char *Str_copy(char * s1, const char * s2) {
    int index = 0;
    assert(s1 != NULL && s2 != NULL);
    /*Replaces the characters in s1, with those in s2*/
    while (s2[index] != '\0') {
        s1[index] = s2[index];
        index++;
    }
    /*Can't forget the null character*/
    s1[index] = '\0';
    return s1; 
}

char *Str_concat(char * s1, const char * s2) {
    int index1 = 0, index2 = 0;
    assert(s1 != NULL && s2 != NULL);
    /*First push index1 to the end of s1 (on the null character)*/
    while (s1[index1] != '\0') {
        index1++;
    }
    /*Append each character from s2 to the end of s1*/
    while (s2[index2] != '\0') {
        s1[index1++] = s2[index2++];
    }
    s1[index1] = '\0';
    return s1;
}

int Str_compare(const char * s1, const char *s2) {
    int index = 0; 
    assert(s1 != NULL && s2 != NULL);
    /*Find the first difference in the two strings 
    (or end of a string)*/
    while (s1[index] == s2[index] && s1[index] != '\0' \
    && s2[index] != '\0') {
        index++;
    } 
    /*If no difference found, they are both equal*/
    if (s1[index] == '\0' && s2[index] == '\0') {
        return 0; 
    /*If s1 is shorter than s2, or if the first different character
    /*of s1 is less than that of s2, then s1 is less than s2*/
    } else if (s1[index] < s2[index] || s1[index] == '\0') {
        return -1;
    /*Else (str at)s2 > (str at)s1*/
    } else {
        return 1;
    }
}

char *Str_search(const char *s1, const char *s2) {
    int index = 0;
    int offset;
    assert(s1 != NULL && s2 != NULL);
    /*Edge case for empty substring; return pointer to s1*/
    if (s2[0] == '\0') {
        return (char*)&s1[0];
    }
    while (s1[index] != '\0') {
        /*Skip until you match the first character of s2*/
        while (s1[index] != s2[0] && s1[index] != '\0') {
            index++;
        }
        /*keep track of an offset as you scan to see if its a match*/  
        offset = 0;
        while (s1[index + offset] == s2[offset] \
        && s1[index + offset] != '\0' && s2[offset] != '\0') {
            offset++;
        }
        /*If at the end of s2 after the scan, you found a match. 
        Return pointer to start (index)*/
        if (s2[offset] == '\0') 
            return (char*)&s1[index];
        /*If at the end of s1 after the scan (but not at end of s2) 
        you ran out of space (no match found)*/
        else if (s1[index + offset] == '\0') 
            return NULL;
        /*Move on and keep searching*/
        else 
            index++;
    }
    return NULL;
}
