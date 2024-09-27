#include "str.h"
#include <string.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *s) {
    const char *endp = s;
    assert(s != NULL);
    while (*endp != '\0') {
        endp++;
    }
    return (size_t)(endp - s);
}

char *Str_copy(char *s1, const char *s2) {
    char *s1p = s1;
    const char *s2p = s2;
    assert(s1 != NULL && s2 != NULL);
    /*Assign characters in s2 to the adresses in s1*/
    while (*s2p != '\0') {
        *s1p++ = *s2p++;
    }
    /*Don't forget the null character*/
    *s1p = '\0';
    return s1;
}

char *Str_concat(char * s1, const char *s2) {
    /*Two pointers. One for scanning through s1, 
    one for scanning through s2*/
    char *s1p = s1;
    const char *s2p = s2;
    assert(s1 != NULL && s2 != NULL);
    /*Scan s1p to end of s1*/
    while (*s1p != '\0') {
        s1p++;
    }
    /*Append characters in s2 to end of s1*/
    while (*s2p != '\0') {
        *s1p++ = *s2p++;
    }
    /*Don't forget null character*/
    *s1p = '\0';
    return s1;
}

int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);
    /*Find the first difference or end of string*/
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
    /*If no difference found they are both equal*/
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    /*If s1 is shorter than s2, or if the first different character
    /*of s1 is less than that of s2, then s1 is less than s2*/
    } else if (*s1 < *s2 || *s1 == '\0') {
        return -1;
    /*Else (str at)s2 > (str at)s1*/
    } else {
        return 1;
    }
}

char *Str_search(const char *s1, const char *s2) {
    /*Two pointers to handle scan to check for a match 
    (without losing place)*/
    const char *scanp1;
    const char *scanp2;
    assert(s1 != NULL && s2 != NULL);
    /*Edge case for empty substring; return pointer to s1*/
    if (*s2 == '\0') {
        return s1;
    }
    while (*s1 != '\0') {
        /*Scan until first character match*/
        while (*s1 != *s2 && *s1 != '\0' && *s2 != '\0') {
            s1++;
        }
        /*Prepare to scan for a match*/
        scanp1 = s1; 
        scanp2 = s2;
        /*Scan for a match until inequality or end of string*/
        while (*scanp1 == *scanp2 && *scanp1 != '\0' \
        && *scanp2 != '\0') {
            scanp1++;
            scanp2++;
        }
        /*Reached end of s2, meaning we found a match!*/
        if (*scanp2 == '\0') {
            return s1;
        /*Reached end of s1 but didnt complete a match;                
        no match found*/
        } else if (*scanp1 == '\0') {
            return NULL;
        /*Move on and keep searching*/
        } else {
            s1++; 
        }
    }
    return NULL;
}

