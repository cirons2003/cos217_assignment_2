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
    while (s2[index] != '\0') {
        s1[index] = s2[index];
        index++;
    }
    s1[index] = '\0';
    return s1; 
}

char *Str_concat(char * s1, const char * s2) {
    int index1 = 0, index2 = 0;
    assert(s1 != NULL && s2 != NULL);
    while (s1[index1] != '\0') {
        index1++;
    }
    while (s2[index2] != '\0') {
        s1[index1++] = s2[index2++];
    }
    s1[index1] = '\0';
    return s1;
}

int Str_compare(const char * s1, const char *s2) {
    int index = 0; 
    assert(s1 != NULL && s2 != NULL);
    while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0') {
        index++;
    } 
    if (s1[index] == '\0' && s2[index] == '\0') {
        return 0; 
    } else if (s1[index] < s2[index] || s1[index] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

char *Str_search(const char *s1, const char *s2) {
    int index = 0;
    int offset;
    assert(s1 != NULL && s2 != NULL);
    if (s2[0] == '\0') {
    	return &s1[0];
    }
    while (s1[index] != '\0') {
        while (s1[index] != s2[0] && s1[index] != '\0') {
            index++;
        }
        offset = 0;
        while (s1[index + offset] == s2[offset] && s1[index + offset] != '\0' && s2[offset] != '\0') {
            offset++;
        }
        if (s2[offset] == '\0') 
            return &s1[index];
        else if (s1[index + offset] == '\0') 
            return NULL;
        else 
            index++;
    }
    return NULL;
}
